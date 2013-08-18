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

// -*- C++ -*- generated by wxGlade 0.6.5 on Tue May 21 00:18:19 2013

#include "settingwindow.hpp"

// begin wxGlade: ::extracode
// end wxGlade

BEGIN_EVENT_TABLE(SettingDialog, wxDialog)
   // ボタンによるイベント
   EVT_BUTTON(ID_OnOkSetting, SettingDialog::OnQuit)
   EVT_BUTTON(ID_OnCancelSetting, SettingDialog::OnQuit)
   // ツリーコントロールでのウィンドウ描画切り替え
   EVT_TREE_SEL_CHANGED(ID_SettingPanelTree, SettingDialog::OnChangeSettingPanel)
END_EVENT_TABLE()



/**
 * 設定画面のコンストラクタ
 */
SettingDialog::SettingDialog(wxWindow* parent, int id, const wxString& title, const wxPoint& pos, const wxSize& size, long style):
wxDialog(parent, id, title, pos, size, wxDEFAULT_DIALOG_STYLE) {

     // begin wxGlade: SettingDialog::SettingDialog
     bottomPanel = new wxPanel(this, wxID_ANY);
     splitterWindow = new wxSplitterWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D|wxSP_BORDER);
     // 左側のツリー部分
     treePanel = new wxPanel(splitterWindow, wxID_ANY);
     settingTreeCtrl = new wxTreeCtrl(treePanel, ID_SettingPanelTree, wxDefaultPosition, wxDefaultSize, 
				      wxTR_HIDE_ROOT|wxTR_HAS_BUTTONS|wxTR_DEFAULT_STYLE|wxSUNKEN_BORDER);
     // 右側の設定画面部分
     settingPanel = new wxPanel(splitterWindow, wxID_ANY);
     spacePanel = new wxPanel(bottomPanel, wxID_ANY);
     // OK,キャンセルボタン
     okButton = new wxButton(bottomPanel, ID_OnOkSetting, wxT("OK"));
     cancelButton = new wxButton(bottomPanel, ID_OnCancelSetting, wxT("キャンセル"));

     SetProperties();
     DoLayout();
     // end wxGlade

     // 初回は通信パネルを開く
#ifndef __WXMAC__
     wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);
     vbox->Add(new NetworkSettingPanel(settingPanel));
     settingPanel->SetSizer(vbox);
#else
     // メインスレッドに更新してもらう
     SendUIUpdateEvent();
#endif
     this->SetTitle(wxT("設定 - 通信"));
}
/**
 * ウィンドウのプロパティを設定
 */
void SettingDialog::SetProperties() {
     // begin wxGlade: SettingDialog::set_properties
     SetSize(wxSize(960, 640));

     // ツリーコントロールの表示内容を設定する
     settingTreeCtrl->AddRoot(wxEmptyString);
     wxTreeItemId item = settingTreeCtrl->AppendItem(settingTreeCtrl->GetRootItem(), wxT("基本"));
     settingTreeCtrl->AppendItem(item, wxT("通信"));
     settingTreeCtrl->AppendItem(item, wxT("パス"));
     settingTreeCtrl->AppendItem(item, wxT("動作"));
     settingTreeCtrl->AppendItem(item, wxT("操作"));
     settingTreeCtrl->AppendItem(item, wxT("タブ操作"));
     settingTreeCtrl->AppendItem(item, wxT("書き込み"));
     settingTreeCtrl->AppendItem(item, wxT("Doe"));
     settingTreeCtrl->AppendItem(item, wxT("その他１"));
     settingTreeCtrl->AppendItem(item, wxT("User"));
     item = settingTreeCtrl->AppendItem(settingTreeCtrl->GetRootItem(), wxT("機能"));
     settingTreeCtrl->AppendItem(item, wxT("ヒント"));
     settingTreeCtrl->AppendItem(item, wxT("あぼーん"));
     settingTreeCtrl->AppendItem(item, wxT("コマンド"));
     settingTreeCtrl->AppendItem(item, wxT("マウス"));
     settingTreeCtrl->AppendItem(item, wxT("検索・更新"));
     settingTreeCtrl->AppendItem(item, wxT("スレッド"));
     settingTreeCtrl->AppendItem(item, wxT("画像"));
     settingTreeCtrl->AppendItem(item, wxT("その他２"));
     item = settingTreeCtrl->AppendItem(settingTreeCtrl->GetRootItem(), wxT("外観"));
     settingTreeCtrl->AppendItem(item, wxT("スレ覧項目"));
     settingTreeCtrl->AppendItem(item, wxT("タブ"));
     settingTreeCtrl->AppendItem(item, wxT("スタイル"));
     settingTreeCtrl->AppendItem(item, wxT("色・フォント"));
     settingTreeCtrl->AppendItem(item, wxT("タブ色"));
     settingTreeCtrl->ExpandAll();
     // end wxGlade
}
/**
 * レイアウトの設定
 */
