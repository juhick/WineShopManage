// FinInfoCount.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "WineShopManage.h"
#include "FinInfoCount.h"
#include "afxdialogex.h"


// CFinInfoCount �Ի���

IMPLEMENT_DYNAMIC(CFinInfoCount, CDialogEx)

CFinInfoCount::CFinInfoCount(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFinInfoCount::IDD, pParent)
	, m_sPname(_T(""))
	, m_sSa(0)
	, m_sIa(0)
	, m_sp(0)
	, m_sDate(_T(""))
{

}

CFinInfoCount::~CFinInfoCount()
{
}

void CFinInfoCount::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_PDEPT, m_sPname);
	DDX_Text(pDX, IDC_SAMOUNT, m_sSa);
	DDX_Text(pDX, IDC_IAMOUNT, m_sIa);
	DDX_Text(pDX, IDC_PROFIT, m_sp);
	DDX_Text(pDX, IDC_STADATE, m_sDate);
}


BEGIN_MESSAGE_MAP(CFinInfoCount, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CFinInfoCount ��Ϣ�������


void CFinInfoCount::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	UpdateData(TRUE);
	CWineShopManageApp* pApp = (CWineShopManageApp*)AfxGetApp();
	_RecordsetPtr pRst;
	CString sql;

	sql.Format("SELECT PDEPT, \"TYPE\", SUM(MONEY) FROM FINANCIALINFO GROUP BY \"TYPE\", PDEPT HAVING PDEPT = '%s' ORDER BY \"TYPE\"", pApp->pDept);

	pRst = pApp->dbOper.ExecuteWithResSQL(_bstr_t(sql));
	m_sPname = pApp->pDept;

	m_sIa = pRst->GetCollect("SUM(MONEY)");
	pRst->MoveNext();
	m_sSa = pRst->GetCollect("SUM(MONEY)");

	sql.Format("SELECT SYSDATE FROM DUAL");
	pRst = pApp->dbOper.ExecuteWithResSQL(_bstr_t(sql));
	m_sDate = pRst->GetCollect("SYSDATE");

	m_sp = m_sIa - m_sSa;
	UpdateData(FALSE);
}
