/* JaneClone - a text board site viewer for 2ch
 * Copyright (C) 2012 Hiroyuki Nagata
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 * Contributor:
 *	Hiroyuki Nagata <newserver002@gmail.com>
 */

#include "ThreadContentWindow.h"

IMPLEMENT_DYNAMIC_CLASS(ThreadContentWindow, wxHtmlWindow)

/**
 * 通常のコンストラクタ
 */
ThreadContentWindow::ThreadContentWindow(wxWindow* parent, const wxString& threadContentPath):
wxHtmlWindow(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHW_SCROLLBAR_AUTO) {

	// 指定されたパスからHTMLファイルを読み出す
	wxString htmlSource = GetConvertedDatFile(threadContentPath);
	// メモリに読み込んだHTMLを表示する
	this->SetPage(htmlSource);
}
/**
 * 指定されたパスからHTMLファイルを読み出し、2ch形式に加工する
 */
const wxString ThreadContentWindow::GetConvertedDatFile(
		const wxString& threadContentPath) {

	// wxStringにバッファするサイズを計測する
	size_t fileSize = JaneCloneUtil::GetFileSize(threadContentPath);

	if (fileSize == 0)
		// 読み込みに失敗した場合
		return FAIL_TO_READ_PAGE;

	// 取得サイズ分だけwxStringを確保する
	wxString htmlSource;
	htmlSource.Alloc(fileSize);
	htmlSource += HTML_HEADER;

	// テキストファイルの読み込み
	wxTextFile datfile;
	datfile.Open(threadContentPath, wxConvUTF8);
	wxString str;
	int number = 1;

	// スレッドのそれぞれの要素
	wxString default_nanashi;
	wxString mail;
	wxString day_and_ID;
	wxString res;

	// ファイルがオープンされているならば
	if (datfile.IsOpened()) {
		for (str = datfile.GetFirstLine(); !datfile.Eof();
				str = datfile.GetNextLine()) {

			// ひとかたまりのHTMLソースにまとめる
			wxString lumpOfHTML = wxT("<dt>");
			wxString num;
			num << number;
			lumpOfHTML += num;

			// 正規表現でレスの内容を取り出してメモリに展開する
			if (regexThread.IsValid()) {
				if (regexThread.Matches(str)) {
					// マッチさせたそれぞれの要素を取得する
					default_nanashi.Clear();
					default_nanashi = regexThread.GetMatch(str, 1);
					mail.Clear();
					mail = regexThread.GetMatch(str, 2);
					day_and_ID.Clear();
					day_and_ID = regexThread.GetMatch(str, 3);

					// レスの最初に<table>タグを入れる
					res.Clear();
					res.Append(wxT("<table border=0 id=\"") + num + wxT("\">"));
					res.Append(regexThread.GetMatch(str, 4));
					res.Append(wxT("</table>"));

					// レス内部のURLに<a>タグをつける
					res = JaneCloneUtil::ReplaceURLText(res);
					// レスの最後に改行
					res.Append(wxT("<br>"));
				}
			}

			if (mail != wxEmptyString) {
				// もしメ欄になにか入っているならば
				lumpOfHTML += wxT(" 名前：<a href=\"mailto:");
				lumpOfHTML += mail;
				lumpOfHTML += wxT("\"><b>");
				lumpOfHTML += default_nanashi;
				lumpOfHTML += wxT("</b></a>");
				lumpOfHTML += day_and_ID;
				lumpOfHTML += wxT("<dd>");
				lumpOfHTML += res;
			} else {
				// 空の場合
				lumpOfHTML += wxT(" 名前：<font color=green><b>");
				lumpOfHTML += default_nanashi;
				lumpOfHTML += wxT("</b></font>");
				lumpOfHTML += day_and_ID;
				lumpOfHTML += wxT("<dd>");
				lumpOfHTML += res;
			}

			// HTMLソースを加える
			htmlSource += lumpOfHTML;

			number++;
		}
	}

	htmlSource += HTML_FOOTER;
	datfile.Close();

	return htmlSource;
}