void SettingDialog::DoLayout() {
     // begin wxGlade: SettingDialog::do_layout
     wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);
     wxBoxSizer* bottomSizer = new wxBoxSizer(wxHORIZONTAL);
     wxBoxSizer* treeVbox = new wxBoxSizer(wxVERTICAL);
     treeVbox->Add(settingTreeCtrl, 1, wxEXPAND, 0);
     treePanel->SetSizer(treeVbox);
     splitterWindow->SplitVertically(treePanel, settingPanel, 200);
     vbox->Add(splitterWindow, 1, wxEXPAND, 0);
     bottomSizer->Add(spacePanel, 1, wxEXPAND, 0);
     bottomSizer->Add(okButton, 0, 0, 5);
     bottomSizer->Add(cancelButton, 0, 0, 5);
     bottomPanel->SetSizer(bottomSizer);
     vbox->Add(bottomPanel, 0, wxTOP|wxEXPAND, 0);
     SetSizer(vbox);
     Layout();
     // end wxGlade
}
/**
 * 設定画面のクローズ
 */
void SettingDialog::OnQuit(wxCommandEvent& event) {
     this->EndModal(0);
}
/**
 * ツリーコントロールでのウィンドウ描画切り替え
 */
void SettingDialog::OnChangeSettingPanel(wxTreeEvent& event) {

     // 選択されたTreeItemIdのインスタンス
     const wxTreeItemId pushedTree = event.GetItem();
     // 板名をwxStringで取得する
     const wxString itemStr(settingTreeCtrl->GetItemText(pushedTree));
     // 取得不可なものであればリターン
     if (itemStr == wxEmptyString) return;

     if (settingPanel) {
	  // settingPanelのインスタンスが存在するならばDestroy
	  // 子ウィンドウを殺す
	  settingPanel->DestroyChildren();	  
     }

     if (itemStr == wxT("通信")) {
	  wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);
	  vbox->Add(new NetworkSettingPanel(settingPanel));
	  settingPanel->SetSizer(vbox);
     } else if (itemStr == wxT("パス")) {
	  wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);
	  vbox->Add(new PathSettingPanel(settingPanel));
	  settingPanel->SetSizer(vbox);
     } else if (itemStr == wxT("動作")) {
	  wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);
	  vbox->Add(new BehaviorPanel(settingPanel));
	  settingPanel->SetSizer(vbox);
     } else if (itemStr == wxT("User")) {
	  wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);
	  vbox->Add(new UserSettingPanel(settingPanel));
	  settingPanel->SetSizer(vbox);
     } else if (itemStr == wxT("色・フォント")) {
	  wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);
	  vbox->Add(new ColorFontSettingPanel(settingPanel));
	  settingPanel->SetSizer(vbox);
     }

     // ウィンドウのタイトルを変える
     this->SetTitle(wxT("設定 - ") + itemStr);
}
