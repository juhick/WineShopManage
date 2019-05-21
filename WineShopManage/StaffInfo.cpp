// StaffInfo.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "WineShopManage.h"
#include "StaffInfo.h"
#include "afxdialogex.h"
#include "DBOperation.h"


// CStaffInfo �Ի���

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


// CStaffInfo ��Ϣ�������


void CStaffInfo::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	CWineShopManageApp *pApp = (CWineShopManageApp*)AfxGetApp();
	m_sEno = pApp->staff.getEno();
	CDBOperation dbOper;

	bool bConn = dbOper.ConnToDB("Provider=OraOLEDB.Oracle;Persist Security Info=True;DataSource=\"(DESCRIPTION =(ADDRESS_LIST =(ADDRESS = (PROTOCOL = TCP)(HOST = 183.175.14.198)(PORT = 7360)))(CONNECT_DATA =(SERVICE_NAME = OrHotel))\"","USER _5_4_2","123456");

	if (bConn == false){
		printf("���Ӿݿ����\n");
		system("pause");
		return;
	}
	printf("���ݿ����ӳɹ�!\n");
	_RecordsetPtr pRst;

	char sql[255] = { 0 };
	//ִ�в�ѯ���
	strcpy_s(sql, "select * from emp_job where eno = 1234");

	pRst = dbOper.ExecuteWithResSQL(sql);

	if (pRst == NULL){
		printf("��ѯ���ݳ��ִ���\n");
		system("pause");
		return;
	}
	if (pRst->adoEOF){
		pRst->Close();
		printf("There is no records in this table\n");
		system("pause");
		return;
	}
	printf("���ڲ�ѯ...\n");

	_variant_t eno, ename, job, dept, jobinfo, jobenv, jobtime;

	while (!pRst->adoEOF){
		//eno = pRst->GetCollect(_variant_t((long)0));
		ename = pRst->GetCollect(_variant_t("ename"));
		job = pRst->GetCollect(_variant_t("job"));
		jobinfo = pRst->GetCollect(_variant_t("jobinfo"));
		jobenv = pRst->GetCollect(_variant_t("jobenv"));
		jobtime = pRst->GetCollect(_variant_t("jobtime"));
		printf("%s\t%s\t%s\t%s\t%s\t%s\n",(LPSTR)(LPCSTR)(_bstr_t)ename, (LPSTR)(LPCSTR)_bstr_t(job),(LPSTR)(LPCSTR)_bstr_t(dept),(LPSTR)(LPCSTR)(_bstr_t)jobinfo,(LPSTR)(LPCSTR)(_bstr_t)jobenv, (LPSTR)(LPCSTR)(_bstr_t)jobtime);
		pRst->MoveNext();
	}

	UpdateData(FALSE);
}
