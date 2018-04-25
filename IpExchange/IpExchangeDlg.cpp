
// IpExchangeDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "IpExchange.h"
#include "IpExchangeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CIpExchangeDlg 对话框




CIpExchangeDlg::CIpExchangeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CIpExchangeDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CIpExchangeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_DWORD_IN, m_edt_DwordIn);
	DDX_Control(pDX, IDC_EDIT_STRING_OUT, m_edt_StringOut);
	DDX_Control(pDX, IDC_EDIT_STRING_IN, m_edt_StringIn);
	DDX_Control(pDX, IDC_EDIT_DWORD_OUT, m_edtDwordOut);
}

BEGIN_MESSAGE_MAP(CIpExchangeDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON_EXCHANGE_DWORD, &CIpExchangeDlg::OnBnClickedButtonExchangeDword)
	ON_BN_CLICKED(IDC_BUTTON_EXCHANGE_STRING, &CIpExchangeDlg::OnBnClickedButtonExchangeString)
END_MESSAGE_MAP()


// CIpExchangeDlg 消息处理程序

BOOL CIpExchangeDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CIpExchangeDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CIpExchangeDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CIpExchangeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CIpExchangeDlg::OnBnClickedButtonExchangeDword()
{
	//将数字格式的IP转换成字符串格式的
	CString cstrDwordIn;
	m_edt_DwordIn.GetWindowText(cstrDwordIn);

	wstring strOut = ExchangeDwordToString(_wtoi(cstrDwordIn.GetBuffer()));
	LONGLONG llId = ConvertIpToCltId((PCHAR)strOut.c_str());
	m_edt_StringOut.SetWindowText(strOut.c_str());
}

void CIpExchangeDlg::OnBnClickedButtonExchangeString()
{
	//将字符串格式的IP转换成数字格式的
	CString cstrStringIn;
	m_edt_StringIn.GetWindowText(cstrStringIn);

	//LONGLONG llOut = ExchangeStringToDword(cstrStringIn.GetBuffer(), FALSE); 

	unsigned long lOut = inet_addr(cstrStringIn.GetBuffer());

	wstring strOut = L"";
	//_i64tow(llOut, (wchar_t*)strOut.c_str(), 10);
	_i64tow(lOut, (wchar_t*)strOut.c_str(), 10);
	m_edtDwordOut.SetWindowText(strOut.c_str());
}

std::wstring CIpExchangeDlg::ExchangeDwordToString( DWORD dwIp )
{
	wchar_t strIp[MAX_PATH] = {0};
	LONGLONG ullIp;
	BYTE bIP[8];

	ullIp = ntohl(dwIp);
	memcpy(bIP,&ullIp,sizeof(bIP));

	if (0 == ullIp)
	{
		return L"127.0.0.1";
	}

	if (ullIp > 0x100000000)
	{
		//ipV6
		wsprintf(strIp, L"%d.%d.%d.%d.%d.%d", bIP[5], bIP[4], bIP[3], bIP[2], bIP[1], bIP[0]);
	}
	else
	{
		//ipV4
		wsprintf(strIp, L"%d.%d.%d.%d", bIP[3], bIP[2], bIP[1], bIP[0]);
	}

	return (wstring)strIp;
}

LONGLONG CIpExchangeDlg::ExchangeStringToDword( wstring strIp, BOOL ipv6)
{
	LONGLONG ullIp = 0;
	int bIP[8];

	if (0 == strIp.length())
	{
		return 0;
	}

	if (ipv6)
	{
		//ipV6
		swscanf_s(strIp.c_str(), L"%d.%d.%d.%d.%d.%d",&bIP[5],&bIP[4],&bIP[3],&bIP[2],&bIP[1],&bIP[0]);
		ullIp = ((LONGLONG)bIP[5]<<40) | ((LONGLONG)bIP[4]<<32) | ((LONGLONG)bIP[3]<<24) | ((LONGLONG)bIP[2]<<16) | ((LONGLONG)bIP[1]<<8) | (LONGLONG)bIP[0];
	}
	else
	{
		//ipV4
		swscanf_s(strIp.c_str(), L"%d.%d.%d.%d",&bIP[3], &bIP[2], &bIP[1], &bIP[0]);
		ullIp = ((LONGLONG)bIP[3]<<24) | ((LONGLONG)bIP[2]<<16) | ((LONGLONG)bIP[1]<<8) | (LONGLONG)bIP[0];
	}	

	return ullIp;
}

LONGLONG CIpExchangeDlg::ConvertIpToCltId( PCHAR pcIp )
{
	LONGLONG llOut = 0;
	WCHAR cBufIn[MAX_PATH];
	PTCHAR pIn = cBufIn;
	PTCHAR pRc = NULL;

	ZeroMemory(cBufIn, MAX_PATH);
	wcscpy(cBufIn, (wchar_t*)pcIp);

	while(1)
	{
		pRc = wcsstr(pIn, L".");
		if(pRc)
		{
			*pRc = '\0';
			llOut |= _wtoi(pIn);
			llOut <<= 8;
			pIn = pRc + 1;
		}
		else
		{
			llOut |= _wtoi(pIn);
			break;
		}
	}

	return llOut;
}
