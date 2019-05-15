// StaffInfo.cpp : 实现文件
//

#include "stdafx.h"
#include "WineShopManage.h"
#include "StaffInfo.h"
#include "afxdialogex.h"


// CStaffInfo 对话框

IMPLEMENT_DYNAMIC(CStaffInfo, CDialogEx)

CStaffInfo::CStaffInfo(CWnd* pParent /*=NULL*/)
	: CDialogEx(CStaffInfo::IDD, pParent)
	, m_sEno(_T(""))
	, m_sEname(_T(""))
	, m_sJob(_T(""))
	, m_sDept(_T(""))
	, m_sJobInfo(_T(""))
	, m_sJobEnv(_T(""))
	, m_sJobTime(_T(""))
{

}

CStaffInfo::~CStaffInfo()
{
}

void CStaffInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_sEno);
	DDV_MaxChars(pDX, m_sEno, 4);
	DDX_Text(pDX, IDC_EDIT4, m_sEname);
	DDV_MaxChars(pDX, m_sEname, 10);
	DDX_Text(pDX, IDC_EDIT2, m_sJob);
	DDV_MaxChars(pDX, m_sJob, 10);
	DDX_Text(pDX, IDC_EDIT6, m_sDept);
	DDV_MaxChars(pDX, m_sDept, 10);
	DDX_Text(pDX, IDC_EDIT5, m_sJobInfo);
	DDV_MaxChars(pDX, m_sJobInfo, 100);
	DDX_Text(pDX, IDC_EDIT3, m_sJobEnv);
	DDV_MaxChars(pDX, m_sJobEnv, 20);
	DDX_Text(pDX, IDC_EDIT7, m_sJobTime);
}


BEGIN_MESSAGE_MAP(CStaffInfo, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CStaffInfo 消息处理程序


void CStaffInfo::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()
	CWineShopManageApp *pApp = (CWineShopManageApp*)AfxGetApp();
	m_sEno = pApp->staff.getEno();
	UpdateData(FALSE);
}
