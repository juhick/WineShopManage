#pragma once


// CFinInfoCount �Ի���

class CFinInfoCount : public CDialogEx
{
	DECLARE_DYNAMIC(CFinInfoCount)

public:
	CFinInfoCount(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CFinInfoCount();

// �Ի�������
	enum { IDD = IDD_FININFOCOUNT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	CString m_sPname;
	double m_sSa;
	double m_sIa;
	double m_sp;
	CString m_sDate;
};
