#pragma once


// CStaffMvDlg �Ի���

class CStaffMvDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CStaffMvDlg)

public:
	CStaffMvDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CStaffMvDlg();

// �Ի�������
	enum { IDD = IDD_MVDIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

public:

	CString m_sEno;
	afx_msg void OnBnClickedCheck();
};