 #include "sg.h"


#include"sg.h"
#include"windows.h"
#include<stdio.h>
int main()
{


sgCreateWindow(800,600);

HBITMAP image=(HBITMAP)LoadImage(0,"right.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
HDC right=CreateCompatibleDC(SGWndDC);
sgSelectTool(right,image);


sgSelectTool(wall,imagewall);

HBITMAP image10=(HBITMAP)LoadImage(0,"list2.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
HDC lista=CreateCompatibleDC(SGWndDC);
sgSelectTool(lista,image10);

HBITMAP image100500 = CreateCompatibleBitmap (SGWndDC, 800, 600);
HDC KARTINKA_C_KARTOY = CreateCompatibleDC (SGWndDC);
sgSelectTool(KARTINKA_C_KARTOY, image100500);

bool surf=false;
bool walls=false;
BitBlt(KARTINKA_C_KARTOY,0,0,800,600,lista,0,0,SRCCOPY);


    int cordin[800][600];



for( int ie=0;ie!=800;ie++)
{
    if(cordin[ie][300]==1)
    {
      BitBlt(KARTINKA_C_KARTOY,ie,300,ie+1,301,list2,0,0,SRCCOPY);

    }
    if( cordin[300][ie]==2)
    {
      BitBlt(KARTINKA_C_KARTOY,300,ie,301,ie+1,wall,0,0,SRCCOPY);

    }

}
int wX = sgGetMouseX();
int wY = sgGetMouseY();
while(!(GetAsyncKeyState(VK_DOWN)))
{
    BitBlt(SGWndDC,0,0,800,600,KARTINKA_C_KARTOY,0,0,SRCCOPY);

     if(sgGetMouseButtons()==1)
    {
   wY = sgGetMouseY();
   wX = sgGetMouseX();

cordin[wX][wY]=1;


for(int c=0;c!=101;c++)
{
    cordin[wX+c][wY]=1;
     BitBlt(KARTINKA_C_KARTOY,wX+c,wY,wX+c+1,wY+1,list2,0,0,SRCCOPY);
    BitBlt(SGWndDC,0,0,800,600,KARTINKA_C_KARTOY,0,0,SRCCOPY);

}





   }


}

BitBlt(SGWndDC,0,0,800,600,KARTINKA_C_KARTOY,0,0,SRCCOPY);
 TransparentBlt ( SGWndDC, xo, yo,94,88, right, 0, 0, 94, 88, RGB ( 255, 255, 255 )  );

while(1)
{

 for(int o=0;o!=94;o++)
     {
       if(cordin[xo+o][yo+89]==1)
         {
             surf=true;

             break;

         }
        else
        {
             surf=false;
            printf("%d\n",yo);

        }
     }
   if(surf==false)
    {

        yo++;
        BitBlt(SGWndDC,0,0,800,600,KARTINKA_C_KARTOY,0,0,SRCCOPY);
         TransparentBlt ( SGWndDC, xo, yo,94,88, right, 0, 0, 94, 88, RGB ( 255, 255, 255 )  );

        Sleep(10);
     }

    if(GetAsyncKeyState(VK_RIGHT)&&(cordin[xo+95][yo+5]!=2))
    {
        xo++;
    BitBlt(SGWndDC,0,0,800,600,KARTINKA_C_KARTOY,0,0,SRCCOPY);
      TransparentBlt ( SGWndDC, xo, yo ,94,88, right, 0, 0, 94, 88, RGB ( 255, 255, 255 )  );

     Sleep(7);
    }
       if(GetAsyncKeyState(VK_LEFT)&&(cordin[xo-1][yo+5]!=2))
    {
        xo--;
    BitBlt(SGWndDC,0,0,800,600,KARTINKA_C_KARTOY,0,0,SRCCOPY);
     TransparentBlt ( SGWndDC, xo, yo ,94,88, right, 0, 0, 94, 88, RGB ( 255, 255, 255 )  );
printf("xx   %d\n",xo);
printf("y    %d\n",yo);
     Sleep(7);
    }
}
}
