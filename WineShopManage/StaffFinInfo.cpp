// StaffFinInfo.cpp : 实现文件
//

#include "stdafx.h"
#include "WineShopManage.h"
#include "StaffFinInfo.h"
#include "afxdialogex.h"
#include "FinInfoCount.h"


// CStaffFinInfo 对话框

IMPLEMENT_DYNAMIC(CStaffFinInfo, CDialogEx)

CStaffFinInfo::CStaffFinInfo(CWnd* pParent /*=NULL*/)
	: CDialogEx(CStaffFinInfo::IDD, pParent)
	, m_sInfoType(_T(""))
	, m_sPname(_T(""))
	, m_sPdept(_T(""))
	, m_fMoney(0)
	, m_Pusage(_T(""))
	, m_sPmgr(_T(""))
	, m_sDate(_T(""))
{

}

CStaffFinInfo::~CStaffFinInfo()
{
}

void CStaffFinInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_INFOTYPE, m_sInfoType);
	DDX_Text(pDX, IDC_PNAME, m_sPname);
	DDX_Text(pDX, IDC_PDEPT, m_sPdept);
	DDX_Text(pDX, IDC_MONEY, m_fMoney);
	DDX_Text(pDX, IDC_PUSAGE, m_Pusage);
	DDX_Text(pDX, IDC_PMGR, m_sPmgr);
	DDX_Text(pDX, IDC_SUBTIME, m_sDate);
}


BEGIN_MESSAGE_MAP(CStaffFinInfo, CDialogEx)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDOK, &CStaffFinInfo::OnBnClickedOk)
END_MESSAGE_MAP()


// CStaffFinInfo 消息处理程序


void CStaffFinInfo::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()
	UpdateData(TRUE);
	CWineShopManageApp *pApp = (CWineShopManageApp*)AfxGetApp();
	_RecordsetPtr pRst;

	CString sql;

	sql.Format("SELECT PNAME, PDEPT, MONEY, SUBTIME, PUSAGE, PMGR, \"TYPE\" FROM FINANCIALINFO WHERE PNO = '%s'", pApp->pNo);

	pRst = pApp->dbOper.ExecuteWithResSQL(_bstr_t(sql));

	m_sPname = pRst->GetCollect("PNAME");
	m_sPdept = pRst->GetCollect("PDEPT");
	m_fMoney = pRst->GetCollect("MONEY");
	m_sDate = pRst->GetCollect("SUBTIME");
	m_Pusage = pRst->GetCollect("PUSAGE");
	m_sInfoType = pRst->GetCollect("TYPE");
	m_sPmgr = pRst->GetCollect("PMGR");

	UpdateData(FALSE);
}


void CStaffFinInfo::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CFinInfoCount dlg;
	dlg.DoModal();
	CDialogEx::OnOK();
}
