// ShowOtherInfoDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "WineShopManage.h"
#include "ShowOtherInfoDlg.h"
#include "afxdialogex.h"


// CShowOtherInfoDlg 对话框

IMPLEMENT_DYNAMIC(CShowOtherInfoDlg, CDialogEx)

CShowOtherInfoDlg::CShowOtherInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CShowOtherInfoDlg::IDD, pParent)
	, m_sEno(_T(""))
	, m_sEname(_T(""))
	, m_sEsex(_T(""))
	, m_sAge(_T(""))
	, m_sJob(_T(""))
	, m_sDept(_T(""))
	, m_sMgr(_T(""))
	, m_sSal(_T(""))
	, m_sComm(_T(""))
	, m_sDate(_T(""))
{

}

CShowOtherInfoDlg::~CShowOtherInfoDlg()
{
}

void CShowOtherInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_SHOWENO, m_sEno);
	DDX_Text(pDX, IDC_ENAMESHOW, m_sEname);
	DDX_Text(pDX, IDC_SEXSHOW, m_sEsex);
	DDX_Text(pDX, IDC_AGESHOW, m_sAge);
	DDX_Text(pDX, IDC_JOBSHOW, m_sJob);
	DDX_Text(pDX, IDC_DEPTSHOW, m_sDept);
	DDX_Text(pDX, IDC_MGRSHOW, m_sMgr);
	DDX_Text(pDX, IDC_SALSHOW, m_sSal);
	DDX_Text(pDX, IDC_COMMSHOW, m_sComm);
	DDX_Text(pDX, IDC_DATESHOW, m_sDate);
}


BEGIN_MESSAGE_MAP(CShowOtherInfoDlg, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CShowOtherInfoDlg 消息处理程序


void CShowOtherInfoDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()
	UpdateData(TRUE);
	CWineShopManageApp *pApp = (CWineShopManageApp* )AfxGetApp();

	_RecordsetPtr pStr;

	CString sql;
	sql.Format("SELECT ENO, ENAME, ESEX, EAGE, JOB, DEPT, MGR, SAL, COMM, HIREDATE FROM EMP_OTHERINFO WHERE ENO = '%s'", pApp->staff.getEno());
	pStr = pApp->dbOper.ExecuteWithResSQL(_bstr_t(sql));

	m_sEno = pStr->GetCollect(_variant_t("ENO"));
	m_sEname = pStr->GetCollect(_variant_t("ENAME"));
	m_sEsex = pStr->GetCollect(_variant_t("ESEX"));
	m_sAge = pStr->GetCollect(_variant_t("EAGE"));
	m_sJob = pStr->GetCollect(_variant_t("JOB"));
	m_sDept = pStr->GetCollect(_variant_t("DEPT"));
	m_sMgr = pStr->GetCollect(_variant_t("MGR"));
	m_sSal = pStr->GetCollect(_variant_t("SAL"));
	m_sComm = pStr->GetCollect(_variant_t("COMM"));
	m_sDate = pStr->GetCollect(_variant_t("HIREDATE"));

	UpdateData(FALSE);
}
