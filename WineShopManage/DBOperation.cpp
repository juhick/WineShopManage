// DBOperation.cpp : 实现文件
//

#include "stdafx.h"
#include "WineShopManage.h"
#include "DBOperation.h"


// CDBOperation

IMPLEMENT_DYNAMIC(CDBOperation, CWnd)

CDBOperation::CDBOperation()
{
	CoInitialize(NULL);
	m_pConnection = CreateConnPtr();
	m_pCommand = CreateCommPtr();
}

CDBOperation::~CDBOperation()
{
	m_pConnection->Close();
}


BEGIN_MESSAGE_MAP(CDBOperation, CWnd)
END_MESSAGE_MAP()



// CDBOperation 消息处理程序




bool CDBOperation::ConnToDB(_bstr_t ConnectionString, _bstr_t UserID, _bstr_t Password)
{
	if (NULL == m_pConnection)
	{
		printf("Failed to create connection\n");
		return false;
	}

	try
	{
		HRESULT hr = m_pConnection->Open(ConnectionString, UserID, Password, NULL);
		if (TRUE == FAILED(hr))
		{
			return false;
		}
		m_pCommand->ActiveConnection = m_pConnection;
		return true;
	}
	catch(_com_error &e)
	{
		PrintErrorInfo(e);
		return false;
	}

}


_RecordsetPtr CDBOperation::ExecuteWithResSQL(_bstr_t sql)
{
	//已经在连接至数据库的时候进行判断了
	//if (NULL ==m_pCommand || 0 == m_pConnection->State)
	//{
	//    printf("Failed to create command ORthe state of connection is zero\n");
	//    return NULL;
	//}

	//char *query =new char;
	//strcpy(query,sql);
	try
	{
		m_pCommand->CommandText =_bstr_t(sql);
		_RecordsetPtr pRst =m_pCommand->Execute(NULL, NULL, adCmdText);
		return pRst;
		//_variant_tra;
		//_RecordsetPtrpRst = m_pConnection->Execute((_bstr_t)query, &ra, adCmdText);
	}
	catch(_com_error &e)
	{
		PrintErrorInfo(e);
		return NULL;
	}

}


void CDBOperation::PrintErrorInfo(_com_error & e)
{
	AfxMessageBox("Error information are as follows");
	CString err;
	err.Format("Error No:%d\nError Message:%s\nError Source:%s\nError Description:%s\n",e.Error(), e.ErrorMessage(), (LPCTSTR)e.Source(), (LPCTSTR)e.Description());
	AfxMessageBox(err);
}


_ConnectionPtr CDBOperation::CreateConnPtr(void)
{
	HRESULT hr;
	_ConnectionPtr connPtr;
	hr = connPtr.CreateInstance(__uuidof(Connection));
	if(FAILED(hr) == TRUE)
	{
		return NULL;
	}
	return connPtr;
}


_CommandPtr CDBOperation::CreateCommPtr(void)
{
	HRESULT hr;
	_CommandPtr commPtr;
	hr = commPtr.CreateInstance(__uuidof(Command));
	if(FAILED(hr) == TRUE)
	{
		return NULL;
	}
	return commPtr;
}


_RecordsetPtr CDBOperation::CreateRecsetPtr(void)
{
	HRESULT hr;
	_RecordsetPtr recsetPtr;
	hr = recsetPtr.CreateInstance(__uuidof(Command));
	if(FAILED(hr) == TRUE)
	{
		return NULL;
	}
	return recsetPtr;

}
