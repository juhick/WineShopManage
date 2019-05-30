// StaffOtherInfo.cpp : 实现文件
//

#include "stdafx.h"
#include "WineShopManage.h"
#include "StaffOtherInfo.h"
#include "afxdialogex.h"
#include "ShowOtherInfoDlg.h"

// CStaffOtherInfo 对话框

IMPLEMENT_DYNAMIC(CStaffOtherInfo, CDialogEx)

CStaffOtherInfo::CStaffOtherInfo(CWnd* pParent /*=NULL*/)
	: CDialogEx(CStaffOtherInfo::IDD, pParent)
	, m_sSal(_T(""))
	, m_sComm(_T(""))
{

}

CStaffOtherInfo::~CStaffOtherInfo()
{
}

void CStaffOtherInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_SAL, m_sSal);
	DDV_MaxChars(pDX, m_sSal, 8);
	DDX_Text(pDX, IDC_COMM, m_sComm);
	DDV_MaxChars(pDX, m_sComm, 8);
	DDX_Control(pDX, IDC_COMBO1, m_sMgrs);
}


BEGIN_MESSAGE_MAP(CStaffOtherInfo, CDialogEx)
	ON_BN_CLICKED(IDOK, &CStaffOtherInfo::OnBnClickedOk)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CStaffOtherInfo 消息处理程序


void CStaffOtherInfo::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CWineShopManageApp *pApp = (CWineShopManageApp*)AfxGetApp();
	CString sql;

	CString MgrNow;
	m_sMgrs.GetWindowText(MgrNow);

	sql.Format("UPDATE EMP_OTHERINFO SET MGR = '%s', SAL = '%s', COMM = '%s' WHERE ENO = '%s'", MgrNow, m_sSal, m_sComm, pApp->staff.getEno());
	pApp->dbOper.ExecuteWithResSQL(_bstr_t(sql));
	CShowOtherInfoDlg dlg;
	dlg.DoModal();
	UpdateData(FALSE);
	CDialogEx::OnOK();
}


void CStaffOtherInfo::OnPaint()
{
	UpdateData(TRUE);
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()
	CWineShopManageApp *pApp = (CWineShopManageApp*)AfxGetApp();
	_RecordsetPtr pRst;
	CString sql;

	sql.Format("SELECT MGR, SAL, COMM FROM EMP_OTHERINFO WHERE ENO = '%s'", pApp->staff.getEno());
	CString MgrOld;
	pRst = pApp->dbOper.ExecuteWithResSQL(_bstr_t(sql));

	MgrOld = pRst->GetCollect(_variant_t("MGR"));

	m_sMgrs.AddString(MgrOld);
	m_sMgrs.SetCurSel(0);
	m_sSal = pRst->GetCollect(_variant_t("SAL"));
	m_sComm = pRst->GetCollect(_variant_t("COMM"));

	sql.Format("SELECT ENO FROM EMP_JOB WHERE ENO != '%s'", MgrOld);
	pRst = pApp->dbOper.ExecuteWithResSQL(_bstr_t(sql));
	while(!pRst->GetadoEOF()){
		m_sMgrs.AddString((CString)(pRst->GetCollect(_variant_t("ENO"))));
		pRst->MoveNext();
	}
	UpdateData(FALSE);
}
