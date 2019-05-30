// StaffAttend.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "WineShopManage.h"
#include "StaffAttend.h"
#include "afxdialogex.h"
#include "StaffAttendManage.h"


// CStaffAttend �Ի���

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


// CStaffAttend ��Ϣ�������


void CStaffAttend::OnBnClickedAttendcontinue()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CWineShopManageApp *pApp = (CWineShopManageApp*)AfxGetApp();
	pApp->staff.setEno(m_sEno);
	CStaffAttendManage dlg;
	dlg.DoModal();
	UpdateData(FALSE);
}
