#pragma once


// CAttendCountShow 对话框

class CAttendCountShow : public CDialogEx
{
	DECLARE_DYNAMIC(CAttendCountShow)

public:
	CAttendCountShow(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAttendCountShow();

// 对话框数据
	enum { IDD = IDD_ATTENDCOUNTDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
