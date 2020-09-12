#include<stdio.h>
#include<windows.h>
#include"sg.h"
#include<time.h>
#include <ctime>
#include<mmsystem.h>
int main()
{

sgCreateWindow(800,600);
    HBITMAP fall_R=(HBITMAP)LoadImage(0,"level.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
    HDC fallR=CreateCompatibleDC(SGWndDC);
    sgSelectTool(fallR,fall_R);
BitBlt(SGWndDC,0,0,800,600,fallR,0,0,SRCCOPY);
int x=255+(255<<8)+(255<<16),y,timer=0;
unsigned int z=0;

while(sgGetMouseButtons()!=1)
{
timer++;
 if(timer==10)
{
        timer=0;
        x=sgGetMouseX();
        y=sgGetMouseY();
        z=GetPixel(SGWndDC,x,y);
        printf("%d\n",z );
}


}
unsigned int a=z<<8;
printf("%d %d",a,z);
}
