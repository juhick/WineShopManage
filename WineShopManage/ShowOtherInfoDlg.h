#pragma once


// CShowOtherInfoDlg �Ի���

class CShowOtherInfoDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CShowOtherInfoDlg)

public:
	CShowOtherInfoDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CShowOtherInfoDlg();

// �Ի�������
	enum { IDD = IDD_SHOWOTHERINFO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_sEno;
	CString m_sEname;
	CString m_sEsex;
	CString m_sAge;
	CString m_sJob;
	CString m_sDept;
	CString m_sMgr;
	CString m_sSal;
	CString m_sComm;
	CString m_sDate;
	afx_msg void OnPaint();
};
