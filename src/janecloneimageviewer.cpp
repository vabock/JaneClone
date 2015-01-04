/**
 * janecloneimageviewer.cpp - janeclone's plain imageviewer
 *
 * Copyright (c) 2013 Hiroyuki Nagata <newserver002@gmail.com>
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

#include "janecloneuiutil.hpp"
#include "janecloneimageviewer.hpp"

#ifndef __WXMSW__
#include"../rc/janeclone.xpm"
#endif

BEGIN_EVENT_TABLE(JaneCloneImageViewer, wxFrame)
   EVT_CLOSE(JaneCloneImageViewer::OnClose)
   EVT_CONTEXT_MENU(JaneCloneImageViewer::OnRightClickImageViewer)
   EVT_MOUSEWHEEL(JaneCloneImageViewer::OnMouseWheel)

   EVT_MENU(ID_OneThumbnailTabClose,JaneCloneImageViewer::OneThumbnailTabClose)
   EVT_MENU(ID_AllThumbnailTabClose,JaneCloneImageViewer::AllThumbnailTabClose)
   EVT_MENU(ID_AllLeftThumbnailTabClose,JaneCloneImageViewer::AllLeftThumbnailTabClose)
   EVT_MENU(ID_AllRightThumbnailTabClose,JaneCloneImageViewer::AllRightThumbnailTabClose)
   EVT_MENU(ID_SelectLeftThumbnailTab,JaneCloneImageViewer::SelectLeftThumbnailTab)
   EVT_MENU(ID_SelectRightThumbnailTab,JaneCloneImageViewer::SelectRightThumbnailTab)
   EVT_MENU(ID_OnOpenImageByBrowser,JaneCloneImageViewer::OnOpenImageByBrowser)
   EVT_MENU(ID_OpenThreadGotImage,JaneCloneImageViewer::OpenThreadGotImage)
   EVT_MENU(ID_CopyImageURLToClipBoard, JaneCloneImageViewer::CopyImageURL)
   EVT_MENU(ID_HideThumbnailTab,JaneCloneImageViewer::HideThumbnailTab)
   EVT_MENU(ID_SaveAsImages,JaneCloneImageViewer::SaveAsImages)
   EVT_MENU(ID_SaveAsImagesAll,JaneCloneImageViewer::SaveAsImagesAll)
   EVT_MENU(ID_Rotate90AntiClockwise,JaneCloneImageViewer::Rotate90AntiClockwise)
   EVT_MENU(ID_Rotate90Clockwise,JaneCloneImageViewer::Rotate90Clockwise)
   EVT_MENU(ID_ZoomIn,JaneCloneImageViewer::ZoomIn)
   EVT_MENU(ID_ZoomOut,JaneCloneImageViewer::ZoomOut)
   EVT_MENU(ID_ResetImageOriginalSize,JaneCloneImageViewer::ResetImageOriginalSize)
END_EVENT_TABLE()

/**
 * Default constructor
 */
JaneCloneImageViewer::JaneCloneImageViewer(wxWindow* parent, int id, const wxString& title, 
					   const wxPoint& pos, const wxSize& size, long style)
