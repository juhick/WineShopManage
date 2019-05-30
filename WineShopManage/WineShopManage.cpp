
// WineShopManage.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "WineShopManage.h"
#include "WineShopManageDlg.h"
#include "DBOperation.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWineShopManageApp

BEGIN_MESSAGE_MAP(CWineShopManageApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CWineShopManageApp ����

CWineShopManageApp::CWineShopManageApp()
{
	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CWineShopManageApp ����

CWineShopManageApp theApp;


// CWineShopManageApp ��ʼ��

BOOL CWineShopManageApp::InitInstance()
{
	AfxOleInit();

	CStdioFile dbconfig;

	CFileException fileException;

	CString m_sPwd, m_sUid, m_sSid;
	CString path = ("dbconfig.txt");

	if(dbconfig.Open(path, CFile::modeRead, &fileException))
	{
		dbconfig.ReadString(m_sPwd);
		dbconfig.ReadString(m_sUid);
		dbconfig.ReadString(m_sSid);
	}
	else{
		TRACE("Can't open file %s, error = %u\n", path, fileException.m_cause);
	}

	dbconfig.Close();

	CString strConnect;
	strConnect.Format("Provider=OraOLEDB.Oracle.1;Password=%s;Persist Security Info=True;User ID=%s;Data Source=%s",m_sPwd, m_sUid, m_sSid);

	bool bConn = dbOper.ConnToDB((_bstr_t)strConnect, (_bstr_t)m_sUid, (_bstr_t)m_sPwd);

	if (false == bConn)
	{
		AfxMessageBox("�������ݿ���ִ���\n");
	}

	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// ���� shell ���������Է��Ի������
	// �κ� shell ����ͼ�ؼ��� shell �б���ͼ�ؼ���
	CShellManager *pShellManager = new CShellManager;

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	CWineShopManageDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}

	// ɾ�����洴���� shell ��������
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�

	return FALSE;
}

