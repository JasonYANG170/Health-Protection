
// YANG RemindDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "YANG Remind.h"
#include "YANG RemindDlg.h"
#include "afxdialogex.h"
#include "tlhelp32.h"
#include <json/json.h>
#include <fstream>
#include "afxdialogex.h"
#include "mmsystem.h"
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
HWND g_hWndNotify;
CString g_strUrl;
using namespace Json;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#define WM_SHOWTASK (WM_USER+200) //注意n换成数字，n的大小应大于100
#define TM_MSG 10000
#define TM_MSG1 50000
#include <shellapi.h>
int xz = 0;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
NOTIFYICONDATA nid;
BOOL isNotify;
CString num = _T("");
CString num2 = _T("");
CString num31 = _T("");
CString num313 = _T("");
CString net = _T("");
int num9;
int num29;
int open;
CString tonken1 = _T("");
CString tonken2 = _T("");
CString program;
CString edition=_T("V5.2.2");
CString xingzuo1 = _T("");
// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

//执行延时操作的地方
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#pragma comment( linker, "/subsystem:/"windows/" /entry:/"mainCRTStartup/"" ) // 设置入口地址  
#include   <windows.h>     
#include   <stdio.h>     

//#define   COMMENDLINE   "REG ADD HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize /v AppsUseLightTheme /t REG_DWORD /d 0 /f&REG ADD HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize /v SystemUsesLightTheme /t REG_DWORD /d 0 /f"

//调用命令行命令而不显示命令行窗口  
#include <afxinet.h>
CString CYANGRemindDlg::UTF8ToUnicode(char* UTF8)
{

	DWORD dwUnicodeLen;        //转换后Unicode的长度
	TCHAR* pwText;            //保存Unicode的指针
	CString strUnicode;        //返回值
	//获得转换后的长度，并分配内存
	dwUnicodeLen = MultiByteToWideChar(CP_UTF8, 0, UTF8, -1, NULL, 0);
	pwText = new TCHAR[dwUnicodeLen];
	if (!pwText)
	{
		return strUnicode;
	}
	//转为Unicode
	MultiByteToWideChar(CP_UTF8, 0, UTF8, -1, pwText, dwUnicodeLen);
	//转为CString
	strUnicode.Format(_T("%s"), pwText);
	//清除内存
	delete[]pwText;
	//返回转换好的Unicode字串
	return strUnicode;
}
BOOL system_hide(char* CommandLine)
{
	SECURITY_ATTRIBUTES   sa;
	HANDLE   hRead, hWrite;

	sa.nLength = sizeof(SECURITY_ATTRIBUTES);
	sa.lpSecurityDescriptor = NULL;
	sa.bInheritHandle = TRUE;
	if (!CreatePipe(&hRead, &hWrite, &sa, 0))
	{
		return   FALSE;
	}

	STARTUPINFO   si;
	PROCESS_INFORMATION   pi;
	si.cb = sizeof(STARTUPINFO);
	GetStartupInfo(&si);
	si.hStdError = hWrite;
	si.hStdOutput = hWrite;
	si.wShowWindow = SW_HIDE;
	si.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;
	int len = MultiByteToWideChar(CP_ACP, 0, CommandLine, -1, NULL, 0);
	wchar_t* wstr = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, CommandLine, -1, wstr, len);

	//关键步骤，CreateProcess函数参数意义请查阅MSDN     
	if (!CreateProcess(NULL, wstr, NULL, NULL, TRUE, NULL, NULL, NULL, &si, &pi))
	{
		return   FALSE;
	}
	CloseHandle(hWrite);

	char   buffer[4096] = { 0 };
	DWORD   bytesRead;
	while (true)
	{
		memset(buffer, 0, strlen(buffer));
		if (ReadFile(hRead, buffer, 4095, &bytesRead, NULL) == NULL)
			break;
		//buffer中就是执行的结果，可以保存到文本，也可以直接输出     
		//printf(buffer);//这行注释掉就可以了     
		Sleep(100);
	}
	return   TRUE;
}
UINT  ThreadFunc(LPVOID  lParam)
{

	tonken1 = AfxGetApp()->GetProfileString(_T("Settings"), _T("LocalRecPath"), _T("C:\\"));//_T("C:\\")为默认值
	tonken2 = AfxGetApp()->GetProfileString(_T("Settings"), _T("LocalRecPath2"), _T("C:\\"));//_T("C:\\")为默认值
	num9 = _ttoi(tonken1);
	num29 = _ttoi(tonken2);
	while (true) {
		for (open; open == 1; open + 0)
		{
			CTime tm; tm = CTime::GetCurrentTime();
			int hour = tm.GetHour();
			CString tempPort;
			tempPort.Format(_T("%d"), hour);

			if (hour == num) {
				system_hide("REG ADD HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize /v AppsUseLightTheme /t REG_DWORD /d 0 /f");

				system_hide("REG ADD HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize /v SystemUsesLightTheme /t REG_DWORD /d 0 /f");

			}
			else if (hour == num2)
			{
				system_hide("REG ADD HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize /v AppsUseLightTheme /t REG_DWORD /d 1 /f");

				system_hide("REG ADD HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize /v SystemUsesLightTheme /t REG_DWORD /d 1 /f");

			}

		}
		Sleep(1000);
	}
}

void CYANGRemindDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (nIDEvent==TM_MSG)
	{
		//具体实现
		SendMessage(WM_CLOSE);
		CDialogEx::OnTimer(TM_MSG);
	}else
	if (nIDEvent==1)
	{
		if (xz == 1) {
			OnBnClickedButton3();
		}
		else if (xz == 2) {
			OnBnClickedButton2();
		}
		else if(xz==3)
		{
			OnBnClickedButton1();
		}
		else if (xz == 4) {
			OnBnClickedButton12();
		}
		else if (xz == 5) {
			OnBnClickedButton18();
		}
		else if (xz == 6) {
			OnBnClickedButton26();
		}
		else if (xz == 7) {
			xinzuo27();
		}
	
		CDialogEx::OnTimer(1);
	}

}

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
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void On15();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CAboutDlg::OnBnClickedButton1)
	ON_COMMAND(15, &CAboutDlg::On15)
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
	DDX_Control(pDX, ID_POWERBOOT, PowerBootButton);
	DDX_Control(pDX, IDC_MFCMENUBUTTON1, m_menu);
}

