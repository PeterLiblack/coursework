
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




bool	keys[256]; // 保存键盘按键的数组
bool	active=true;// 窗口的活动标志，缺省为TRUE
bool	fullscreen=true;// 全屏标志缺省，缺省设定成全屏模式

GLfloat xrot;// X 旋转
GLfloat yrot;// y 旋转
GLfloat zrot;// z 旋转


GLuint	texture[6];//存储6个纹理

int cxScreen=GetSystemMetrics(SM_CXSCREEN);
int cyScreen=GetSystemMetrics(SM_CYSCREEN);

LRESULT CALLBACK WndProc(HWND hwnd,UINT message,WPARAM wParam,LPARAM lParam);

AUX_RGBImageRec* LoadBMP(char* filename)// 载入位图图象,图像存储为bmp形式
{
    FILE* file=NULL;

    if(!filename)// 确保文件名已提供
    {
	return NULL;
    }

    file=fopen(filename,"r");// 打开文件

    if(file)
    {
	fclose(file);
	return auxDIBImageLoad(filename);
    }
    return NULL;
}

int LoadGLTextures()// 根据加载的位图创建纹理
{
    int status=FALSE; // 指示纹理创建是否成功的标志
    
  
    AUX_RGBImageRec* textureImage[6];//OpenGL可以把纹理映射到指定的图形的表面上创建一个纹理图像数组，这里指定数组大小为6
    memset(textureImage,0,sizeof(AUX_RGBImageRec*)*6);//初始化纹理图像数组，为其分配内存
    char* texImg[6]={"data\\front.bmp","data\\back.bmp","data\\top.bmp",
	             "data\\bottom.bmp","data\\right.bmp","data\\left.bmp"};// 创建一个位图名称数组，对应6幅位图
    
    for(int i=0;i<6;i++)// 遍历位图名称数组，根据位图名称分别生成
    {
	if(textureImage[i]=LoadBMP(texImg[i]))// 加载位图i成功，修改状态标志变量Status为TRUE
	{
	    status=TRUE;
	    glGenTextures(1,&texture[i]);  // 为第i个位图创建纹理
	    glBindTexture(GL_TEXTURE_2D,texture[i]);// 将生成的纹理的名称绑定到指定的纹理上
	    glTexImage2D(GL_TEXTURE_2D,0,3,textureImage[i]->sizeX,textureImage[i]->sizeY,
		         0,GL_RGB,GL_UNSIGNED_BYTE,textureImage[i]->data);

	    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	}

	if(textureImage[i])// 释放位图数组占用的内存空间
	{
	    if(textureImage[i]->data)
	    {
		free(textureImage[i]->data);
	    }
	    free(textureImage[i]);
	}
    }

    return status;// 创建纹理并加载，返回成功或者失败的标志Status
}

GLvoid ReSizeGLScene(GLsizei width,GLsizei height)// 重置OpenGL窗口大小
{
    if(0==height)
    {
	height=1;
    }

    glViewport(0,0,width,height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(30.0f,(GLfloat)width/(GLfloat)height,1.0f,100.0f);// 设置视口的大小

    glMatrixMode(GL_MODELVIEW);// 选择模型观察矩阵
    glLoadIdentity();// 重置模型观察矩阵
}

int InitGL(GLvoid)// 此处开始对OpenGL进行所有设置

{
    if(!LoadGLTextures())// 调用纹理载入子例程
    {
	MessageBox(NULL,"LoadGLTextures Failed!","Error",MB_OK | MB_ICONEXCLAMATION);// after error ocured,added for debug
	return FALSE;// 如果未能载入，返回FALSE
    }
    glEnable(GL_TEXTURE_2D); // 启用纹理映射
    glShadeModel(GL_SMOOTH);// 启用阴影平滑
    glClearColor(0.0f,0.0f,0.0f,0.5f);// 黑色背景
    glClearDepth(1.0f);// 设置深度缓存
    glEnable(GL_DEPTH_TEST); // 启用深度测试
    glDepthFunc(GL_LEQUAL);// 所作深度测试的类型

    glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);// 真正精细的透视修正

    return true;
}

