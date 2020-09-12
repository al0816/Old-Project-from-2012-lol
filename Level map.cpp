#include<stdio.h>
#include<windows.h>
#include"sg.h"
#include<time.h>
#include <ctime>
#include<mmsystem.h>
int main()
{
int width=800;
int height=600;
sgCreateWindow(width,height);
HBITMAP image=(HBITMAP)LoadImage(0,"Level.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
HDC Level=CreateCompatibleDC(SGWndDC);
sgSelectTool(Level,image);
BitBlt(SGWndDC,0,0,width,height,Level,0,0,SRCCOPY);

FILE * pFile;
pFile = fopen ("myfile.txt","w");
for (int i = 0; i < width; i++)
{
printf("%d\n",i);
for (int j = 0; j < height; j++)
        {

            if(GetPixel(SGWndDC, i, j)!=255+(255<<8)+(255<<16))
            {

                 fprintf (pFile,"%d\n",0);
            }
            else
            {

                fprintf (pFile,"%d\n",1);
            }

        }
}

fclose (pFile);
printf("DONE");
}