BEGIN_MESSAGE_MAP(CYANGRemindDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON5, &CYANGRemindDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CYANGRemindDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON1, &CYANGRemindDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CYANGRemindDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON8, &CYANGRemindDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON7, &CYANGRemindDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON4, &CYANGRemindDlg::OnBnClickedButton4)
	ON_BN_CLICKED(ID_POWERBOOT, &CYANGRemindDlg::OnBnClickedPowerboot)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON9, &CYANGRemindDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON3, &CYANGRemindDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON10, &CYANGRemindDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_CHECK1, &CYANGRemindDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK3, &CYANGRemindDlg::OnBnClickedCheck3)
	ON_BN_CLICKED(IDC_BUTTON11, &CYANGRemindDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &CYANGRemindDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON13, &CYANGRemindDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON14, &CYANGRemindDlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON15, &CYANGRemindDlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON16, &CYANGRemindDlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON17, &CYANGRemindDlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON20, &CYANGRemindDlg::OnBnClickedButton20)
	ON_BN_CLICKED(IDC_BUTTON22, &CYANGRemindDlg::OnBnClickedButton22)
	ON_BN_CLICKED(IDC_BUTTON21, &CYANGRemindDlg::OnBnClickedButton21)
	ON_BN_CLICKED(IDC_BUTTON23, &CYANGRemindDlg::OnBnClickedButton23)
	ON_BN_CLICKED(IDC_BUTTON24, &CYANGRemindDlg::OnBnClickedButton24)
	ON_BN_CLICKED(IDC_BUTTON25, &CYANGRemindDlg::OnBnClickedButton25)
	ON_BN_CLICKED(IDC_BUTTON18, &CYANGRemindDlg::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON19, &CYANGRemindDlg::OnBnClickedButton19)
	ON_BN_CLICKED(IDC_BUTTON26, &CYANGRemindDlg::OnBnClickedButton26)
	ON_BN_CLICKED(IDC_MFCMENUBUTTON1, &CYANGRemindDlg::OnBnClickedMfcmenubutton1)
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
	split.SetDropDownMenu(IDR_MENU1, 0);
	CMenu* pMenu = new CMenu;

	pMenu->LoadMenu(IDR_MENU1);  // 载入菜单资源

	m_menu.m_hMenu = pMenu->GetSubMenu(0)->GetSafeHmenu();  // 将CMFCMenuButton和Menu IDR_MENU1关联
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
	num = AfxGetApp()->GetProfileString(_T("Settings"), _T("LocalRecPath"), _T("C:\\"));//_T("C:\\")为默认值
	num2 = AfxGetApp()->GetProfileString(_T("Settings"), _T("LocalRecPath2"), _T("C:\\"));//_T("C:\\")为默认值
	num31 = AfxGetApp()->GetProfileString(_T("Settings"), _T("LocalRecPath3"), _T("C:\\"));//_T("C:\\")为默认值
	num313 = AfxGetApp()->GetProfileString(_T("Settings"), _T("LocalRecPath313"), _T("C:\\"));//_T("C:\\")为默认值
	xingzuo1 = AfxGetApp()->GetProfileString(_T("Settings"), _T("LocalRecPathxz"), _T("C:\\"));//_T("C:\\")为默认值
	if (!isNotify)
	{
		nid.cbSize = (DWORD)sizeof(NOTIFYICONDATA);
		nid.hWnd = this->m_hWnd;
		nid.uID = IDR_MAINFRAME;
		nid.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP | NIF_INFO;
		nid.uCallbackMessage = WM_SHOWTASK;//自定义的消息名称,注意:这里的消息是用户自定义消息  
		nid.hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_MAINFRAME));
		wcscpy_s(nid.szTip, _T("YANG Remind程序"));//信息提示条为"计划任务提醒"  
		wcscpy_s(nid.szInfo, num);
		wcscpy_s(nid.szInfoTitle, num2);
		nid.dwInfoFlags = NIIF_INFO;
		//nid.uTimeout = 5;
		Shell_NotifyIcon(NIM_ADD, &nid);//在托盘区添加图标  
		//AnimateWindow(5000, AW_HIDE | AW_BLEND);      //可以缓慢消失窗口  

		Shell_NotifyIcon(NIM_DELETE, &nid);
		//KillTimer(0);
		//ToTray();
		//ShowWindow(SW_HIDE);//隐藏主窗口  
		int num3;

		num3 = _ttoi(num31);
		int num31;

		num31 = _ttoi(num313);
		if (num3 == 1) {
			if (num31 == 0)
			{
				SetTimer(TM_MSG, 5000, NULL);
				KillTimer(TM_MSG);
			}
			else {
				SetTimer(TM_MSG, 5000, NULL);
			}
		}
		else if (num3 == 2)
		{
			if (num31 == 0) {
				netlist();
				SetTimer(TM_MSG, 5000, NULL);
				KillTimer(TM_MSG);
			}
			else
			{
				netlist();
				SetTimer(TM_MSG, 5000, NULL);

			}
		}

	}
	AfxBeginThread(ThreadFunc, (LPVOID)this);//启动新的线程
	CInternetSession session(_T("HttpClient"));
	TCHAR* url = _T("https://api.vvhan.com/api/qqsc?key=969c8d1f86b653696f929406faa0bbc0");
	CHttpFile* pfile = (CHttpFile*)session.OpenURL(url);
	DWORD dwStatusCode;
	pfile->QueryInfoStatusCode(dwStatusCode);
	if (dwStatusCode == HTTP_STATUS_OK)
	{
		CString content4;
		CString data;
		while (pfile->ReadString(data))
		{
			content4 += data;
		}
		char* pch;
		pch = new char[content4.GetLength() * sizeof(TCHAR) + 1];
		memcpy(pch, content4, content4.GetLength() * sizeof(TCHAR));
		content4 = UTF8ToUnicode(pch);//转换编码，不然就乱码了

		CString str3 = content4;
		str3.ReleaseBuffer();
		Json::Reader reader23;
		Json::Value root23;
		CString temp23;
		CString temp223;
		CString temp323;
		USES_CONVERSION;
		//using namespace std;
		//string str33(CW2A(str3.GetString()));

		const char* cJson1 = T2A(str3.GetBuffer(0));
		str3.ReleaseBuffer();
		if (reader23.parse(cJson1, root23)) {
			temp23 = root23["text"].asCString();

		}
		if (edition == temp23) {
			
		}
		else
		{
			CString a = _T("已发布新版本\"");
			CString a1 = _T("\"请尽快更新！");
			MessageBox(a+temp23+a1);
		}
	}
	pfile->Close();
	delete pfile;
	session.Close();

}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CYANGRemindDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
void CYANGRemindDlg::TZ() {
	if (!isNotify)
	{
		nid.cbSize = (DWORD)sizeof(NOTIFYICONDATA);
		nid.hWnd = this->m_hWnd;
		nid.uID = IDR_MAINFRAME;
		nid.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP | NIF_INFO;
		nid.uCallbackMessage = WM_SHOWTASK;//自定义的消息名称,注意:这里的消息是用户自定义消息  
		nid.hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_MAINFRAME));
		wcscpy_s(nid.szTip, _T("YANG Remind程序"));//信息提示条为"计划任务提醒"  
		wcscpy_s(nid.szInfo, num);
		wcscpy_s(nid.szInfoTitle, num2);
		nid.dwInfoFlags = NIIF_INFO;
		//nid.uTimeout = 5;
		Shell_NotifyIcon(NIM_ADD, &nid);//在托盘区添加图标  
		//AnimateWindow(5000, AW_HIDE | AW_BLEND);      //可以缓慢消失窗口  
		//ShowWindow(SW_HIDE);//隐藏主窗口  
		Shell_NotifyIcon(NIM_DELETE, &nid);
		//KillTimer(0);
	}
}


