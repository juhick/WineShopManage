#pragma once


// CStaffFinInfo �Ի���

class CStaffFinInfo : public CDialogEx
{
	DECLARE_DYNAMIC(CStaffFinInfo)

public:
	CStaffFinInfo(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CStaffFinInfo();

// �Ի�������
	enum { IDD = IDD_STAFFFININFO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_sInfoType;
	CString m_sPname;
	CString m_sPdept;
	double m_fMoney;
	CString m_Pusage;
	CString m_sPmgr;
	afx_msg void OnPaint();
	CString m_sDate;
	afx_msg void OnBnClickedOk();
};
