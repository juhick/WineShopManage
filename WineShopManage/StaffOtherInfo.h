#pragma once
#include "d:\microsoft visual studio 10.0\vc\atlmfc\include\afxwin.h"


// CStaffOtherInfo �Ի���

class CStaffOtherInfo : public CDialogEx
{
	DECLARE_DYNAMIC(CStaffOtherInfo)

public:
	CStaffOtherInfo(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CStaffOtherInfo();

// �Ի�������
	enum { IDD = IDD_StaffOtherInfo };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_sSal;
	afx_msg void OnBnClickedOk();
	CString m_sComm;
	CComboBox m_sMgrs;
	afx_msg void OnPaint();
};
