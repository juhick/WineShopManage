// StaffInfo.cpp : 实现文件
//

#include "stdafx.h"
#include "WineShopManage.h"
#include "StaffInfo.h"
#include "afxdialogex.h"
#include "DBOperation.h"
#include "StaffOtherInfo.h"


// CStaffInfo 对话框

IMPLEMENT_DYNAMIC(CStaffInfo, CDialogEx)

CStaffInfo::CStaffInfo(CWnd* pParent /*=NULL*/)
	: CDialogEx(CStaffInfo::IDD, pParent)
	, m_sEno(_T(""))
	, m_sEname(_T(""))
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
	DDX_Text(pDX, IDC_ENO, m_sEno);
	DDV_MaxChars(pDX, m_sEno, 4);
	DDX_Text(pDX, IDC_ENAME, m_sEname);
	DDV_MaxChars(pDX, m_sEname, 10);
	DDX_Text(pDX, IDC_JOBINFO, m_sJobInfo);
	DDV_MaxChars(pDX, m_sJobInfo, 100);
	DDX_Text(pDX, IDC_JOBENV, m_sJobEnv);
	DDV_MaxChars(pDX, m_sJobEnv, 20);
	DDX_Text(pDX, IDC_JOBTIME, m_sJobTime);
	DDX_Control(pDX, IDC_JOBS, m_sJobs);
	DDX_Control(pDX, IDC_DEPTS, m_sDepts);
}


BEGIN_MESSAGE_MAP(CStaffInfo, CDialogEx)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_STIFBT, &CStaffInfo::OnBnClickedStifbt)
END_MESSAGE_MAP()


// CStaffInfo 消息处理程序


void CStaffInfo::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()
	CWineShopManageApp *pApp = (CWineShopManageApp*)AfxGetApp();
	m_sEno = pApp->staff.getEno();

	_RecordsetPtr pRst;
	CString sql;

	sql = "SELECT ENAME, JOB, DEPT, JOBINFO, JOBENV, JOBTIME FROM EMP_JOB WHERE ENO = " + m_sEno;

	pRst = pApp->dbOper.ExecuteWithResSQL(_bstr_t(sql));

	if (pRst == NULL){
		//AfxMessageBox("查询数据出现错误！");
	}
	if (pRst->adoEOF){
		pRst->Close();
		//AfxMessageBox("There is no records in this table");
	}

	m_sEname = pRst->GetCollect(_variant_t("ENAME"));
	m_sJobs.AddString((CString)(pRst->GetCollect(_variant_t("JOB"))));
	m_sJobs.SetCurSel(0);
	m_sDepts.AddString((CString)pRst->GetCollect(_variant_t("DEPT"))) ;
	m_sDepts.SetCurSel(0);
	m_sJobInfo = pRst->GetCollect(_variant_t("JOBINFO"));
	m_sJobEnv = pRst->GetCollect(_variant_t("JOBENV"));
	m_sJobTime = pRst->GetCollect(_variant_t("JOBTIME"));

	//pRst->Close();

	CString JobNow;

	m_sJobs.GetWindowText(JobNow);

	sql.Format("SELECT DISTINCT JOB FROM EMP_JOB WHERE JOB != '%s'", JobNow);
	pRst = pApp->dbOper.ExecuteWithResSQL((_bstr_t)sql);

	while(!pRst->GetadoEOF()){
		m_sJobs.AddString((CString)(pRst->GetCollect(_variant_t("JOB"))));
		pRst->MoveNext();
	}
	
	CString DeptNow;

	m_sDepts.GetWindowText(DeptNow);

	sql.Format("SELECT DISTINCT DEPT FROM EMP_JOB WHERE DEPT != '%s'", DeptNow);
	pRst = pApp->dbOper.ExecuteWithResSQL((_bstr_t)sql);

	while(!pRst->GetadoEOF()){
		m_sDepts.AddString((CString)(pRst->GetCollect(_variant_t("DEPT"))));
		pRst->MoveNext();
	}

	/*pRst->Close();
	pRst->Release();*/

	UpdateData(FALSE);
	
}


void CStaffInfo::OnBnClickedStifbt()
{
	// TODO: 在此添加控件通知处理程序代码
	CWineShopManageApp *pApp = (CWineShopManageApp*)AfxGetApp();
	UpdateData(TRUE);
	CString sql;

	CString JobNow;
	m_sJobs.GetWindowText(JobNow);
	CString DeptNow;
	m_sDepts.GetWindowText(DeptNow);

	sql.Format("UPDATE EMP_JOB SET JOB = '%s', DEPT = '%s', JOBINFO = '%s', JOBENV = '%s', JOBTIME = '%s' WHERE ENO = '%s'", JobNow, DeptNow, m_sJobInfo, m_sJobEnv, m_sJobTime, m_sEno);
	pApp->dbOper.ExecuteWithResSQL(_bstr_t(sql));
	sql.Format("UPDATE EMP_OTHERINFO SET JOB = '%s', DEPT = '%s' WHERE ENO = '%s'", JobNow, DeptNow, m_sEno);
	pApp->dbOper.ExecuteWithResSQL(_bstr_t(sql));

	CStaffOtherInfo dlg;
	dlg.DoModal();

	UpdateData(FALSE);
}
