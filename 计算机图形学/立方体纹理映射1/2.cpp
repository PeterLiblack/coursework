
#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <gl\gl.h>
#include <gl\glu.h>
#include <gl\glaux.h>
#pragma comment(lib,"openGL32.lib")
#pragma comment(lib,"glu32.lib")
#pragma comment(lib,"glaux.lib")

#ifdef _WIN32

#include <windows.h>
#endif
#include <windows.h>


HGLRC	hRC=NULL;
HDC	hDC=NULL;
HWND	hwnd=NULL;
HINSTANCE   hInstance;




bool	keys[256]; // ������̰���������
bool	active=true;// ���ڵĻ��־��ȱʡΪTRUE
bool	fullscreen=true;// ȫ����־ȱʡ��ȱʡ�趨��ȫ��ģʽ

GLfloat xrot;// X ��ת
GLfloat yrot;// y ��ת
GLfloat zrot;// z ��ת


GLuint	texture[6];//�洢6������

int cxScreen=GetSystemMetrics(SM_CXSCREEN);
int cyScreen=GetSystemMetrics(SM_CYSCREEN);

LRESULT CALLBACK WndProc(HWND hwnd,UINT message,WPARAM wParam,LPARAM lParam);

AUX_RGBImageRec* LoadBMP(char* filename)// ����λͼͼ��,ͼ��洢Ϊbmp��ʽ
{
    FILE* file=NULL;

    if(!filename)// ȷ���ļ������ṩ
    {
	return NULL;
    }

    file=fopen(filename,"r");// ���ļ�

    if(file)
    {
	fclose(file);
	return auxDIBImageLoad(filename);
    }
    return NULL;
}

int LoadGLTextures()// ���ݼ��ص�λͼ��������
{
    int status=FALSE; // ָʾ�������Ƿ�ɹ��ı�־
    
  
    AUX_RGBImageRec* textureImage[6];//OpenGL���԰�����ӳ�䵽ָ����ͼ�εı����ϴ���һ������ͼ�����飬����ָ�������СΪ6
    memset(textureImage,0,sizeof(AUX_RGBImageRec*)*6);//��ʼ������ͼ�����飬Ϊ������ڴ�
    char* texImg[6]={"data\\front.bmp","data\\back.bmp","data\\top.bmp",
	             "data\\bottom.bmp","data\\right.bmp","data\\left.bmp"};// ����һ��λͼ�������飬��Ӧ6��λͼ
    
    for(int i=0;i<6;i++)// ����λͼ�������飬����λͼ���Ʒֱ�����
    {
	if(textureImage[i]=LoadBMP(texImg[i]))// ����λͼi�ɹ����޸�״̬��־����StatusΪTRUE
	{
	    status=TRUE;
	    glGenTextures(1,&texture[i]);  // Ϊ��i��λͼ��������
	    glBindTexture(GL_TEXTURE_2D,texture[i]);// �����ɵ���������ư󶨵�ָ����������
	    glTexImage2D(GL_TEXTURE_2D,0,3,textureImage[i]->sizeX,textureImage[i]->sizeY,
		         0,GL_RGB,GL_UNSIGNED_BYTE,textureImage[i]->data);

	    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	}

	if(textureImage[i])// �ͷ�λͼ����ռ�õ��ڴ�ռ�
	{
	    if(textureImage[i]->data)
	    {
		free(textureImage[i]->data);
	    }
	    free(textureImage[i]);
	}
    }

    return status;// �����������أ����سɹ�����ʧ�ܵı�־Status
}