:wxFrame(parent, id, title, pos, size, wxDEFAULT_FRAME_STYLE)
{

     // アイコンの設定を行う
#ifdef __WXMSW__
     SetIcon(wxICON(wxicon));
#else
     SetIcon(wxICON(janeclone));
#endif

     // wxAuiManagerの初期化
     m_mgr.SetManagedWindow(this);
     // ノートブックのサイズ調整
     wxSize client_size = GetClientSize();
     // 画像を表示させるパネルの宣言
     thumbnailNoteBook = new wxAuiNotebook(this, ID_ThumbnailNoteBook, wxPoint(client_size.x, client_size.y), 
					   wxDefaultSize, wxAUI_NB_SCROLL_BUTTONS | wxAUI_NB_WINDOWLIST_BUTTON);
     // ステータスバー設置
     CreateStatusBar(3);

     popupMenu.Append(JaneCloneUiUtil::CreateMenuItemFromID(&popupMenu, ID_OneThumbnailTabClose));	// このタブを閉じる
     popupMenu.Append(wxID_ANY, wxT("エラーのタブを閉じる"));
     popupMenu.AppendSeparator();
     popupMenu.Append(wxID_ANY, wxT("このタブ以外を閉じる"));
     popupMenu.Append(JaneCloneUiUtil::CreateMenuItemFromID(&popupMenu, ID_AllThumbnailTabClose));	// すべてのタブを閉じる
     popupMenu.Append(JaneCloneUiUtil::CreateMenuItemFromID(&popupMenu, ID_AllLeftThumbnailTabClose));	// これより左を閉じる
     popupMenu.Append(JaneCloneUiUtil::CreateMenuItemFromID(&popupMenu, ID_AllRightThumbnailTabClose));	// これより右を閉じる
     popupMenu.AppendSeparator();
     popupMenu.Append(wxID_ANY, wxT("マーク/解除"));
     popupMenu.Append(wxID_ANY, wxT("すべてマーク"));
     popupMenu.Append(wxID_ANY, wxT("すべてマーク解除"));
     popupMenu.AppendSeparator();
     popupMenu.Append(JaneCloneUiUtil::CreateMenuItemFromID(&popupMenu, ID_SaveAsImages));	// 名前を付けて保存
     popupMenu.Append(JaneCloneUiUtil::CreateMenuItemFromID(&popupMenu, ID_SaveAsImagesAll));	// 全て保存
     popupMenu.AppendSeparator();
     popupMenu.Append(wxID_ANY, wxT("再読み込み"));
     popupMenu.Append(JaneCloneUiUtil::CreateMenuItemFromID(&popupMenu, ID_OnOpenImageByBrowser)); // ブラウザで開く
     popupMenu.Append(wxID_ANY, wxT("外部ビューアで開く"));
     popupMenu.Append(wxID_ANY, wxT("Windowsの関連付けで開く"));
     popupMenu.Append(JaneCloneUiUtil::CreateMenuItemFromID(&popupMenu, ID_OpenThreadGotImage));	// 参照元スレッドを開く
     popupMenu.Append(JaneCloneUiUtil::CreateMenuItemFromID(&popupMenu, ID_CopyImageURLToClipBoard));	// URLをコピー
     popupMenu.AppendSeparator();
     popupMenu.Append(JaneCloneUiUtil::CreateMenuItemFromID(&popupMenu, ID_Rotate90AntiClockwise));	// 左回転
     popupMenu.Append(JaneCloneUiUtil::CreateMenuItemFromID(&popupMenu, ID_Rotate90Clockwise));		// 右回転
     popupMenu.AppendSeparator();
     popupMenu.Append(JaneCloneUiUtil::CreateMenuItemFromID(&popupMenu, ID_ZoomIn));	// ズームイン
     popupMenu.Append(JaneCloneUiUtil::CreateMenuItemFromID(&popupMenu, ID_ZoomOut));	// ズームアウト
     popupMenu.Append(wxID_ANY, wxT("ズーム変更"));
     popupMenu.Append(JaneCloneUiUtil::CreateMenuItemFromID(&popupMenu, ID_ResetImageOriginalSize));	// 元のサイズに戻す
     popupMenu.AppendSeparator();
     popupMenu.Append(wxID_ANY, wxT("ウィンドウに合わせて表示"));
     popupMenu.Append(JaneCloneUiUtil::CreateMenuItemFromID(&popupMenu, ID_CallViewerSettingWindow));	// ビューア設定
     popupMenu.AppendSeparator();
     popupMenu.Append(JaneCloneUiUtil::CreateMenuItemFromID(&popupMenu, ID_SelectRightThumbnailTab));	// 次のタブ
     popupMenu.Append(JaneCloneUiUtil::CreateMenuItemFromID(&popupMenu, ID_SelectLeftThumbnailTab));	// 前のタブ
     popupMenu.AppendSeparator();
     popupMenu.Append(JaneCloneUiUtil::CreateMenuItemFromID(&popupMenu, ID_HideThumbnailTab));	// ビューアを隠す

     set_properties(title);
     do_layout();
}
/**
 * フレームクラスのデストラクタ
 */
JaneCloneImageViewer::~JaneCloneImageViewer() 
{
     // wxAuiManagerはデストラクタで破棄しなければいけない
     m_mgr.UnInit();
}
/**
 * タイトルとサイズを設定
 */
void JaneCloneImageViewer::set_properties(const wxString& title) 
{
    SetTitle(title);
    SetSize(wxSize(640, 480));
}
/**
 * レイアウトを設定する
 */
void JaneCloneImageViewer::do_layout() 
{
    wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);
    vbox->Add(thumbnailNoteBook, 1, wxEXPAND, 0);
    SetSizer(vbox);
    Layout();
}
/**
 * Assignment operator
 */
JaneCloneImageViewer& JaneCloneImageViewer::operator=(const JaneCloneImageViewer& rhs) 
{
    if (this != &rhs) 
    {
        // TODO: implement copy
    }
    return *this;
}
/**
 *  画像ファイルの情報を設定する
 */
