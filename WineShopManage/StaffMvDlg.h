#pragma once


// CStaffMvDlg 对话框

class CStaffMvDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CStaffMvDlg)

public:
	CStaffMvDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CStaffMvDlg();

// 对话框数据
	enum { IDD = IDD_MVDIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

public:

	CString m_sEno;
	afx_msg void OnBnClickedCheck();
};