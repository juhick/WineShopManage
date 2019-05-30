// AttendCountShow.cpp : 实现文件
//

#include "stdafx.h"
#include "WineShopManage.h"
#include "AttendCountShow.h"
#include "afxdialogex.h"


// CAttendCountShow 对话框

IMPLEMENT_DYNAMIC(CAttendCountShow, CDialogEx)

CAttendCountShow::CAttendCountShow(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAttendCountShow::IDD, pParent)
	, m_sEno(_T(""))
	, m_sEname(_T(""))

	, m_iNormalTimes(0)
	, m_iOverTimes(0)
	, m_iLateTimes(0)
	, m_iEarlyTimes(0)
	, m_iLeaveTimes(0)
	, m_iAbsentTimes(0)
{

}

CAttendCountShow::~CAttendCountShow()
{
}

void CAttendCountShow::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_ENO, m_sEno);
	DDX_Text(pDX, IDC_SHOWENAME, m_sEname);

	DDX_Text(pDX, IDC_NORMALTIMES, m_iNormalTimes);
	DDX_Text(pDX, IDC_OVERTIMES, m_iOverTimes);
	DDX_Text(pDX, IDC_LATETIMES, m_iLateTimes);
	DDX_Text(pDX, IDC_EARLYTIMES, m_iEarlyTimes);
	DDX_Text(pDX, IDC_LEAVETIMES, m_iLeaveTimes);
	DDX_Text(pDX, IDC_ABSENTTIMES, m_iAbsentTimes);
}


BEGIN_MESSAGE_MAP(CAttendCountShow, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CAttendCountShow 消息处理程序


void CAttendCountShow::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()
	UpdateData(TRUE);
	CWineShopManageApp *pApp = (CWineShopManageApp*)AfxGetApp();
	m_sEno = pApp->staff.getEno();
	m_sEname = pApp->staff.getEname();

	_RecordsetPtr pRst;

	CString sql;

	sql.Format("SELECT ENO,ATTENDCODE,COUNT(ATTENDCODE) FROM EMP_ATTENDINFO GROUP BY ENO, ATTENDCODE HAVING ENO = '%s'", m_sEno);

	pRst = pApp->dbOper.ExecuteWithResSQL(_bstr_t(sql));

	//CString codes[] = {"正常", "加班", "迟到", "早退", "旷工", "请假"};

	while(!pRst->GetadoEOF()){
		CString code = pRst->GetCollect(_variant_t("ATTENDCODE"));
		code.TrimRight();
		code.TrimLeft();
		CString number = pRst->GetCollect(_variant_t(long(2)));
		int num = _ttoi(number);
		if (code == "正常") m_iNormalTimes = num;
		else if (code == "加班") m_iOverTimes = num;
		else if (code == "迟到") m_iLateTimes = num;
		else if (code == "早退") m_iEarlyTimes = num;
		else if (code == "旷工") m_iAbsentTimes = num;
		else if (code == "请假") m_iLeaveTimes = num;
		pRst->MoveNext();
	}
	UpdateData(FALSE);
}
