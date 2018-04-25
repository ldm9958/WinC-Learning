
// IpExchangeDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include <string>

using namespace std;


// CIpExchangeDlg 对话框
class CIpExchangeDlg : public CDialog
{
// 构造
public:
	CIpExchangeDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_IPEXCHANGE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edt_DwordIn;
	CEdit m_edt_StringOut;
	CEdit m_edt_StringIn;
	CEdit m_edtDwordOut;
	afx_msg void OnBnClickedButtonExchangeDword();
	afx_msg void OnBnClickedButtonExchangeString();

	LONGLONG ConvertIpToCltId(PCHAR pcIp);
	wstring ExchangeDwordToString(DWORD dwIp);
	LONGLONG ExchangeStringToDword(wstring strIp, BOOL ipv6);	
};
