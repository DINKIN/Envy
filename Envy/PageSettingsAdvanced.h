//
// PageSettingsAdvanced.h
//
// This file is part of Envy (getenvy.com) � 2016-2018
// Portions copyright Shareaza 2002-2007 and PeerProject 2008-2012
//
// Envy is free software. You may redistribute and/or modify it
// under the terms of the GNU Affero General Public License
// as published by the Free Software Foundation (fsf.org);
// version 3 or later at your option. (AGPLv3)
//
// Envy is distributed in the hope that it will be useful,
// but AS-IS WITHOUT ANY WARRANTY; without even implied warranty
// of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
// See the GNU Affero General Public License 3.0 for details:
// (http://www.gnu.org/licenses/agpl.html)
//

#pragma once

#include "WndSettingsPage.h"
#include "CtrlFontCombo.h"

class CSettingEdit;


class CAdvancedSettingsPage : public CSettingsPage
{
	DECLARE_DYNCREATE(CAdvancedSettingsPage)

public:
	CAdvancedSettingsPage();
//	virtual ~CAdvancedSettingsPage();

protected:
	enum { IDD = IDD_SETTINGS_ADVANCED };

	CListCtrl		m_wndList;
	CSpinButtonCtrl	m_wndValueSpin;
	CEdit			m_wndValue;
	CEdit			m_wndText;
	CFontCombo		m_wndFonts;
	CButton			m_wndBool;
	CButton			m_wndDefault;
	CStatic			m_wndQuickFilterIcon;
	CEdit			m_wndQuickFilter;
//	CEditItemList	m_pSettings;
	bool			m_bUpdating;
	UINT_PTR		m_nTimer;

//	int		GetListItem(const EditItem* pItem);
	void	UpdateListItem(int nItem);	// Update list item
	void	UpdateInputArea();			// Update edit box, spins and buttons
	void	AddSettings();				// Add settings to list
	void	CommitAll();				// Commit all data to settings
	void	UpdateAll();				// Update settings list
	bool	IsModified() const;			// Check if some of settings was modified

	class EditItem
	{
	public:
		EditItem(const CSettings::Item* pItem);

		CSettings::Item* m_pItem;		// Parent item
		CString	m_sName;				// Item name
		DWORD	m_nValue;				// Current value for DWORD
		bool	m_bValue;				// Current value for bool
		CString	m_sValue;				// Current value for CString
		DWORD	m_nOriginalValue;		// Original value for DWORD
		bool	m_bOriginalValue;		// Original value for bool
		CString	m_sOriginalValue;		// Original value for CString

		void	Update();				// Reload data from parent item
		void	Commit();				// Commit data to parent item
		bool	IsModified() const;		// Value was modified
		bool	IsDefault() const;		// Check if value is equal to default value
		void	Default();				// Restore default value
	};

	virtual void OnOK();
	virtual void DoDataExchange(CDataExchange* pDX);
	virtual BOOL OnInitDialog();

	afx_msg void OnDestroy();
	afx_msg void OnChangeValue();
	afx_msg void OnItemChangedProperties(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnColumnClickProperties(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedDefaultValue();
	afx_msg void OnEnChangeQuickfilter();
	afx_msg void OnTimer(UINT_PTR nIDEvent);

	DECLARE_MESSAGE_MAP()
};