void CYANGRemindDlg::OnBnClickedButton1()
{
	TZ();
	xz = 3;

// TODO: 在此添加控件通知处理程序代码
}




#define TOOLTIPS_NAME_	"XXXX"
//最小化到托盘函数
void CYANGRemindDlg::ToTray()
{
	NOTIFYICONDATA nid;
	nid.cbSize = (DWORD)sizeof(NOTIFYICONDATA);
	nid.hWnd = this->m_hWnd;
	nid.uID = IDR_MAINFRAME;
	nid.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
	nid.uCallbackMessage = WM_SHOWTASK;//自定义的消息名称
	nid.hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_MAINFRAME));
	wcscpy_s(nid.szTip, _T(TOOLTIPS_NAME_)); //信息提示条
	Shell_NotifyIcon(NIM_ADD, &nid); //在托盘区添加图标
	ShowWindow(SW_HIDE); //隐藏主窗口
}
#define TOOLTIPS_NAME_	"YANG Remind"

//删除托盘图标函数
void CYANGRemindDlg::DeleteTray()
{
	NOTIFYICONDATA nid;
	nid.cbSize = (DWORD)sizeof(NOTIFYICONDATA);
	nid.hWnd = this->m_hWnd;
	nid.uID = IDR_MAINFRAME;
	nid.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
	nid.uCallbackMessage = WM_SHOWTASK; //自定义的消息名称
	nid.hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_MAINFRAME));
	wcscpy_s(nid.szTip, _T(TOOLTIPS_NAME_)); //信息提示条为“计划任务提醒”
	Shell_NotifyIcon(NIM_DELETE, &nid); //在托盘区删除图标
}

afx_msg LRESULT CYANGRemindDlg::OnShowtask(WPARAM wParam, LPARAM lParam)
{
	if (wParam != IDR_MAINFRAME)
		return 1;
	switch (lParam)
	{
	case WM_RBUTTONUP://右键起来时弹出快捷菜单，这里只有一个“关闭”
	{
		LPPOINT lpoint = new tagPOINT;
		::GetCursorPos(lpoint);//得到鼠标位置
		CMenu menu;
		menu.CreatePopupMenu();//声明一个弹出式菜单


		menu.AppendMenu(MF_STRING, WM_DESTROY, _T("关闭")); //增加菜单项“关闭”，点击则发送消息WM_DESTROY给主窗口（已隐藏），将程序结束。
		menu.TrackPopupMenu(TPM_LEFTALIGN, lpoint->x, lpoint->y, this); //确定弹出式菜单的位置
		HMENU hmenu = menu.Detach();
		menu.DestroyMenu(); //资源回收
		delete lpoint;
	} break;
	case WM_LBUTTONDBLCLK: //双击左键的处理
	{
		this->ShowWindow(SW_SHOW);//简单的显示主窗口完事儿
		DeleteTray();
	} break;
	default: break;
	}
	return 0;
}




void CYANGRemindDlg::OnBnClickedPowerboot()
{
	// TODO: 在此添加控件通知处理程序代码
	HKEY hKey;
	//找到系统的启动项
	CString lpRun = _T("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run");
	//打开启动项
	long lRet = RegOpenKeyEx(HKEY_CURRENT_USER, lpRun, 0, KEY_ALL_ACCESS, &hKey);
	if (lRet != ERROR_SUCCESS)
		MessageBox(_T("打开启动项失败"));
	//找到程序自身路径
	TCHAR pFileName[MAX_PATH] = {};
	GetModuleFileName(NULL, pFileName, MAX_PATH);
	//判断是否已经设置开机启动
	TCHAR PowerBoot[MAX_PATH] = {};
	DWORD nLongth = MAX_PATH;
	long result = RegGetValue(hKey, NULL, _T("PowerBoot"), RRF_RT_REG_SZ, 0, PowerBoot, &nLongth);
	if (result == ERROR_SUCCESS)
	{
		//自启状态;
		//取消自动启动
		lRet = RegDeleteValue(hKey, _T("PowerBoot"));
		if (lRet == ERROR_SUCCESS)
		{
			MessageBox(_T("关闭自启成功"));
			PowerBootButton.SetWindowText(_T("未自启状态"));
		}
	}
	else
	{
		//未自启状态
		//设置自启
		lRet = RegSetValueEx(hKey, _T("PowerBoot"), 0, REG_SZ, (LPBYTE)pFileName, (lstrlen(pFileName) + 1) * sizeof(TCHAR));
		if (lRet == ERROR_SUCCESS)
		{
			MessageBox(_T("设置自启成功"));
			PowerBootButton.SetWindowText(_T("自启状态"));
		}
	}
	//关闭注册表
	RegCloseKey(hKey);

}


void CYANGRemindDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	MessageBox(_T("已开启最小化，系统托盘中左键双击图标打开程序，右键图标关闭程序"));
	ToTray();
}


void CYANGRemindDlg::OnBnClickedButton5()
{
	//CString tonken1 = _T("");
	GetDlgItem(IDC_EDIT2)->GetWindowText(num2);
	//num == _ttoi(tonken1);
	//CString tonken2 = _T("");
	GetDlgItem(IDC_EDIT1)->GetWindowText(num);
	//num2 == _ttoi(tonken2);
	AfxGetApp()->WriteProfileString(_T("Settings"), _T("LocalRecPath"), num);//_localRecPath就是要保存的信息，Settings为注册表子键，LocalRecPath即子键的键值名
	AfxGetApp()->WriteProfileString(_T("Settings"), _T("LocalRecPath2"), num2);//_localRecPath就是要保存的信息，Settings为注册表子键，LocalRecPath即子键的键值名
	MessageBox(_T("保存成功，点击<预览>查看吧"), NULL, MB_OK);
	// TODO: 在此添加控件通知处理程序代码
}



void CYANGRemindDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
//	Delete_Value(_T("HKEY_CURRENT_USER\\Software\\应用程序向导生成的本地应用程序"), _T("YANG Remind"));


	CRegKey mykey;
	if (mykey.Open(HKEY_CURRENT_USER, _T("Software\\应用程序向导生成的本地应用程序")) != ERROR_SUCCESS)
	{
		MessageBox(_T("删除失败"));
	}
	else
	{
		if (mykey.RecurseDeleteKey(_T("YANG Remind")) != ERROR_SUCCESS)

		{
			MessageBox(_T("删除失败"));
		}
		MessageBox(_T("删除成功"));
	}
	mykey.Close();

}
//定义Timer事件



void CYANGRemindDlg::OnBnClickedButton7()
{
	KillTimer(TM_MSG);
	num313 = _T("0");
	AfxGetApp()->WriteProfileString(_T("Settings"), _T("LocalRecPath313"), num313);//_localRecPath就是要保存的信息，Settings为注册表子键，LocalRecPath即子键的键值名
	// TODO: 在此添加控件通知处理程序代码
	MessageBox(_T("自动关闭程序设置已关闭"));
}


void CYANGRemindDlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	num313 = _T("1");
	AfxGetApp()->WriteProfileString(_T("Settings"), _T("LocalRecPath313"), num313);//_localRecPath就是要保存的信息，Settings为注册表子键，LocalRecPath即子键的键值名
	MessageBox(_T("警告（重大操作提示）：自动关闭程序设置已开启，下次打开程序会在弹窗结束后自动关闭程序，如需关闭请在程序关闭前点击<取消自动关闭>"));
}





//void CAboutDlg::OnBnClickedButton1()
//{
	// TODO: 在此添加控件通知处理程序代码
	//system("start https://github.com/JasonYANG170/YANG-Remind/releases");
//}


void CYANGRemindDlg::netlist()
{
	// TODO: 在此添加控件通知处理程序代码
	// TODO: 在此添加控件通知处理程序代码
	CInternetSession session(_T("HttpClient"));
	TCHAR* url = _T("https://v1.jinrishici.com/shuqing/shanggan");
	CHttpFile* pfile = (CHttpFile*)session.OpenURL(url);
	DWORD dwStatusCode;
	pfile->QueryInfoStatusCode(dwStatusCode);
	if (dwStatusCode == HTTP_STATUS_OK)
	{
		CString content4;
		CString data;
		while (pfile->ReadString(data))
		{
			content4 += data;
		}
		char* pch;
		pch = new char[content4.GetLength() * sizeof(TCHAR) + 1];
		memcpy(pch, content4, content4.GetLength() * sizeof(TCHAR));
		content4 = UTF8ToUnicode(pch);//转换编码，不然就乱码了

		CString str3 = content4;
		str3.ReleaseBuffer();
		Json::Reader reader23;
		Json::Value root23;
		CString temp23;
		CString temp223;
		CString temp323;
		USES_CONVERSION;
		//using namespace std;
		//string str33(CW2A(str3.GetString()));

		const char* cJson1 = T2A(str3.GetBuffer(0));
        str3.ReleaseBuffer();
        if (reader23.parse(cJson1, root23)) {
            temp23 = root23["content"].asCString();
            temp223 = root23["origin"].asCString();
            temp323 = root23["author"].asCString();
        }
 
		
		temp223 = temp223 + "  作者：" + temp323;
		
		num2 = temp23;
		AfxGetApp()->WriteProfileString(_T("Settings"), _T("LocalRecPath2"), num2);//_localRecPath就是要保存的信息，Settings为注册表子键，LocalRecPath即子键的键值名
		num = temp223;
		AfxGetApp()->WriteProfileString(_T("Settings"), _T("LocalRecPath"), num);//_localRecPath就是要保存的信息，Settings为注册表子键，LocalRecPath即子键的键值名
	}
	pfile->Close();
	delete pfile;
	session.Close();
	//char* str = "content春如旧。人空瘦。泪痕红浥鲛绡透。";
	//	"origin" : "钗头凤·红酥手",
	//	"author" : "陆游",
	//	"category" : "古诗文-抒情-伤感";
	TZ();

}


void CYANGRemindDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	netlist();
	num31 = _T("2");
	AfxGetApp()->WriteProfileString(_T("Settings"), _T("LocalRecPath3"), num31);//_localRecPath就是要保存的信息，Settings为注册表子键，LocalRecPath即子键的键值名
	xz = 2;
}


void CYANGRemindDlg::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	CAboutDlg dlgAbout;
	dlgAbout.DoModal();
}


void CYANGRemindDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	xz = 1;
	CInternetSession session(_T("HttpClient"));
	TCHAR* url = _T("https://api.vvhan.com/api/en?type=sj");
	CHttpFile* pfile = (CHttpFile*)session.OpenURL(url);
	DWORD dwStatusCode;
	pfile->QueryInfoStatusCode(dwStatusCode);
	if (dwStatusCode == HTTP_STATUS_OK)
	{
		CString content;
		CString data;
		while (pfile->ReadString(data))
		{
			content += data;
		}
		char* pch;
		pch = new char[content.GetLength() * sizeof(TCHAR) + 1];
		memcpy(pch, content, content.GetLength() * sizeof(TCHAR));
		content = UTF8ToUnicode(pch);//转换编码，不然就乱码了
		//AfxMessageBox(content);
		//CString content2;
	//	content2 = content.Left(content.Find('r'));
	//	content2 = content2.Right(content.GetLength() - 1 - content.ReverseFind(':'));
		//CString contenta;
	//	contenta = content.Left(content.Find('a'));
		//contenta = content.Right(content.GetLength() - 1 - content.ReverseFind(':'));

		int start = content.Find(_T("zh\":\""));
		int end = content.Find(_T("\",\"en\":"));
		CString result = content.Mid(start + 5, end - start - 5);
		int start1 = content.Find(_T("en\":\""));
		int end1 = content.Find(_T("\",\"pic\":"));
		CString result1 = content.Mid(start1 + 5, end1 - start1 - 5);
		//temp2 = temp2 + "\r\n作者：" + temp3;

		//CString strLeftString;
			//int nLengthLeft = 0;
			//nLengthLeft = content.Find(_T("。"));//获取等号的位置
			//AfxMessageBox(content2);
		//	strLeftString = content.Left(nLengthLeft);//获得等号左面的字符串
		//	CString strRightString;
			//int nLength = strLeftString.GetLength();
			//nLengthLeft = 0;
		//	nLength = strLeftString.Find(_T("origin"));
		//	strRightString = strLeftString.Right(nLength - nLengthLeft - 1);//获得等号右面的字符串

		//	AfxMessageBox(result);

		//	AfxMessageBox(result1);
			//AfxMessageBox(strRightString);
		num2 = result1;
		AfxGetApp()->WriteProfileString(_T("Settings"), _T("LocalRecPath2"), num2);//_localRecPath就是要保存的信息，Settings为注册表子键，LocalRecPath即子键的键值名
		num = result;
		AfxGetApp()->WriteProfileString(_T("Settings"), _T("LocalRecPath"), num);//_localRecPath就是要保存的信息，Settings为注册表子键，LocalRecPath即子键的键值名
		TZ();
		//ssssssssssssssssdasd
	}
	pfile->Close();
	delete pfile;
	session.Close();
	//char* str = "content春如旧。人空瘦。泪痕红浥鲛绡透。";
	//	"origin" : "钗头凤·红酥手",
	//	"author" : "陆游",
	//	"category" : "古诗文-抒情-伤感";
}


void CAboutDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	system("start https://github.com/JasonYANG170/YANG-Remind/releases");
}
int anjian = 0;

void CYANGRemindDlg::OnBnClickedButton10()
{
	// TODO: 在此添加控件通知处理程序代码
		// TODO: 在此添加控件通知处理程序代码
	//CString tempPort;
	//tempPort.Format(_T("%d"), xz);  //Use Unicode Character Set
	//MessageBox(tempPort);
	int time;
	CString time1;
	GetDlgItem(IDC_EDIT3)->GetWindowText(time1);
	time = _ttoi(time1);
	if (anjian == 1) {
		time = time * 3600000;
	}
	else
	{
		time = time * 60000;
	}
	SetTimer(1, time, NULL);
}


void CYANGRemindDlg::OnBnClickedCheck1()
{
	// TODO: 在此添加控件通知处理程序代码
	anjian == 1;
}


void CYANGRemindDlg::OnBnClickedCheck3()
{
	// TODO: 在此添加控件通知处理程序代码
	anjian == 0;
}


void CYANGRemindDlg::OnBnClickedButton11()
{
	KillTimer(1);
	// TODO: 在此添加控件通知处理程序代码
}


void CYANGRemindDlg::OnBnClickedButton12()
{
	xz = 4;
	// TODO: 在此添加控件通知处理程序代码
	CInternetSession session(_T("HttpClient"));
	TCHAR* url = _T("https://api.vvhan.com/api/weather");
	CHttpFile* pfile = (CHttpFile*)session.OpenURL(url);
	DWORD dwStatusCode;
	pfile->QueryInfoStatusCode(dwStatusCode);
	if (dwStatusCode == HTTP_STATUS_OK)
	{
		CString content;
		CString data;
		while (pfile->ReadString(data))
		{
			content += data;
		}
		char* pch;
		pch = new char[content.GetLength() * sizeof(TCHAR) + 1];
		memcpy(pch, content, content.GetLength() * sizeof(TCHAR));
		content = UTF8ToUnicode(pch);//转换编码，不然就乱码了
		//AfxMessageBox(content);
		//CString content2;
	//	content2 = content.Left(content.Find('r'));
	//	content2 = content2.Right(content.GetLength() - 1 - content.ReverseFind(':'));
		//CString contenta;
	//	contenta = content.Left(content.Find('a'));
		//contenta = content.Right(content.GetLength() - 1 - content.ReverseFind(':'));

		CString str = content;
		Json::Reader reader;
		Json::Value root;
		CString temp;
		CString temp2;
		CString temp3;
		CString temp4;
		CString temp5;
		CString temp6;
		USES_CONVERSION;
		char* cJson = T2A(str.GetBuffer(0));
		str.ReleaseBuffer();
		if (reader.parse(cJson, root)) {
			temp = root["city"].asCString();
			temp2 = root["info"]["type"].asCString();
			temp3 = root["info"]["high"].asCString();
			temp4 = root["info"]["low"].asCString();
			temp5 = root["info"]["tip"].asCString();
			temp6 = root["info"]["air"]["aqi_name"].asCString();
		}
		temp = temp + " " + temp2+" "+temp3+" "+temp4+" 空气质量 "+temp6;

		//CString strLeftString;
			//int nLengthLeft = 0;
			//nLengthLeft = content.Find(_T("。"));//获取等号的位置
			//AfxMessageBox(content2);
		//	strLeftString = content.Left(nLengthLeft);//获得等号左面的字符串
		//	CString strRightString;
			//int nLength = strLeftString.GetLength();
			//nLengthLeft = 0;
		//	nLength = strLeftString.Find(_T("origin"));
		//	strRightString = strLeftString.Right(nLength - nLengthLeft - 1);//获得等号右面的字符串
		//MessageBox(temp);
		num2 = temp5;
		AfxGetApp()->WriteProfileString(_T("Settings"), _T("LocalRecPath2"), num2);//_localRecPath就是要保存的信息，Settings为注册表子键，LocalRecPath即子键的键值名
		num = temp;
		AfxGetApp()->WriteProfileString(_T("Settings"), _T("LocalRecPath"), num);//_localRecPath就是要保存的信息，Settings为注册表子键，LocalRecPath即子键的键值名
	}
	pfile->Close();
	delete pfile;
	session.Close();
	TZ();

}



void CYANGRemindDlg::OnBnClickedButton13()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CYANGRemindDlg::OnBnClickedButton14()
{
	open = 1;
	MessageBox(_T("已开启"), NULL, MB_OK);
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_EDIT4)->GetWindowText(tonken1);
	GetDlgItem(IDC_EDIT5)->GetWindowText(tonken2);
	MessageBox(_T("保存成功，请在程序设置中<开启定时>即可定时切换。"), NULL, MB_OK);
	AfxGetApp()->WriteProfileString(_T("Settings"), _T("LocalRecPath"), tonken1);//_localRecPath就是要保存的信息，Settings为注册表子键，LocalRecPath即子键的键值名
	AfxGetApp()->WriteProfileString(_T("Settings"), _T("LocalRecPath2"), tonken2);//_localRecPath就是要保存的信息，Settings为注册表子键，LocalRecPath即子键的键值名
}


