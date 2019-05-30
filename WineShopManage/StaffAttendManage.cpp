// StaffAttendManage.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "WineShopManage.h"
#include "StaffAttendManage.h"
#include "afxdialogex.h"
#include "AttendCountShow.h"


// CStaffAttendManage �Ի���

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


// CStaffAttendManage ��Ϣ�������


void CStaffAttendManage::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	UpdateData(TRUE);
	CWineShopManageApp *pApp = (CWineShopManageApp*)AfxGetApp();
	_RecordsetPtr pRst;
	m_sEno = pApp->staff.getEno();

	CString sql;
	sql.Format("SELECT ENAME FROM EMP_OTHERINFO WHERE ENO = '%s'", m_sEno);

	pRst = pApp->dbOper.ExecuteWithResSQL(_bstr_t(sql));

	m_sEname = pRst->GetCollect(_variant_t("ENAME"));

	CString codes[] = {"����", "�Ӱ�", "�ٵ�", "����", "����", "���"};

	for (int i = 0; i < 6; i++){
		m_sCodes.AddString(codes[i]);
	}

	UpdateData(FALSE);
}


void CStaffAttendManage::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
