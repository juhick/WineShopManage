// StaffAttendManage.cpp : 实现文件
//

#include "stdafx.h"
#include "WineShopManage.h"
#include "StaffAttendManage.h"
#include "afxdialogex.h"
#include "AttendCountShow.h"


// CStaffAttendManage 对话框

IMPLEMENT_DYNAMIC(CStaffAttendManage, CDialogEx)

CStaffAttendManage::CStaffAttendManage(CWnd* pParent /*=NULL*/)
	: CDialogEx(CStaffAttendManage::IDD, pParent)
	, m_sEno(_T(""))
	, m_sEname(_T(""))
{

}

CStaffAttendManage::~CStaffAttendManage()
{
}

void CStaffAttendManage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_ATTENDENO, m_sEno);
	DDX_Text(pDX, IDC_ATTENDENAME, m_sEname);
	DDX_Control(pDX, IDC_ATTENDCODE, m_sCodes);
}


BEGIN_MESSAGE_MAP(CStaffAttendManage, CDialogEx)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDOK, &CStaffAttendManage::OnBnClickedOk)
END_MESSAGE_MAP()


// CStaffAttendManage 消息处理程序


void CStaffAttendManage::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()
	UpdateData(TRUE);
	CWineShopManageApp *pApp = (CWineShopManageApp*)AfxGetApp();
	_RecordsetPtr pRst;
	m_sEno = pApp->staff.getEno();

	CString sql;
	sql.Format("SELECT ENAME FROM EMP_OTHERINFO WHERE ENO = '%s'", m_sEno);

	pRst = pApp->dbOper.ExecuteWithResSQL(_bstr_t(sql));

	m_sEname = pRst->GetCollect(_variant_t("ENAME"));

	CString codes[] = {"正常", "加班", "迟到", "早退", "旷工", "请假"};

	for (int i = 0; i < 6; i++){
		m_sCodes.AddString(codes[i]);
	}

	UpdateData(FALSE);
}


void CStaffAttendManage::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CWineShopManageApp *pApp = (CWineShopManageApp*)AfxGetApp();
	CString code;
	m_sCodes.GetWindowText(code);

	CString sql; 
	sql.Format("INSERT INTO EMP_ATTENDINFO(ATTENDID, ENO, ENAME, ATTENDCODE, ATTENDDATE) VALUES ((SELECT MAX(ATTENDID) FROM EMP_ATTENDINFO) + 1,'%s','%s','%s',SYSDATE)",m_sEno, m_sEname, code);

	pApp->dbOper.ExecuteWithResSQL(_bstr_t(sql));
	
	pApp->staff.setEname(m_sEname);
	UpdateData(FALSE);
	CAttendCountShow dlg;
	dlg.DoModal();
	CDialogEx::OnOK();
}
