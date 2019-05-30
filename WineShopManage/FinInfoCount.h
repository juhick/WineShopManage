#pragma once


// CFinInfoCount 对话框

class CFinInfoCount : public CDialogEx
{
	DECLARE_DYNAMIC(CFinInfoCount)

public:
	CFinInfoCount(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CFinInfoCount();

// 对话框数据
	enum { IDD = IDD_FININFOCOUNT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	CString m_sPname;
	double m_sSa;
	double m_sIa;
	double m_sp;
	CString m_sDate;
};
