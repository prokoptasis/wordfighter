// WordFighter.h : main header file for the WORDFIGHTER application
//

#if !defined(AFX_WORDFIGHTER_H__BB78AA7D_CF51_4B0E_B3B7_8029FBFE33B1__INCLUDED_)
#define AFX_WORDFIGHTER_H__BB78AA7D_CF51_4B0E_B3B7_8029FBFE33B1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CWordFighterApp:
// See WordFighter.cpp for the implementation of this class
//

class CWordFighterApp : public CWinApp
{
public:
	CWordFighterApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWordFighterApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CWordFighterApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WORDFIGHTER_H__BB78AA7D_CF51_4B0E_B3B7_8029FBFE33B1__INCLUDED_)
