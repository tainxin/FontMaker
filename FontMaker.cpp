// FontMaker.cpp : 定义应用程序的类行为。
//

#include "stdafx.h"
#include "FontMaker.h"
#include "FontMakerDlg.h"
#include "AboutBox.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFontMakerApp
BEGIN_MESSAGE_MAP(CFontMakerApp, CWinApp)
	ON_COMMAND(ID_HELP, OnHelp)
END_MESSAGE_MAP()


// CFontMakerApp 构造
CFontMakerApp::CFontMakerApp()
{
	bHelp=TRUE;
}


// 唯一的一个 CFontMakerApp 对象
CFontMakerApp theApp;


// CFontMakerApp 初始化
BOOL CFontMakerApp::InitInstance()
{
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);
	CWinApp::InitInstance();
	CFontMakerDlg dlg;
	m_pMainWnd = &dlg;
	dlg.DoModal();

	return FALSE;
}

BOOL CFontMakerApp::GetPath(CString& path)
{
	int len;
	CString str;
	WCHAR* temp;
	temp= _wcsdup(m_pszHelpFilePath);
	str = m_pszHelpFilePath;
	len = str.ReverseFind(L'\\');
	temp[len+1] = L'\0';
	path = temp;
	free(temp);
	return TRUE;
}

void CFontMakerApp::OnHelp()
{
	CAboutBox abox;
	if(bHelp==TRUE)
	{
		bHelp=FALSE;
		abox.DoModal();
		bHelp=TRUE;
	}
}
