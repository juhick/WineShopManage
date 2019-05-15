// StaffMvDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "WineShopManage.h"
#include "StaffMvDlg.h"
#include "afxdialogex.h"
#include "StaffInfo.h"


// CStaffMvDlg �Ի���

IMPLEMENT_DYNAMIC(CStaffMvDlg, CDialogEx)

CStaffMvDlg::CStaffMvDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CStaffMvDlg::IDD, pParent),m_sEno(_T(""))
	
{

}

CStaffMvDlg::~CStaffMvDlg()
{
}

void CStaffMvDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDITENO, m_sEno);
	DDV_MaxChars(pDX, m_sEno, 4);
}


BEGIN_MESSAGE_MAP(CStaffMvDlg, CDialogEx)
//	ON_BN_CLICKED(IDOK, &CStaffMvDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_CHECK, &CStaffMvDlg::OnBnClickedCheck)
END_MESSAGE_MAP()


void CStaffMvDlg::OnBnClickedCheck()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	CWineShopManageApp *pApp = (CWineShopManageApp *)AfxGetApp();
	pApp->staff.setEno(m_sEno); 
	CStaffInfo dlg;
	dlg.DoModal();
}
