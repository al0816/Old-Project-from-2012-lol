#if _WIN32_WINNT < 0x0500
#undef _WIN32_WINNT
#define _WIN32_WINNT 0x0500
#endif
#define WINVER 0x0500
#include<stdio.h>

#include<windows.h>
#include"sg.h"
#include<time.h>
#include <ctime>
#include<mmsystem.h>
int width=1400;
int height=800;
int W_width=1400;
int W_height=800;
int lime=124+(252<<8)+(0<<16);
int blue=68+(116<<8)+(244<<16);
int *data = new int [width * height];



struct pony
{
    double sec,sec2;
    int x,y,sprite;
    bool right_button,left_button,ground,napravlenie_v_pravo,wall_R,wall_L,button_R,button_L;
    bool jump_ready;
    char spriteBMP[100],model[100];
    int fall_delay,fall_counter,walk_delay,walk_R_counter,walk_L_counter,jump_delay;
    int jump_counter;
    bool jump_pose2;
    void jump(HDC Mir=CreateCompatibleDC (SGWndDC),HDC pose_R=CreateCompatibleDC (SGWndDC),HDC pose_L=CreateCompatibleDC (SGWndDC),HDC FALL_R=CreateCompatibleDC (SGWndDC),HDC FALL_L=CreateCompatibleDC (SGWndDC))
    {
        if(GetAsyncKeyState(VK_SPACE)&&ground==true)
        {
            jump_ready=false;
        }
        if(jump_ready==false)
        {

            jump_counter++;

            if(jump_counter==100&&jump_pose2==false)
            {
                jump_pose2=true;
                if(napravlenie_v_pravo==true)

                     {
                                            BitBlt(SGWndDC,x,y,94,88,Mir,x,y,SRCCOPY);
                                            TransparentBlt(SGWndDC,x,y,94,88,pose_R,0,0,94,88,RGB ( 255, 255, 255));
                    }
                    else
                    {
                                            BitBlt(SGWndDC,x,y,94,88,Mir,x,y,SRCCOPY);
                                            TransparentBlt(SGWndDC,x,y,94,88,pose_L,0,0,94,88,RGB ( 255, 255, 255));
                    }

            }
             if(jump_counter>=100&&jump_counter<=150&&jump_pose2==true)
             {
                 y--;
                printf("sad");
                if(napravlenie_v_pravo==true)

                     {
                                            BitBlt(SGWndDC,x,y+1,94,89,Mir,x,y+1,SRCCOPY);
                              printf("sad");
                                            TransparentBlt(SGWndDC,x,y+1,94,89,FALL_R,0,0,94,89,RGB ( 255, 255, 255));
                    }
                    else
                    {
                                            BitBlt(SGWndDC,x,y+1,94,89,Mir,x,y+1,SRCCOPY);
                                            TransparentBlt(SGWndDC,x,y+1,94,89,FALL_L,0,0,94,89,RGB ( 255, 255, 255));
                    }
             }
            if(jump_counter==150)
             {
                 jump_ready=true;
                 jump_counter=0;
             }

        }

    }

    void fall_CHECK(HDC Mir=CreateCompatibleDC (SGWndDC),HDC FALL_R=CreateCompatibleDC (SGWndDC),HDC FALL_L=CreateCompatibleDC (SGWndDC))
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





