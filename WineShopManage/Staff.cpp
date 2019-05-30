// Staff.cpp : 实现文件
//

#include "stdafx.h"
#include "WineShopManage.h"
#include "Staff.h"


// CStaff

IMPLEMENT_DYNAMIC(CStaff, CWnd)

CStaff::CStaff()
{
	m_sEno = "";
	m_sEname = "";
	m_sJob = "";
	m_sJobEnv = "";
	m_sJobInfo = "";
	m_sJobTime = "";
}

CStaff::~CStaff()
{
}


BEGIN_MESSAGE_MAP(CStaff, CWnd)
END_MESSAGE_MAP()



// CStaff 消息处理程序


CString CStaff::getEno(void)
{
	return m_sEno;
}

CString CStaff::getEname(void)
{
	return m_sEname;
}

CString CStaff::getJob(void)
{
	return m_sJob;
}


CString CStaff::getJobInfo(void)
{
	return m_sJobInfo;
}


CString CStaff::getJobEnv(void)
{
	return m_sJobEnv;
}


CString CStaff::getJobTime(void)
{
	return m_sJobTime;
}


void CStaff::setEno(CString Eno)
{
	m_sEno = Eno;
}

void CStaff::setEname(CString Ename)
{
	m_sEname = Ename;
}

void CStaff::setJob(CString Job)
{
	m_sJob = Job;
}
void CStaff::setJobInfo(CString JobInfo)
{
	m_sJobInfo = JobInfo;
}

void CStaff::setJobEnv(CString JobEnv)
{
	m_sJobEnv = JobEnv;
}

void CStaff::setJobTime(CString JobTime)
{
	m_sJobTime = JobTime;
}