#pragma once


// CStaff

class CStaff : public CWnd
{
	DECLARE_DYNAMIC(CStaff)

public:
	CStaff();
	virtual ~CStaff();

protected:
	DECLARE_MESSAGE_MAP()

private:
	CString m_sEno;
	CString m_sEname;
	CString m_sJob;
	CString m_sJobInfo;
	CString m_sJobEnv;
	CString m_sJobTime;
public:
	CString getEno(void);
	CString getEname(void);
	CString getJob(void);
	CString getJobInfo(void);
	CString getJobEnv(void);
	CString getJobTime(void);
	void setEno(CString Eno = "");
	void setEname(CString Ename = "");
	void setJob(CString Job = "");
	void setJobInfo(CString JobInfo = "");
	void setJobEnv(CString JobEnv = "");
	void setJobTime(CString JobTime = "");
};