void JaneCloneImageViewer::SetImageFile(std::unique_ptr<DownloadImageResult>& result) 
{
     thumbnailNoteBook->Freeze();

     // resultの結果を元に画像のサムネイルと画像を配置する
     wxImage image;
     wxBitmap bitmap;
     
     // load wxImage
     if (!image.LoadFile(result->imagePath)) 
     {
	  wxMessageBox(wxT("画像ファイルの読み出しに失敗しました"),
		       wxT("画像ビューア"),
		       wxICON_ERROR);
	  result->result = false;
	  return;
     }
     // wxImage to wxBitmap
     bitmap = wxBitmap(image);

     if (!bitmap.Ok()) 
     {
	  wxMessageBox(wxT("画像データの内部変換に失敗しました"),
		       wxT("画像ビューア"),
		       wxICON_ERROR);
	  result->result = false;
	  return;
     }
     // wxBitmapTypeの判別
     wxBitmapType type;
     const wxString ext = result->ext;

     if (!ext.CmpNoCase(wxT("png"))) 
     {
     	  type = wxBITMAP_TYPE_PNG;
     } 
     else if (!ext.CmpNoCase(wxT("jpg"))) 
     {
     	  type = wxBITMAP_TYPE_JPEG;
     } 
     else if (!ext.CmpNoCase(wxT("jpeg"))) 
     {
     	  type = wxBITMAP_TYPE_JPEG;
     } 
     else if (!ext.CmpNoCase(wxT("gif"))) 
     {
     	  type = wxBITMAP_TYPE_GIF;
     } 
     else if (!ext.CmpNoCase(wxT("bmp"))) 
     {
     	  type = wxBITMAP_TYPE_BMP;
     } 
     else if (!ext.CmpNoCase(wxT("ico"))) 
     {
     	  type = wxBITMAP_TYPE_ICO;
     } 
     else if (!ext.CmpNoCase(wxT("xpm"))) 
     {
     	  type = wxBITMAP_TYPE_XPM;
     } 
     else if (!ext.CmpNoCase(wxT("tiff"))) 
     {
     	  type = wxBITMAP_TYPE_TIF;
     } 
     else 
     {
     	  type = wxBITMAP_TYPE_ANY;
     }
     // 読み取った画像をパネルに載せる
     wxImagePanel* panel = new wxImagePanel(thumbnailNoteBook, result, type);

     // サムネイルを作る
     wxBitmap thumbnail = wxBitmap(image.Scale(64, 64));
     thumbnailNoteBook->AddPage(panel, wxEmptyString, false, thumbnail);
     result->result = true;

     thumbnailNoteBook->Thaw();
     m_mgr.Update();
}
/**
 * ウィンドウを閉じるイベント
 */
void JaneCloneImageViewer::OnClose(wxCloseEvent& event) 
{
     // wxAuiNotebookがもっていたデータは落とす
     size_t pages = thumbnailNoteBook->GetPageCount();
     for (size_t i = 0; i < pages; i++) 
     {
	  thumbnailNoteBook->DeletePage(0);
     }
     
     // 画像ビューアはJaneClone本体が落ちるまで閉じない
     this->Hide();
     event.Skip(false);
}
/**
 * 画像ビューアを開いた状態でマウスホイールを動かした場合のイベント
 */
void JaneCloneImageViewer::OnMouseWheel(wxMouseEvent& event) 
{     
     if (event.m_wheelRotation == 0) return;
     
     if (event.m_controlDown) 
     {
	  // コントロールキーが押されている => 画像の拡大縮小
	  if (event.m_wheelRotation > 0) 
	  {
	       // プラス値 ←
	       ZoomIn();
	       
	  } 
	  else 
	  {
	       // マイナス値 →
	       ZoomOut();
	  }	  
	  
     } 
     else 
     {
	  const int current = thumbnailNoteBook->GetSelection();		    
	  const int max     = thumbnailNoteBook->GetPageCount();

	  // 画像の切り替え
	  if (event.m_wheelRotation > 0) 
	  {
	       // プラス値 ←
	       if (current != 0) thumbnailNoteBook->SetSelection(current - 1);
	  } 
	  else 
	  {
	       // マイナス値 →
	       if (current != max) thumbnailNoteBook->SetSelection(current + 1);
	  }	  
     }

     event.Skip();
}
/**
 * 画像ビューアで右クリックした場合の処理
 */
