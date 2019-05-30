#pragma once


// CStaffFinInfo 对话框

class CStaffFinInfo : public CDialogEx
{
	DECLARE_DYNAMIC(CStaffFinInfo)

public:
	CStaffFinInfo(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CStaffFinInfo();

// 对话框数据
	enum { IDD = IDD_STAFFFININFO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