int DrawGLScene(GLvoid)// 从这里开始进行所有的绘制
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0.0f,0.0f,-5.5f);

    glRotatef(xrot,1.0f,0.0f,0.0f);// 绕X轴旋转
    glRotatef(yrot,0.0f,1.0f,0.0f);// 绕y轴旋转
    glRotatef(zrot,0.0f,0.0f,1.0f);// 绕z轴旋转

    
    
    // front face  前侧面
    glBindTexture(GL_TEXTURE_2D,texture[0]);
    glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f); glVertex3f(-1.0f,-1.0f,1.0f);
	glTexCoord2f(1.0f,0.0f); glVertex3f(1.0f,-1.0f,1.0f);
	glTexCoord2f(1.0f,1.0f); glVertex3f(1.0f,1.0f,1.0f);
	glTexCoord2f(0.0f,1.0f); glVertex3f(-1.0f,1.0f,1.0f);
    glEnd();
    // back face后侧面
    glBindTexture(GL_TEXTURE_2D,texture[1]);
    glBegin(GL_QUADS);
	glTexCoord2f(1.0f,0.0f); glVertex3f(-1.0f,-1.0f,-1.0f);
	glTexCoord2f(0.0f,0.0f); glVertex3f(1.0f,-1.0f,-1.0f);
	glTexCoord2f(0.0f,1.0f); glVertex3f(1.0f,1.0f,-1.0f);
	glTexCoord2f(1.0f,1.0f); glVertex3f(-1.0f,1.0f,-1.0f);
    glEnd();
    // top face顶面
    glBindTexture(GL_TEXTURE_2D,texture[2]);
    glBegin(GL_QUADS);
	glTexCoord2f(0.0f,0.0f); glVertex3f(-1.0f,1.0f,1.0f);
	glTexCoord2f(1.0f,0.0f); glVertex3f(1.0f,1.0f,1.0f);
	glTexCoord2f(1.0f,1.0f); glVertex3f(1.0f,1.0f,-1.0f);
	glTexCoord2f(0.0f,1.0f); glVertex3f(-1.0f,1.0f,-1.0f);
    glEnd();
    // bottom face底面
    glBindTexture(GL_TEXTURE_2D,texture[3]);
    glBegin(GL_QUADS);
	glTexCoord2f(1.0f,0.0f); glVertex3f(-1.0f,-1.0f,1.0f);
	glTexCoord2f(0.0f,0.0f); glVertex3f(1.0f,-1.0f,1.0f);
	glTexCoord2f(0.0f,1.0f); glVertex3f(1.0f,-1.0f,-1.0f);
	glTexCoord2f(1.0f,1.0f); glVertex3f(-1.0f,-1.0f,-1.0f);
    glEnd();
    // right face 右侧面
    glBindTexture(GL_TEXTURE_2D,texture[4]);
    glBegin(GL_QUADS);
	glTexCoord2f(0.0f,1.0f); glVertex3f(1.0f,1.0f,1.0f);
	glTexCoord2f(0.0f,0.0f); glVertex3f(1.0f,-1.0f,1.0f);
	glTexCoord2f(1.0f,0.0f); glVertex3f(1.0f,-1.0,-1.0f);
	glTexCoord2f(1.0f,1.0f); glVertex3f(1.0f,1.0f,-1.0f);
    glEnd();
    // left face左侧面
    glBindTexture(GL_TEXTURE_2D,texture[5]);
    glBegin(GL_QUADS);
	glTexCoord2f(1.0f,1.0f); glVertex3f(-1.0f,1.0f,1.0f);
	glTexCoord2f(1.0f,0.0f); glVertex3f(-1.0f,-1.0f,1.0f);
	glTexCoord2f(0.0f,0.0f); glVertex3f(-1.0f,-1.0,-1.0f);
	glTexCoord2f(0.0f,1.0f); glVertex3f(-1.0f,1.0f,-1.0f);
    glEnd();

    xrot+=0.1;//绕X轴转速 
    yrot+=0.1;
    zrot+=0.1;

    return true;
}

GLvoid KillGLWindow(GLvoid) // 正常销毁窗口
{
    if(fullscreen)// 我们处于全屏模式吗?
    {
	ChangeDisplaySettings(NULL,0);
	ShowCursor(TRUE);
    }

    if(hRC!=NULL)
    {
	if(!wglMakeCurrent(NULL,NULL))// 我们能否释放DC和RC描述表?
	{
	    MessageBox(NULL," 释放DC或RC失败","关闭错误 ",MB_OK | MB_ICONINFORMATION);
	}

	if(!wglDeleteContext(hRC)) // 我们能否删除RC?
	{
	    MessageBox(NULL,"释放RC失败!","关闭错误",MB_OK | MB_ICONINFORMATION);
	}
	hRC=NULL;
    }

    if(hDC!=NULL && !ReleaseDC(hwnd,hDC)) // 我们能否释放 DC?
    {
	MessageBox(NULL,"释放DC失败!","关闭错误",MB_OK | MB_ICONINFORMATION);
	hDC=NULL;
    }

    if(hwnd!=NULL && !DestroyWindow(hwnd))// 能否销毁窗口?
    {
	MessageBox(NULL,"释放窗口句柄失败!","关闭错误",MB_OK | MB_ICONINFORMATION);
	hwnd=NULL;
    }

    if(!UnregisterClass("OpenGL",hInstance))// 能否注销类?
    {
	MessageBox(NULL,"不能注销窗口类","关闭错误",MB_OK | MB_ICONINFORMATION);
	hInstance=NULL;
    }
}

