
// WineShopManage.cpp : 定义应用程序的类行为。
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


// CWineShopManageApp 构造

CWineShopManageApp::CWineShopManageApp()
{
	// 支持重新启动管理器
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CWineShopManageApp 对象

CWineShopManageApp theApp;


// CWineShopManageApp 初始化

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
		AfxMessageBox("连接数据库出现错误\n");
	}

	// 如果一个运行在 Windows XP 上的应用程序清单指定要
	// 使用 ComCtl32.dll 版本 6 或更高版本来启用可视化方式，
	//则需要 InitCommonControlsEx()。否则，将无法创建窗口。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 将它设置为包括所有要在应用程序中使用的
	// 公共控件类。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// 创建 shell 管理器，以防对话框包含
	// 任何 shell 树视图控件或 shell 列表视图控件。
	CShellManager *pShellManager = new CShellManager;

	// 标准初始化
	// 如果未使用这些功能并希望减小
	// 最终可执行文件的大小，则应移除下列
	// 不需要的特定初始化例程
	// 更改用于存储设置的注册表项
	// TODO: 应适当修改该字符串，
	// 例如修改为公司或组织名
	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));

	CWineShopManageDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: 在此放置处理何时用
		//  “确定”来关闭对话框的代码
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: 在此放置处理何时用
		//  “取消”来关闭对话框的代码
	}

	// 删除上面创建的 shell 管理器。
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	// 由于对话框已关闭，所以将返回 FALSE 以便退出应用程序，
	//  而不是启动应用程序的消息泵。

	return FALSE;
}