void JaneCloneImageViewer::OnRightClickImageViewer(wxContextMenuEvent& event) {

     // ポップアップメニューを表示させる
     PopupMenu(&popupMenu);
}
/**
 * 画像タブをひとつ閉じる
 */
void JaneCloneImageViewer::OneThumbnailTabClose(wxCommandEvent& event) 
{
     // アクティブなタブを選択して閉じる
     thumbnailNoteBook->DeletePage(thumbnailNoteBook->GetSelection());
}
/**
 * すべての画像タブを閉じる
 */
void JaneCloneImageViewer::AllThumbnailTabClose(wxCommandEvent& event) 
{
     const int pages = thumbnailNoteBook->GetPageCount();
     for (int i=0;i<pages;i++) 
     {
	  thumbnailNoteBook->DeletePage(0);
     }
}
/**
 * これより左の画像タブをを閉じる
 */
void JaneCloneImageViewer::AllLeftThumbnailTabClose(wxCommandEvent& event) 
{
     // タブの数を数える
     const size_t select = thumbnailNoteBook->GetSelection();

     for (unsigned int i=0;i<select;i++) 
     {
	  thumbnailNoteBook->DeletePage(0);
     }
}
/**
 * これより右の画像タブを閉じる
 */
void JaneCloneImageViewer::AllRightThumbnailTabClose(wxCommandEvent& event) 
{
     // タブの数を数える
     const size_t pages = thumbnailNoteBook->GetPageCount();
     const size_t select = thumbnailNoteBook->GetSelection();
     for (unsigned int i=0;i<pages;i++) 
     {
	  if (i>select) 
	  {
	       thumbnailNoteBook->DeletePage(select+1);
	  }
     }
}
/**
 * 左の画像タブに移動
 */
void JaneCloneImageViewer::SelectLeftThumbnailTab(wxCommandEvent& event) 
{
     const int current = thumbnailNoteBook->GetSelection();
     // プラス値 ←
     if (current != 0) thumbnailNoteBook->SetSelection(current - 1);
}
/**
 * 右の画像タブに移動
 */
void JaneCloneImageViewer::SelectRightThumbnailTab(wxCommandEvent& event) 
{
     const int current = thumbnailNoteBook->GetSelection();		    
     const int max     = thumbnailNoteBook->GetPageCount();
     if (current != max) thumbnailNoteBook->SetSelection(current + 1);
}
/**
 * 画像をブラウザで開く
 */
void JaneCloneImageViewer::OnOpenImageByBrowser(wxCommandEvent& event) 
{
     wxWindow* target = thumbnailNoteBook->GetPage(thumbnailNoteBook->GetSelection());

     if ( wxImagePanel* image = dynamic_cast<wxImagePanel*>(target)) 
     {
	  wxString url  = image->GetImageURL();
	  wxString rest = wxEmptyString;

	  if (url.StartsWith(wxT("ttp"), &rest)) 
	  {
	       url.Replace(wxT("ttp"), wxT("http"), false);
	  }

	  wxLaunchDefaultBrowser(url);
     }     
}
/**
 * 参照元スレッドを開く
 */
void JaneCloneImageViewer::OpenThreadGotImage(wxCommandEvent& event) 
{
     wxWindow* target = thumbnailNoteBook->GetPage(thumbnailNoteBook->GetSelection());

     if ( wxImagePanel* image = dynamic_cast<wxImagePanel*>(target)) 
     {
/**	  const wxString title = image->GetDownloadImageResult().threadInfo->title;
	  if ( title != wxEmptyString )
	  {
	       // 対象スレッドを更新する
	       JaneCloneUiUtil::QueueEventHelper(wxEVT_COMMAND_TEXT_UPDATED, ID_ReloadThreadByName, title);
	       this->Hide();
	  }*/
     }     
}
/**
 * 画像ビューアを隠す
 */
void JaneCloneImageViewer::HideThumbnailTab(wxCommandEvent& event) 
{
     this->Hide();
}
/**
 * 名前をつけて保存
 */
