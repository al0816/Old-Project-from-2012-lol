#include"sg.h"
#include<stdio.h>



int main()
{
    sgCreateWindow(800,600);


    //изображения
    HBITMAP image1000=(HBITMAP)LoadImage(0,"list2.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
    HDC list=CreateCompatibleDC(SGWndDC);
    sgSelectTool(list,image1000);

                 HBITMAP image=(HBITMAP)LoadImage(0,"right.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC right=CreateCompatibleDC(SGWndDC);
                sgSelectTool(right,image);

                HBITMAP image2=(HBITMAP)LoadImage(0,"right2.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC right2=CreateCompatibleDC(SGWndDC);
                sgSelectTool(right2,image2);

                HBITMAP image3=(HBITMAP)LoadImage(0,"right3.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC right3=CreateCompatibleDC(SGWndDC);
                sgSelectTool(right3,image3);

                HBITMAP image4=(HBITMAP)LoadImage(0,"right4.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC right4=CreateCompatibleDC(SGWndDC);
                sgSelectTool(right4,image4);

                HBITMAP image5=(HBITMAP)LoadImage(0,"right5.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC right5=CreateCompatibleDC(SGWndDC);
                sgSelectTool(right5,image5);

                HBITMAP image6=(HBITMAP)LoadImage(0,"right6.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC right6=CreateCompatibleDC(SGWndDC);
                sgSelectTool(right6,image6);

                HBITMAP image7=(HBITMAP)LoadImage(0,"right7.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC right7=CreateCompatibleDC(SGWndDC);
                sgSelectTool(right7,image7);

                HBITMAP image8=(HBITMAP)LoadImage(0,"right8.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC right8=CreateCompatibleDC(SGWndDC);
                sgSelectTool(right8,image8);

                HBITMAP image9=(HBITMAP)LoadImage(0,"right9.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC right9=CreateCompatibleDC(SGWndDC);
                sgSelectTool(right9,image9);

                HBITMAP image10=(HBITMAP)LoadImage(0,"right10.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC right10=CreateCompatibleDC(SGWndDC);
                sgSelectTool(right10,image10);

                HBITMAP image11=(HBITMAP)LoadImage(0,"right11.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC right11=CreateCompatibleDC(SGWndDC);
                sgSelectTool(right11,image11);

                                // 2LEFT


                HBITMAP image12=(HBITMAP)LoadImage(0,"left.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC left=CreateCompatibleDC(SGWndDC);
                sgSelectTool(left,image12);

                HBITMAP image13=(HBITMAP)LoadImage(0,"left2.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC left2=CreateCompatibleDC(SGWndDC);
                sgSelectTool(left2,image13);

                HBITMAP image14=(HBITMAP)LoadImage(0,"left3.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC left3=CreateCompatibleDC(SGWndDC);
                sgSelectTool(left3,image14);

                HBITMAP image40=(HBITMAP)LoadImage(0,"left4.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC left4=CreateCompatibleDC(SGWndDC);
                sgSelectTool(left4,image40);

                HBITMAP image50=(HBITMAP)LoadImage(0,"left5.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC left5=CreateCompatibleDC(SGWndDC);
                sgSelectTool(left5,image50);

                HBITMAP image60=(HBITMAP)LoadImage(0,"left6.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC left6=CreateCompatibleDC(SGWndDC);
                sgSelectTool(left6,image60);

                HBITMAP image70=(HBITMAP)LoadImage(0,"left7.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC left7=CreateCompatibleDC(SGWndDC);
                sgSelectTool(left7,image70);

                HBITMAP image80=(HBITMAP)LoadImage(0,"left8.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC left8=CreateCompatibleDC(SGWndDC);
                sgSelectTool(left8,image80);

                HBITMAP image90=(HBITMAP)LoadImage(0,"left9.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC left9=CreateCompatibleDC(SGWndDC);
                sgSelectTool(left9,image90);

                HBITMAP image100=(HBITMAP)LoadImage(0,"left10.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC left10=CreateCompatibleDC(SGWndDC);
                sgSelectTool(left10,image100);

                HBITMAP image999=(HBITMAP)LoadImage(0,"grass.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC grass=CreateCompatibleDC(SGWndDC);
                sgSelectTool(grass,image999);


                HBITMAP image110=(HBITMAP)LoadImage(0,"left11.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC left11=CreateCompatibleDC(SGWndDC);
                sgSelectTool(left11,image110);
                // конец изображений
                HBITMAP mir= CreateCompatibleBitmap (SGWndDC, 800, 600);
                HDC Mir= CreateCompatibleDC (SGWndDC);
                sgSelectTool(Mir,mir);
                //
                int wX = sgGetMouseX();
                int wY = sgGetMouseY();
                int stand[20][12]={{0}};
                int x=0,y=0;
                int a=0,b=0;
                int yGround=6;
                int walk=0;
                int grounds=0;
                int maxgrounds=3;
                while(grounds<=maxgrounds)
                {

                    stand[grounds][yGround]=1;
                    grounds++;

                    Sleep(5);

                }
                printf("%d\n",grounds);
                int color=0;
                int creator=0;
                while(color!=8)
                {

                    if (stand[color][yGround]==1)
                    {
                        printf("color=%d\n",color);
                        BitBlt(Mir,color*100,yGround*50,color*100+100,yGround*50+12+50,grass,0,0,SRCCOPY);



                           // TransparentBlt (Mir, color*80, yGround*50-12 ,color*80+100,50, grass, 0, 0, 100, 50, RGB ( 255, 255, 255 )  );

                    }
                    color++;
                }
                BitBlt(SGWndDC,0,0,800,600,Mir,0,0,SRCCOPY);
                while(1)
                {


                    a=x/8;
                    b=y/50;
                    printf("%d = a    b=%d\n",a,b);
                    if((stand[a][b+2]!=1)&&(stand[a+1][b+2]!=1))
                    {
                       y++;
                       BitBlt(SGWndDC,0,0,800,600,Mir,0,0,SRCCOPY);
                        TransparentBlt ( SGWndDC, x, y ,100,100, right, 0, 0, 100, 100, RGB ( 255, 255, 255 )  );
                       Sleep(5);
                    }



                     if(GetAsyncKeyState(VK_RIGHT))
                     {
                         walk++;
                         BitBlt(SGWndDC,0,0,800,600,Mir,0,0,SRCCOPY);
                        TransparentBlt ( SGWndDC, x, y ,100,100, right, 0, 0, 100, 100, RGB ( 255, 255, 255 )  );                         x++;
                         Sleep(1);
                     }
                }

}




//                while(!(GetAsyncKeyState(VK_DOWN)))
//                {
//                     BitBlt(SGWndDC,0,0,800,600,Mir,0,0,SRCCOPY);
//                      if(sgGetMouseButtons()==1)
//                        {
//                            wY = sgGetMouseY();
//                            wX = sgGetMouseX();
//                            cordin[wX][wY]=1;
//                        }
//
//                }






