// StaffAttend.cpp : 实现文件
//

#include "stdafx.h"
#include "WineShopManage.h"
#include "StaffAttend.h"
#include "afxdialogex.h"
#include "StaffAttendManage.h"


// CStaffAttend 对话框

IMPLEMENT_DYNAMIC(CStaffAttend, CDialogEx)

CStaffAttend::CStaffAttend(CWnd* pParent /*=NULL*/)
	: CDialogEx(CStaffAttend::IDD, pParent)
	, m_sEno(_T(""))
{

}

CStaffAttend::~CStaffAttend()
{
}

void CStaffAttend::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_ATTENDENO, m_sEno);
	DDV_MaxChars(pDX, m_sEno, 4);
}


BEGIN_MESSAGE_MAP(CStaffAttend, CDialogEx)
	ON_BN_CLICKED(IDC_ATTENDCONTINUE, &CStaffAttend::OnBnClickedAttendcontinue)
END_MESSAGE_MAP()


// CStaffAttend 消息处理程序


void CStaffAttend::OnBnClickedAttendcontinue()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CWineShopManageApp *pApp = (CWineShopManageApp*)AfxGetApp();
	pApp->staff.setEno(m_sEno);
	CStaffAttendManage dlg;
	dlg.DoModal();
	UpdateData(FALSE);
}
