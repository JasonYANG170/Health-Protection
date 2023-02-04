
// YANG RemindDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "YANG Remind.h"
#include "YANG RemindDlg.h"
#include "afxdialogex.h"
#define WM_SHOWTASK (WM_USER+200) //注意n换成数字，n的大小应大于100

#include <shellapi.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
NOTIFYICONDATA nid;
BOOL isNotify;


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CYANGRemindDlg 对话框



CYANGRemindDlg::CYANGRemindDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_YANG_REMIND_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CYANGRemindDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CYANGRemindDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CYANGRemindDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CYANGRemindDlg 消息处理程序

BOOL CYANGRemindDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	isNotify = false;


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CYANGRemindDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CYANGRemindDlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CYANGRemindDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CYANGRemindDlg::OnBnClickedButton1()
{
		// TODO: 在此添加控件通知处理程序代码   
		if (!isNotify)
		{
			nid.cbSize = (DWORD)sizeof(NOTIFYICONDATA);
			nid.hWnd = this->m_hWnd;
			nid.uID = IDR_MAINFRAME;
			nid.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP | NIF_INFO;
			nid.uCallbackMessage = WM_SHOWTASK;//自定义的消息名称,注意:这里的消息是用户自定义消息  
			nid.hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_MAINFRAME));
			wcscpy_s(nid.szTip, _T("VC系统托盘程序"));//信息提示条为"计划任务提醒"  
			wcscpy_s(nid.szInfo, _T("标题"));
			wcscpy_s(nid.szInfoTitle, _T("内容"));
			nid.dwInfoFlags = NIIF_INFO;
			//nid.uTimeout = 5;
			Shell_NotifyIcon(NIM_ADD, &nid);//在托盘区添加图标  
			//AnimateWindow(5000, AW_HIDE | AW_BLEND);      //可以缓慢消失窗口  
			ShowWindow(SW_HIDE);//隐藏主窗口  
			Shell_NotifyIcon(NIM_DELETE, &nid);
			//KillTimer(0);
		}
		//AnimateWindow(1000,AW_HIDE|AW_BLEND);      //可以缓慢消失窗口  
	   // KillTimer(0);  
		//ShowWindow(SW_HIDE);//隐藏主窗口  


	// TODO: 在此添加控件通知处理程序代码
}
