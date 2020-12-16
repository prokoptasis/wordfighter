///////////////////////////////////////////////////////////////////////////////
// WordFighterDlg.cpp : implementation file
// Only just for Fun
// 2002.7.25.Tur
// made by Jhook
///////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "WordFighter.h"
#include "WordFighterDlg.h"
#include "MMSystem.h"
#include "resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWordFighterDlg dialog

CWordFighterDlg::CWordFighterDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWordFighterDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWordFighterDlg)
	m_strEnglishWord = _T("단어장을 열어주세요");
	m_strJudgement = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWordFighterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWordFighterDlg)
	DDX_Control(pDX, IDC_CHECK4, m_strCheck4);
	DDX_Control(pDX, IDC_CHECK3, m_strCheck3);
	DDX_Control(pDX, IDC_CHECK2, m_strCheck2);
	DDX_Control(pDX, IDC_CHECK1, m_strCheck1);
	DDX_Text(pDX, IDC_111, m_strEnglishWord);
	DDX_Text(pDX, IDC_JUDGEMENT, m_strJudgement);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CWordFighterDlg, CDialog)
	//{{AFX_MSG_MAP(CWordFighterDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CHECK1, OnCheck1)
	ON_BN_CLICKED(IDC_CHECK2, OnCheck2)
	ON_BN_CLICKED(IDC_CHECK3, OnCheck3)
	ON_BN_CLICKED(IDC_CHECK4, OnCheck4)
	ON_BN_CLICKED(IDC_NEXT, OnNext)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWordFighterDlg message handlers

/////////////////////////////////////////////////////////////////////////////
// ^.^ C++맞아?
/////////////////////////////////////////////////////////////////////////////

struct QuestionList 
{ 
	int index; 
	char English[30]; 
	char Korean[30];	
	int tested;	
	int Right; 
	int Wrong; 
	QuestionList *Next; 
};
	
QuestionList *pNode; //범용노드
QuestionList *temp;  //최종노드
bool init=true;		 //이닛안할라고 만든거

void Question(int d);	//인덱스를 넘겨주면 해당 포인터에 맞춰준다.

BOOL CWordFighterDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void Question(int d)	//해당 인덱스에 포인터를 맞춰주는 함수
{
	pNode=temp;
	while(!(pNode->index==d))
	{
		pNode=pNode->Next;
	};
}


void CWordFighterDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CWordFighterDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CWordFighterDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CWordFighterDlg::OnCheck1()	//체크를 바꿔주고 답을 체크
{
	// TODO: Add your control notification handler code here
	m_nAnswer = 1;
	if(m_strCheck1.GetCheck()==1)
	{
		m_strCheck2.SetCheck(false);
		m_strCheck3.SetCheck(false);
		m_strCheck4.SetCheck(false);
	};
	CheckAnswer();
	UpdateData(TRUE);	

}

void CWordFighterDlg::OnCheck2()	//체크를 바꿔주고 답을 체크 
{
	// TODO: Add your control notification handler code here
	m_nAnswer = 2;
	if(m_strCheck2.GetCheck()==1)
	{
		m_strCheck1.SetCheck(false);
		m_strCheck3.SetCheck(false);
		m_strCheck4.SetCheck(false);
	};
	CheckAnswer();
	UpdateData(TRUE);

}

void CWordFighterDlg::OnCheck3()	//체크를 바꿔주고 답을 체크 
{
	// TODO: Add your control notification handler code here
	m_nAnswer = 3;
	if(m_strCheck3.GetCheck()==1)
	{
		m_strCheck1.SetCheck(false);
		m_strCheck2.SetCheck(false);
		m_strCheck4.SetCheck(false);
	};
	CheckAnswer();
	UpdateData(TRUE);


}

void CWordFighterDlg::OnCheck4() 	//체크를 바꿔주고 답을 체크
{
	// TODO: Add your control notification handler code here
	m_nAnswer = 4;
	if(m_strCheck4.GetCheck()==1)
	{
		m_strCheck1.SetCheck(false);
		m_strCheck2.SetCheck(false);
		m_strCheck3.SetCheck(false);
	};	

	CheckAnswer();
	UpdateData(TRUE);
}

