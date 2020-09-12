#include<stdio.h>
#include<windows.h>
#include"sg.h"
#include<time.h>
#include <ctime>
#include<mmsystem.h>
int main()
{
    sgCreateWindow(800,600);
    HBITMAP white=(HBITMAP)LoadImage(0,"darkleft2.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
    HDC whitelist=CreateCompatibleDC(SGWndDC);
    sgSelectTool(whitelist,white);
     TransparentBlt(SGWndDC,200,300,50,88,whitelist,0,0,94,88,RGB ( 255, 255, 255));
     Sleep(19999);
}
