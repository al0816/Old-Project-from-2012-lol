#include"sg.h"
#include"windows.h"
#include<stdio.h>
int main()
{
    sgCreateWindow(1280,600);


    //изображения
                HBITMAP image1000=(HBITMAP)LoadImage(0,"list2.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC World=CreateCompatibleDC(SGWndDC);
                sgSelectTool(World,image1000);

                HBITMAP blox=(HBITMAP)LoadImage(0,"block.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC block=CreateCompatibleDC(SGWndDC);
                sgSelectTool(block,blox);

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


                HBITMAP white=(HBITMAP)LoadImage(0,"pic0.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC whitelist=CreateCompatibleDC(SGWndDC);
                sgSelectTool(whitelist,white);
                //DeClaRing A jump :o
                HBITMAP jumppose1=(HBITMAP)LoadImage(0,"jump.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC jump0=CreateCompatibleDC(SGWndDC);
                sgSelectTool(jump0,jumppose1);

                 HBITMAP jumpposeL=(HBITMAP)LoadImage(0,"jumpL.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC jumpL=CreateCompatibleDC(SGWndDC);
                sgSelectTool(jumpL,jumpposeL);

                 HBITMAP jumppose2=(HBITMAP)LoadImage(0,"jump2.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC jump2=CreateCompatibleDC(SGWndDC);
                sgSelectTool(jump2,jumppose2);

                 HBITMAP jumppose2L=(HBITMAP)LoadImage(0,"jump2L.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC jump2L=CreateCompatibleDC(SGWndDC);
                sgSelectTool(jump2L,jumppose2L);

                HBITMAP jumppre1=(HBITMAP)LoadImage(0,"jumppre.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC jumppre=CreateCompatibleDC(SGWndDC);
                sgSelectTool(jumppre,jumppre1);

                HBITMAP jumpprel=(HBITMAP)LoadImage(0,"jumppreL.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC jumppreL=CreateCompatibleDC(SGWndDC);
                sgSelectTool(jumppreL,jumpprel);



                //declaring a fire

                HBITMAP fireballRD=(HBITMAP)LoadImage(0,"fireballR.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC fireballR=CreateCompatibleDC(SGWndDC);
                sgSelectTool(fireballR,fireballRD);


                //declaring a fall
                 HBITMAP fall0=(HBITMAP)LoadImage(0,"fallR.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC fallR=CreateCompatibleDC(SGWndDC);
                sgSelectTool(fallR,fall0);

                       HBITMAP fall2=(HBITMAP)LoadImage(0,"fallL.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC fallL=CreateCompatibleDC(SGWndDC);
                sgSelectTool(fallL,fall2);

// arowz

                HBITMAP arrowD=(HBITMAP)LoadImage(0,"arrow.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC arrow=CreateCompatibleDC(SGWndDC);
                sgSelectTool(arrow,arrowD);


//незнаю надо ли ещё 1 бул для проверки ввоздухе. i just dont know what went wrong:o

int partypose=0;
int partyposeL=0;
int jumpfor=0;
int oldmouseX=0;
int oldmouseY=0;

int xCheckLeft=0;
//
int fireballLaunched=false;
double fireballX=0;
int fireballY=0;
//

bool wallAirR=false;
bool wallAirL=false;


                HBITMAP mir= CreateCompatibleBitmap (SGWndDC, 1280, 600);
                HDC Mir= CreateCompatibleDC (SGWndDC);
                sgSelectTool(Mir,mir);


                 int xLevel=600;
                int fall=0;
                    bool wallR=false;
                    bool wallL=false;

                double x=70;
                int y=0;

                int xHill=0;
                int yHill=400;
                int Hills=0;
                bool lime=false;
                int MaxHills=7;
                int moveR=0;
                int life=3;
                   int moveL=0;
                int mouseX=sgGetMouseX();
                int mouseY=sgGetMouseY();
                bool colorcheck=false;
                int idle=0;
                int Direction=1;
                int drawCheckX=0;
                int boolCheck=0;
        int object=0;
        int objectCheck=0;

               // BitBlt(Mir,xLevel,0,xLevel+800,600,World,0,0,SRCCOPY);
               // TransparentBlt ( SGWndDC, x, y ,94,88, right, 0, 0, 94, 88, RGB ( 255, 255, 255 )  );
                BitBlt(SGWndDC,0,0,xLevel+880,600,Mir,0,0,SRCCOPY);
                while(Hills!=MaxHills)
                {

                    TransparentBlt(Mir,xHill,yHill,100,50,grass,0,0,100,50,RGB ( 255, 255, 255));
                    xHill+=100;
                    Hills++;
                }
                int yBl=0;
                bool blockcheck=false;
                //Level editor ^_^ lol.
               while(!(GetAsyncKeyState(VK_DOWN)))
                {
                    if(GetAsyncKeyState(0x031))
                    {
                        object=1;
                    }
                    if(GetAsyncKeyState(0x032))
                    {
                        object=2;
                    }




                    if((sgGetMouseButtons()==1))
                    {
                    mouseY = sgGetMouseY();
                    mouseX = sgGetMouseX();

                         objectCheck++;


                    if(object==1)
                    {




                        for(int i=0,yc=0;i!=32*32;i++)
                        {

                            if((GetPixel(Mir,drawCheckX+mouseX,mouseY+yc)!=RGB(0,0,0))||(GetPixel(Mir,drawCheckX+mouseX,mouseY)!=RGB(0,0,0)))
                            {

                                lime=true;
                                break;
                            }
                            else
                            {
                                lime=false;
                            }
                            drawCheckX++;
                            if( drawCheckX==32)
                            {
                                 drawCheckX=0;
                                 yc++;
                            }


                        }

                         drawCheckX=0;
                        if(lime==false)
                        {
                            printf("yes\n");
                            BitBlt(Mir,mouseX,mouseY,mouseX+32,mouseY+32,block,0,0,SRCCOPY);
                            BitBlt(SGWndDC,0,0,xLevel+880,600,Mir,0,0,SRCCOPY);

                        }
                    }



                    if(object==2)
                    {

                         for(int i=0,yc=0,i2=0;i!=8*43;i++)
                        {


                            if((GetPixel(Mir,i2+mouseX,mouseY+yc)!=RGB(0,0,0))||(GetPixel(Mir,mouseX,mouseY)!=RGB(0,0,0)))
                            {

                                lime=true;
                                break;
                            }
                            else
                            {
                                lime=false;
                            }
                            i2++;
                            if(i2==8)
                            {
                                i2=0;
                                yc++;
                            }



                        }

                        if(lime==false)
                        {
                            printf("yes\n");
                            TransparentBlt ( Mir, mouseX, mouseY ,8,43, arrow, 0, 0, 8, 43, RGB ( 255, 255, 255 )  );

                            BitBlt(SGWndDC,0,0,xLevel+880,600,Mir,0,0,SRCCOPY);

                        }


                    }



                }
                }
                //LEVEL EDITOR ENDZ:/


double firerange=0;
double firerangemax=300.00000000;
int jump=0;
int fire=0;
  int fireblt=0;
                   start:  while(1)
                    {

                        if(life==0)
                        {
                            for(int i=0;i!=1;i++)
                        {
                             printf("GAME OVER LOL\nFOR NEW GAME PRESS 3,ALSO PRESS 3 TO WIN");


                        }
                        if(GetAsyncKeyState(0x033))
                        {
                            life=3;
                            x=0;
                            y=0;
                            goto start;
                        }

                        }
                        if(life>0)
                        {



                        //breaks points  grounds check
                        for(int i=26;i!=69;i++)
                        {

                            if((GetPixel(Mir,x+i,y+88)==RGB(124,252,0)||(GetPixel(Mir,x+i,y+88)==RGB(68,116,244))))
                            {

                               colorcheck=true;
                                 jump=0;
                               fall=0;
                               break;
                            }
                            else
                            {
                                colorcheck=false;
                            }

                        }
                          for(int i=26;i!=69;i++)
                        {
                        if(GetPixel(Mir,x+i,y+89)==RGB(152,248,216))
                            {


                               life--;
                                jumpfor=0;

                                goto label;
                            }


                        }


                        if(colorcheck==false)
                        {
                          partypose=0;

                            idle=0;
                            fall=1;
                            y++;
                            if(Direction==1)
                            {


                            BitBlt(SGWndDC,0,0,xLevel+880,600,Mir,0,0,SRCCOPY);
                            TransparentBlt ( SGWndDC, x, y ,94,88, fallR, 0, 0, 94, 88, RGB ( 255, 255, 255 )  );
                            Sleep(8);
                            }
                            if(Direction==0)
                            {


                            BitBlt(SGWndDC,0,0,xLevel+880,600,Mir,0,0,SRCCOPY);
                            TransparentBlt ( SGWndDC, x, y ,94,88, fallL, 0, 0, 94, 88, RGB ( 255, 255, 255 )  );
                            Sleep(8);
                            }

                            if(GetAsyncKeyState(VK_RIGHT))
                            {
                                      Direction=1;
                                for(int i=0;i!=88;i++)
                            {
                                if(GetPixel(SGWndDC,x+69,y+i)==RGB(68,116,244)||(GetPixel(SGWndDC,x+69,y+i)==RGB(1,0,0)))
                                {

                                    wallR=true;
                                    break;
                                }
                                else
                                {
                                    wallR=false;
                                }
                            }
                            if(wallR==false)
                            {


                                x+=0.4;
                            }
                            }
                             if(GetAsyncKeyState(VK_LEFT))
                            {
                                Direction=0;
                                for(int i=0;i!=88;i++)
                            {
                                if(GetPixel(SGWndDC,x+25,y+i)==RGB(68,116,244))
                                {

                                    wallL=true;
                                    break;
                                }
                                else
                                {
                                    wallL=false;
                                }
                            }
                            if(wallL==false)
                            {


                                x-=0.4;
                            }
                            }

                        }


                        if(GetAsyncKeyState(0x034)&&(fireballLaunched==false)&&(moveR==0)&&(fall==0)&&!(GetAsyncKeyState(VK_RIGHT)))
                        {

                            fireballX=x+96;
                            fireballY=y+20;
                            fireballLaunched=true;


                        }
                        if(fireballLaunched==true)
                        {

                              fireballX+=0.05;
                                fire++;
                                fireblt++;
                        if(fireblt==20)
                        {
                            fireblt=0;
                            if(!GetAsyncKeyState(VK_RIGHT))
                            {


                            BitBlt(SGWndDC,0,0,xLevel+880,600,Mir,0,0,SRCCOPY);
                            TransparentBlt ( SGWndDC, fireballX, fireballY ,26,14, fireballR, 0, 0, 26, 14, RGB ( 255, 255, 255 )  );
                            }


                            }




                        }
                        if(fire==1500)
                        {
                            fire=0;
                            firerange=0;
 BitBlt(SGWndDC,0,0,xLevel+880,600,Mir,0,0,SRCCOPY);
    TransparentBlt ( SGWndDC, x, y ,94,88, right, 0, 0, 94, 88, RGB ( 255, 255, 255 )  );

                        fireballLaunched=false;


                        }


//RIGHT WALk
                        if(GetAsyncKeyState(VK_RIGHT)&&(fall==0))
                        {

                            Direction=1;
                            for(int i=0;i!=88;i++)
                            {
                                if((GetPixel(Mir,x+69,y+i)==RGB(68,116,244))||(GetPixel(Mir,x+69,y+i)==RGB(1,0,0)))
                                {


                                    wallR=true;
                                    break;
                                }
                                else
                                {
                                    wallR=false;
                                }
                            }
                            if((wallR==true)&&(fall==0))
                            {
                            BitBlt(SGWndDC,0,0,xLevel+880,600,Mir,0,0,SRCCOPY);
                             TransparentBlt ( SGWndDC, x, y ,94,88, right, 0, 0, 94, 88, RGB ( 255, 255, 255 )  );
                             moveR=0;
                            }
                            if(wallR==false)
                            {
                             idle=0;

                            x+=0.1;
                            moveR++;
                            printf("%d\n",moveR);

                            if(moveR==1)
                            {
                            BitBlt(SGWndDC,0,0,xLevel+880,600,Mir,0,0,SRCCOPY);
                            TransparentBlt ( SGWndDC, x, y ,94,88, right, 0, 0, 94, 88, RGB ( 255, 255, 255 )  );
                            }
                             if(moveR==70)
                            {
                            BitBlt(SGWndDC,0,0,xLevel+880,600,Mir,0,0,SRCCOPY);
                            TransparentBlt ( SGWndDC, x, y ,94,88, right2, 0, 0, 94, 88, RGB ( 255, 255, 255 )  );
                            }
                             if(moveR==120)
                            {
                            BitBlt(SGWndDC,0,0,xLevel+880,600,Mir,0,0,SRCCOPY);
                             TransparentBlt ( SGWndDC, x, y ,94,88, right3, 0, 0, 94, 88, RGB ( 255, 255, 255 )  );
                            }
                             if(moveR==180)
                            {


                            BitBlt(SGWndDC,0,0,xLevel+880,600,Mir,0,0,SRCCOPY);
                             TransparentBlt ( SGWndDC, x, y ,94,88, right4, 0, 0, 94, 88, RGB ( 255, 255, 255 )  );


                            }
                             if(moveR==240)
                            {


                            BitBlt(SGWndDC,0,0,xLevel+880,600,Mir,0,0,SRCCOPY);
                             TransparentBlt ( SGWndDC, x, y ,94,88, right5, 0, 0, 94, 88, RGB ( 255, 255, 255 )  );
                            }
                             if(moveR==300)
                            {


                            BitBlt(SGWndDC,0,0,xLevel+880,600,Mir,0,0,SRCCOPY);
                             TransparentBlt ( SGWndDC, x, y ,94,88, right6, 0, 0, 94, 88, RGB ( 255, 255, 255 )  );
                            }
                             if(moveR==360)
                            {
                            BitBlt(SGWndDC,0,0,xLevel+880,600,Mir,0,0,SRCCOPY);
                             TransparentBlt ( SGWndDC, x, y ,94,88, right7, 0, 0, 94, 88, RGB ( 255, 255, 255 )  );

                            }
                             if(moveR==420)
                            {
                            BitBlt(SGWndDC,0,0,xLevel+880,600,Mir,0,0,SRCCOPY);
                             TransparentBlt ( SGWndDC, x, y ,94,88, right8, 0, 0, 94, 88, RGB ( 255, 255, 255 )  );
                            }
                             if(moveR==480)
                            {


                            BitBlt(SGWndDC,0,0,xLevel+880,600,Mir,0,0,SRCCOPY);
                             TransparentBlt ( SGWndDC, x, y ,94,88, right9, 0, 0, 94, 88, RGB ( 255, 255, 255 )  );
                        }
                             if(moveR==540)
                            {
                            BitBlt(SGWndDC,0,0,xLevel+880,600,Mir,0,0,SRCCOPY);
                             TransparentBlt ( SGWndDC, x, y ,94,88, right10, 0, 0, 94, 88, RGB ( 255, 255, 255 )  );
                        }
                             if(moveR==600)
                            {
                        BitBlt(SGWndDC,0,0,xLevel+880,600,Mir,0,0,SRCCOPY);
                        TransparentBlt ( SGWndDC, x, y ,94,88, right11, 0, 0, 94, 88, RGB ( 255, 255, 255 )  );
                        moveR=0;
                            }

                            }
                            if(fireballLaunched==true)
                        {
                             TransparentBlt ( SGWndDC, fireballX, fireballY ,26,14, fireballR, 0, 0, 26, 14, RGB ( 255, 255, 255 )  );

                        }


                        }


                         if(GetAsyncKeyState(VK_LEFT)&&(fall==0))
                        {
                            Direction=0;
                            for(int i=0;i!=88;i++)
                            {
                                if(GetPixel(Mir,x+25,y+i)==RGB(68,116,244)||(GetPixel(Mir,x+25,y+i)==RGB(1,0,0)))
                                {

                                    wallL=true;

                                    break;
                                }
                                else
                                {
                                    wallL=false;
                                }
                            }
                             if((wallL==true)&&(fall==0))
                            {
                            BitBlt(SGWndDC,0,0,xLevel+880,600,Mir,0,0,SRCCOPY);
                             TransparentBlt ( SGWndDC, x, y ,94,88, left, 0, 0, 94, 88, RGB ( 255, 255, 255 )  );
                             Sleep(30);
                             moveL=0;
                            }
                            if(wallL==false)
                            {



                             idle=0;

                            x--;
                            moveL++;

                            if(moveL==1)
                            {
                            BitBlt(SGWndDC,0,0,xLevel+880,600,Mir,0,0,SRCCOPY);
                             TransparentBlt ( SGWndDC, x, y ,94,88, left, 0, 0, 94, 88, RGB ( 255, 255, 255 )  );
                             Sleep(30);
                            }
                             if(moveL==2)
                            {


                            BitBlt(SGWndDC,0,0,xLevel+880,600,Mir,0,0,SRCCOPY);
                             TransparentBlt ( SGWndDC, x, y ,94,88, left2, 0, 0, 94, 88, RGB ( 255, 255, 255 )  );
                             Sleep(30);

                            }
                             if(moveL==3)
                            {


                            BitBlt(SGWndDC,0,0,xLevel+880,600,Mir,0,0,SRCCOPY);
                             TransparentBlt ( SGWndDC, x, y ,94,88, left3, 0, 0, 94, 88, RGB ( 255, 255, 255 )  );
                             Sleep(30);

                            }
                             if(moveL==4)
                            {


                            BitBlt(SGWndDC,0,0,xLevel+880,600,Mir,0,0,SRCCOPY);
                             TransparentBlt ( SGWndDC, x, y ,94,88, left4, 0, 0, 94, 88, RGB ( 255, 255, 255 )  );
                             Sleep(30);

                            }
                             if(moveL==5)
                            {


                            BitBlt(SGWndDC,0,0,xLevel+880,600,Mir,0,0,SRCCOPY);
                             TransparentBlt ( SGWndDC, x, y ,94,88, left5, 0, 0, 94, 88, RGB ( 255, 255, 255 )  );
                             Sleep(30);

                            }
                             if(moveL==6)
                            {


                            BitBlt(SGWndDC,0,0,xLevel+880,600,Mir,0,0,SRCCOPY);
                             TransparentBlt ( SGWndDC, x, y ,94,88, left6, 0, 0, 94, 88, RGB ( 255, 255, 255 )  );
                             Sleep(30);

                            }
                             if(moveL==7)
                            {


                            BitBlt(SGWndDC,0,0,xLevel+880,600,Mir,0,0,SRCCOPY);
                             TransparentBlt ( SGWndDC, x, y ,94,88, left7, 0, 0, 94, 88, RGB ( 255, 255, 255 )  );
                             Sleep(30);

                            }
                             if(moveL==8)
                            {


                            BitBlt(SGWndDC,0,0,xLevel+880,600,Mir,0,0,SRCCOPY);
                             TransparentBlt ( SGWndDC, x, y ,94,88, left8, 0, 0, 94, 88, RGB ( 255, 255, 255 )  );
                             Sleep(30);

                            }
                             if(moveL==9)
                            {


                            BitBlt(SGWndDC,0,0,xLevel+880,600,Mir,0,0,SRCCOPY);
                             TransparentBlt ( SGWndDC, x, y ,94,88, left9, 0, 0, 94, 88, RGB ( 255, 255, 255 )  );
                             Sleep(30);

                            }
                             if(moveL==10)
                            {


                            BitBlt(SGWndDC,0,0,xLevel+880,600,Mir,0,0,SRCCOPY);
                             TransparentBlt ( SGWndDC, x, y ,94,88, left10, 0, 0, 94, 88, RGB ( 255, 255, 255 )  );
                             Sleep(30);

                            }
                             if(moveL==11)
                            {


                            BitBlt(SGWndDC,0,0,xLevel+880,600,Mir,0,0,SRCCOPY);
                             TransparentBlt ( SGWndDC, x, y ,94,88, left11, 0, 0, 94, 88, RGB ( 255, 255, 255 )  );
                             Sleep(30);
                             moveL=0;
                            }
                            }


                        }











                        if(GetAsyncKeyState(VK_SPACE)&&(jump==0))
                        {
                        idle=0;
                         label: while(jumpfor!=50)
                           {
                               idle=0;
                               jumpfor++;
                               if(GetAsyncKeyState(VK_RIGHT))
                               {
                                   Direction=1;
                                for(int i=0;i!=88;i++)
                                    {

                                            if(GetPixel(Mir,x+69,y+i)==RGB(68,116,244)||(GetPixel(Mir,x+69,y+i)==RGB(1,0,0)))
                                            {


                                                wallAirR=true;
                                                break;
                                            }
                                            else
                                            {
                                                wallAirR=false;
                                            }
                                    }
                                    if(wallAirR==false)
                                    {
                                        x++;
                                    }

                               }

                                 if(GetAsyncKeyState(VK_LEFT))
                               {
                            Direction=0;
                                for(int i=0;i!=88;i++)
                                    {
                                            if(GetPixel(Mir,x+25,y+i)==RGB(68,116,244)||(GetPixel(Mir,x+25,y+i)==RGB(1,0,0)))
                                            {


                                                wallAirL=true;
                                                break;
                                            }
                                            else
                                            {
                                                wallAirL=false;
                                            }
                                    }
                                    if(wallAirL==false)
                                    {
                                        x--;
                                    }

                               }




                               if(Direction==1)
                        {
                                             while(partypose!=1)
                                                {
                                                partypose++;
                                                BitBlt(SGWndDC,0,0,xLevel+880,600,Mir,0,0,SRCCOPY);
                                                TransparentBlt ( SGWndDC, x, y ,94,88, jumppre, 0, 0, 94, 88, RGB ( 255, 255, 255 )  );
                                                Sleep(169);

                                                BitBlt(SGWndDC,0,0,xLevel+880,600,Mir,0,0,SRCCOPY);
                                                 TransparentBlt ( SGWndDC, x, y ,94,88, jump0, 0, 0, 94, 88, RGB ( 255, 255, 255 )  );
                                                 Sleep(100);
                                                }


                        idle=0;
                        y--;
                        BitBlt(SGWndDC,0,0,xLevel+880,600,Mir,0,0,SRCCOPY);
                        TransparentBlt ( SGWndDC, x, y ,94,88, jump2, 0, 0, 94, 88, RGB ( 255, 255, 255 )  );
                        Sleep(10);
                        }
                                if(Direction==0)
                             {
                                                 while(partypose!=1)
                                                {
                                                BitBlt(SGWndDC,0,0,xLevel+880,600,Mir,0,0,SRCCOPY);
                                                TransparentBlt ( SGWndDC, x, y ,94,88, jumppreL, 0, 0, 94, 88, RGB ( 255, 255, 255 )  );
                                                Sleep(169);

                                                partypose++;
                                                BitBlt(SGWndDC,0,0,xLevel+880,600,Mir,0,0,SRCCOPY);
                                                TransparentBlt ( SGWndDC, x, y ,94,88, jumpL, 0, 0, 94, 88, RGB ( 255, 255, 255 )  );
                                                Sleep(100);
                                                }

                            idle=0;
                            y--;
                            BitBlt(SGWndDC,0,0,xLevel+880,600,Mir,0,0,SRCCOPY);
                            TransparentBlt ( SGWndDC, x, y ,94,88, jump2L, 0, 0, 94, 88, RGB ( 255, 255, 255 )  );
                            Sleep(10);
                             }




                             jump=1;

                           }



                        }
                        jumpfor=0;

                          if(!(GetAsyncKeyState(VK_RIGHT))&&!(GetAsyncKeyState(VK_LEFT))&&(fall==0)&&!(GetAsyncKeyState(VK_SPACE)))
                         {


                             if((idle!=1)&&(fall==0))
                            {


                                printf("uASDpdate\n");
                             idle++;




                             if(Direction==1)
                             {
                             moveR=0;
                             BitBlt(SGWndDC,0,0,xLevel+880,600,Mir,0,0,SRCCOPY);
                             TransparentBlt ( SGWndDC, x, y ,94,88, right, 0, 0, 94, 88, RGB ( 255, 255, 255 )  );

                            }
                            if(Direction==0)
                             {
                             moveL=0;
                             BitBlt(SGWndDC,0,0,xLevel+880,600,Mir,0,0,SRCCOPY);
                             TransparentBlt ( SGWndDC, x, y ,94,88, left, 0, 0, 94, 88, RGB ( 255, 255, 255 )  );

                            }


                         }
                        }





                    }
                    }
}





















