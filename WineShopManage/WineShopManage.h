
// WineShopManage.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������
#include "Staff.h"
#include "DBOperation.h"

// CWineShopManageApp:
// �йش����ʵ�֣������ WineShopManage.cpp
//

class CWineShopManageApp : public CWinApp
{
public:
	CWineShopManageApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
public:
	CStaff staff;
	CDBOperation dbOper;
	CString pNo;
	CString pDept;
};

extern CWineShopManageApp theApp;