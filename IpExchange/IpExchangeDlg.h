
// IpExchangeDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include <string>

using namespace std;


// CIpExchangeDlg �Ի���
class CIpExchangeDlg : public CDialog
{
// ����
public:
	CIpExchangeDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_IPEXCHANGE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