      if(ground==false)
                    {

                        fall_counter++;
                        if(fall_counter==fall_delay&&jump_ready==true)
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
void walk_R_CHECK(HDC Mir=CreateCompatibleDC (SGWndDC))
{

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
   void walk_R_script(HDC Mir=CreateCompatibleDC (SGWndDC))
   {
           if(GetAsyncKeyState(right_button)&&!(GetAsyncKeyState(left_button))&&(ground==true))
   {

       if(napravlenie_v_pravo!=true)
       {
           napravlenie_v_pravo=true;
            sprite=1;
       }



             if((wall_R==false))
            {
                walk_R_counter++;


              if(walk_R_counter==walk_delay/2)
                  {
                    x++;
                    sprintf(spriteBMP,"%sright%d.bmp",model,sprite);
                    HBITMAP image=(HBITMAP)LoadImage(0,spriteBMP,IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                    HDC right=CreateCompatibleDC(SGWndDC);
                    sgSelectTool(right,image);
                    BitBlt(SGWndDC,x-1,y,95,88,Mir,x-1,y,SRCCOPY);
                    TransparentBlt(SGWndDC,x,y,94,88,right,0,0,94,88,RGB ( 255, 255, 255));


                  }
                         if(walk_R_counter==walk_delay)
                  {
                    x++;
                    walk_R_counter=0;
                    sprite++;
                    if(sprite==12)
                    {
                        sprite=1;
                    }

                    walk_R_counter=0;
                    sprintf(spriteBMP,"%sright%d.bmp",model,sprite);


                    HBITMAP image=(HBITMAP)LoadImage(0,spriteBMP,IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                    HDC right=CreateCompatibleDC(SGWndDC);
                    sgSelectTool(right,image);

                    BitBlt(SGWndDC,x-1,y,95,88,Mir,x-1,y,SRCCOPY);
                    TransparentBlt(SGWndDC,x,y,94,88,right,0,0,94,88,RGB ( 255, 255, 255));
                    DeleteObject(SelectObject(right,image));
                    memset(spriteBMP,0, sizeof(char)*100);

                  }
            }


}
else
{
    if(ground==true)
    {
        right_button=false;
    }
}
}





void walk_L_CHECK()
    {
           if(!(GetAsyncKeyState(right_button))&&(GetAsyncKeyState(left_button))&&(ground==true))
       {

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

if(!GetAsyncKeyState(right_button)&&(GetAsyncKeyState(left_button))&&(ground==true))
   {

       if(napravlenie_v_pravo==true)
       {
           napravlenie_v_pravo=false;
            sprite=1;
       }



             if((wall_L==false))
            {
                walk_L_counter++;


              if(walk_L_counter==walk_delay)
                  {
                    walk_L_counter=0;
                    sprite++;
                    if(sprite==12)
                    {
                        sprite=1;
                    }
                    x--;
                    walk_L_counter=0;
                    sprintf(spriteBMP,"%sleft%d.bmp",model,sprite);


                    HBITMAP image=(HBITMAP)LoadImage(0,spriteBMP,IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                    HDC left=CreateCompatibleDC(SGWndDC);
                    sgSelectTool(left,image);

                    BitBlt(SGWndDC,x,y,96,88,Mir,x,y,SRCCOPY);
                    TransparentBlt(SGWndDC,x,y,94,88,left,0,0,94,88,RGB ( 255, 255, 255));
                    DeleteObject(SelectObject(left,image));
                    memset(spriteBMP,0, sizeof(char)*100);

                  }
            }


}
else
{
    if(ground==true)
    {
 left_button=false;
    }
}

    }
//////////////////////void button_madnes()
//////////////////////{
//////////////////////   if(left_button==false&&right_button==false)
//////////////////////   {
//////////////////////       sprite=0;
//////////////////////       if
//////////////////////   }
//////////////////////}

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
player.fall_delay=3000;
player.x=400;
player.y=500;
player.right_button=39;
player.jump_ready=true;
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
player.jump_pose2=false;
dark.left_button=100;
player.jump_counter=0;
dark.right_button=102;
dark.x=200;
dark.walk_delay=player.walk_delay;
dark.sprite=1;
dark.walk_R_counter=0;
dark.y=500;
dark.fall_counter=0;
dark.fall_delay=player.fall_delay;
dark.button_L=false;
dark.button_R=false;
player.button_L=false;
player.button_R=false;
player.jump_counter=0;
player.jump_ready=true;
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


while(Game==true)
        {




            player.fall_CHECK(Mir,fallR,fallL);
            player.walk_R_CHECK(Mir);
            player.walk_R_script(Mir);
            player.walk_L_CHECK();
            player.walk_L(Mir);
            dark.fall_CHECK(Mir,dark_fallR,dark_fallL);
            dark.walk_R_CHECK(Mir);
            dark.walk_R_script(Mir);
            dark.walk_L_CHECK();
            dark.walk_L(Mir);
            player.jump(Mir,fallR,fallL,fallR,fallL);


//            player.walk_L(Mir);
//            dark.walk_R(Mir);
//            dark.walk_L(Mir);
////
//            dark.button_madnes();
//            player.button_madnes();


        }





}