GLvoid ReSizeGLScene(GLsizei width,GLsizei height)// ����OpenGL���ڴ�С
{
    if(0==height)
    {
	height=1;
    }

    glViewport(0,0,width,height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(30.0f,(GLfloat)width/(GLfloat)height,1.0f,100.0f);// �����ӿڵĴ�С

    glMatrixMode(GL_MODELVIEW);// ѡ��ģ�͹۲����
    glLoadIdentity();// ����ģ�͹۲����
}

int InitGL(GLvoid)// �˴���ʼ��OpenGL������������

{
    if(!LoadGLTextures())// ������������������
    {
	MessageBox(NULL,"LoadGLTextures Failed!","Error",MB_OK | MB_ICONEXCLAMATION);// after error ocured,added for debug
	return FALSE;// ���δ�����룬����FALSE
    }
    glEnable(GL_TEXTURE_2D); // ��������ӳ��
    glShadeModel(GL_SMOOTH);// ������Ӱƽ��
    glClearColor(0.0f,0.0f,0.0f,0.5f);// ��ɫ����
    glClearDepth(1.0f);// ������Ȼ���
    glEnable(GL_DEPTH_TEST); // ������Ȳ���
    glDepthFunc(GL_LEQUAL);// ������Ȳ��Ե�����

    glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);// ������ϸ��͸������

    return true;
}

int DrawGLScene(GLvoid)// �����￪ʼ�������еĻ���
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0.0f,0.0f,-5.5f);

    glRotatef(xrot,1.0f,0.0f,0.0f);// ��X����ת
    glRotatef(yrot,0.0f,1.0f,0.0f);// ��y����ת
    glRotatef(zrot,0.0f,0.0f,1.0f);// ��z����ת

    
    
    // front face  ǰ����
    glBindTexture(GL_TEXTURE_2D,texture[0]);
    glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f); glVertex3f(-1.0f,-1.0f,1.0f);
	glTexCoord2f(1.0f,0.0f); glVertex3f(1.0f,-1.0f,1.0f);
	glTexCoord2f(1.0f,1.0f); glVertex3f(1.0f,1.0f,1.0f);
	glTexCoord2f(0.0f,1.0f); glVertex3f(-1.0f,1.0f,1.0f);
    glEnd();
    // back face�����
    glBindTexture(GL_TEXTURE_2D,texture[1]);
    glBegin(GL_QUADS);
	glTexCoord2f(1.0f,0.0f); glVertex3f(-1.0f,-1.0f,-1.0f);
	glTexCoord2f(0.0f,0.0f); glVertex3f(1.0f,-1.0f,-1.0f);
	glTexCoord2f(0.0f,1.0f); glVertex3f(1.0f,1.0f,-1.0f);
	glTexCoord2f(1.0f,1.0f); glVertex3f(-1.0f,1.0f,-1.0f);
    glEnd();
    // top face����
    glBindTexture(GL_TEXTURE_2D,texture[2]);
    glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f); glVertex3f(-1.0f,1.0f,1.0f);
	glTexCoord2f(1.0f,0.0f); glVertex3f(1.0f,1.0f,1.0f);
	glTexCoord2f(1.0f,1.0f); glVertex3f(1.0f,1.0f,-1.0f);
	glTexCoord2f(0.0f,1.0f); glVertex3f(-1.0f,1.0f,-1.0f);
    glEnd();
    // bottom face����
    glBindTexture(GL_TEXTURE_2D,texture[3]);
    glBegin(GL_QUADS);
	glTexCoord2f(1.0f,0.0f); glVertex3f(-1.0f,-1.0f,1.0f);
	glTexCoord2f(0.0f,0.0f); glVertex3f(1.0f,-1.0f,1.0f);
	glTexCoord2f(0.0f,1.0f); glVertex3f(1.0f,-1.0f,-1.0f);
	glTexCoord2f(1.0f,1.0f); glVertex3f(-1.0f,-1.0f,-1.0f);
    glEnd();
    // right face �Ҳ���
    glBindTexture(GL_TEXTURE_2D,texture[4]);
    glBegin(GL_QUADS);
	glTexCoord2f(0.0f,1.0f); glVertex3f(1.0f,1.0f,1.0f);
	glTexCoord2f(0.0f,0.0f); glVertex3f(1.0f,-1.0f,1.0f);
	glTexCoord2f(1.0f,0.0f); glVertex3f(1.0f,-1.0,-1.0f);
	glTexCoord2f(1.0f,1.0f); glVertex3f(1.0f,1.0f,-1.0f);
    glEnd();
    // left face�����
    glBindTexture(GL_TEXTURE_2D,texture[5]);
    glBegin(GL_QUADS);
	glTexCoord2f(1.0f,1.0f); glVertex3f(-1.0f,1.0f,1.0f);
	glTexCoord2f(1.0f,0.0f); glVertex3f(-1.0f,-1.0f,1.0f);
	glTexCoord2f(0.0f,0.0f); glVertex3f(-1.0f,-1.0,-1.0f);
	glTexCoord2f(0.0f,1.0f); glVertex3f(-1.0f,1.0f,-1.0f);
    glEnd();

    xrot+=0.1;//��X��ת�� 
    yrot+=0.1;
    zrot+=0.1;

    return true;
}

