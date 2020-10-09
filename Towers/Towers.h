
// Towers.h : main header file for the Towers application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CTowersApp:
// See Towers.cpp for the implementation of this class
//

class CTowersApp : public CWinApp
{
public:
	CTowersApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CTowersApp theApp;
