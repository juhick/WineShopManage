// Financialmanage.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "WineShopManage.h"
#include "Financialmanage.h"
#include "afxdialogex.h"
#include "StaffFinInfo.h"


// CFinancialmanage �Ի���

IMPLEMENT_DYNAMIC(CFinancialmanage, CDialogEx)

CFinancialmanage::CFinancialmanage(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFinancialmanage::IDD, pParent)
	, m_pName(_T(""))
	, m_fMoney(0)
	, m_sUsage(_T(""))
{

}

CFinancialmanage::~CFinancialmanage()
{
}

void CFinancialmanage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_INFOTYPE, m_sInfoType);
	DDX_Text(pDX, IDC_PNAME, m_pName);
	DDV_MaxChars(pDX, m_pName, 40);
	DDX_Control(pDX, IDC_PDEPT, m_sPdept);
	DDX_Text(pDX, IDC_MONEY, m_fMoney);
	DDV_MinMaxDouble(pDX, m_fMoney, 0, 9999999.99);
	DDX_Text(pDX, IDC_PUSAGE, m_sUsage);
	DDV_MaxChars(pDX, m_sUsage, 100);
	DDX_Control(pDX, IDC_PMGR, m_sPmgr);
}


BEGIN_MESSAGE_MAP(CFinancialmanage, CDialogEx)
	ON_WM_PAINT()
//	ON_CBN_SELCHANGE(IDC_PDEPT, &CFinancialmanage::OnCbnSelchangePdept)
//	ON_CBN_SELCHANGE(IDC_PMGR, &CFinancialmanage::OnCbnSelchangePmgr)
ON_CBN_DROPDOWN(IDC_PMGR, &CFinancialmanage::OnCbnDropdownPmgr)
ON_BN_CLICKED(IDC_INFOSHOW, &CFinancialmanage::OnBnClickedInfoshow)
END_MESSAGE_MAP()


// CFinancialmanage ��Ϣ�������


void CFinancialmanage::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	UpdateData(TRUE);
	CWineShopManageApp* pApp = (CWineShopManageApp*)AfxGetApp();
	_RecordsetPtr pRst;
	CString sql;
	
	m_sInfoType.AddString("����");
	m_sInfoType.AddString("֧��");

	sql.Format("SELECT DISTINCT DEPT FROM EMP_JOB");
	pRst = pApp->dbOper.ExecuteWithResSQL((_bstr_t)sql);

	while(!pRst->GetadoEOF()){
		m_sPdept.AddString((CString)(pRst->GetCollect(_variant_t("DEPT"))));
		pRst->MoveNext();
	}

	m_sPdept.SetCurSel(0);
	CString nowDept;
	m_sPdept.GetWindowText(nowDept);

	sql.Format("SELECT ENAME FROM EMP_JOB WHERE DEPT = '%s'", nowDept);
	pRst = pApp->dbOper.ExecuteWithResSQL((_bstr_t)sql);

	while(!pRst->GetadoEOF()){
		m_sPmgr.AddString((CString)(pRst->GetCollect(_variant_t("ENAME"))));
		pRst->MoveNext();
	}

	UpdateData(FALSE);
}

void CFinancialmanage::OnCbnDropdownPmgr()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_sPmgr.ResetContent();
	CWineShopManageApp* pApp = (CWineShopManageApp*)AfxGetApp();
	_RecordsetPtr pRst;
	CString nowDept;
	CString sql;
	m_sPdept.GetWindowText(nowDept);

	sql.Format("SELECT ENAME FROM EMP_JOB WHERE DEPT = '%s'", nowDept);
	pRst = pApp->dbOper.ExecuteWithResSQL((_bstr_t)sql);

	while(!pRst->GetadoEOF()){
		m_sPmgr.AddString((CString)(pRst->GetCollect(_variant_t("ENAME"))));
		pRst->MoveNext();
	}
	UpdateData(FALSE);
}


void CFinancialmanage::OnBnClickedInfoshow()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CWineShopManageApp* pApp = (CWineShopManageApp*)AfxGetApp();
	_RecordsetPtr pRst;
	CString typeNow, deptNow, mgrNow;
	m_sInfoType.GetWindowText(typeNow);
	m_sPdept.GetWindowText(deptNow);
	m_sPmgr.GetWindowText(mgrNow);

	CString sql;

	sql.Format("INSERT INTO FINANCIALINFO(PNO, PNAME, PDEPT, MONEY, SUBTIME, PUSAGE, PMGR, \"TYPE\") VALUES ((SELECT COUNT(PNO) FROM FINANCIALINFO) + 1, '%s', '%s', '%f', SYSDATE, '%s', '%s', '%s')", m_pName, deptNow, m_fMoney, m_sUsage, mgrNow, typeNow);
	pApp->dbOper.ExecuteWithResSQL(_bstr_t(sql));

	sql.Format("SELECT COUNT(PNO) FROM FINANCIALINFO");
	pRst = pApp->dbOper.ExecuteWithResSQL(_bstr_t(sql));

	pApp->pNo = pRst->GetCollect("COUNT(PNO)");
	pApp->pDept = deptNow;
	CStaffFinInfo dlg;
	dlg.DoModal();
	UpdateData(FALSE);
}
