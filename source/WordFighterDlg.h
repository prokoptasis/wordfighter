// WordFighterDlg.h : header file
//

#if !defined(AFX_WORDFIGHTERDLG_H__79467217_15CB_48B3_8577_B958B21E768C__INCLUDED_)
#define AFX_WORDFIGHTERDLG_H__79467217_15CB_48B3_8577_B958B21E768C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CWordFighterDlg dialog

class CWordFighterDlg : public CDialog
{
// Construction
public:
	CString m_strData;
	void OnFileOpen();
	int m_nAnswer;
	int m_nCorrect;
	int m_nTotal;
 

	CWordFighterDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CWordFighterDlg)
	enum { IDD = IDD_WORDFIGHTER_DIALOG };
	CButton	m_strCheck4;
	CButton	m_strCheck3;
	CButton	m_strCheck2;
	CButton	m_strCheck1;
	CString	m_strEnglishWord;
	CString	m_strJudgement;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWordFighterDlg)
	public:
	virtual void Serialize(CArchive& ar);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void CheckAnswer();
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CWordFighterDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCheck1();
	afx_msg void OnCheck2();
	afx_msg void OnCheck3();
	afx_msg void OnCheck4();
	virtual void OnOK();
	afx_msg void OnNext();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void MakeNodeEtc();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WORDFIGHTERDLG_H__79467217_15CB_48B3_8577_B958B21E768C__INCLUDED_)
