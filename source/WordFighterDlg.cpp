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
	m_strEnglishWord = _T("�ܾ����� �����ּ���");
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
// ^.^ C++�¾�?
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
	
QuestionList *pNode; //������
QuestionList *temp;  //�������
bool init=true;		 //�̴־��Ҷ�� �����

void Question(int d);	//�ε����� �Ѱ��ָ� �ش� �����Ϳ� �����ش�.

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

void Question(int d)	//�ش� �ε����� �����͸� �����ִ� �Լ�
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

void CWordFighterDlg::OnCheck1()	//üũ�� �ٲ��ְ� ���� üũ
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

void CWordFighterDlg::OnCheck2()	//üũ�� �ٲ��ְ� ���� üũ 
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

void CWordFighterDlg::OnCheck3()	//üũ�� �ٲ��ְ� ���� üũ 
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

void CWordFighterDlg::OnCheck4() 	//üũ�� �ٲ��ְ� ���� üũ
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
		m_strJudgement="����";
		PlaySound(NULL,NULL,SND_PURGE);
		PlaySound(MAKEINTRESOURCE(IDR_WAVE_Right1),NULL,SND_RESOURCE|SND_ASYNC);
	}
	else
	{
		m_strJudgement="��";
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
	if(temp==NULL){MessageBox("�ܾ����� �����ּ���","Notice",MB_OK);return;};
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
	//���� ��ֱ�
	//---------------------------------------------------------------------

	//CFile file("sourcex.txt",  CFile::modeRead);
	//CArchive ar(&file, CArchive::load);
	//Serialize(ar);

	//---------------------------------------------------------------------
	//�Լ��� ��������
	//---------------------------------------------------------------------
	int i=0; //txt���� �а� �ִ� ���� ��ġ
	int Line=0; //�ټ� üũ
	int MaxList=0;

	int check=0; //��Ʈ��Ʈ�� �볪������ �� ��Ƽ��
	m_nAnswer=0;
	char buf[100]; //���� ����	
	char tem[10]; //���� ��������
	memset(buf,'\0',sizeof(buf)); //�ʱ�ȭ
	memset(tem,'\0',sizeof(buf)); //�ʱ�ȭ

	//---------------------------------------------------------------------
	//���̸� ���ڷ� �����Ѵ�
	//---------------------------------------------------------------------
	while (!(((int)(m_strData.GetAt(i)))==13))
	{
		wsprintf(tem,"%c",m_strData.GetAt(i));
		strcat(buf,tem);
		i++;
	};
	
	MaxList=atoi(buf); //���̸� �о� Max List�� ��ֱ�

	memset(buf,'\0',sizeof(buf)); //������ ��������
	memset(tem,'\0',sizeof(buf)); //������ ��������

	//---------------------------------------------------------------------
	//�ܾ ���� �о� ��忡 �־��ش�.
	//---------------------------------------------------------------------
	
	while (!(Line==MaxList))
	{
		switch(((int)(m_strData.GetAt(i))))
		{
			case 9: //�ܾ�ѱ�
				switch(check)
				{
					case 0: //index �־��ֱ�
						pNode->index=atoi(buf);
						memset(buf,'\0',sizeof(buf));	
						check++;
						break;

					case 1: //english �־��ֱ�
						wsprintf(pNode->English,"%s",buf);
						memset(buf,'\0',sizeof(buf));	
						check++;
						break;

					case 2: //korean �־��ֱ�
						wsprintf(pNode->Korean,"%s",buf);
						memset(buf,'\0',sizeof(buf));	
						check++;
						break;

					case 3: //tested �־��ֱ�
						pNode->tested=atoi(buf);
						memset(buf,'\0',sizeof(buf));	
						check++;
						break;

					case 4: //righted �־��ֱ�
						pNode->Right=atoi(buf);
						memset(buf,'\0',sizeof(buf));	
						check++;
						break;
				};
				break;

			case 13: //�����϶�
				
				if(check==5) // ������ �ϴ� üũ�� �ȵǼ�... --; �������ص� �Ҽ����� ��...
				{		
					pNode->Wrong=atoi(buf);
					memset(buf,'\0',sizeof(buf));	
					check=0;
				};

				if (init==true)	//ó���϶�
				{
					init=false;	//ó���� �ƴ϶�� ���ֱ�
					pNode=new QuestionList; //����ϳ� ���鱸
					pNode->Next=NULL; //�Ǿ�(��)�ſ� ���� �־��ֱ�
					temp=pNode; //���� ��带 ������ش�.
				}
				else
				{
					pNode=new QuestionList;
					pNode->Next=temp;
					temp=pNode;
				};
				
				memset(buf,'\0',sizeof(buf));	//Ȯ�� ���
				memset(temp,'\0',sizeof(temp)); //Ȯ�� ���
				
				i++;	//���� �Ѿ� ����
				Line++;	//���� �Ѿ� ����.
				break;
			
			case 10: //�̰� �ΰ� ���� �־ �Ѿ�°�... -.-
				i++;	//���� �Ѿ� ����.
				break;
				
			default :	//�ϰŵ� �ƴ� ���ڶ�� ���ۿ� �ڲ� �����ش�.
				wsprintf(tem,"%c",m_strData.GetAt(i));
				strcat(buf,tem);
				break;
		};
		i++;
	};

	//---------------------------------------------------------------------
	//	��������
	//	������ ������ ����ϴ� ���� �ƴ����� ������ �ε����� �����Ѵ�.
	//	-.- �� �̷��� ������ �ϴٺ��� �̷� ����.
	//---------------------------------------------------------------------	
	int nTotal=(int)MaxList;
	srand(GetCurrentTime());	//������ �����
	int Q=rand()%(nTotal-1)+1;	//���ټ����� �����ϰ� �����ֱ� ������ ����.

	
	int d1,Q1,A1,A2,A3,A4;		//��Ÿ���
	m_nCorrect=d1=rand()%4+1;	//1~4���� �����ϰ� �ϳ� ���

	switch(d1)
	{
	case 1:						//1���� ���϶�
		Q1=A1=Q;				
		do
		{
			A2=rand()%(nTotal);
			A3=rand()%(nTotal);
			A4=rand()%(nTotal);
		}	while (A1==A2||A1==A3||A1==A4||A2==A3||A2==A4||A3==A4);
		break;
	
	case 2:						//2���� ���϶�
		Q1=A2=Q;
		do
		{
		A1=rand()%(nTotal);
		A3=rand()%(nTotal);
		A4=rand()%(nTotal);
		}	while (A1==A2||A1==A3||A1==A4||A2==A3||A2==A4||A3==A4);
		break;

	case 3:						//3���� ���϶�
		Q1=A3=Q;
		do
		{
		A1=rand()%(nTotal);
		A2=rand()%(nTotal);
		A4=rand()%(nTotal);
		}	while (A1==A2||A1==A3||A1==A4||A2==A3||A2==A4||A3==A4);
		break;

	case 4:						//4���� ���϶�
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
	//	������ ������ ������ش�.
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
