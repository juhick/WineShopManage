#pragma once
#include "d:\microsoft visual studio 10.0\vc\atlmfc\include\afxwin.h"
#include "d:\microsoft visual studio 10.0\vc\atlmfc\include\afxwin.h"
#include "d:\microsoft visual studio 10.0\vc\atlmfc\include\afxwin.h"


// CFinancialmanage �Ի���

class CFinancialmanage : public CDialogEx
{
	DECLARE_DYNAMIC(CFinancialmanage)

public:
	CFinancialmanage(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CFinancialmanage();

// �Ի�������
	enum { IDD = IDD_FINANCIALMANAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_sInfoType;
	CString m_pName;
	CComboBox m_sPdept;
	double m_fMoney;
	CString m_sUsage;
	CComboBox m_sPmgr;
	afx_msg void OnPaint();
	afx_msg void OnCbnDropdownPmgr();
	afx_msg void OnBnClickedInfoshow();
};
