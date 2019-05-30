#pragma once
#include "d:\microsoft visual studio 10.0\vc\atlmfc\include\afxwin.h"


// CStaffAttendManage 对话框

class CStaffAttendManage : public CDialogEx
{
	DECLARE_DYNAMIC(CStaffAttendManage)

public:
	CStaffAttendManage(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CStaffAttendManage();

// 对话框数据
	enum { IDD = IDD_ATTENDINPUT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_sEno;
	CString m_sEname;
	CComboBox m_sCodes;
	afx_msg void OnPaint();
	afx_msg void OnBnClickedOk();
};
