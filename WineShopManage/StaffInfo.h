#pragma once


// CStaffInfo �Ի���

class CStaffInfo : public CDialogEx
{
	DECLARE_DYNAMIC(CStaffInfo)

public:
	CStaffInfo(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CStaffInfo();

// �Ի�������
	enum { IDD = IDD_STAFFINFO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_sEno;
	CString m_sEname;
	CString m_sJob;
	CString m_sDept;
	CString m_sJobInfo;
	CString m_sJobEnv;
	CString m_sJobTime;
	afx_msg void OnPaint();
};
