#pragma once


// CStaffAttend �Ի���

class CStaffAttend : public CDialogEx
{
	DECLARE_DYNAMIC(CStaffAttend)

public:
	CStaffAttend(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CStaffAttend();

// �Ի�������
	enum { IDD = IDD_ATTENDENOINPUT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_sEno;
	afx_msg void OnBnClickedAttendcontinue();
};