void CWordFighterDlg::CheckAnswer()
{
	UpdateData(TRUE);	
	if (m_nAnswer>0 && m_nCorrect==m_nAnswer)
	{
		m_strJudgement="정답";
		PlaySound(NULL,NULL,SND_PURGE);
		PlaySound(MAKEINTRESOURCE(IDR_WAVE_Right1),NULL,SND_RESOURCE|SND_ASYNC);
	}
	else
	{
		m_strJudgement="땡";
		int i=rand()%3;
		switch(i)
		{
		case 0:
			PlaySound(NULL,NULL,SND_PURGE);
			PlaySound(MAKEINTRESOURCE(IDR_WAVE_Wrong1),NULL,SND_RESOURCE|SND_ASYNC);
			break;
		case 1:
			PlaySound(NULL,NULL,SND_PURGE);
			PlaySound(MAKEINTRESOURCE(IDR_WAVE_Wrong2),NULL,SND_RESOURCE|SND_ASYNC);
			break;
		case 2:
			PlaySound(NULL,NULL,SND_PURGE);
			PlaySound(MAKEINTRESOURCE(IDR_WAVE_Wrong3),NULL,SND_RESOURCE|SND_ASYNC);
			break;
		};
	};
	UpdateData(FALSE);
}

void CWordFighterDlg::OnOK() 
{
	// TODO: Add extra validation here
	// CDialog::OnOK();
	OnFileOpen();
	MakeNodeEtc();

}

void CWordFighterDlg::OnNext() 
{
	// TODO: Add your control notification handler code here
	m_strCheck1.SetCheck(false);
	m_strCheck2.SetCheck(false);
	m_strCheck3.SetCheck(false);
	m_strCheck4.SetCheck(false);
	m_nAnswer=0;
	if(temp==NULL){MessageBox("단어장을 열어주세요","Notice",MB_OK);return;};
	MakeNodeEtc();
}

void CWordFighterDlg::OnFileOpen()
{
	char szFilter[] = "Text Files(*.wff)|*.wff|All Files(*.*)|*.*||";

	CFileDialog fileDlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, szFilter);
	if(IDOK == fileDlg.DoModal())
	{
		CFile file(fileDlg.GetFileName(),  CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		Serialize(ar);
    }
}

void CWordFighterDlg::Serialize(CArchive& ar) 
{
	if (ar.IsStoring())
	{	// storing code
	}
	else
	{	// loading code
		DWORD dwSize = ar.GetFile()->GetLength();
		ar.Read(m_strData.GetBuffer(dwSize), dwSize);
		m_strData.ReleaseBuffer();
	}
}