void CYANGRemindDlg::OnBnClickedButton15()
{
	// TODO: 在此添加控件通知处理程序代码
	// 	open = 0;
	MessageBox(_T("已关闭"), NULL, MB_OK);
	// TODO: 在此添加控件通知处理程序代码
	CRegKey mykey;
	if (mykey.Open(HKEY_CURRENT_USER, _T("Software\\应用程序向导生成的本地应用程序")) != ERROR_SUCCESS)
	{
		MessageBox(_T("删除失败"));
	}
	else
	{
		if (mykey.RecurseDeleteKey(_T("ww")) != ERROR_SUCCESS)

		{
			MessageBox(_T("删除失败"));
		}
		MessageBox(_T("删除成功"));
	}
	mykey.Close();
}


void CYANGRemindDlg::OnBnClickedButton16()
{
	// TODO: 在此添加控件通知处理程序代码
	system_hide("REG ADD HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize /v AppsUseLightTheme /t REG_DWORD /d 1 /f");

	system_hide("REG ADD HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize /v SystemUsesLightTheme /t REG_DWORD /d 1 /f");
	MessageBox(_T("已变更浅色模式"), NULL, MB_OK);
}


void CYANGRemindDlg::OnBnClickedButton17()
{
	// TODO: 在此添加控件通知处理程序代码
	system_hide("REG ADD HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize /v AppsUseLightTheme /t REG_DWORD /d 0 /f");

	system_hide("REG ADD HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize /v SystemUsesLightTheme /t REG_DWORD /d 0 /f");
	MessageBox(_T("已变更深色模式"), NULL, MB_OK);
}

void KillProcess(CString sExeName)
{
	HANDLE hSnapShot = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hSnapShot == 0)
		return;
	PROCESSENTRY32 thePE;
	thePE.dwSize = sizeof(PROCESSENTRY32);


	//遍历正在运行的第一个系统进程


	bool Status = Process32First(hSnapShot, &thePE);
	bool bHaveFlag = false;
	DWORD ProcessID = 0;


	while (Status)
	{
		//遍历正在运行的下一个系统进程  
		Status = Process32Next(hSnapShot, &thePE);
		//找到相应的进程 **.exe


		// if(0 == wcscmp(thePE.szExeFile,L""))
		CString sFindName = thePE.szExeFile;
		CString sTemp = sExeName.Mid(0, sFindName.GetLength());


		if (sFindName == sTemp)
		{
			bHaveFlag = true;
			ProcessID = thePE.th32ProcessID;


			//结束指定的进程 ProcessID
			if (!TerminateProcess(OpenProcess(PROCESS_TERMINATE || PROCESS_QUERY_INFORMATION, false, ProcessID), 0))
			{
				//AfxMessageBox(L"无法终止指定的进程！", MB_ICONWARNING || MB_OK);
			}
			else
			{
				//AfxMessageBox(L"进程结束！", MB_ICONWARNING || MB_OK);
				break;
			}
		}
	}
	CloseHandle(hSnapShot);
}

void CYANGRemindDlg::OnBnClickedButton20()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_EDIT6)->GetWindowText(program);
}


void CYANGRemindDlg::OnBnClickedButton22()
{
	// TODO: 在此添加控件通知处理程序代码
	int time;
	CString time1;
	GetDlgItem(IDC_EDIT7)->GetWindowText(time1);
	time = _ttoi(time1);
	time = time * 60000;
	SetTimer(2, time, NULL);
}


void CYANGRemindDlg::OnBnClickedButton21()
{
	// TODO: 在此添加控件通知处理程序代码
	KillProcess(program);
}
UINT  ThreadFunc2(LPVOID  lParam)
{

	while (true) {
		KillProcess(program);
		Sleep(1000);
	}
}


void CYANGRemindDlg::OnBnClickedButton23()
{
	// TODO: 在此添加控件通知处理程序代码
	AfxBeginThread(ThreadFunc2, (LPVOID)this);//启动新的线程
}


void CYANGRemindDlg::OnBnClickedButton24()
{
	// TODO: 在此添加控件通知处理程序代码
	CString a = (_T("shutdown -s -t "));
	CString time;
	GetDlgItem(IDC_EDIT8)->GetWindowText(time);
	int i = wcstol(time, NULL, 10);
	i *= 3600;
	CString times = (_T(""));
	times.Format(_T("%d"), i);
	a = a + times;
	int len = WideCharToMultiByte(CP_ACP, 0, a, -1, NULL, 0, NULL, NULL);
	char* ptxtTemp = new char[len + 1];
	WideCharToMultiByte(CP_ACP, 0, a, -1, ptxtTemp, len, NULL, NULL);
	system(ptxtTemp);
	//...
	delete[] ptxtTemp;
}

void CYANGRemindDlg::OnBnClickedButton25()
{
	// TODO: 在此添加控件通知处理程序代码
	system("shutdown -a");
}
#define progressCtrl
// 声明全局变量

// MCI通知消息处理函数


// 播放在线MP3文件
LRESULT CYANGRemindDlg::OnPlayFinished(WPARAM wParam, LPARAM lParam)
{
	// 弹出提示框并等待用户确认
	if (AfxMessageBox(_T("Do you want to play again?"), MB_YESNO) == IDYES)
	{
		// 重新打开 URL 以继续播放
		mciSendString(_T("close mp3"), NULL, 0, NULL);
		CString strCommand;
		strCommand.Format(_T("open %s type mpegvideo alias mp3 notify"), g_strUrl);
		mciSendString(strCommand, NULL, 0, g_hWndNotify);
		mciSendString(_T("play mp3"), NULL, 0, NULL);
	}
	else
	{
		// 停止播放
		mciSendString(_T("stop mp3"), NULL, 0, NULL);
		mciSendString(_T("close mp3"), NULL, 0, NULL);

		// 退出消息循环
		PostQuitMessage(0);
	}

	return 0;
}
void  CYANGRemindDlg::PlayMP3(LPCTSTR lpszFileName)
{
	
	g_strUrl = lpszFileName;

	// 打开MCI设备并播放音频
	CString strCommand;
	strCommand.Format(_T("open %s type mpegvideo alias mp3 notify"), lpszFileName);
	mciSendString(strCommand, NULL, 0, NULL);
	mciSendString(_T("play mp3"), NULL, 0, NULL);

	MSG msg;

	while (::GetMessage(&msg, NULL, 0, 0))
	{
		::TranslateMessage(&msg);
		::DispatchMessage(&msg);
	}
	StopMP3();



}
void CYANGRemindDlg::StopMP3()
{
	mciSendString(_T("stop mp3"), NULL, 0, NULL);
	mciSendString(_T("close mp3"), NULL, 0, NULL);
}

