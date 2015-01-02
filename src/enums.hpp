/**
 * enums.hpp - janeclones' enums
 *
 * Copyright (C) 2013-2014 Hiroyuki Nagata <newserver002@gmail.com>
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

#ifndef ENUMS_HPP_
#define ENUMS_HPP_

#include "enumstring.hpp"

// テーブル要素
#define X_TABLE_ITEM(x, lbl) X(x, STR(x), lbl)

// 使いたい列挙型を定義する.バックスラッシュの後ろに文字があるとコンパイルエラーになるので注意
#define X_TABLE \
X_TABLE_ITEM(ID_Restart,			wxT("再起動"))						\
X_TABLE_ITEM(ID_Test,				wxT("テスト用"))					\
X_TABLE_ITEM(ID_Logging,			wxT("ログ出力制御用"))					\
X_TABLE_ITEM(ID_WindowMinimize,			wxT("ウィンドウを最小化する"))				\
X_TABLE_ITEM(ID_GetBoardList,			wxT("板一覧情報取得"))					\
X_TABLE_ITEM(ID_CheckLogDirectory,		wxT("保存されているログをスレッド一覧に表示する"))	\
X_TABLE_ITEM(ID_GetVersionInfo,			wxT("バージョン情報"))					\
X_TABLE_ITEM(ID_WxJaneClone,			wxT("メインのウィンドウID"))				\
X_TABLE_ITEM(ID_ThreadNoteBook,			wxT("スレッド一覧ノートブックに使うID"))		\
X_TABLE_ITEM(ID_BoardNoteBook,			wxT("板一覧用ノートブックに使うID"))			\
X_TABLE_ITEM(ID_ThumbnailNoteBook,		wxT("画像ビューア用ID"))				\
X_TABLE_ITEM(ID_BoardTreectrl,			wxT("板一覧ツリー用ID"))				\
X_TABLE_ITEM(ID_ShingetsuBoardTreectrl,		wxT("新月公開ノード一覧ツリー用ID"))			\
X_TABLE_ITEM(ID_FavsTreectrl,			wxT("お気に入りツリー用ID"))				\
X_TABLE_ITEM(ID_NowReadingTreectrl,		wxT("閲覧中ツリー用ID"))				\
X_TABLE_ITEM(ID_BoardTreeNoteBook,		wxT("板一覧ツリーを載せるノートブックに使うID"))	\
X_TABLE_ITEM(ID_ThreadContentWindow,		wxT("スレビュー画面用ID"))				\
X_TABLE_ITEM(ID_OneBoardTabClose,		wxT("スレッド一覧タブをひとつ閉じる"))			\
X_TABLE_ITEM(ID_ExcepSelTabClose,		wxT("現在選択されていないスレッド一覧タブを閉じる"))	\
X_TABLE_ITEM(ID_AllBoardTabClose,		wxT("すべてのスレッド一覧タブを閉じる"))		\
X_TABLE_ITEM(ID_AllLeftBoardTabClose,		wxT("これより左のスレッド一覧タブをを閉じる"))		\
X_TABLE_ITEM(ID_AllRightBoardTabClose,		wxT("これより右のスレッド一覧タブを閉じる"))		\
X_TABLE_ITEM(ID_OnOpenBoardByBrowser,		wxT("スレッド一覧をブラウザで開く"))			\
X_TABLE_ITEM(ID_ReloadOneBoard,			wxT("アクティブなスレッド一覧をひとつ更新する"))	\
X_TABLE_ITEM(ID_ReloadAllBoard,			wxT("すべてのタブのスレッド一覧を更新する"))		\
X_TABLE_ITEM(ID_CopyBURLToClipBoard,		wxT("板のURLをクリップボードにコピーする"))		\
X_TABLE_ITEM(ID_CopyBTitleToClipBoard,		wxT("板のタイトルをクリップボードにコピーする"))	\
X_TABLE_ITEM(ID_CopyBBothDataToClipBoard,	wxT("板のURLとタイトルをクリップボードにコピーする"))	\
X_TABLE_ITEM(ID_DeleteBSelectedDatFile,		wxT("選択中のログを削除"))				\
X_TABLE_ITEM(ID_DeleteBAllDatFile,		wxT("すべてのログを削除"))				\
X_TABLE_ITEM(ID_DeleteBAllDatFileWithoutFav,	wxT("お気に入り以外のログを削除"))			\
X_TABLE_ITEM(ID_CopyTURLToClipBoard,		wxT("スレッドのURLをクリップボードにコピーする"))	\
X_TABLE_ITEM(ID_CopyTTitleToClipBoard,		wxT("スレッドのタイトルをクリップボードにコピーする"))	\
X_TABLE_ITEM(ID_CopyTBothDataToClipBoard,	wxT("スレッドのURLとタイトルをクリップボードにコピーする")) \
X_TABLE_ITEM(ID_CopyTContentsToClipBoard,	wxT("スレッドの内容をクリップボードにコピーする"))	\
X_TABLE_ITEM(ID_CopyTAllToClipBoard,		wxT("スレッドの内容, URL, タイトルをクリップボードにコピーする")) \
X_TABLE_ITEM(ID_OneThreadTabClose,		wxT("スレタブをひとつ閉じる"))				\
X_TABLE_ITEM(ID_ExcepSelThreadTabClose,		wxT("現在選択されていないスレタブを閉じる"))		\
X_TABLE_ITEM(ID_AllThreadTabClose,		wxT("すべてのスレタブを閉じる"))			\
X_TABLE_ITEM(ID_AllLeftThreadTabClose,		wxT("これより左のスレタブをを閉じる"))			\
X_TABLE_ITEM(ID_AllRightThreadTabClose,		wxT("これより右のスレタブを閉じる"))			\
X_TABLE_ITEM(ID_OnOpenThreadByBrowser,		wxT("スレッドをブラウザで開く"))			\
X_TABLE_ITEM(ID_SaveDatFile,			wxT("datファイルに名前を付けて保存"))			\
X_TABLE_ITEM(ID_SaveDatFileToClipBoard,		wxT("datをクリップボードにコピー"))			\
X_TABLE_ITEM(ID_DeleteDatFile,			wxT("このログを削除"))					\
X_TABLE_ITEM(ID_ReloadThisThread,		wxT("スレッドの再読み込み"))				\
X_TABLE_ITEM(ID_CallResponseWindow,		wxT("書き込み用のウィンドウを呼び出す"))		\
X_TABLE_ITEM(ID_BoardListCtrl,			wxT("板一覧リスト自体を表すID"))			\
X_TABLE_ITEM(ID_ShingetsuBoardListCtrl,		wxT("新月の板一覧リスト自体を表すID"))			\
X_TABLE_ITEM(ID_FontDialogBoardTree,		wxT("板一覧ツリー部分のフォントの指定を行う"))		\
X_TABLE_ITEM(ID_FontDialogLogWindow,		wxT("ログ出力画面部分のフォントの指定を行う"))		\
X_TABLE_ITEM(ID_FontDialogBoardNotebook,	wxT("スレッド一覧部分のフォントの指定を行う"))		\
X_TABLE_ITEM(ID_FontDialogThreadNotebook,	wxT("スレッド画面部分のフォント設定を呼び出"))		\
X_TABLE_ITEM(ID_FontDialogThreadContents,	wxT("スレッド内で使用するフォント設定を呼び"))		\
X_TABLE_ITEM(ID_URLWindowButton,		wxT("URL入力ウィンドウのボタンを表すID"))		\
X_TABLE_ITEM(ID_UserLastClosedThreadMenuUp,	wxT("ユーザーが最後に閉じたスレッドの情報を"))		\
X_TABLE_ITEM(ID_UserLastClosedBoardMenuUp,	wxT("ユーザーが最後に閉じた板の情報を項目に"))		\
X_TABLE_ITEM(ID_UserLookingTabsMenuUp,		wxT("ユーザーが現在見ているスレタブ・板タブ"))		\
X_TABLE_ITEM(ID_JaneCloneMgrUpdate,		wxT("Auiマネージャーの更新を行う"))			\
X_TABLE_ITEM(ID_CommonAuiToolBarUpdate,		wxT("Auiツールバーの更新を行う"))			\
X_TABLE_ITEM(ID_FavsTreectrlUpdate,		wxT("お気に入りツリーの更新を行う"))			\
X_TABLE_ITEM(ID_NowReadingTreectrlUpdate,	wxT("閲覧中ツリーの更新を行う"))			\
X_TABLE_ITEM(ID_UserLookingTabsControl,		wxT("ユーザーが現在フォーカスしているウィン"))		\
X_TABLE_ITEM(ID_MoveNextTab,			wxT("表示しているタブを移動する(次)"))			\
X_TABLE_ITEM(ID_MovePrevTab,			wxT("表示しているタブを移動する(前)"))			\
X_TABLE_ITEM(ID_UserLookingTabsMenuClick,	wxT("ユーザーが現在見ているスレタブ・板タブ"))		\
X_TABLE_ITEM(ID_OnOpenJaneCloneOfficial,	wxT("JaneClone公式サイトをブラウザで開く"))		\
X_TABLE_ITEM(ID_OnOpen2chViewerOfficial,	wxT("●公式サイトをブラウザで開く"))			\
X_TABLE_ITEM(ID_ThreadContentSearchBar,		wxT("スレッド内容バーの検索ボックスのID"))		\
X_TABLE_ITEM(ID_ThreadSearchBar,		wxT("スレッド検索ボックスのID"))			\
X_TABLE_ITEM(ID_BoardSearchBar,			wxT("板名検索ボックスのID"))				\
X_TABLE_ITEM(ID_ShingetsuBoardSearchBar,	wxT("新月の板名検索ボックスのID"))			\
X_TABLE_ITEM(ID_FavsSearchBar,			wxT("お気に入りのデータ検索ボックスのID"))		\
X_TABLE_ITEM(ID_NowReadingSearchBar,		wxT("閲覧中のデータ検索ボックスのID"))			\
X_TABLE_ITEM(ID_ThreadSearchBarCombo,		wxT("スレッド検索ボックスのコンボボックス"))		\
X_TABLE_ITEM(ID_BoardSearchBarCombo,		wxT("板名検索ボックスのコンボボックス"))		\
X_TABLE_ITEM(ID_FavsSearchBarCombo,		wxT("お気に入りのデータ検索ボックスのコンボボックス"))	\
X_TABLE_ITEM(ID_NowReadingSearchBarCombo,	wxT("閲覧中のデータ検索ボックスのコンボボックス"))	\
X_TABLE_ITEM(ID_ThreadSearchBoxDoSearch,	wxT("検索ボックス(スレッド一覧)で検索ボタンを押す"))	\
X_TABLE_ITEM(ID_BoardSearchBoxDoSearch,		wxT("検索ボックス(板一覧)で検索ボタンを押す"))		\
X_TABLE_ITEM(ID_FavsSearchBoxDoSeach,		wxT("検索ボックス(お気に入り一覧)で検索ボタンを押す"))	\
X_TABLE_ITEM(ID_NowReadingBoxDoSeach,		wxT("検索ボックス(閲覧中一覧)で検索ボタンを押す"))	\
X_TABLE_ITEM(ID_SearchBoxUp,			wxT("検索ボックスで上に移動"))				\
X_TABLE_ITEM(ID_SearchBoxDown,			wxT("検索ボックスで下に移動"))				\
X_TABLE_ITEM(ID_SearchBoxCopy,			wxT("検索ボックスでコピー実行"))			\
X_TABLE_ITEM(ID_SearchBoxCut,			wxT("検索ボックスで切り取り実行"))			\
X_TABLE_ITEM(ID_SearchBoxSelectAll,		wxT("検索ボックスで全て選択"))				\
X_TABLE_ITEM(ID_SearchBoxClear,			wxT("検索ボックスをクリア"))				\
X_TABLE_ITEM(ID_SearchBoxNormalSearch,		wxT("検索ボックスで通常検索"))				\
X_TABLE_ITEM(ID_SearchBoxRegexSearch,		wxT("検索ボックスで正規表現検索"))			\
X_TABLE_ITEM(ID_SearchBarHide,			wxT("検索ボックスを隠す"))				\
X_TABLE_ITEM(ID_FloatToolBar,			wxT("アイコン付きのツールバー自体のID"))		\
X_TABLE_ITEM(ID_SwitchSeparateXY,		wxT("縦⇔横分割切り替え"))				\
X_TABLE_ITEM(ID_SwitchTwoThreePane,		wxT("２⇔３ペイン切り替え"))				\
X_TABLE_ITEM(ID_ShowBoardListTree,		wxT("板一覧ツリー表示切り替え"))			\
X_TABLE_ITEM(ID_SwitchRightPane,		wxT("右側ペインの内容切り替え"))			\
X_TABLE_ITEM(ID_CallSettingWindow,		wxT("設定画面を呼び出す"))				\
X_TABLE_ITEM(ID_CallViewerSettingWindow,	wxT("ビューア設定画面を呼び出す"))			\
X_TABLE_ITEM(ID_ResponseWindow,			wxT(""))						\
X_TABLE_ITEM(ID_QuitResponseWindow,		wxT(""))						\
X_TABLE_ITEM(ID_PostResponse,			wxT(""))						\
X_TABLE_ITEM(ID_PostConfirmForm,		wxT(""))						\
X_TABLE_ITEM(ID_TCBAutoReload,			wxT(""))						\
X_TABLE_ITEM(ID_TCBRedResExtract,		wxT(""))						\
X_TABLE_ITEM(ID_TCBRefresh,			wxT(""))						\
X_TABLE_ITEM(ID_TCBScrollToNewRes,		wxT(""))						\
X_TABLE_ITEM(ID_TCBStop,			wxT(""))						\
X_TABLE_ITEM(ID_TCBResExtract,			wxT(""))						\
X_TABLE_ITEM(ID_TCBNewThread,			wxT(""))						\
X_TABLE_ITEM(ID_TCBBookMark,			wxT(""))						\
X_TABLE_ITEM(ID_TCBDeleteLog,			wxT(""))						\
X_TABLE_ITEM(ID_TCBClose,			wxT(""))						\
X_TABLE_ITEM(ID_TCBNormalSearch,		wxT(""))						\
X_TABLE_ITEM(ID_TCBHideSearchBar,		wxT("スレッド内容バーの内容を隠す"))			\
X_TABLE_ITEM(ID_TCBForward,			wxT(""))						\
X_TABLE_ITEM(ID_TCBBackward,			wxT(""))						\
X_TABLE_ITEM(ID_ThreadContentBarUpdate,		wxT(""))						\
X_TABLE_ITEM(ID_CopyFromHtmlWindow,		wxT("HtmlWindowで選択しているテキストをクリップボードにコピーする")) \
X_TABLE_ITEM(ID_CopyURLFromHtmlWindow,		wxT("HtmlWindowで選択しているURLをクリップボードにコピーする")) \
X_TABLE_ITEM(ID_ShowRawHtmlFromHtmlWindow,	wxT("HtmlWindowでスレッドのHTMLソースを表示する"))	\
X_TABLE_ITEM(ID_SelectAllTextHtmlWindow,	wxT("HtmlWindowでテキストを全て選択する"))		\
X_TABLE_ITEM(ID_SearchSelectWordByYahoo,	wxT("選択したテキストでヤフー検索"))			\
X_TABLE_ITEM(ID_SearchSelectWordByGoogle,	wxT("選択したテキストでGoogle検索"))			\
X_TABLE_ITEM(ID_SearchSelectWordByAmazon,	wxT("選択したテキストでAmazon検索"))			\
X_TABLE_ITEM(ID_SearchThreadBySelectWord,	wxT("選択したテキストでスレタイ検索"))			\
X_TABLE_ITEM(ID_CallResponseWindowAnchor,	wxT("書き込み用のウィンドウをアンカー付きで呼び出す"))	\
X_TABLE_ITEM(ID_CallResponseWindowQuote,	wxT("書き込み用のウィンドウをレス引用付きで呼び出す"))	\
X_TABLE_ITEM(ID_HtmlSourceDebug,		wxT(""))						\
X_TABLE_ITEM(ID_ImagePanel,			wxT("画像パネル"))					\
X_TABLE_ITEM(ID_OneThumbnailTabClose,		wxT("画像タブをひとつ閉じる"))				\
X_TABLE_ITEM(ID_AllThumbnailTabClose,		wxT("すべての画像タブを閉じる"))			\
X_TABLE_ITEM(ID_SaveAsImages,			wxT("名前をつけて保存"))				\
X_TABLE_ITEM(ID_SaveAsImagesAll,		wxT("すべて保存"))					\
X_TABLE_ITEM(ID_AllLeftThumbnailTabClose,	wxT("これより左の画像タブをを閉じる"))			\
X_TABLE_ITEM(ID_AllRightThumbnailTabClose,	wxT("これより右の画像タブを閉じる"))			\
X_TABLE_ITEM(ID_SelectLeftThumbnailTab,		wxT("左の画像タブに移動"))				\
X_TABLE_ITEM(ID_SelectRightThumbnailTab,	wxT("右の画像タブに移動"))				\
X_TABLE_ITEM(ID_OnOpenImageByBrowser,		wxT("画像をブラウザで開く"))				\
X_TABLE_ITEM(ID_OpenThreadGotImage,		wxT("画像取得元のスレッドを開く")) \
X_TABLE_ITEM(ID_CopyImageURLToClipBoard,	wxT("画像URLをクリップボードにコピーする"))		\
X_TABLE_ITEM(ID_Rotate90AntiClockwise,		wxT("画像を90度左回転させる"))				\
X_TABLE_ITEM(ID_Rotate90Clockwise,		wxT("画像を90度右回転させる"))				\
X_TABLE_ITEM(ID_ZoomIn,				wxT("画像を拡大する"))					\
X_TABLE_ITEM(ID_ZoomOut,			wxT("画像を縮小する"))					\
X_TABLE_ITEM(ID_ResetImageOriginalSize,		wxT("画像のサイズを元に戻す"))				\
X_TABLE_ITEM(ID_HideThumbnailTab,		wxT("画像ビューアを隠す"))				\
X_TABLE_ITEM(ID_OnClickMenuCOL_CHK,		wxT("新着チェック"))					\
X_TABLE_ITEM(ID_OnClickMenuCOL_NUM,		wxT("番号"))						\
X_TABLE_ITEM(ID_OnClickMenuCOL_TITLE,		wxT("タイトル"))					\
X_TABLE_ITEM(ID_OnClickMenuCOL_RESP,		wxT("レス"))						\
X_TABLE_ITEM(ID_OnClickMenuCOL_CACHEDRES,	wxT("取得"))						\
X_TABLE_ITEM(ID_OnClickMenuCOL_NEWRESP,		wxT("新着"))						\
X_TABLE_ITEM(ID_OnClickMenuCOL_INCRESP,		wxT("増レス"))						\
X_TABLE_ITEM(ID_OnClickMenuCOL_MOMENTUM,	wxT("勢い"))						\
X_TABLE_ITEM(ID_OnClickMenuCOL_LASTUP,		wxT("最終取得"))					\
X_TABLE_ITEM(ID_OnClickMenuCOL_SINCE,		wxT("SINCE"))						\
X_TABLE_ITEM(ID_OnClickMenuCOL_OID,		wxT("固有番号"))					\
X_TABLE_ITEM(ID_OnClickMenuCOL_BOARDNAME,	wxT("板"))						\
X_TABLE_ITEM(ID_OnCancelSetting,		wxT("設定画面をキャンセル"))				\
X_TABLE_ITEM(ID_OnOkSetting,			wxT("設定画面をOkで終了"))				\
X_TABLE_ITEM(ID_SettingPanelTree,		wxT("設定画面の描画を切り替える"))			\
X_TABLE_ITEM(ID_SettingPanelUpdate,		wxT("設定画面の更新をメインスレッドに伝える"))		\
X_TABLE_ITEM(ID_ViewerSettingNote,		wxT("ビューア設定画面"))				\
X_TABLE_ITEM(ID_NetworkPanelUpdate,		wxT("ネットワーク設定画面の更新をメインスレッドに伝える")) \
X_TABLE_ITEM(ID_NetworkPanel,			wxT("ネットワーク設定用画面"))				\
X_TABLE_ITEM(ID_NetworkPanelUseProxy,		wxT("プロキシを使用するかどうか"))			\
X_TABLE_ITEM(ID_NetworkPanelUseProxyCache,	wxT("プロキシでキャッシュを使用するかどうか"))		\
X_TABLE_ITEM(ID_NetworkPanelBasicAuthUserName,	wxT("ベーシック認証のユーザー名"))			\
X_TABLE_ITEM(ID_NetworkPanelBasicAuthPassword,	wxT("ベーシック認証のパスワード"))			\
X_TABLE_ITEM(ID_NetworkPanelProxyReceiveAddr,	wxT("Proxy受信用アドレス"))				\
X_TABLE_ITEM(ID_NetworkPanelProxyReceivePort,	wxT("Proxy受信用ポート"))				\
X_TABLE_ITEM(ID_NetworkPanelProxySendAddr,	wxT("Proxy送信用アドレス"))				\
X_TABLE_ITEM(ID_NetworkPanelProxySendPort,	wxT("Proxy送信用ポート"))				\
X_TABLE_ITEM(ID_NetworkPanelProxySSLAuthAddr,	wxT("Proxy SSL認証用アドレス"))				\
X_TABLE_ITEM(ID_NetworkPanelProxySSLAuthPort,	wxT("Proxy SSL認証用ポート"))				\
X_TABLE_ITEM(ID_NetworkPanelBoardListURL,	wxT("ボード一覧取得URL"))				\
X_TABLE_ITEM(ID_NetworkPanelReceiveBufferSize,	wxT("受信バッファサイズ"))				\
X_TABLE_ITEM(ID_NetworkPanelMaxConn,		wxT("最大接続数"))					\
X_TABLE_ITEM(ID_PathSettingPanel,		wxT("各種パス設定用画面"))				\
X_TABLE_ITEM(ID_BrowserCheck,			wxT("使用するブラウザを指定するかどうか"))		\
X_TABLE_ITEM(ID_BrowserPathTC,			wxT("ブラウザのパスをもつテキストコントロール"))	\
X_TABLE_ITEM(ID_DirPickerBrowser,		wxT("ブラウザのパスを参照する"))			\
X_TABLE_ITEM(ID_BoardListTC,			wxT("板一覧リストを保持する場所をもつテキストコントロール")) \
X_TABLE_ITEM(ID_DirPickerBoardList,		wxT("板一覧リストのパスを参照する"))			\
X_TABLE_ITEM(ID_SkinPathTC,			wxT("スキン用のファイルのパスをもつテキストコントロール")) \
X_TABLE_ITEM(ID_DirPickerSkin,			wxT("スキン用ファイルのパスを参照する"))		\
X_TABLE_ITEM(ID_ClearBrowserPath,		wxT("ブラウザパス設定値を削除"))			\
X_TABLE_ITEM(ID_ClearBoardListPath,		wxT("板一覧リストのパス設定値を削除"))			\
X_TABLE_ITEM(ID_ClearSkinPath,			wxT("スキンのパス設定値を削除"))			\
X_TABLE_ITEM(ID_BehaviorPanel,			wxT("動作設定用パネル"))				\
X_TABLE_ITEM(ID_OpenBNewTabCheck,		wxT("新しいタブで板を開く"))				\
X_TABLE_ITEM(ID_OnlyOneCategoryCheck,		wxT("カテゴリを一つしか開かない"))			\
X_TABLE_ITEM(ID_OpenTNewTabCheck,		wxT("新しいタブでスレを開く"))				\
X_TABLE_ITEM(ID_ThreadNewTabCombo,		wxT("新しいタブでスレを開く"))				\
X_TABLE_ITEM(ID_LastReadThreadPosCheck,		wxT("最後に見たスレの位置にジャンプ"))			\
X_TABLE_ITEM(ID_ThreadJumpSetting,		wxT("最後に見たスレの位置にジャンプ"))			\
X_TABLE_ITEM(ID_RedrawNewThreadCheck,		wxT("新着チェック時に既得レスを描き直す"))		\
X_TABLE_ITEM(ID_ShowResponseCombo,		wxT("既得スレの表示レス数"))				\
X_TABLE_ITEM(ID_FavoriteNewTabCheck,		wxT("お気に入りを新しいタブで開く"))			\
X_TABLE_ITEM(ID_FavoriteOnlyOneFolder,		wxT("お気に入りフォルダを一つしか開かない"))		\
X_TABLE_ITEM(ID_ColorFontSettingPanel,		wxT("色・フォント設定用画面"))				\
X_TABLE_ITEM(ID_TreeSampleLabel,		wxT("ツリーサンプル"))					\
X_TABLE_ITEM(ID_ThreadListSampleLabel,		wxT("スレ欄サンプル"))					\
X_TABLE_ITEM(ID_ExtractSampleLabel,		wxT("抽出サンプル"))					\
X_TABLE_ITEM(ID_LogWindowSampleLabel,		wxT("ログ出力画面サンプル"))				\
X_TABLE_ITEM(ID_ThreadTitleSampleLabel,		wxT("スレッドタイトルサンプル"))			\
X_TABLE_ITEM(ID_ThreadViewSampleLabel,		wxT("スレビューサンプル"))				\
X_TABLE_ITEM(ID_KakikoSampleLabel,		wxT("書き込みサンプル"))				\
X_TABLE_ITEM(ID_MemoSampleLabel,		wxT("メモ欄サンプル"))					\
X_TABLE_ITEM(ID_HintSampleLabel,		wxT("ヒントサンプル"))					\
X_TABLE_ITEM(ID_LinkSampleLabel,		wxT("リンクサンプル"))					\
X_TABLE_ITEM(ID_OthersSampleLabel,		wxT("その他サンプル"))					\
X_TABLE_ITEM(ID_AllSampleLabel,			wxT("ツリーフォント設定ボタン"))			\
X_TABLE_ITEM(ID_TreeFontButton,			wxT("スレ欄フォント設定ボタン"))			\
X_TABLE_ITEM(ID_ThreadListFontButton,		wxT("抽出フォント設定ボタン"))				\
X_TABLE_ITEM(ID_ExtractFontButton,		wxT("ログ出力画面フォント設定ボタン"))			\
X_TABLE_ITEM(ID_LogWindowFontButton,		wxT("スレッドタイトルフォント設定ボタン"))		\
X_TABLE_ITEM(ID_ThreadTitleFontButton,		wxT("書き込みフォント設定ボタン"))			\
X_TABLE_ITEM(ID_KakikoFontButton,		wxT("メモ欄フォント設定ボタン"))			\
X_TABLE_ITEM(ID_MemoFontButton,			wxT("ヒントフォント設定ボタン"))			\
X_TABLE_ITEM(ID_HintFontButton,			wxT("リンクフォント設定ボタン"))			\
X_TABLE_ITEM(ID_LinkFontButton,			wxT("その他フォント設定ボタン"))			\
X_TABLE_ITEM(ID_OthersFontButton,		wxT("すべてフォント設定ボタン"))			\
X_TABLE_ITEM(ID_AllFontButton,			wxT("スレ欄背景色設定ボタン"))				\
X_TABLE_ITEM(ID_BoardListBGColorButton,		wxT("抽出背景色設定ボタン"))				\
X_TABLE_ITEM(ID_ThreadListBGColorButton,	wxT("ログ出力画面背景色設定ボタン"))			\
X_TABLE_ITEM(ID_LogWindowBGColorButton,		wxT("スレッドタイトル背景色設定ボタン"))		\
X_TABLE_ITEM(ID_ThreadTitleBGColorButton,	wxT("スレビュー背景色設定ボタン"))			\
X_TABLE_ITEM(ID_ThreadViewBGColorButton,	wxT("メモ欄背景色設定ボタン"))				\
X_TABLE_ITEM(ID_MemoBGColorButton,		wxT("ヒント背景色設定ボタン"))				\
X_TABLE_ITEM(ID_HintBGColorButton,		wxT("ポップアップ背景色設定ボタン"))			\
X_TABLE_ITEM(ID_PopupBGColorButton,		wxT("すべての背景色設定ボタン"))			\
X_TABLE_ITEM(ID_AllBGColorButton,		wxT(""))						\
X_TABLE_ITEM(ID_UserSettingPanel,		wxT(""))						\
X_TABLE_ITEM(ID_MaruUserID,			wxT(""))						\
X_TABLE_ITEM(ID_MaruUserPassword,		wxT(""))						\
X_TABLE_ITEM(ID_MaruAutoLoginCheck,		wxT(""))						\
X_TABLE_ITEM(ID_MaruLogoutButton,		wxT(""))						\
X_TABLE_ITEM(ID_BEMailAddress,			wxT(""))						\
X_TABLE_ITEM(ID_BEPassword,			wxT(""))						\
X_TABLE_ITEM(ID_TabColorSettingPanel,		wxT(""))						\
X_TABLE_ITEM(ID_ThreadTabColorCheck,		wxT(""))						\
X_TABLE_ITEM(ID_ActiveTabBGColorButton,		wxT(""))						\
X_TABLE_ITEM(ID_DefaultActiveTabSampleLabel,	wxT(""))						\
X_TABLE_ITEM(ID_ReadingActiveTabSampleLabel,	wxT(""))						\
X_TABLE_ITEM(ID_BrokenActiveTabSampleLabel,	wxT(""))						\
X_TABLE_ITEM(ID_CannotPostActiveTabSampleLabel, wxT(""))						\
X_TABLE_ITEM(ID_UpdateActiveTabSampleLabel,	wxT(""))						\
X_TABLE_ITEM(ID_PartialContentActiveTabSampleLabel, wxT(""))						\
X_TABLE_ITEM(ID_DeactiveTabBGColorButton,	wxT(""))						\
X_TABLE_ITEM(ID_DefaultDeactiveTabSampleLabel,	wxT(""))						\
X_TABLE_ITEM(ID_ReadingDeactiveTabSampleLabel,	wxT(""))						\
X_TABLE_ITEM(ID_BrokenDeactiveTabSampleLabel,	wxT(""))						\
X_TABLE_ITEM(ID_CannotPostDeactiveTabSampleLabel, wxT(""))						\
X_TABLE_ITEM(ID_UpdateDeactiveTabSampleLabel,	wxT(""))						\
X_TABLE_ITEM(ID_PartialContentDeactiveTabSampleLabel, wxT(""))						\
X_TABLE_ITEM(ID_ThreadTabDefaultFontColorButton, wxT(""))						\
X_TABLE_ITEM(ID_ThreadTabReadingFontColorButton, wxT(""))						\
X_TABLE_ITEM(ID_ThreadTabBrokenFontColorButton, wxT(""))						\
X_TABLE_ITEM(ID_ThreadTabCannotPostFontColorButton, wxT(""))						\
X_TABLE_ITEM(ID_ThreadTabUpdateFontColorButton, wxT(""))						\
X_TABLE_ITEM(ID_ThreadTabPartialContentFontColorButton, wxT(""))					\
X_TABLE_ITEM(ID_AutoReloadSampleLabel,		wxT(""))						\
X_TABLE_ITEM(ID_AutoReloadFontColorButton,	wxT(""))						\
X_TABLE_ITEM(ID_TabControlSettingPanel,		wxT(""))						\
X_TABLE_ITEM(ID_TabControlSettingPanelOpenTabChoice,			wxT(""))			\
X_TABLE_ITEM(ID_TabControlSettingPanelOpenTabFromOtherTabChoice,	wxT(""))			\
X_TABLE_ITEM(ID_TabControlSettingPanelCloseThreadViewTabChoice,		wxT(""))			\
X_TABLE_ITEM(ID_TabControlSettingPanelCloseThreadTabChoice,		wxT(""))			\
X_TABLE_ITEM(ID_AddThreadFavorite,		wxT("お気に入りに追加(スレッド)"))			\
X_TABLE_ITEM(ID_DelThreadFavorite,		wxT("お気に入りを削除(スレッド)"))			\
X_TABLE_ITEM(ID_AddBoardFavorite,		wxT("お気に入りに追加(板)"))				\
X_TABLE_ITEM(ID_DelBoardFavorite,		wxT("お気に入りを削除(板)"))				\
X_TABLE_ITEM(ID_AddAllThreadFavorite,		wxT("すべてのタブをお気に入りに追加"))			\
X_TABLE_ITEM(ID_ResponseWindowSageChk,		wxT("レス用ウィンドウのsageチェック"))			\
X_TABLE_ITEM(ID_ResponseWindowBeChk,		wxT("レス用ウィンドウのBEチェック"))			\
X_TABLE_ITEM(ID_ChangeUserLastAttached,		wxT("ユーザーが最後に触ったウィジェットを記録"))	\
X_TABLE_ITEM(ID_ReloadThreadByName,		wxT("スレッド名を元にスレッドを更新する"))		\
X_TABLE_ITEM(ID_NewBoardAddDialog,		wxT("外部板登録ダイアログ"))				\
X_TABLE_ITEM(ID_CallNewBoardAddDialog,		wxT("外部板登録用ダイアログを呼び出す"))		\
X_TABLE_ITEM(ID_OperationPanel,			wxT("各種操作設定用画面"))				\
X_TABLE_ITEM(ID_KakikomiPanel,			wxT("書き込み設定用画面"))				\
X_TABLE_ITEM(ID_DoePanel,			wxT("スレ表示欄の設定画面"))				\
X_TABLE_ITEM(ID_OtherSettingPanelOne,		wxT("その他の設定画面１"))				\
X_TABLE_ITEM(ID_ResetBoardListTree,		wxT("板一覧ツリーのウィジェットの初期化イベント"))	\
X_TABLE_ITEM(ID_Receive_Timeout_Sec,		wxT("受信タイムアウト秒"))				\
X_TABLE_ITEM(ID_Connection_Timeout_Sec,		wxT("接続タイムアウト秒"))				\
X_TABLE_ITEM(ID_JaneCloneEnumsEnd,		wxT(""))

// 列挙型の実体をマクロで生成する
enum JANECLONE_ENUMS {
     ID_Quit = 1,
     #define X(Enum, String, Label) Enum,
     X_TABLE
     #undef X
     ID_UserLastClosedThreadClick = 1000,  // ユーザーが最後に閉じたスレッドの情報をクリックした(動的なIDのため1000~)
     ID_UserLastClosedBoardClick  = 1100,  // ユーザーが最後に閉じた板の情報をクリックした(動的なIDのため1100~)     
     ID_UserFavoriteThreadClick   = 1200,  // ユーザーがお気に入りに登録したスレッドの情報をクリックした(動的なIDのため1200~)
     ID_ThreadContentBar  = 1500           // ThreadContentBar自体のID(動的なIDのため1500~)
};

// 列挙型を文字列化
Begin_Enum_String( JANECLONE_ENUMS )
{

#define X(Enum, String, Label) \
     Enum_String( Enum ) \

     X_TABLE
#undef X

}
End_Enum_String;

#endif /* ENUMS_HPP_ */