void JaneCloneImageViewer::SaveAsImages(wxCommandEvent& event) 
{
     wxWindow* target = thumbnailNoteBook->GetPage(thumbnailNoteBook->GetSelection());

     if ( wxImagePanel* image = dynamic_cast<wxImagePanel*>(target)) 
     {	       
	  const wxString caption = wxT("画像ファイルに名前を付けて保存");
	  wxString defaultDir = wxEmptyString; // OSのデフォルトに合わせる

	  // ファイルパスの組み立てとファイルの有無確認
	  wxString filePath = image->GetFilePath();

	  if (!wxFile::Exists(filePath)) 
	  {
	       // 無ければエラーメッセージ表示
	       wxMessageBox(wxT("保存するための画像ファイルが見つかりませんでした"));
	       return;
	  }

	  wxFileDialog dialog(this, caption, defaultDir, wxEmptyString, wxEmptyString, wxFD_SAVE);
	  dialog.SetPath(filePath);

	  if (dialog.ShowModal() == wxID_OK) 
	  {
	       bool ret = wxCopyFile(filePath, dialog.GetPath(), true);
	       if (!ret) {
		    wxMessageBox(wxT("画像ファイルの保存に失敗しました"));
	       }
	  }

     }
}

/**
 * すべて保存
 */
void JaneCloneImageViewer::SaveAsImagesAll(wxCommandEvent& event) 
{

     const wxString caption = wxT("指定したフォルダにすべての画像ファイルを保存");
     wxString defaultDir = wxEmptyString; // OSのデフォルトに合わせる

     wxDirDialog dialog(this, caption, defaultDir);

     if (dialog.ShowModal() == wxID_OK) 
     {
	  const int pages = thumbnailNoteBook->GetPageCount();
	  for (int i=0;i<pages;i++) 
	  {
	       wxWindow* target = thumbnailNoteBook->GetPage(i);
	       if ( wxImagePanel* image = dynamic_cast<wxImagePanel*>(target))
	       {
		    const wxString filePath = image->GetFilePath();
		    if (wxFile::Exists(filePath))
		    {
			 wxString path, name, ext;
			 wxFileName::SplitPath(filePath,&path,&name,&ext);
			 wxCopyFile(filePath, dialog.GetPath() + wxFileSeparator + name + '.' + ext, true);
		    }
	       }
	  }

	  wxMessageBox(wxString::Format(wxT("%d 件のファイルを保存しました"), pages));
     }
}

/**
 * URLをコピー
 */
void JaneCloneImageViewer::CopyImageURL(wxCommandEvent& event) {

     wxWindow* target = thumbnailNoteBook->GetPage(thumbnailNoteBook->GetSelection());

     if ( wxImagePanel* image = dynamic_cast<wxImagePanel*>(target)) 
     {
	  const wxString url  = image->GetImageURL();

	  if (wxTheClipboard->Open()) 
	  {
	       wxTheClipboard->Clear();
	       wxTheClipboard->SetData(new wxTextDataObject(url));
	       wxTheClipboard->Close();
	  }
     }
}
/**
 * 左回転
 */
void JaneCloneImageViewer::Rotate90AntiClockwise(wxCommandEvent& event) 
{
     wxWindow* target = thumbnailNoteBook->GetPage(thumbnailNoteBook->GetSelection());

     if ( wxImagePanel* image = dynamic_cast<wxImagePanel*>(target)) 
     {
	  image->Rotate90(false);
     }
}
/**
 * 右回転
 */
void JaneCloneImageViewer::Rotate90Clockwise(wxCommandEvent& event) 
{
     wxWindow* target = thumbnailNoteBook->GetPage(thumbnailNoteBook->GetSelection());

     if ( wxImagePanel* image = dynamic_cast<wxImagePanel*>(target)) 
     {
	  image->Rotate90(true);
     }
}
/**
 * 画像を拡大する
 */
void JaneCloneImageViewer::ZoomIn(wxCommandEvent& event) 
{
     ZoomIn();
}

void JaneCloneImageViewer::ZoomIn() 
{
     wxWindow* target = thumbnailNoteBook->GetPage(thumbnailNoteBook->GetSelection());

     if ( wxImagePanel* image = dynamic_cast<wxImagePanel*>(target)) 
     {
	  image->Resize(true);
     }
}

/**
 * 画像を縮小する
 */
void JaneCloneImageViewer::ZoomOut(wxCommandEvent& event) 
{
     ZoomOut();
}

void JaneCloneImageViewer::ZoomOut() 
{
     wxWindow* target = thumbnailNoteBook->GetPage(thumbnailNoteBook->GetSelection());

     if ( wxImagePanel* image = dynamic_cast<wxImagePanel*>(target)) 
     {
	  image->Resize(false);
     }
}
/**
 * 画像を元のサイズに戻す
 */
void JaneCloneImageViewer::ResetImageOriginalSize(wxCommandEvent& event) 
{
     wxWindow* target = thumbnailNoteBook->GetPage(thumbnailNoteBook->GetSelection());

     if ( wxImagePanel* image = dynamic_cast<wxImagePanel*>(target)) 
     {
	  image->Reset();
     }
}