GLvoid KillGLWindow(GLvoid) // �������ٴ���
{
    if(fullscreen)// ���Ǵ���ȫ��ģʽ��?
    {
	ChangeDisplaySettings(NULL,0);
	ShowCursor(TRUE);
    }

    if(hRC!=NULL)
    {
	if(!wglMakeCurrent(NULL,NULL))// �����ܷ��ͷ�DC��RC������?
	{
	    MessageBox(NULL," �ͷ�DC��RCʧ��","�رմ��� ",MB_OK | MB_ICONINFORMATION);
	}

	if(!wglDeleteContext(hRC)) // �����ܷ�ɾ��RC?
	{
	    MessageBox(NULL,"�ͷ�RCʧ��!","�رմ���",MB_OK | MB_ICONINFORMATION);
	}
	hRC=NULL;
    }

    if(hDC!=NULL && !ReleaseDC(hwnd,hDC)) // �����ܷ��ͷ� DC?
    {
	MessageBox(NULL,"�ͷ�DCʧ��!","�رմ���",MB_OK | MB_ICONINFORMATION);
	hDC=NULL;
    }

    if(hwnd!=NULL && !DestroyWindow(hwnd))// �ܷ����ٴ���?
    {
	MessageBox(NULL,"�ͷŴ��ھ��ʧ��!","�رմ���",MB_OK | MB_ICONINFORMATION);
	hwnd=NULL;
    }

    if(!UnregisterClass("OpenGL",hInstance))// �ܷ�ע����?
    {
	MessageBox(NULL,"����ע��������","�رմ���",MB_OK | MB_ICONINFORMATION);
	hInstance=NULL;
    }
}

