#pragma once

#import "C:\Program Files\Common Files\system\ado\msado15.dll" no_namespace rename("EOF","adoEOF")

// CDBOperation

class CDBOperation : public CWnd
{
	DECLARE_DYNAMIC(CDBOperation)

public:
	CDBOperation();
	virtual ~CDBOperation();

protected:
	DECLARE_MESSAGE_MAP()
public:
	bool ConnToDB(char * ConnectionString, char * UserID, char * Password);
	_RecordsetPtr ExecuteWithResSQL(const char * sql);
private:
	void PrintErrorInfo(_com_error & e);
	_ConnectionPtr CreateConnPtr(void);
	_CommandPtr CreateCommPtr(void);
public:
	_RecordsetPtr CreateRecsetPtr(void);
private:
	_ConnectionPtr m_pConnection;
	_CommandPtr m_pCommand;
};