BOOL CreateGLWindow(char* title,int x,int y,int width,int height,int bits,bool fullscreenflag)
{
    GLuint pixelFormat;// 保存查找匹配的结果
    WNDCLASS wc;
    DWORD dwExStyle;
    DWORD dwStyle;

    RECT windowRect;
    windowRect.left=(long)x;// 将Left   设为 x
    windowRect.top=(long)y;
    windowRect.right=(long)(width+x);
    windowRect.bottom=(long)(height+y);

    fullscreen=fullscreenflag;// 设置全局全屏标志
    
    hInstance=GetModuleHandle(NULL);// 取得我们窗口的实例

 wc.style        = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;        // 移动时重画，并为窗口取得DC
    wc.lpfnWndProc        = (WNDPROC) WndProc;                // WndProc处理消息

    wc.cbClsExtra=0;
    wc.cbWndExtra=0;
    wc.hbrBackground=NULL;
    wc.hCursor=LoadCursor(NULL,IDC_ARROW); // 装入鼠标指针
    wc.hIcon=LoadIcon(NULL,IDI_APPLICATION);
    wc.hInstance=hInstance;
    wc.lpfnWndProc=WndProc;
    wc.lpszClassName="OpenGL";
    wc.lpszMenuName=NULL;
    wc.style=CS_HREDRAW | CS_VREDRAW | CS_OWNDC;

    if(!RegisterClass(&wc))// 尝试注册窗口类
    {
	MessageBox(NULL,"注册窗口失败","错误",MB_OK | MB_ICONEXCLAMATION);
	return FALSE;
    }

    if(fullscreen)// 要尝试全屏模式吗?
    {
	DEVMODE dm;
	memset(&dm,0,sizeof(DEVMODE));
	dm.dmSize=sizeof(DEVMODE);
	dm.dmBitsPerPel=bits;
	dm.dmPelsWidth=cxScreen;
	dm.dmPelsHeight=cyScreen;
	dm.dmFields=DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;
	
	if(ChangeDisplaySettings(&dm,CDS_FULLSCREEN)!=DISP_CHANGE_SUCCESSFUL)
	{// 若模式失败，提供两个选项：退出或在窗口内运行。
	    if(MessageBox(NULL,"全屏模式在当前显卡上设置失败！\n使用窗口模式？","NeHe G",MB_YESNO | MB_ICONEXCLAMATION)==IDYES)
	    {
		fullscreen=FALSE;// 选择窗口模式(Fullscreen=FALSE)
	    }
	    else
	    {
		MessageBox(NULL,"程序将被关闭","错误",MB_OK | MB_ICONSTOP);
		return FALSE;
	    }
	}
    }

    if(fullscreen) // 仍处于全屏模式吗?
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

    AdjustWindowRectEx(&windowRect,dwStyle,FALSE,dwExStyle);// 调整窗口达到真正要求的大小

    if(!(hwnd=CreateWindowEx(dwExStyle,"OpenGL",title,WS_CLIPCHILDREN | WS_CLIPSIBLINGS | dwStyle,
			     x,y,width,height,
			     NULL,NULL,hInstance,NULL)))
    {
	KillGLWindow();// 重置显示区
	MessageBox(NULL,"不能创建一个窗口设备描述表","错误",MB_OK | MB_ICONEXCLAMATION);
	return FALSE;
    }

    if(fullscreen)
    {
	SetWindowPos(hwnd,HWND_TOP,0,0,cxScreen,cyScreen,SWP_SHOWWINDOW);
    }

    static PIXELFORMATDESCRIPTOR pfd=// /pfd 告诉窗口我们所希望的东东，即窗口使用的像素格式
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
	MessageBox(NULL,"不能创建一种相匹配的像素格式","错误",MB_OK | MB_ICONEXCLAMATION);
	return FALSE;
    }

    if(!(pixelFormat=ChoosePixelFormat(hDC,&pfd)))
    {
	KillGLWindow();
	MessageBox(NULL,"不能设置像素格式","错误",MB_OK | MB_ICONEXCLAMATION);
	return FALSE;
    }

    if(!SetPixelFormat(hDC,pixelFormat,&pfd))
    {
	KillGLWindow();
	MessageBox(NULL,"不能设置像素格式","错误r",MB_OK | MB_ICONEXCLAMATION);
	return FALSE;
    }

    if(!(hRC=wglCreateContext(hDC)))
    {
	KillGLWindow();
	MessageBox(NULL,"不能创建OpenGL渲染描述表","错误",MB_OK | MB_ICONEXCLAMATION);
	return FALSE;
    }

    if(!wglMakeCurrent(hDC,hRC))
    {
	KillGLWindow();
	MessageBox(NULL,"不能激活当前的OpenGL渲然描述表","错误",MB_OK | MB_ICONEXCLAMATION);
	return FALSE;
    }

    ShowWindow(hwnd,SW_SHOW);// 显示窗口
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

    if(MessageBox(NULL,"你想在全屏模式下运行么？","设置全屏模式",MB_YESNO | MB_ICONQUESTION)==IDNO)
    {
	fullscreen=FALSE;
    }

    if(!CreateGLWindow("纹理映射 ",cxScreen/5,cyScreen/6,3*cxScreen/5,2*cyScreen/3,32,fullscreen))// 创建OpenGL窗口
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
	{// 绘制场景。监视ESC键和来自DrawGLScene()的退出消息
	    if(active)//程序激活的么?
	    {
		if(keys[VK_ESCAPE]) // ESC 按下了么?
		{
		    done=TRUE;// ESC 发出退出信号
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