BOOL CreateGLWindow(char* title,int x,int y,int width,int height,int bits,bool fullscreenflag)
{
    GLuint pixelFormat;// �������ƥ��Ľ��
    WNDCLASS wc;
    DWORD dwExStyle;
    DWORD dwStyle;

    RECT windowRect;
    windowRect.left=(long)x;// ��Left   ��Ϊ x
    windowRect.top=(long)y;
    windowRect.right=(long)(width+x);
    windowRect.bottom=(long)(height+y);

    fullscreen=fullscreenflag;// ����ȫ��ȫ����־
    
    hInstance=GetModuleHandle(NULL);// ȡ�����Ǵ��ڵ�ʵ��

 wc.style        = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;        // �ƶ�ʱ�ػ�����Ϊ����ȡ��DC
    wc.lpfnWndProc        = (WNDPROC) WndProc;                // WndProc������Ϣ

    wc.cbClsExtra=0;
    wc.cbWndExtra=0;
    wc.hbrBackground=NULL;
    wc.hCursor=LoadCursor(NULL,IDC_ARROW); // װ�����ָ��
    wc.hIcon=LoadIcon(NULL,IDI_APPLICATION);
    wc.hInstance=hInstance;
    wc.lpfnWndProc=WndProc;
    wc.lpszClassName="OpenGL";
    wc.lpszMenuName=NULL;
    wc.style=CS_HREDRAW | CS_VREDRAW | CS_OWNDC;

    if(!RegisterClass(&wc))// ����ע�ᴰ����
    {
	MessageBox(NULL,"ע�ᴰ��ʧ��","����",MB_OK | MB_ICONEXCLAMATION);
	return FALSE;
    }

    if(fullscreen)// Ҫ����ȫ��ģʽ��?
    {
	DEVMODE dm;
	memset(&dm,0,sizeof(DEVMODE));
	dm.dmSize=sizeof(DEVMODE);
	dm.dmBitsPerPel=bits;
	dm.dmPelsWidth=cxScreen;
	dm.dmPelsHeight=cyScreen;
	dm.dmFields=DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;
	
	if(ChangeDisplaySettings(&dm,CDS_FULLSCREEN)!=DISP_CHANGE_SUCCESSFUL)
	{// ��ģʽʧ�ܣ��ṩ����ѡ��˳����ڴ��������С�
	    if(MessageBox(NULL,"ȫ��ģʽ�ڵ�ǰ�Կ�������ʧ�ܣ�\nʹ�ô���ģʽ��","NeHe G",MB_YESNO | MB_ICONEXCLAMATION)==IDYES)
	    {
		fullscreen=FALSE;// ѡ�񴰿�ģʽ(Fullscreen=FALSE)
	    }
	    else
	    {
		MessageBox(NULL,"���򽫱��ر�","����",MB_OK | MB_ICONSTOP);
		return FALSE;
	    }
	}
    }

    if(fullscreen) // �Դ���ȫ��ģʽ��?
    {
	dwExStyle=WS_EX_APPWINDOW;
	dwStyle=WS_POPUP;
	ShowCursor(FALSE);
    }
    else
    {
	dwExStyle=WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;
	dwStyle=WS_OVERLAPPEDWINDOW;
    }

    AdjustWindowRectEx(&windowRect,dwStyle,FALSE,dwExStyle);// �������ڴﵽ����Ҫ��Ĵ�С

    if(!(hwnd=CreateWindowEx(dwExStyle,"OpenGL",title,WS_CLIPCHILDREN | WS_CLIPSIBLINGS | dwStyle,
			     x,y,width,height,
			     NULL,NULL,hInstance,NULL)))
    {
	KillGLWindow();// ������ʾ��
	MessageBox(NULL,"���ܴ���һ�������豸������","����",MB_OK | MB_ICONEXCLAMATION);
	return FALSE;
    }

    if(fullscreen)
    {
	SetWindowPos(hwnd,HWND_TOP,0,0,cxScreen,cyScreen,SWP_SHOWWINDOW);
    }

    static PIXELFORMATDESCRIPTOR pfd=// /pfd ���ߴ���������ϣ���Ķ�����������ʹ�õ����ظ�ʽ
    {
	sizeof(PIXELFORMATDESCRIPTOR),
	1,
	PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
	PFD_TYPE_RGBA,
	bits,
	0,0,0,0,0,0,
	0,
	0,
	0,
	0,0,0,0,
	16,
	0,
	0,
	PFD_MAIN_PLANE,
	0,
	0,0,0
    };

    if(!(hDC=GetDC(hwnd)))
    {
	KillGLWindow();
	MessageBox(NULL,"���ܴ���һ����ƥ������ظ�ʽ","����",MB_OK | MB_ICONEXCLAMATION);
	return FALSE;
    }

    if(!(pixelFormat=ChoosePixelFormat(hDC,&pfd)))
    {
	KillGLWindow();
	MessageBox(NULL,"�����������ظ�ʽ","����",MB_OK | MB_ICONEXCLAMATION);
	return FALSE;
    }

    if(!SetPixelFormat(hDC,pixelFormat,&pfd))
    {
	KillGLWindow();
	MessageBox(NULL,"�����������ظ�ʽ","����r",MB_OK | MB_ICONEXCLAMATION);
	return FALSE;
    }

    if(!(hRC=wglCreateContext(hDC)))
    {
	KillGLWindow();
	MessageBox(NULL,"���ܴ���OpenGL��Ⱦ������","����",MB_OK | MB_ICONEXCLAMATION);
	return FALSE;
    }

    if(!wglMakeCurrent(hDC,hRC))
    {
	KillGLWindow();
	MessageBox(NULL,"���ܼ��ǰ��OpenGL��Ȼ������","����",MB_OK | MB_ICONEXCLAMATION);
	return FALSE;
    }

    ShowWindow(hwnd,SW_SHOW);// ��ʾ����
    SetForegroundWindow(hwnd);
    SetFocus(hwnd);
    ReSizeGLScene(width,height);

    if(!InitGL())
    {
	KillGLWindow();
	MessageBox(NULL,"Initialization Failed!","Error",MB_OK | MB_ICONEXCLAMATION);
	return FALSE;
    }

    return TRUE;
}

