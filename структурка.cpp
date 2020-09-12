#include<stdio.h>
#include<windows.h>
#include"sg.h"

int width=1400;
int height=800;
int W_width=1400;
int W_height=800;
int lime=124+(252<<8)+(0<<16);
int blue=68+(116<<8)+(244<<16);
int *data = new int [width * height];




struct pony
{

    int x,y,sprite,right_button,left_button;
    bool ground,napravlenie_v_pravo,wall_R,wall_L,button_R,button_L;
    char spriteBMP[100],model[100];
    int fall_delay,fall_counter,walk_delay,walk_R_counter,walk_L_counter;

    void fall_CHECK()
    {
             if(y+89<=height)
            {


               for(int i=26;i<=69;i++)
                    {
                        if((data[x+i + (y+88)*width]==lime)||(data[x+i + (y+88)] * width==blue))
                            {
                                ground=true;
                                break;
                            }

                        else
                            {
                                if(i==69)
                                    {

                                        ground=false;

                                        break;
                                    }
                            }

                    }
            }
        else
            {
                ground=true;
            }

    }

    void fall_script(HDC Mir=CreateCompatibleDC (SGWndDC),HDC FALL_R=CreateCompatibleDC (SGWndDC),HDC FALL_L=CreateCompatibleDC (SGWndDC))
    {


      if(ground==false)
                    {

                        fall_counter++;
                        if(fall_counter==fall_delay)
                            {
                                fall_counter=0;
                                y++;
                                    if(napravlenie_v_pravo==true)
                                        {
                                            BitBlt(SGWndDC,x,y-1,94,88,Mir,x,y-1,SRCCOPY);
                                            TransparentBlt(SGWndDC,x,y,94,88,FALL_R,0,0,94,88,RGB ( 255, 255, 255));
                                        }
                                    else
                                        {
                                            BitBlt(SGWndDC,x,y-1,94,88,Mir,x,y-1,SRCCOPY);
                                            TransparentBlt(SGWndDC,x,y,94,88,FALL_L,0,0,94,88,RGB ( 255, 255, 255));
                                        }

                            }

                    }
    }
void walk_R_CHECK()
{
      if(GetAsyncKeyState(right_button)&&!(GetAsyncKeyState(left_button))&&(ground==true))
   {
       button_R=true;
       if(napravlenie_v_pravo!=true)
       {
           napravlenie_v_pravo=true;
            sprite=1;
       }

         for(int i=0;i<=88;i++)
            {

                if(data[x+69+(y+i) * width]==blue)
                    {
                        wall_R=true;
                        break;
                    }
                else
                    {
                        if(i==88)
                            {
                                wall_R=false;
                                break;
                            }
                    }
            }
}
}
void walk_R(HDC Mir=CreateCompatibleDC (SGWndDC))
{

        if((wall_R==false)&&(button_R==true))
            {

              walk_R_counter++;
              if(walk_R_counter==walk_delay)
                  {
                    sprite++;
                    if(sprite==12)
                    {
                        sprite=1;
                    }
                    x++;
                    walk_R_counter=0;
                    sprintf(spriteBMP,"%sright%d.bmp",model,sprite);
                    HBITMAP image=(HBITMAP)LoadImage(0,spriteBMP,IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                    HDC right=CreateCompatibleDC(SGWndDC);
                    sgSelectTool(right,image);

                    BitBlt(SGWndDC,x-1,y,95,88,Mir,x-1,y,SRCCOPY);
                    TransparentBlt(SGWndDC,x,y,94,88,right,0,0,94,88,RGB ( 255, 255, 255));
                    DeleteObject(SelectObject(right,image));
                    memset(spriteBMP,0, sizeof(char)*100);
                    printf("BIsaddasdasdasdasdLT ED!!\n");
                  }
            }
}


void walk_L_CHECK()
    {
           if(!(GetAsyncKeyState(right_button))&&(GetAsyncKeyState(left_button))&&(ground==true))
       {
           button_L=true;

           if(napravlenie_v_pravo==true)
           {
                napravlenie_v_pravo=false;
                sprite=1;
           }

             for(int i=0;i<=88;i++)
                {

                    if(data[x+25+(y+i) * width]==blue)
                        {
                            wall_L=true;
                            break;
                        }
                    else
                        {
                            if(i==88)
                                {
                                    wall_L=false;
                                    break;
                                }
                        }
                }
    }
    }
void walk_L(HDC Mir=CreateCompatibleDC (SGWndDC))
    {


            if((wall_L==false)&&(button_L==true))
                {

                  walk_L_counter++;
                  if(walk_L_counter==walk_delay)
                      {
                        sprite++;
                        if(sprite==12)
                        {
                            sprite=1;
                        }
                        x--;
                        walk_L_counter=0;
                        sprintf(spriteBMP,"%sleft%d.bmp",model,sprite);
                        HBITMAP imag1=(HBITMAP)LoadImage(0,spriteBMP,IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                        HDC left=CreateCompatibleDC(SGWndDC);
                        sgSelectTool(left,imag1);
                        BitBlt(SGWndDC,x,y,95,88,Mir,x,y,SRCCOPY);
                        TransparentBlt(SGWndDC,x,y,94,88,left,0,0,94,88,RGB ( 255, 255, 255));
                        DeleteObject(SelectObject(left,imag1));
                        memset(spriteBMP,0, sizeof(char)*100);
                    printf("BIsaddasdasdasdasdLT ED!!\n");
                      }
                }
    }
void button_madnes()
{
    if(!(GetAsyncKeyState(right_button)))
    {
        button_R=false;
    }
    if(!(GetAsyncKeyState(left_button)))
    {
        button_L=false;
    }
}

};


int main()
{

sgCreateWindow(W_width,W_height);
    HBITMAP fall_R=(HBITMAP)LoadImage(0,"fallR.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
    HDC fallR=CreateCompatibleDC(SGWndDC);
    sgSelectTool(fallR,fall_R);

    HBITMAP fall_L=(HBITMAP)LoadImage(0,"fallL.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
    HDC fallL=CreateCompatibleDC(SGWndDC);
    sgSelectTool(fallL,fall_L);

    HBITMAP fall_R_dark=(HBITMAP)LoadImage(0,"darkfallR.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
    HDC dark_fallR=CreateCompatibleDC(SGWndDC);
    sgSelectTool(dark_fallR,fall_R_dark);

    HBITMAP fall_L_dark=(HBITMAP)LoadImage(0,"darkfallL.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
    HDC dark_fallL=CreateCompatibleDC(SGWndDC);
    sgSelectTool(dark_fallL,fall_L_dark);

    HBITMAP white=(HBITMAP)LoadImage(0,"pic0.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC whitelist=CreateCompatibleDC(SGWndDC);
                sgSelectTool(whitelist,white);

    HBITMAP mir= CreateCompatibleBitmap (SGWndDC,width, height);
    HDC Mir= CreateCompatibleDC (SGWndDC);
    sgSelectTool(Mir,mir);

int escape=0;
pony player;
player.sprite=1;
player.fall_counter=0;
player.fall_delay=12000;
player.x=400;
player.y=0;
player.right_button=39;
player.left_button=37;
player.walk_R_counter=0;
player.walk_delay=10000;
player.napravlenie_v_pravo=true;
player.walk_L_counter=0;
sprintf(player.model,"");
pony dark;
sprintf(dark.model,"dark");
dark.walk_L_counter=0;
dark.wall_L=false;
dark.wall_R=false;
player.wall_R=false;
dark.left_button=100;
dark.right_button=102;
dark.x=200;
dark.walk_delay=player.walk_delay;
dark.sprite=1;
dark.walk_R_counter=0;
dark.y=300;
dark.fall_counter=0;
dark.fall_delay=player.fall_delay;
dark.button_L=true;
dark.button_R=true;
player.button_L=true;
player.button_R=true;

int TIME=0;
int TIME2=0;
bool Game=true;

BitBlt(Mir,0,0,width,height,whitelist,0,0,SRCCOPY);
    //FILE * pFile;
//pFile = fopen ("myfile.txt","w");

for (int i = 0; i < width; i++)
for (int j = 0; j < height; j++)
        {
            data[i + j * width] = GetPixel(Mir, i, j);

        //    fprintf (pFile,"%d,",data[i + j * width]);
        }
//fclose (pFile);

BitBlt(SGWndDC,0,0,W_width,W_height,Mir,0,0,SRCCOPY);

TIME= GetTickCount();
dark.walk_L_counter=dark.walk_delay-1;
dark.walk_R_counter=dark.walk_delay-1;
player.walk_R_counter=player.walk_delay-1;
player.walk_L_counter=player.walk_delay-1;
for(int i=0; i<1;i++)
{

            player.fall_CHECK();
            player.walk_R_CHECK();
            player.walk_L_CHECK();

            dark.fall_CHECK();
            dark.walk_L_CHECK();
            dark.walk_R_CHECK();



            player.button_L=true;
            player.button_R=true;
            dark.button_L=true;
            dark.button_R=true;
            player.fall_script(Mir,fallR,fallL);
            dark.fall_script(Mir,dark_fallR,dark_fallL);
            player.ground=true;

            player.walk_R(Mir);
            player.walk_L(Mir);
            dark.walk_R(Mir);
            dark.walk_L(Mir);

            dark.button_madnes();
            player.button_madnes();
}


TIME2= timeGetTime() ;
printf("%d    ",TIME2-TIME);
while(Game==true)
        {
            player.fall_CHECK();
            player.walk_R_CHECK();
            player.walk_L_CHECK();

            dark.fall_CHECK();
            dark.walk_L_CHECK();
            dark.walk_R_CHECK();





            player.fall_script(Mir,fallR,fallL);
            dark.fall_script(Mir,dark_fallR,dark_fallL);
            player.walk_R(Mir);
            player.walk_L(Mir);
            dark.walk_R(Mir);
            dark.walk_L(Mir);

            dark.button_madnes();
            player.button_madnes();

        }





}






