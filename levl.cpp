#include<stdio.h>
#include"sgs.h"
#include<windows.h>

struct levl
{
    int x,y;

};


int monicx=1280;
int monicy=800;

void SaveBMP () {
BITMAPFILEHEADER bfh; //��������� � ���������� �����
BITMAPINFOHEADER bih; //��������� � ��������� ������� ��������
BITMAPINFO bi; //�������� ������� ��� ������� GetDIBits ()
void *pdwBits = NULL; //��������� �� ����� � ������� ��������
DWORD dwWB = 0; //���������� ��� �������� ���������� ���� � ����
HANDLE hFile = NULL; //����� ��������� �����

//������� ������ �����, � ������� ����� ����������� ��������
pdwBits = (void *)GlobalAlloc (GMEM_FIXED, monicx * monicy * 4);

//�������� ���������
memset (&bfh, 0, sizeof (BITMAPFILEHEADER));
memset (&bih, 0, sizeof (BITMAPINFOHEADER));
memset (&bi, 0, sizeof (BITMAPINFO));

//��������� ������������ ���������
bfh.bfType = 0x4D42; // ���������, ��� ��� bmp 'BM'
bfh.bfOffBits = sizeof(bfh) + sizeof(bih);
bfh.bfSize = bfh.bfOffBits + monicx * monicy * 4; // ��������� ������ ��������� �����

//��������� �������� ��������
bih.biSize = sizeof(bih); // ��� ��������
bih.biBitCount = 32; // 16 ��� �� �������
bih.biCompression = BI_RGB; // ��� ������
bih.biHeight = monicy;
bih.biWidth = monicx;
bih.biPlanes = 1;

//�������� � ��������� BITMAPINFO
CopyMemory (&bi, &bih, sizeof (BITMAPINFOHEADER));

//�������� � ������� ������� ���� �������� �� ��������� � ������
GetDIBits (SGWndDC, bmap, 0, monicy, pdwBits, (LPBITMAPINFO)&bi, DIB_RGB_COLORS);

//������� ���� ��� ������
hFile = CreateFile ("save.bmp",
GENERIC_WRITE,
0,
NULL,
CREATE_ALWAYS,
FILE_ATTRIBUTE_NORMAL,
(HANDLE)NULL);
if (hFile == INVALID_HANDLE_VALUE) {
if (pdwBits) GlobalFree (pdwBits);

return;
}

//���������� ��������� � ���������� �����
if (!WriteFile (hFile, (void *)&bfh, sizeof (BITMAPFILEHEADER), &dwWB, NULL)) {

if (pdwBits) GlobalFree (pdwBits);
return;
}

//���������� ��������� � ��������� ������� ��������
if (!WriteFile (hFile, (void *)&bih, sizeof (BITMAPINFOHEADER), &dwWB, NULL)) {

if (pdwBits) GlobalFree (pdwBits);
return;
}

//���������� ������ ���� �������� ����� ���� ���������� ��������
if (!WriteFile (hFile, (void *)pdwBits, monicx * monicy * 4, &dwWB, NULL)) {

if (pdwBits) GlobalFree (pdwBits);
return;
}

//��������� ����� ����� � ������� �����
CloseHandle (hFile);
if (pdwBits) GlobalFree (pdwBits);
return;
}
int main()
{

sgCreateWindow(1280,800);

HBITMAP listD=(HBITMAP)LoadImage(0,"fon.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
HDC fon=CreateCompatibleDC(SGWndDC);
sgSelectTool(fon,listD);

HBITMAP blox=(HBITMAP)LoadImage(0,"block.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
HDC block=CreateCompatibleDC(SGWndDC);
sgSelectTool(block,blox);

HBITMAP blox2=(HBITMAP)LoadImage(0,"block2.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
HDC block2=CreateCompatibleDC(SGWndDC);
sgSelectTool(block2,blox2);

HBITMAP arrowD=(HBITMAP)LoadImage(0,"arrow.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
HDC arrow=CreateCompatibleDC(SGWndDC);
sgSelectTool(arrow,arrowD);

int color=0;
levl mouse;
int object=1;
bool draw=false;
int check=0;

BitBlt(SGWndDC,0,0,1280,800,fon,0,0,SRCCOPY);
while(!GetAsyncKeyState(VK_DOWN))
{
    printf("PRESS DOWN");
      if((sgGetMouseButtons()==1))
                    {
                        mouse.y = sgGetMouseY();
                        mouse.x= sgGetMouseX();
                        color=GetPixel(SGWndDC,mouse.x,mouse.y);
                    }



}
while(!GetAsyncKeyState(VK_UP))
{
     printf("PRESS Up");

      if(GetAsyncKeyState(0x031))
                    {
                        SaveBMP();
                        object=1;
                    }
                    if(GetAsyncKeyState(0x032))
                    {
                        object=2;
                    }
          if((sgGetMouseButtons()==1))
                    {

                        mouse.y = sgGetMouseY();
                        mouse.x= sgGetMouseX();
                        for(int i=0,y=0;y<=32;i++)
                        {
                            if(i==33)
                            {
                                i=0;
                                y++;
                            }
                            if(GetPixel(SGWndDC,mouse.x+i,mouse.y+y)!=color)
                            {
                                check++;
                                break;
                            }
                        }
                        if(check>0)
                        {
                            check=0;
                            draw=false;
                        }
                          else
                        {
                            check=0;
                            draw=true;
                        }


                        if(draw==true)
                        {

                            if(object==1)
                            {
                                  BitBlt(SGWndDC,mouse.x,mouse.y,32,32,block,0,0,SRCCOPY);
                            }
                            if(object==2)
                            {
                                  BitBlt(SGWndDC,mouse.x,mouse.y,32,32,block2,0,0,SRCCOPY);
                            }
                        }

                    }





}

}