LRESULT CALLBACK WndProc(HWND hwnd,UINT message,WPARAM wParam,LPARAM lParam)
{
    switch(message)
    {
	case WM_ACTIVATE:
	{
	    if(!HIWORD(wParam))
	    {
		active=TRUE;
	    }
	    else
	    {
		active=FALSE;
	    }

	    return 0;
	}

	case WM_SYSCOMMAND:
	{
	    switch(wParam)
	    {
		case SC_SCREENSAVE:
		case SC_MONITORPOWER:
		return 0;
	    }
	    break;
	}

	case WM_CLOSE:
	{
	    PostQuitMessage(0);
	    return 0;
	}

	case WM_KEYDOWN:
	{
	    keys[wParam]=TRUE;
	    return 0;
	}

	case WM_KEYUP:
	{
	    keys[wParam]=FALSE;
	    return 0;
	}

	case WM_SIZE:
	{
	    ReSizeGLScene(LOWORD(lParam),HIWORD(lParam));
	    return 0;
	}
    }

    return DefWindowProc(hwnd,message,wParam,lParam);
}

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE,LPSTR lpCmdLine,int nShowCmd)
{
    MSG msg;
    BOOL done=FALSE;

    if(MessageBox(NULL,"������ȫ��ģʽ������ô��","����ȫ��ģʽ",MB_YESNO | MB_ICONQUESTION)==IDNO)
    {
	fullscreen=FALSE;
    }

    if(!CreateGLWindow("����ӳ�� ",cxScreen/5,cyScreen/6,3*cxScreen/5,2*cyScreen/3,32,fullscreen))// ����OpenGL����
    {
	return 0;
    }

    if(fullscreen)
    {
	ReSizeGLScene(cxScreen,cyScreen);
    }

    while(!done)
    {
	if(PeekMessage(&msg,NULL,0,0,PM_REMOVE))
	{
	    if(msg.message==WM_QUIT)
	    {
		done=TRUE;
	    }
	    else
	    {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	    }
	}
	else
	{// ���Ƴ���������ESC��������DrawGLScene()���˳���Ϣ
	    if(active)//���򼤻��ô?
	    {
		if(keys[VK_ESCAPE]) // ESC ������ô?
		{
		    done=TRUE;// ESC �����˳��ź�
		    SendMessage(hwnd,WM_CLOSE,0,0);
		}
		else
		{
		    DrawGLScene();
		    SwapBuffers(hDC);
		}
	    }

	   
		
		if(keys[VK_F1])
	    {
		keys[VK_F1]=FALSE;
		KillGLWindow();
		fullscreen=!fullscreen;
		




		if(!CreateGLWindow("NeHe's Texture Tutorial",cxScreen/5,cyScreen/6,3*cxScreen/5,2*cyScreen/3,32,fullscreen))
		{
		    return 0;
		}
		
		if(fullscreen)
		{
		    ReSizeGLScene(cxScreen,cyScreen);
		}
	    }
	}
    }
    KillGLWindow();
    return msg.wParam;
}