void CYANGRemindDlg::OnBnClickedButton18()
{
	xz = 5;
	// TODO: 在此添加控件通知处理程序代码
	CInternetSession session(_T("HttpClient"));
	TCHAR* url = _T("https://api.vvhan.com/api/rand.music?type=json&sort=%E7%83%AD%E6%AD%8C%E6%A6%9C");
	CHttpFile* pfile = (CHttpFile*)session.OpenURL(url);
	DWORD dwStatusCode;
	pfile->QueryInfoStatusCode(dwStatusCode);
	if (dwStatusCode == HTTP_STATUS_OK)
	{
		CString content;
		CString data;
		while (pfile->ReadString(data))
		{
			content += data;
		}
		char* pch;
		pch = new char[content.GetLength() * sizeof(TCHAR) + 1];
		memcpy(pch, content, content.GetLength() * sizeof(TCHAR));
		content = UTF8ToUnicode(pch);//转换编码，不然就乱码了
		//MessageBox(content);
		CString str = content;
		Json::Reader reader;
		Json::Value root;
		CString temp;
		CString temp2;
		CString temp3;
		CString temp4;
		CString temp5;
		CString temp6;
		USES_CONVERSION;
		char* cJson = T2A(str.GetBuffer(0));
		str.ReleaseBuffer();
		if (reader.parse(cJson, root)) {
			temp2 = root["info"]["mp3url"].asCString();
				temp3 = root["info"]["name"].asCString();
			//	temp4 = root["info"]["auther"].asCString();
				//temp5 = root["info"]["tip"].asCString();
				//temp6 = root["info"]["air"]["aqi_name"].asCString();
		}
		//temp = temp + " " + temp2 + " " + temp3 + " " + temp4 + " 空气质量 " + temp6;
		//MessageBox(temp2);
		//MessageBox(temp3);
		//MessageBox(temp);
		PlayMP3(temp2);
	//	num2 = temp3;
	//	AfxGetApp()->WriteProfileString(_T("Settings"), _T("LocalRecPath"), temp3);//_localRecPath就是要保存的信息，Settings为注册表子键，LocalRecPath即子键的键值名
		//num = temp4;
		//AfxGetApp()->WriteProfileString(_T("Settings"), _T("LocalRecPath"), temp4);//_localRecPath就是要保存的信息，Settings为注册表子键，LocalRecPath即子键的键值名
		if (!isNotify)
		{
			nid.cbSize = (DWORD)sizeof(NOTIFYICONDATA);
			nid.hWnd = this->m_hWnd;
			nid.uID = IDR_MAINFRAME;
			nid.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP | NIF_INFO;
			nid.uCallbackMessage = WM_SHOWTASK;//自定义的消息名称,注意:这里的消息是用户自定义消息  
			nid.hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_MAINFRAME));
			wcscpy_s(nid.szTip, _T("YANG Remind程序"));//信息提示条为"计划任务提醒"  
			wcscpy_s(nid.szInfo, temp3);
			wcscpy_s(nid.szInfoTitle, temp3);
			nid.dwInfoFlags = NIIF_INFO;
			//nid.uTimeout = 5;
			Shell_NotifyIcon(NIM_ADD, &nid);//在托盘区添加图标  
			//AnimateWindow(5000, AW_HIDE | AW_BLEND);      //可以缓慢消失窗口  
			//ShowWindow(SW_HIDE);//隐藏主窗口  
			Shell_NotifyIcon(NIM_DELETE, &nid);
			//KillTimer(0);
		}
	}
	pfile->Close();
	delete pfile;
	session.Close();

}



void CYANGRemindDlg::OnBnClickedButton19()
{
	// TODO: 在此添加控件通知处理程序代码
	StopMP3();
}


void CYANGRemindDlg::OnBnClickedButton26()
{
	xz = 6;
	// TODO: 在此添加控件通知处理程序代码
	CInternetSession session(_T("HttpClient"));
	TCHAR* url = _T("https://api.vvhan.com/api/hotlist?type=baiduRD");
	CHttpFile* pfile = (CHttpFile*)session.OpenURL(url);
	DWORD dwStatusCode;
	pfile->QueryInfoStatusCode(dwStatusCode);
	if (dwStatusCode == HTTP_STATUS_OK)
	{
		CString content;
		CString data;
		while (pfile->ReadString(data))
		{
			content += data;
		}
		char* pch;
		pch = new char[content.GetLength() * sizeof(TCHAR) + 1];
		memcpy(pch, content, content.GetLength() * sizeof(TCHAR));
		content = UTF8ToUnicode(pch);//转换编码，不然就乱码了
		//AfxMessageBox(content);
		//CString content2;
	//	content2 = content.Left(content.Find('r'));
	//	content2 = content2.Right(content.GetLength() - 1 - content.ReverseFind(':'));
		//CString contenta;
	//	contenta = content.Left(content.Find('a'));
		//contenta = content.Right(content.GetLength() - 1 - content.ReverseFind(':'));

		CString str = content;
		Json::Reader reader;
		Json::Value root;
		CString temp;
		CString temp2;
		CString temp3;
		CString temp4;
		CString temp5;
		CString temp6;
		USES_CONVERSION;
		char* cJson = T2A(str.GetBuffer(0));
		str.ReleaseBuffer();
		if (reader.parse(cJson, root)) {
			temp = root["data"][0]["title"].asCString();
			temp2 = root["data"][0]["desc"].asCString();
			MessageBox(temp3+temp4);
		}
		num2 = temp;
		AfxGetApp()->WriteProfileString(_T("Settings"), _T("LocalRecPath2"), num2);//_localRecPath就是要保存的信息，Settings为注册表子键，LocalRecPath即子键的键值名
		num = temp2;
		AfxGetApp()->WriteProfileString(_T("Settings"), _T("LocalRecPath"), num);//_localRecPath就是要保存的信息，Settings为注册表子键，LocalRecPath即子键的键值名
	}
	pfile->Close();
	delete pfile;
	session.Close();
	TZ();
}

