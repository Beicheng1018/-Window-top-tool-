
// SetTopDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "SetTop.h"
#include "SetTopDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define KEYDOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0) 

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


// CSetTopDlg 对话框



CSetTopDlg::CSetTopDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SETTOP_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSetTopDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CSetTopDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CSetTopDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CSetTopDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CSetTopDlg 消息处理程序

BOOL CSetTopDlg::OnInitDialog()
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
	// 
	//修改字体
	CFont m_font;
	m_font.CreatePointFont(200, _T("黑体"),NULL);
	GetDlgItem(IDC_STATIC1)->SetFont(&m_font);
	GetDlgItem(IDC_STATIC2)->SetFont(&m_font);
	GetDlgItem(IDC_STATIC3)->SetFont(&m_font);
	GetDlgItem(IDC_STATIC4)->SetFont(&m_font);
	GetDlgItem(IDC_STATIC5)->SetFont(&m_font);







	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CSetTopDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSetTopDlg::OnPaint()
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
HCURSOR CSetTopDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//自定义函数

void chgCurMove() {
	//简洁写法
	SetSystemCursor(LoadCursorFromFile(_T("aero_move_l.cur")), 32512);
}

void chgCurLink() {
	SetSystemCursor(LoadCursorFromFile(_T("aero_link_l.cur")), 32512);
}


//改回默认的
void chgCurBack() {
	// 设置鼠标指针为自定义图标
	SetSystemCursor(LoadCursorFromFile(_T("aero_arrow_l.cur")), 32512);
}

void CSetTopDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	chgCurLink();

	while (1) {//点下时获得窗口的信息
		if (KEYDOWN(VK_LBUTTON)) {
			break;
		}
	}
	chgCurBack();

	POINT point;//创建位置类

	GetCursorPos(&point);//获得鼠标位置

	HWND wnd = ::WindowFromPoint(point);//获得该位置处的wnd窗口句柄

	int hexNum;
	TCHAR tHexNum[MAX_PATH];
	TCHAR className[MAX_PATH];
	TCHAR wndName[MAX_PATH];

	hexNum = (int)wnd;//获得句柄
	_stprintf(tHexNum,_T("%08X"),hexNum);
	GetClassName(wnd, className, MAX_PATH);//获得类名
	::GetWindowText(wnd, wndName, MAX_PATH);//获得窗口名字
	
	//改变编辑框文本
	GetDlgItem(IDC_EDIT1)->SetWindowText(tHexNum);
	GetDlgItem(IDC_EDIT2)->SetWindowText(className);
	GetDlgItem(IDC_EDIT3)->SetWindowText(wndName);

	//设为置顶
	::SetWindowPos(wnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);//SWP_NOMOVE|SWP_NOSIZE 将四个数字参数给无效了
}


void CSetTopDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	chgCurLink();
	while (1) {//点下时获得窗口的信息
		if (KEYDOWN(VK_LBUTTON)) {
			break;
		}
	}
	chgCurBack();

	POINT point;//创建位置类

	GetCursorPos(&point);//获得鼠标位置

	HWND wnd = ::WindowFromPoint(point);//获得该位置处的wnd窗口句柄

	int hexNum;
	TCHAR tHexNum[MAX_PATH];
	TCHAR className[MAX_PATH];
	TCHAR wndName[MAX_PATH];

	hexNum = (int)wnd;//获得句柄
	_stprintf(tHexNum, _T("%08X"), hexNum);
	GetClassName(wnd, className, MAX_PATH);//获得类名
	::GetWindowText(wnd, wndName, MAX_PATH);//获得窗口名字

	//改变编辑框文本
	GetDlgItem(IDC_EDIT1)->SetWindowText(tHexNum);
	GetDlgItem(IDC_EDIT2)->SetWindowText(className);
	GetDlgItem(IDC_EDIT3)->SetWindowText(wndName);

	//设为置顶
	::SetWindowPos(wnd, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);//SWP_NOMOVE|SWP_NOSIZE 将四个数字参数给无效了
}
