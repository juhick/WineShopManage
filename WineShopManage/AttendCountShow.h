#pragma once


// CAttendCountShow �Ի���

class CAttendCountShow : public CDialogEx
{
	DECLARE_DYNAMIC(CAttendCountShow)

public:
	CAttendCountShow(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAttendCountShow();

// �Ի�������
	enum { IDD = IDD_ATTENDCOUNTDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_sEno;
	CString m_sEname;

	afx_msg void OnPaint();
	int m_iNormalTimes;
	int m_iOverTimes;
	int m_iLateTimes;
	int m_iEarlyTimes;
	int m_iLeaveTimes;
	int m_iAbsentTimes;
};