void CWordFighterDlg::MakeNodeEtc()
{
	//---------------------------------------------------------------------
	//파일 까넣기
	//---------------------------------------------------------------------

	//CFile file("sourcex.txt",  CFile::modeRead);
	//CArchive ar(&file, CArchive::load);
	//Serialize(ar);

	//---------------------------------------------------------------------
	//함수의 변수선언
	//---------------------------------------------------------------------
	int i=0; //txt에서 읽고 있는 글자 위치
	int Line=0; //줄수 체크
	int MaxList=0;

	int check=0; //스트럭트에 노나넣을때 쓸 인티져
	m_nAnswer=0;
	char buf[100]; //범용 버퍼	
	char tem[10]; //범용 템프버퍼
	memset(buf,'\0',sizeof(buf)); //초기화
	memset(tem,'\0',sizeof(buf)); //초기화

	//---------------------------------------------------------------------
	//길이를 숫자루 추출한당
	//---------------------------------------------------------------------
	while (!(((int)(m_strData.GetAt(i)))==13))
	{
		wsprintf(tem,"%c",m_strData.GetAt(i));
		strcat(buf,tem);
		i++;
	};
	
	MaxList=atoi(buf); //길이를 읽어 Max List에 까넣기

	memset(buf,'\0',sizeof(buf)); //썼으니 지워주자
	memset(tem,'\0',sizeof(buf)); //썼으니 지워주자

	//---------------------------------------------------------------------
	//단어를 끊어 읽어 노드에 넣어준다.
	//---------------------------------------------------------------------
	
	while (!(Line==MaxList))
	{
		switch(((int)(m_strData.GetAt(i))))
		{
			case 9: //단어넘기
				switch(check)
				{
					case 0: //index 넣어주기
						pNode->index=atoi(buf);
						memset(buf,'\0',sizeof(buf));	
						check++;
						break;

					case 1: //english 넣어주기
						wsprintf(pNode->English,"%s",buf);
						memset(buf,'\0',sizeof(buf));	
						check++;
						break;

					case 2: //korean 넣어주기
						wsprintf(pNode->Korean,"%s",buf);
						memset(buf,'\0',sizeof(buf));	
						check++;
						break;

					case 3: //tested 넣어주기
						pNode->tested=atoi(buf);
						memset(buf,'\0',sizeof(buf));	
						check++;
						break;

					case 4: //righted 넣어주기
						pNode->Right=atoi(buf);
						memset(buf,'\0',sizeof(buf));	
						check++;
						break;
				};
				break;

			case 13: //끝줄일때
				
				if(check==5) // 위에다 하니 체크가 안되서... --; 지저분해도 할수없지 뭐...
				{		
					pNode->Wrong=atoi(buf);
					memset(buf,'\0',sizeof(buf));	
					check=0;
				};

				if (init==true)	//처음일때
				{
					init=false;	//처음이 아니라고 해주구
					pNode=new QuestionList; //노들하나 만들구
					pNode->Next=NULL; //맨앞(뒤)거에 널을 넣어주구
					temp=pNode; //최종 노드를 기록해준다.
				}
				else
				{
					pNode=new QuestionList;
					pNode->Next=temp;
					temp=pNode;
				};
				
				memset(buf,'\0',sizeof(buf));	//확인 사살
				memset(temp,'\0',sizeof(temp)); //확인 사살
				
				i++;	//글자 넘어 간다
				Line++;	//줄을 넘어 간다.
				break;
			
			case 10: //이건 두개 잡혀 있어서 넘어가는거... -.-
				i++;	//글자 넘어 간다.
				break;
				
			default :	//암거두 아닌 글자라면 버퍼에 꾹꾹 눌러준다.
				wsprintf(tem,"%c",m_strData.GetAt(i));
				strcat(buf,tem);
				break;
		};
		i++;
	};

	//---------------------------------------------------------------------
	//	질문선택
	//	실제로 질문을 출력하는 것은 아니지만 쓸려는 인덱스를 선택한다.
	//	-.- 뭐 이렇게 저렇게 하다보니 이래 됐음.
	//---------------------------------------------------------------------	
	int nTotal=(int)MaxList;
	srand(GetCurrentTime());	//랜덤을 쓸라믄
	int Q=rand()%(nTotal-1)+1;	//총줄수에서 랜덤하게 돌려주구 문제를 고른다.

	
	int d1,Q1,A1,A2,A3,A4;		//기타등등
	m_nCorrect=d1=rand()%4+1;	//1~4개중 랜덤하게 하나 찍기

	switch(d1)
	{
	case 1:						//1번이 답일때
		Q1=A1=Q;				
		do
		{
			A2=rand()%(nTotal);
			A3=rand()%(nTotal);
			A4=rand()%(nTotal);
		}	while (A1==A2||A1==A3||A1==A4||A2==A3||A2==A4||A3==A4);
		break;
	
	case 2:						//2번이 답일때
		Q1=A2=Q;
		do
		{
		A1=rand()%(nTotal);
		A3=rand()%(nTotal);
		A4=rand()%(nTotal);
		}	while (A1==A2||A1==A3||A1==A4||A2==A3||A2==A4||A3==A4);
		break;

	case 3:						//3번이 답일때
		Q1=A3=Q;
		do
		{
		A1=rand()%(nTotal);
		A2=rand()%(nTotal);
		A4=rand()%(nTotal);
		}	while (A1==A2||A1==A3||A1==A4||A2==A3||A2==A4||A3==A4);
		break;

	case 4:						//4번이 답일때
		Q1=A4=Q;
		
		do
		{
		A1=rand()%(nTotal);
		A2=rand()%(nTotal);
		A3=rand()%(nTotal);
		}	while (A1==A2||A1==A3||A1==A4||A2==A3||A2==A4||A3==A4);
		break;
	}

	//---------------------------------------------------------------------
	//	선택한 질문을 출력해준다.
	//---------------------------------------------------------------------	

	UpdateData(TRUE);
	Question(Q1);
	m_strEnglishWord=pNode->English;
	Question(A1);
	m_strCheck1.SetWindowText(pNode->Korean);
	Question(A2);
	m_strCheck2.SetWindowText(pNode->Korean);
	Question(A3);
	m_strCheck3.SetWindowText(pNode->Korean);
	Question(A4);
	m_strCheck4.SetWindowText(pNode->Korean);
	UpdateData(FALSE);

}