void CYANGRemindDlg::xinzuo27()
{
	xz = 7;
	// TODO: 在此添加控件通知处理程序代码
	CInternetSession session(_T("HttpClient"));
	CString url1= _T("https://api.vvhan.com/api/horoscope?type=");
	CString str = url1+xingzuo1;
	TCHAR* url = (LPTSTR)(LPCTSTR)str;
	CHttpFile* pfile = (CHttpFile*)session.OpenURL(url);
	DWORD dwStatusCode;
	pfile->QueryInfoStatusCode(dwStatusCode);
	if (dwStatusCode == HTTP_STATUS_OK)
	{
		CString content;
		CString data;
		while (pfile->ReadString(data))
		{
			content += data;
		}
		char* pch;
		pch = new char[content.GetLength() * sizeof(TCHAR) + 1];
		memcpy(pch, content, content.GetLength() * sizeof(TCHAR));
		content = UTF8ToUnicode(pch);//转换编码，不然就乱码了
		//AfxMessageBox(content);
		//CString content2;
	//	content2 = content.Left(content.Find('r'));
	//	content2 = content2.Right(content.GetLength() - 1 - content.ReverseFind(':'));
		//CString contenta;
	//	contenta = content.Left(content.Find('a'));
		//contenta = content.Right(content.GetLength() - 1 - content.ReverseFind(':'));

		CString str = content;
		Json::Reader reader;
		Json::Value root;
		CString temp;
		CString temp2;
		CString temp3;
		CString temp4;
		CString temp5;
		CString temp6;
		USES_CONVERSION;
		char* cJson = T2A(str.GetBuffer(0));
		str.ReleaseBuffer();
		if (reader.parse(cJson, root)) {
			temp = root["data"]["title"].asCString();
			temp2 = root["data"]["fortunetext"]["all"].asCString();
			MessageBox(temp + temp2);
		}
		num2 = temp;
		AfxGetApp()->WriteProfileString(_T("Settings"), _T("LocalRecPath2"), num2);//_localRecPath就是要保存的信息，Settings为注册表子键，LocalRecPath即子键的键值名
		num = temp2;
		AfxGetApp()->WriteProfileString(_T("Settings"), _T("LocalRecPath"), num);//_localRecPath就是要保存的信息，Settings为注册表子键，LocalRecPath即子键的键值名
	}
	pfile->Close();
	delete pfile;
	session.Close();
	TZ();
}


void CYANGRemindDlg::OnBnClickedMfcmenubutton1()
{
	// TODO: 在此添加控件通知处理程序代码
	switch (m_menu.m_nMenuResult)
	{
	case ID_1:
	{
		TZ();
		break;
	}
	case ID_2:
	{
		OnBnClickedButton26();
		break;
	}
	case ID_3:
	{
		OnBnClickedButton12();
		break;
	}	
	case ID_4:
	{
		OnBnClickedButton3();
		break;
	}
	case ID_5:
	{
		OnBnClickedButton2();
		break;
	}
	case ID_6:
	{
		OnBnClickedButton18();
		break;
	}
	case ID_7:
	{
		OnBnClickedButton19();
		break;
	}
	case ID_32787:
	{

		xingzuo1 = _T("aquarius&time=today");
		AfxGetApp()->WriteProfileString(_T("Settings"), _T("LocalRecPathxz"), xingzuo1);//_localRecPath就是要保存的信息，Settings为注册表子键，LocalRecPath即子键的键值名
		xinzuo27();
		break;
	}
	case ID_32788:
	{

		xingzuo1 = _T("pisces&time=today");
		AfxGetApp()->WriteProfileString(_T("Settings"), _T("LocalRecPathxz"), xingzuo1);//_localRecPath就是要保存的信息，Settings为注册表子键，LocalRecPath即子键的键值名
		xinzuo27();
		break;
	}
	case ID_32794:
	{

		xingzuo1 = _T("aries&time=today");
		AfxGetApp()->WriteProfileString(_T("Settings"), _T("LocalRecPathxz"), xingzuo1);//_localRecPath就是要保存的信息，Settings为注册表子键，LocalRecPath即子键的键值名
		xinzuo27();
		break;
	}
	case ID_32795:
	{
	
		xingzuo1 = _T("taurus&time=today");
		AfxGetApp()->WriteProfileString(_T("Settings"), _T("LocalRecPathxz"), xingzuo1);//_localRecPath就是要保存的信息，Settings为注册表子键，LocalRecPath即子键的键值名
		xinzuo27();
		break;
	}
	case ID_32796:
	{

		xingzuo1 = _T("gemini&time=today");
		AfxGetApp()->WriteProfileString(_T("Settings"), _T("LocalRecPathxz"), xingzuo1);//_localRecPath就是要保存的信息，Settings为注册表子键，LocalRecPath即子键的键值名
		xinzuo27();
		break;
	}
	case ID_32797:
	{

		xingzuo1 = _T("cancer&time=today");
		AfxGetApp()->WriteProfileString(_T("Settings"), _T("LocalRecPathxz"), xingzuo1);//_localRecPath就是要保存的信息，Settings为注册表子键，LocalRecPath即子键的键值名
		xinzuo27();
		break;
	}
	case ID_32798:
	{

		xingzuo1 = _T("leo&time=today");
		AfxGetApp()->WriteProfileString(_T("Settings"), _T("LocalRecPathxz"), xingzuo1);//_localRecPath就是要保存的信息，Settings为注册表子键，LocalRecPath即子键的键值名
		xinzuo27();
		break;
	}
	case ID_32799:
	{

		xingzuo1 = _T("virgo&time=today");
		AfxGetApp()->WriteProfileString(_T("Settings"), _T("LocalRecPathxz"), xingzuo1);//_localRecPath就是要保存的信息，Settings为注册表子键，LocalRecPath即子键的键值名;
		xinzuo27();
		break;
	}
	case ID_32800:
	{
	
		xingzuo1 = _T("libra&time=today");
		AfxGetApp()->WriteProfileString(_T("Settings"), _T("LocalRecPathxz"), xingzuo1);//_localRecPath就是要保存的信息，Settings为注册表子键，LocalRecPath即子键的键值名
		xinzuo27();
		break;
	}
	case ID_32801:
	{

		xingzuo1 = _T("scorpio&time=today");
		AfxGetApp()->WriteProfileString(_T("Settings"), _T("LocalRecPathxz"), xingzuo1);//_localRecPath就是要保存的信息，Settings为注册表子键，LocalRecPath即子键的键值名
		xinzuo27();
		break;
	}
	case ID_32802:
	{

		xingzuo1 = _T("sagittarius&time=today");
		AfxGetApp()->WriteProfileString(_T("Settings"), _T("LocalRecPathxz"), xingzuo1);//_localRecPath就是要保存的信息，Settings为注册表子键，LocalRecPath即子键的键值名
		xinzuo27();
		break;
	}
	case ID_32803:
	{
	
		xingzuo1 = _T("capricorn&time=today");
		AfxGetApp()->WriteProfileString(_T("Settings"), _T("LocalRecPathxz"), xingzuo1);//_localRecPath就是要保存的信息，Settings为注册表子键，LocalRecPath即子键的键值名
		xinzuo27();
		break;
	}

	}
}



void CAboutDlg::On15()
{
	// TODO: 在此添加命令处理程序代码
}
