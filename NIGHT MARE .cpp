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
int width=800;
int height=600;

int W_width=800;
int W_height=600;
int *data = new int [width * height];



struct pony
{
    double sec,sec2;
    int x,y,sprite,left_button,right_button,pose_time,jump_time,jump_counter;
    int jump_end_time;

    bool ground,napravlenie_v_pravo,wall_R,wall_L;

    bool jump_ready;

    char spriteBMP[100],model[100];
    int fall_delay,fall_counter,walk_delay,walk_R_counter,walk_L_counter,jump_delay;

    bool jump_pose2;
    void jump(HDC Mir=CreateCompatibleDC (SGWndDC),HDC pose1_R=CreateCompatibleDC (SGWndDC),HDC pose1_L=CreateCompatibleDC (SGWndDC),HDC FALL_R=CreateCompatibleDC (SGWndDC),HDC FALL_L=CreateCompatibleDC (SGWndDC),HDC pose2_R=CreateCompatibleDC (SGWndDC),HDC pose2_L=CreateCompatibleDC (SGWndDC))
    {
        if(GetAsyncKeyState(VK_SPACE)&&ground==true)
        {
            jump_ready=false;
        }
        if(jump_ready==false)
        {
            jump_counter++;
            if(jump_counter==1)
            {

                if(napravlenie_v_pravo==true)

                     {
                                            BitBlt(SGWndDC,x,y,94,88,Mir,x,y,SRCCOPY);
                                            TransparentBlt(SGWndDC,x,y,94,88,pose1_R,0,0,94,88,RGB ( 255, 255, 255));
                    }
                    else
                    {
                                            BitBlt(SGWndDC,x,y,94,88,Mir,x,y,SRCCOPY);
                                            TransparentBlt(SGWndDC,x,y,94,88,pose1_L,0,0,94,88,RGB ( 255, 255, 255));
                    }

            }
             if(jump_counter==pose_time)
             {
                if(napravlenie_v_pravo==true)
                    {
                                            BitBlt(SGWndDC,x,y+1,94,89,Mir,x,y+1,SRCCOPY);
                                            TransparentBlt(SGWndDC,x,y+1,94,89,pose2_R,0,0,94,89,RGB ( 255, 255, 255));
                    }
                    else
                    {
                                            BitBlt(SGWndDC,x,y+1,94,89,Mir,x,y+1,SRCCOPY);
                                           TransparentBlt(SGWndDC,x,y+1,94,89,pose2_L,0,0,94,89,RGB ( 255, 255, 255));
                    }
             }
             if(jump_counter>jump_time)
             {
                 jump_counter++;
                 if(jump_counter==3)
                 {
                    jump_counter=0;

                 y--;
                  if(napravlenie_v_pravo==true)
                    {
                                            BitBlt(SGWndDC,x,y+1,94,89,Mir,x,y+1,SRCCOPY);
                                            TransparentBlt(SGWndDC,x,y+1,94,89,FALL_R,0,0,94,89,RGB ( 255, 255, 255));
                    }
                    else
                    {
                                            BitBlt(SGWndDC,x,y+1,94,89,Mir,x,y+1,SRCCOPY);
                                             TransparentBlt(SGWndDC,x,y+1,94,89,FALL_L,0,0,94,89,RGB ( 255, 255, 255));
                    }
                 }
             }
            if(jump_counter==jump_end_time)
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
                        if((data[x+i + (y+89) * width]==0))
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
void walk_R_CHECK(HDC Mir=CreateCompatibleDC (SGWndDC))
{

         for(int i=0;i<=88;i++)
            {

                if(data[x+69+(y+i) * width]==0)
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
           if(GetAsyncKeyState(right_button))
   {


       if(napravlenie_v_pravo!=true)
       {
           napravlenie_v_pravo=true;
            sprite=1;
       }

    if(wall_R==false)
            {
                walk_R_counter++;

              if(walk_R_counter==walk_delay/2)
                  {
                    x++;
                    if(ground==true)
                    {
                    sprintf(spriteBMP,"%sright%d.bmp",model,sprite);
                    }
                    else
                    {
                        sprintf(spriteBMP,"%sfallright.bmp",model);
                    }

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
                     if(ground==true)
                    {
                    sprintf(spriteBMP,"%sright%d.bmp",model,sprite);
                    sprite++;
                    }
                    else
                    {
                        sprintf(spriteBMP,"%sfallright.bmp",model);
                    }

                    HBITMAP image=(HBITMAP)LoadImage(0,spriteBMP,IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                    HDC right=CreateCompatibleDC(SGWndDC);
                    sgSelectTool(right,image);
                    BitBlt(SGWndDC,x-1,y,95,88,Mir,x-1,y,SRCCOPY);
                    TransparentBlt(SGWndDC,x,y,94,88,right,0,0,94,88,RGB ( 255, 255, 255));


                  }
                      if(sprite==11)
                    {
                        sprite=1;
                    }
            }


}
}





void walk_L_CHECK()
    {
             for(int i=0;i<=88;i++)
                {

                    if(data[x+25+(y+i) * width]==0)
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
void debug()
{
    if(GetAsyncKeyState(VK_DOWN))
    {
        printf("WALL R = %d GROUND = %d  LEFT = %d\n",wall_R,ground,wall_L);
    }

}
void walk_L_script(HDC Mir=CreateCompatibleDC (SGWndDC))
    {

if((GetAsyncKeyState(left_button))&&(ground==true))
   {

       if(napravlenie_v_pravo==true)
       {
           napravlenie_v_pravo=false;
            sprite=1;
       }

        if(wall_L==false)
            {
                walk_L_counter++;

              if(walk_L_counter==walk_delay/2)
                  {
                        x--;
                        sprintf(spriteBMP,"%sleft%d.bmp",model,sprite);
                        HBITMAP image=(HBITMAP)LoadImage(0,spriteBMP,IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                        HDC left=CreateCompatibleDC(SGWndDC);
                        sgSelectTool(left,image);
                        BitBlt(SGWndDC,x,y,96,88,Mir,x,y,SRCCOPY);
                        TransparentBlt(SGWndDC,x,y,94,88,left,0,0,94,88,RGB ( 255, 255, 255));


                  }

              if(walk_L_counter==walk_delay)
                  {
                        walk_L_counter=0;
                        sprite++;
                        x--;
                        sprintf(spriteBMP,"%sleft%d.bmp",model,sprite);
                        HBITMAP image=(HBITMAP)LoadImage(0,spriteBMP,IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                        HDC left=CreateCompatibleDC(SGWndDC);
                        sgSelectTool(left,image);
                        BitBlt(SGWndDC,x,y,96,88,Mir,x,y,SRCCOPY);
                        TransparentBlt(SGWndDC,x,y,94,88,left,0,0,94,88,RGB ( 255, 255, 255));
                  }
            }

              if(sprite==11)
                    {
                        sprite=1;
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
    HBITMAP fall_R=(HBITMAP)LoadImage(0,"fallright.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
    HDC fallR=CreateCompatibleDC(SGWndDC);
    sgSelectTool(fallR,fall_R);

    HBITMAP fall_L=(HBITMAP)LoadImage(0,"fallL.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
    HDC fallL=CreateCompatibleDC(SGWndDC);
    sgSelectTool(fallL,fall_L);

    HBITMAP pose1_R=(HBITMAP)LoadImage(0,"pose1_R.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
    HDC poseR=CreateCompatibleDC(SGWndDC);
    sgSelectTool(poseR,pose1_R);

    HBITMAP pose1_L=(HBITMAP)LoadImage(0,"pose1_L.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
    HDC poseL=CreateCompatibleDC(SGWndDC);
    sgSelectTool(poseL,pose1_L);

     HBITMAP pose2_R=(HBITMAP)LoadImage(0,"pose2_R.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
    HDC pose2R=CreateCompatibleDC(SGWndDC);
    sgSelectTool(pose2R,pose2_R);

    HBITMAP pose2_L=(HBITMAP)LoadImage(0,"pose2_L.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
    HDC pose2L=CreateCompatibleDC(SGWndDC);
    sgSelectTool(pose2L,pose2_L);

    HBITMAP fall_R_dark=(HBITMAP)LoadImage(0,"darkfallR.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
    HDC dark_fallR=CreateCompatibleDC(SGWndDC);
    sgSelectTool(dark_fallR,fall_R_dark);

    HBITMAP fall_L_dark=(HBITMAP)LoadImage(0,"darkfallL.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
    HDC dark_fallL=CreateCompatibleDC(SGWndDC);
    sgSelectTool(dark_fallL,fall_L_dark);

    HBITMAP white=(HBITMAP)LoadImage(0,"Level.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC whitelist=CreateCompatibleDC(SGWndDC);
                sgSelectTool(whitelist,white);

    HBITMAP mir= CreateCompatibleBitmap (SGWndDC,width, height);
    HDC Mir= CreateCompatibleDC (SGWndDC);
    sgSelectTool(Mir,mir);

int escape=0;
pony player;
player.sprite=1;
player.fall_counter=0;
player.fall_delay=500;
player.x=300;
player.y=350;
player.right_button=39;
player.jump_ready=true;
player.left_button=37;
player.walk_R_counter=0;
player.walk_delay=200;
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
dark.y=300;
dark.fall_counter=0;
dark.fall_delay=player.fall_delay;
player.jump_time=player.pose_time+4000;
player.jump_counter=0;
player.pose_time=1000;
player.jump_time=2000;
player.jump_end_time=player.jump_time+40;

player.jump_ready=true;
int TIME=0;
int TIME2=0;
bool Game=true;

BitBlt(Mir,0,0,width,height,whitelist,0,0,SRCCOPY);
BitBlt(SGWndDC,0,0,width,height,whitelist,0,0,SRCCOPY);
FILE * pFile;
pFile = fopen ("myfile.txt","rw");
char codes[10];

for (int i = 0; i < width; i++)
for (int j = 0; j < height; j++)
        {
            fgets(codes,10,pFile);
            data[i + j * width]=atoi(codes);
//            if(GetPixel(Mir, i, j)!=255+(255<<8)+(255<<16))
//            {
//                data[i + j * width] = 0;
//                 fprintf (pFile,"%d\n",data[i + j * width]);
//            }
//            else
//            {
//                data[i + j * width] = 1;
//                fprintf (pFile,"%d\n",data[i + j * width]);
//            }

        }
fclose (pFile);

BitBlt(SGWndDC,0,0,W_width,W_height,Mir,0,0,SRCCOPY);


while(Game==true)
        {



            player.walk_R_CHECK(Mir);
            player.fall_CHECK(Mir,fallR,fallL);
            player.walk_R_script(Mir);
            player.walk_L_CHECK();
            player.walk_L_script(Mir);
            player.jump(Mir,poseR,poseL,fallR,fallL,pose2R,pose2L);

            dark.fall_CHECK(Mir,dark_fallR,dark_fallL);
            dark.walk_R_CHECK(Mir);
            dark.walk_R_script(Mir);
            dark.walk_L_CHECK();
            dark.walk_L_script(Mir);

            player.debug();

//            player.walk_L(Mir);
//            dark.walk_R(Mir);
//            dark.walk_L(Mir);
////
//            dark.button_madnes();
//            player.button_madnes();


        }





}






