#if _WIN32_WINNT < 0x0500
#undef _WIN32_WINNT
#define _WIN32_WINNT 0x0500
#endif
#define WINVER 0x0500
#include"sg.h"
#include"windows.h"
#include<stdio.h>
struct Color
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char x;
};

Color pixel;
Color lime = { 124, 252, 0, 0 };

int LEFTorRIGHT=1;
int player_X=200;
int player_Y=0;
int player_fallC=0;
int player_walk=0;
int player_walk_L=0;
int player_LIVES=2;
bool ground_player=false;
bool player_fall=true;

bool wall_fall_player_R=false;
bool wall_player_R=false;
int wall_player_R_Pixel=0;
int wall_player_R_1=0;

bool wall_fall_player_L=false;
bool wall_player_L=false;
int wall_player_L_Pixel=0;
int wall_player_L_1=0;

int jump_pose_R=0;
int jump_pose_L=0;

double dark_X=400;
int dark_Y=600;
int dark_fallC=0;
int wall_dark_R_Pixel=0;

bool ground_dark=false;
bool dark_fall=true;

bool wall_fall_dark_R=false;
bool wall_fall_dark_L=false;
bool wall_dark_R=false;
bool wall_dark_L=false;

int jump_dark_pose_R=0;
int jump_dark_pose_L=0;

int groundPixel_player=0;
int groundPixel_dark=0;
int dark_walk=0;
int dark_walk_R=0;
int dark_lives=4;
bool dark_Direction=true;
bool fireball_R_launched=false;
int fireball_R_X=0;
int fireball_R_Y=0;
int fireball_R_time=0;
int fireball_R_update=0;

bool fireball_L_launched=false;
int fireball_L_X=0;
int fireball_L_Y=0;
int fireball_L_time=0;
int fireball_L_update=0;

int dark_X_int=dark_X;
bool dark_dead_update=false;
bool direction_right=true;
bool dark_live=true;
void fireball_script(HDC death_V=CreateCompatibleDC(SGWndDC),HDC fireball_R_V=CreateCompatibleDC(SGWndDC),HDC fireball_L_V=CreateCompatibleDC(SGWndDC),HDC Mir_V=CreateCompatibleDC(SGWndDC))
{
        if((fireball_R_launched==false)&&(fireball_L_launched==false))
    {
         fireball_R_X=player_X+60;
        fireball_R_Y=player_Y+20;
        fireball_L_X=player_X-24;
        fireball_L_Y=player_Y+20;

    }
        if((fireball_R_X+26>dark_X_int)&&(dark_live==true)&&(fireball_R_launched==true)&&(player_X<dark_X))

        {
        fireball_R_time=0;
        dark_X+=40;
        fireball_R_launched=false;
        dark_lives--;
        BitBlt(SGWndDC,dark_X-40,dark_Y,134,88,Mir_V,dark_X-40,dark_Y,SRCCOPY);
        BitBlt(SGWndDC,fireball_R_X-1,fireball_R_Y,27,14,Mir_V,fireball_R_X-1,fireball_R_Y,SRCCOPY);
        }
        if((fireball_L_X<dark_X_int+95)&&(dark_live==true)&&(fireball_L_launched==true)&&(player_X>dark_X))

        {
        fireball_L_time=0;
        dark_X-=40;
        fireball_L_launched=false;
        dark_lives--;
        BitBlt(SGWndDC,dark_X,dark_Y,134,88,Mir_V,dark_X,dark_Y,SRCCOPY);
        BitBlt(SGWndDC,fireball_L_X-1,fireball_L_Y,27,14,Mir_V,fireball_L_X-1,fireball_L_Y,SRCCOPY);
        }
        if((dark_lives==0)&&(dark_dead_update==false))
        {
            dark_live=false;
            dark_dead_update=true;
            BitBlt(SGWndDC,dark_X,dark_Y,94,88,Mir_V,dark_X,dark_Y,SRCCOPY);
            TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,death_V,0,0,94,88,RGB ( 255, 255, 255));

        }


        if((GetAsyncKeyState(0x031))&&(fireball_R_launched==false)&&(fireball_L_launched==false))
                        {
//                            mciSendString("play song from 1000 to 2000", NULL, 0, 0);
                            if(direction_right==true)
                            {
                            fireball_R_launched=true;
                           fireball_R_X=player_X+60;
                           fireball_R_Y=player_Y+20;
                            }
                            else
                            {
                            fireball_L_launched=true;
                           fireball_L_X=player_X+60;
                           fireball_L_Y=player_Y+20;
                            }
                    }


        if(fireball_R_launched==true)
            {
                fireball_R_time+=2;
                fireball_R_update++;
                if(fireball_R_update==10)
                {
                    fireball_R_update=0;
                    fireball_R_X+=2;
                    if(fireball_R_X>player_X+95)
                       {
                    BitBlt(SGWndDC,fireball_R_X-1,fireball_R_Y,27,14,Mir_V,fireball_R_X-1,fireball_R_Y,SRCCOPY);
                    TransparentBlt(SGWndDC,fireball_R_X,fireball_R_Y,26,14,fireball_R_V,0,0,26,14,RGB ( 255, 255, 255));
                       }


                }

            }
               if(fireball_L_launched==true)
            {
                fireball_L_time+=2;
                fireball_L_update++;
                if(fireball_L_update==10)
                {
                    fireball_L_update=0;
                    fireball_L_X-=2;
                    if(fireball_L_X+24<player_X)
                       {
                    BitBlt(SGWndDC,fireball_L_X,fireball_L_Y,27,14,Mir_V,fireball_L_X,fireball_L_Y,SRCCOPY);
                    TransparentBlt(SGWndDC,fireball_L_X,fireball_L_Y,26,14,fireball_L_V,0,0,26,14,RGB ( 255, 255, 255));
                       }


                }

            }

            if(fireball_R_time==3000)
                                {
                                    BitBlt(SGWndDC,fireball_R_X-1,fireball_R_Y,27,14,Mir_V,fireball_R_X-1,fireball_R_Y,SRCCOPY);
                                    fireball_R_launched=false;
                                    fireball_R_time=0;


                                }
            if(fireball_L_time==3000)
                                {
                                    fireball_L_launched=false;
                                    fireball_L_time=0;
                                     BitBlt(SGWndDC,fireball_L_X-1,fireball_L_Y,27,14,Mir_V,fireball_L_X-1,fireball_L_Y,SRCCOPY);

                                }


}
void fireball_VK_EDITION(HDC fireball_R_V=CreateCompatibleDC(SGWndDC),HDC fireball_L_V=CreateCompatibleDC(SGWndDC),HDC Mir_V=CreateCompatibleDC(SGWndDC))
{
     if(fireball_R_launched==true)
            {
                fireball_R_time+=2;
                fireball_R_update++;
                if(fireball_R_update==10)
                {
                    fireball_R_update=0;
                    fireball_R_X+=2;
                    if(fireball_R_X>player_X+95)
                       {
                    BitBlt(SGWndDC,fireball_R_X-1,fireball_R_Y,27,14,Mir_V,fireball_R_X-1,fireball_R_Y,SRCCOPY);
                    TransparentBlt(SGWndDC,fireball_R_X,fireball_R_Y,26,14,fireball_R_V,0,0,26,14,RGB ( 255, 255, 255));
                       }


                }

            }
               if(fireball_L_launched==true)
            {
                fireball_L_time+=2;
                fireball_L_update++;
                if(fireball_L_update==10)
                {
                    fireball_L_update=0;
                    fireball_L_X-=2;
                    if(fireball_L_X+24<player_X)
                       {
                    BitBlt(SGWndDC,fireball_L_X,fireball_L_Y,27,14,Mir_V,fireball_L_X,fireball_L_Y,SRCCOPY);
                    TransparentBlt(SGWndDC,fireball_L_X,fireball_L_Y,26,14,fireball_L_V,0,0,26,14,RGB ( 255, 255, 255));
                       }


                }

            }

            if(fireball_R_time==3000)
                                {
                                    BitBlt(SGWndDC,fireball_R_X-1,fireball_R_Y,27,14,Mir_V,fireball_R_X-1,fireball_R_Y,SRCCOPY);
                                    fireball_R_launched=false;
                                    fireball_R_time=0;


                                }
            if(fireball_L_time==3000)
                                {
                                    fireball_L_launched=false;
                                    fireball_L_time=0;
                                     BitBlt(SGWndDC,fireball_L_X-1,fireball_L_Y,27,14,Mir_V,fireball_L_X-1,fireball_L_Y,SRCCOPY);

                                }

}
void darkscript_LEFTforRIGHT(HDC darkleft_V=CreateCompatibleDC(SGWndDC),HDC darkleft2_V=CreateCompatibleDC(SGWndDC),HDC darkleft3_V=CreateCompatibleDC(SGWndDC),HDC darkleft4_V=CreateCompatibleDC(SGWndDC),HDC darkleft5_V=CreateCompatibleDC(SGWndDC),HDC darkleft6_V=CreateCompatibleDC(SGWndDC),HDC darkleft7_V=CreateCompatibleDC(SGWndDC),HDC darkleft8_V=CreateCompatibleDC(SGWndDC),HDC darkleft9_V=CreateCompatibleDC(SGWndDC),HDC darkleft10_V=CreateCompatibleDC(SGWndDC),HDC darkleft11_V=CreateCompatibleDC(SGWndDC),HDC Mir_V=CreateCompatibleDC (SGWndDC))
{

   if((dark_X>player_X+95)&&(ground_dark==true)&&(dark_lives>0))
                                {
dark_Direction=false;

                                    dark_walk++;

                                            if(dark_walk==1)
                                                    {
                                                    dark_X-=1.9;
                                                    BitBlt(SGWndDC,dark_X,dark_Y,96,88,Mir_V,dark_X,dark_Y,SRCCOPY);
                                                    TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkleft_V,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                                            if(dark_walk==100)
                                                    {

                                                    dark_X-=1.9;
                                                      BitBlt(SGWndDC,dark_X,dark_Y,96,88,Mir_V,dark_X,dark_Y,SRCCOPY);
                                                    TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkleft2_V,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                                            if(dark_walk==200)
                                                  {
                                                    dark_X-=1.9;
                                                    BitBlt(SGWndDC,dark_X,dark_Y,96,88,Mir_V,dark_X,dark_Y,SRCCOPY);
                                                    TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkleft3_V,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                                             if(dark_walk==300)
                                                    {
                                                    dark_X-=1.9;
                                                       BitBlt(SGWndDC,dark_X,dark_Y,96,88,Mir_V,dark_X,dark_Y,SRCCOPY);
                                                    TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkleft4_V,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                                             if(dark_walk==400)
                                                    {
                                                    dark_X-=1.9;
                                                       BitBlt(SGWndDC,dark_X,dark_Y,96,88,Mir_V,dark_X,dark_Y,SRCCOPY);
                                                     TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkleft5_V,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                                             if(dark_walk==500)
                                                    {
                                                    dark_X-=1.9;
                                                    BitBlt(SGWndDC,dark_X,dark_Y,96,88,Mir_V,dark_X,dark_Y,SRCCOPY);
                                                    TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkleft6_V,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                                             if(dark_walk==600)
                                                    {
                                                    dark_X-=1.9;
                                                     BitBlt(SGWndDC,dark_X,dark_Y,96,88,Mir_V,dark_X,dark_Y,SRCCOPY);
                                                    TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkleft7_V,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                                             if(dark_walk==700)
                                                    {
                                                    dark_X-=1.9;
                                                    BitBlt(SGWndDC,dark_X,dark_Y,96,88,Mir_V,dark_X,dark_Y,SRCCOPY);
                                                    TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkleft8_V,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                                             if(dark_walk==800)
                                                    {
                                                    dark_X-=1.9;
                                                   BitBlt(SGWndDC,dark_X,dark_Y,96,88,Mir_V,dark_X,dark_Y,SRCCOPY);
                                                    TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkleft9_V,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                                             if(dark_walk==900)
                                                    {
                                                    dark_X-=1.9;
                                                     BitBlt(SGWndDC,dark_X,dark_Y,96,88,Mir_V,dark_X,dark_Y,SRCCOPY);
                                                    TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkleft10_V,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                                             if(dark_walk==1000)
                                                    {
                                                    dark_walk=0;
                                                    dark_X-=1.9;
                                                   BitBlt(SGWndDC,dark_X,dark_Y,96,88,Mir_V,dark_X,dark_Y,SRCCOPY);
                                                    TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkleft11_V,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                           }
}
void darkscript_LEFTforRIGHT_VK_EDITION(HDC darkleft_V=CreateCompatibleDC(SGWndDC),HDC darkleft2_V=CreateCompatibleDC(SGWndDC),HDC darkleft3_V=CreateCompatibleDC(SGWndDC),HDC darkleft4_V=CreateCompatibleDC(SGWndDC),HDC darkleft5_V=CreateCompatibleDC(SGWndDC),HDC darkleft6_V=CreateCompatibleDC(SGWndDC),HDC darkleft7_V=CreateCompatibleDC(SGWndDC),HDC darkleft8_V=CreateCompatibleDC(SGWndDC),HDC darkleft9_V=CreateCompatibleDC(SGWndDC),HDC darkleft10_V=CreateCompatibleDC(SGWndDC),HDC darkleft11_V=CreateCompatibleDC(SGWndDC),HDC Mir_V=CreateCompatibleDC (SGWndDC))
{

   if((dark_X>player_X+95)&&(ground_dark==true)&&(dark_lives>0))
                           {

                                dark_Direction=false;
                                    dark_walk++;

                                            if(dark_walk==1)
                                                    {
                                                    dark_X-=2;
                                                    BitBlt(SGWndDC,dark_X,dark_Y,96,88,Mir_V,dark_X,dark_Y,SRCCOPY);
                                                    TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkleft_V,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                                            if(dark_walk==100)
                                                    {

                                                    dark_X-=2;
                                                      BitBlt(SGWndDC,dark_X,dark_Y,96,88,Mir_V,dark_X,dark_Y,SRCCOPY);
                                                    TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkleft2_V,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                                            if(dark_walk==200)
                                                  {
                                                    dark_X-=2;
                                                    BitBlt(SGWndDC,dark_X,dark_Y,96,88,Mir_V,dark_X,dark_Y,SRCCOPY);
                                                    TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkleft3_V,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                                             if(dark_walk==300)
                                                    {
                                                    dark_X-=2;
                                                       BitBlt(SGWndDC,dark_X,dark_Y,96,88,Mir_V,dark_X,dark_Y,SRCCOPY);
                                                    TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkleft4_V,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                                             if(dark_walk==400)
                                                    {
                                                    dark_X-=2;
                                                       BitBlt(SGWndDC,dark_X,dark_Y,96,88,Mir_V,dark_X,dark_Y,SRCCOPY);
                                                     TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkleft5_V,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                                             if(dark_walk==500)
                                                    {
                                                    dark_X-=2;
                                                    BitBlt(SGWndDC,dark_X,dark_Y,96,88,Mir_V,dark_X,dark_Y,SRCCOPY);
                                                    TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkleft6_V,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                                             if(dark_walk==600)
                                                    {
                                                    dark_X-=2;
                                                     BitBlt(SGWndDC,dark_X,dark_Y,96,88,Mir_V,dark_X,dark_Y,SRCCOPY);
                                                    TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkleft7_V,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                                             if(dark_walk==700)
                                                    {
                                                    dark_X-=2;
                                                    BitBlt(SGWndDC,dark_X,dark_Y,96,88,Mir_V,dark_X,dark_Y,SRCCOPY);
                                                    TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkleft8_V,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                                             if(dark_walk==800)
                                                    {
                                                    dark_X-=2;
                                                   BitBlt(SGWndDC,dark_X,dark_Y,96,88,Mir_V,dark_X,dark_Y,SRCCOPY);
                                                    TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkleft9_V,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                                             if(dark_walk==900)
                                                    {
                                                    dark_X-=2;
                                                     BitBlt(SGWndDC,dark_X,dark_Y,96,88,Mir_V,dark_X,dark_Y,SRCCOPY);
                                                    TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkleft10_V,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                                             if(dark_walk==1000)
                                                    {

                                                    dark_walk=0;
                                                    dark_X-=2;
                                                   BitBlt(SGWndDC,dark_X,dark_Y,96,88,Mir_V,dark_X,dark_Y,SRCCOPY);
                                                    TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkleft11_V,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                           }
}




void darkscript_RIGHTforLEFT(HDC darkright_V=CreateCompatibleDC(SGWndDC),HDC darkright2_V=CreateCompatibleDC(SGWndDC),HDC darkright3_V=CreateCompatibleDC(SGWndDC),HDC darkright4_V=CreateCompatibleDC(SGWndDC),HDC darkright5_V=CreateCompatibleDC(SGWndDC),HDC darkright6_V=CreateCompatibleDC(SGWndDC),HDC darkright7_V=CreateCompatibleDC(SGWndDC),HDC darkright8_V=CreateCompatibleDC(SGWndDC),HDC darkright9_V=CreateCompatibleDC(SGWndDC),HDC darkright10_V=CreateCompatibleDC(SGWndDC),HDC darkright11_V=CreateCompatibleDC(SGWndDC),HDC Mir_V=CreateCompatibleDC (SGWndDC))
{

   if((dark_X+93<player_X)&&(ground_dark==true)&&(dark_lives>0))
            {
            dark_Direction=true;

                                    dark_walk_R++;

                                            if(dark_walk_R==1)
                                                    {
                                                    dark_X+=1.9;
                                                    BitBlt(SGWndDC,dark_X-2,dark_Y,96,88,Mir_V,dark_X-2,dark_Y,SRCCOPY);
                                                    TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkright_V,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                                            if(dark_walk_R==100)
                                                    {

                                                    dark_X+=1.9;
                                                       BitBlt(SGWndDC,dark_X-2,dark_Y,96,88,Mir_V,dark_X-2,dark_Y,SRCCOPY);
                                                    TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkright2_V,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                                            if(dark_walk_R==200)
                                                  {
                                                    dark_X+=1.9;
                                                     BitBlt(SGWndDC,dark_X-2,dark_Y,96,88,Mir_V,dark_X-2,dark_Y,SRCCOPY);
                                                    TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkright3_V,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                                             if(dark_walk_R==300)
                                                    {
                                                    dark_X+=1.9;
                                                        BitBlt(SGWndDC,dark_X-2,dark_Y,96,88,Mir_V,dark_X-2,dark_Y,SRCCOPY);
                                                    TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkright4_V,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                                             if(dark_walk_R==400)
                                                    {
                                                    dark_X+=1.9;
                                                        BitBlt(SGWndDC,dark_X-2,dark_Y,96,88,Mir_V,dark_X-2,dark_Y,SRCCOPY);
                                                     TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkright5_V,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                                             if(dark_walk_R==500)
                                                    {
                                                    dark_X+=1.9;
                                                     BitBlt(SGWndDC,dark_X-2,dark_Y,96,88,Mir_V,dark_X-2,dark_Y,SRCCOPY);
                                                    TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkright6_V,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                                             if(dark_walk_R==600)
                                                    {
                                                    dark_X+=1.9;
                                                      BitBlt(SGWndDC,dark_X-2,dark_Y,96,88,Mir_V,dark_X-2,dark_Y,SRCCOPY);
                                                    TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkright7_V,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                                             if(dark_walk_R==700)
                                                    {
                                                    dark_X+=1.9;
                                                     BitBlt(SGWndDC,dark_X-2,dark_Y,96,88,Mir_V,dark_X-2,dark_Y,SRCCOPY);
                                                    TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkright8_V,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                                             if(dark_walk_R==800)
                                                    {
                                                    dark_X+=1.9;
                                                    BitBlt(SGWndDC,dark_X-2,dark_Y,96,88,Mir_V,dark_X-2,dark_Y,SRCCOPY);
                                                    TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkright9_V,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                                             if(dark_walk_R==900)
                                                    {
                                                    dark_X+=1.9;
                                                      BitBlt(SGWndDC,dark_X-2,dark_Y,96,88,Mir_V,dark_X-2,dark_Y,SRCCOPY);
                                                    TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkright10_V,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                                             if(dark_walk_R==1000)
                                                    {

                                                    dark_walk_R=0;
                                                    dark_X+=1.9;
                                                    BitBlt(SGWndDC,dark_X-2,dark_Y,96,88,Mir_V,dark_X-2,dark_Y,SRCCOPY);
                                                    TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkright11_V,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                           }
}
void darkscript_RIGHTforLEFT_VK_EDITION(HDC darkright_V=CreateCompatibleDC(SGWndDC),HDC darkright2_V=CreateCompatibleDC(SGWndDC),HDC darkright3_V=CreateCompatibleDC(SGWndDC),HDC darkright4_V=CreateCompatibleDC(SGWndDC),HDC darkright5_V=CreateCompatibleDC(SGWndDC),HDC darkright6_V=CreateCompatibleDC(SGWndDC),HDC darkright7_V=CreateCompatibleDC(SGWndDC),HDC darkright8_V=CreateCompatibleDC(SGWndDC),HDC darkright9_V=CreateCompatibleDC(SGWndDC),HDC darkright10_V=CreateCompatibleDC(SGWndDC),HDC darkright11_V=CreateCompatibleDC(SGWndDC),HDC Mir_V=CreateCompatibleDC (SGWndDC))
{

    if((dark_X+93<player_X)&&(ground_dark==true)&&(dark_lives>0))

                            {
                                    dark_Direction=true;

                                    dark_walk_R++;

                                            if(dark_walk_R==1)
                                                    {
                                                    dark_X+=1;
                                                     BitBlt(SGWndDC,dark_X-2,dark_Y,96,88,Mir_V,dark_X-2,dark_Y,SRCCOPY);
                                                    TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkright_V,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                                            if(dark_walk_R==100)
                                                    {

                                                    dark_X+=1;
                                                       BitBlt(SGWndDC,dark_X-2,dark_Y,96,88,Mir_V,dark_X-2,dark_Y,SRCCOPY);
                                                    TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkright2_V,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                                            if(dark_walk_R==200)
                                                  {
                                                    dark_X+=1;
                                                     BitBlt(SGWndDC,dark_X-2,dark_Y,96,88,Mir_V,dark_X-2,dark_Y,SRCCOPY);
                                                    TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkright3_V,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                                             if(dark_walk_R==300)
                                                    {
                                                    dark_X+=1;
                                                        BitBlt(SGWndDC,dark_X-2,dark_Y,96,88,Mir_V,dark_X-2,dark_Y,SRCCOPY);
                                                    TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkright4_V,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                                             if(dark_walk_R==400)
                                                    {
                                                    dark_X+=1;
                                                        BitBlt(SGWndDC,dark_X-2,dark_Y,96,88,Mir_V,dark_X-2,dark_Y,SRCCOPY);
                                                     TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkright5_V,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                                             if(dark_walk_R==500)
                                                    {
                                                    dark_X+=1;
                                                     BitBlt(SGWndDC,dark_X-2,dark_Y,96,88,Mir_V,dark_X-2,dark_Y,SRCCOPY);
                                                    TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkright6_V,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                                             if(dark_walk_R==600)
                                                    {
                                                    dark_X+=1;
                                                      BitBlt(SGWndDC,dark_X-2,dark_Y,96,88,Mir_V,dark_X-2,dark_Y,SRCCOPY);
                                                    TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkright7_V,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                                             if(dark_walk_R==700)
                                                    {
                                                    dark_X+=1;
                                                     BitBlt(SGWndDC,dark_X-2,dark_Y,96,88,Mir_V,dark_X-2,dark_Y,SRCCOPY);
                                                    TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkright8_V,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                                             if(dark_walk_R==800)
                                                    {
                                                    dark_X+=1;
                                                    BitBlt(SGWndDC,dark_X-2,dark_Y,96,88,Mir_V,dark_X-2,dark_Y,SRCCOPY);
                                                    TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkright9_V,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                                             if(dark_walk_R==900)
                                                    {
                                                    dark_X+=1;
                                                      BitBlt(SGWndDC,dark_X-2,dark_Y,96,88,Mir_V,dark_X-2,dark_Y,SRCCOPY);
                                                    TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkright10_V,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                                             if(dark_walk_R==1000)
                                                    {

                                                    dark_walk_R=0;
                                                    dark_X+=1;
                                                    BitBlt(SGWndDC,dark_X-2,dark_Y,96,88,Mir_V,dark_X-2,dark_Y,SRCCOPY);
                                                    TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkright11_V,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                           }
}





void player_R_script(HDC right_V=CreateCompatibleDC(SGWndDC),HDC right2_V=CreateCompatibleDC(SGWndDC),HDC right3_V=CreateCompatibleDC(SGWndDC),HDC right4_V=CreateCompatibleDC(SGWndDC),HDC right5_V=CreateCompatibleDC(SGWndDC),HDC right6_V=CreateCompatibleDC(SGWndDC),HDC right7_V=CreateCompatibleDC(SGWndDC),HDC right8_V=CreateCompatibleDC(SGWndDC),HDC right9_V=CreateCompatibleDC(SGWndDC),HDC right10_V=CreateCompatibleDC(SGWndDC),HDC right11_V=CreateCompatibleDC(SGWndDC),HDC Mir_V=CreateCompatibleDC (SGWndDC))
{
 if(wall_player_R==false)
                                     {
                                         direction_right=true;
                                         wall_player_R_1=0;
                                        player_walk++;
                                            if(player_walk==1)
                                                    {
                                                    player_X++;
                                                    BitBlt(SGWndDC,player_X-1,player_Y,95,88,Mir_V,player_X-1,player_Y,SRCCOPY);
                                                    TransparentBlt(SGWndDC,player_X,player_Y,94,88,right_V,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                                            if(player_walk==60)
                                                    {
                                                    player_X++;
                                                   BitBlt(SGWndDC,player_X-1,player_Y,95,88,Mir_V,player_X-1,player_Y,SRCCOPY);
                                                    TransparentBlt(SGWndDC,player_X,player_Y,94,88,right2_V,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                                            if(player_walk==120)
                                                    {
                                                    player_X++;
                                                    BitBlt(SGWndDC,player_X-1,player_Y,95,88,Mir_V,player_X-1,player_Y,SRCCOPY);
                                                    TransparentBlt(SGWndDC,player_X,player_Y,94,88,right3_V,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                                             if(player_walk==180)
                                                    {
                                                    player_X++;
                                                    BitBlt(SGWndDC,player_X-1,player_Y,95,88,Mir_V,player_X-1,player_Y,SRCCOPY);
                                                    TransparentBlt(SGWndDC,player_X,player_Y,94,88,right4_V,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                                             if(player_walk==240)
                                                    {
                                                    player_X++;
                                                    BitBlt(SGWndDC,player_X-1,player_Y,95,88,Mir_V,player_X-1,player_Y,SRCCOPY);
                                                    TransparentBlt(SGWndDC,player_X,player_Y,94,88,right5_V,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                                             if(player_walk==300)
                                                    {
                                                    player_X++;
                                                    BitBlt(SGWndDC,player_X-1,player_Y,95,88,Mir_V,player_X-1,player_Y,SRCCOPY);
                                                    TransparentBlt(SGWndDC,player_X,player_Y,94,88,right6_V,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                                             if(player_walk==360)
                                                    {
                                                    player_X++;
                                                   BitBlt(SGWndDC,player_X-1,player_Y,95,88,Mir_V,player_X-1,player_Y,SRCCOPY);
                                                    TransparentBlt(SGWndDC,player_X,player_Y,94,88,right7_V,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                                             if(player_walk==420)
                                                    {
                                                    player_X++;
                                                    BitBlt(SGWndDC,player_X-1,player_Y,95,88,Mir_V,player_X-1,player_Y,SRCCOPY);
                                                    TransparentBlt(SGWndDC,player_X,player_Y,94,88,right8_V,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                                             if(player_walk==480)
                                                    {
                                                    player_X++;
                                                    BitBlt(SGWndDC,player_X-1,player_Y,95,88,Mir_V,player_X-1,player_Y,SRCCOPY);
                                                    TransparentBlt(SGWndDC,player_X,player_Y,94,88,right9_V,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                                             if(player_walk==540)
                                                    {
                                                    player_X++;
                                                    BitBlt(SGWndDC,player_X-1,player_Y,95,88,Mir_V,player_X-1,player_Y,SRCCOPY);
                                                    TransparentBlt(SGWndDC,player_X,player_Y,94,88,right10_V,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                                             if(player_walk==600)
                                                    {
                                                        player_walk=0;
                                                    player_X++;
                                                    BitBlt(SGWndDC,player_X-1,player_Y,95,88,Mir_V,player_X-1,player_Y,SRCCOPY);
                                                    TransparentBlt(SGWndDC,player_X,player_Y,94,88,right11_V,0,0,94,88,RGB ( 255, 255, 255));
                                                    }

                                    }
}












int main()
{

    sgCreateWindow(1280,800);
    //изображения
    HBITMAP fireDR=(HBITMAP)LoadImage(0,"fireballR.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
    HDC fireball_R=CreateCompatibleDC(SGWndDC);
    sgSelectTool(fireball_R,fireDR);

        HBITMAP fireDL=(HBITMAP)LoadImage(0,"fireballL.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
    HDC fireball_L=CreateCompatibleDC(SGWndDC);
    sgSelectTool(fireball_L,fireDL);

                HBITMAP image1000=(HBITMAP)LoadImage(0,"list2.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC World=CreateCompatibleDC(SGWndDC);
                sgSelectTool(World,image1000);

                HBITMAP npc=(HBITMAP)LoadImage(0,"darkleft.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC darkleft=CreateCompatibleDC(SGWndDC);
                sgSelectTool(darkleft,npc);

                HBITMAP npc2=(HBITMAP)LoadImage(0,"darkleft2.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC darkleft2=CreateCompatibleDC(SGWndDC);
                sgSelectTool(darkleft2,npc2);

                HBITMAP npc3=(HBITMAP)LoadImage(0,"darkleft3.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC darkleft3=CreateCompatibleDC(SGWndDC);
                sgSelectTool(darkleft3,npc3);

                HBITMAP npc4=(HBITMAP)LoadImage(0,"darkleft4.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC darkleft4=CreateCompatibleDC(SGWndDC);
                sgSelectTool(darkleft4,npc4);

                HBITMAP npc5=(HBITMAP)LoadImage(0,"darkleft5.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC darkleft5=CreateCompatibleDC(SGWndDC);
                sgSelectTool(darkleft5,npc5);

                HBITMAP npc6=(HBITMAP)LoadImage(0,"darkleft6.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC darkleft6=CreateCompatibleDC(SGWndDC);
                sgSelectTool(darkleft6,npc6);

                HBITMAP npc7=(HBITMAP)LoadImage(0,"darkleft7.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC darkleft7=CreateCompatibleDC(SGWndDC);
                sgSelectTool(darkleft7,npc7);

                HBITMAP npc8=(HBITMAP)LoadImage(0,"darkleft8.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC darkleft8=CreateCompatibleDC(SGWndDC);
                sgSelectTool(darkleft8,npc8);

                HBITMAP npc9=(HBITMAP)LoadImage(0,"darkleft9.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC darkleft9=CreateCompatibleDC(SGWndDC);
                sgSelectTool(darkleft9,npc9);

                HBITMAP npc10=(HBITMAP)LoadImage(0,"darkleft10.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC darkleft10=CreateCompatibleDC(SGWndDC);
                sgSelectTool(darkleft10,npc10);

                HBITMAP npc11=(HBITMAP)LoadImage(0,"darkleft11.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC darkleft11=CreateCompatibleDC(SGWndDC);
                sgSelectTool(darkleft11,npc11);


                 HBITMAP npcright=(HBITMAP)LoadImage(0,"darkright.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC darkright=CreateCompatibleDC(SGWndDC);
                sgSelectTool(darkright,npcright);

                HBITMAP npcright2=(HBITMAP)LoadImage(0,"darkright2.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC darkright2=CreateCompatibleDC(SGWndDC);
                  sgSelectTool(darkright2,npcright2);

                HBITMAP npcright3=(HBITMAP)LoadImage(0,"darkright3.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC darkright3=CreateCompatibleDC(SGWndDC);
                sgSelectTool(darkright3,npcright3);

                HBITMAP npcright4=(HBITMAP)LoadImage(0,"darkright4.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC darkright4=CreateCompatibleDC(SGWndDC);
                sgSelectTool(darkright4,npcright4);

                HBITMAP npcright5=(HBITMAP)LoadImage(0,"darkright5.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC darkright5=CreateCompatibleDC(SGWndDC);
                sgSelectTool(darkright5,npcright5);

                HBITMAP npcright6=(HBITMAP)LoadImage(0,"darkright6.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC darkright6=CreateCompatibleDC(SGWndDC);
                sgSelectTool(darkright6,npcright6);

                HBITMAP npcright7=(HBITMAP)LoadImage(0,"darkright7.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC darkright7=CreateCompatibleDC(SGWndDC);
                sgSelectTool(darkright7,npcright7);

                HBITMAP npcright8=(HBITMAP)LoadImage(0,"darkright8.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC darkright8=CreateCompatibleDC(SGWndDC);
                sgSelectTool(darkright8,npcright8);

                HBITMAP npcright9=(HBITMAP)LoadImage(0,"darkright9.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC darkright9=CreateCompatibleDC(SGWndDC);
                sgSelectTool(darkright9,npcright9);

                HBITMAP npcright10=(HBITMAP)LoadImage(0,"darkright10.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC darkright10=CreateCompatibleDC(SGWndDC);
                sgSelectTool(darkright10,npcright10);

                HBITMAP npcright11=(HBITMAP)LoadImage(0,"darkright11.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC darkright11=CreateCompatibleDC(SGWndDC);
                sgSelectTool(darkright11,npcright11);




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
                HBITMAP fall0=(HBITMAP)LoadImage(0,"fallR.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC fallR=CreateCompatibleDC(SGWndDC);
                sgSelectTool(fallR,fall0);
                HBITMAP fall2=(HBITMAP)LoadImage(0,"fallL.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC fallL=CreateCompatibleDC(SGWndDC);
                sgSelectTool(fallL,fall2);
                HBITMAP arrowD=(HBITMAP)LoadImage(0,"arrow.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC arrow=CreateCompatibleDC(SGWndDC);
                sgSelectTool(arrow,arrowD);

                HBITMAP lolD=(HBITMAP)LoadImage(0,"dead_space_lol.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC deadlol=CreateCompatibleDC(SGWndDC);
                sgSelectTool(deadlol,lolD);


                HBITMAP menuD=(HBITMAP)LoadImage(0,"menu.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC menu=CreateCompatibleDC(SGWndDC);
                sgSelectTool(menu,menuD);

                HBITMAP mir= CreateCompatibleBitmap (SGWndDC, 1280, 800);
                HDC Mir= CreateCompatibleDC (SGWndDC);
                sgSelectTool(Mir,mir);




//mciSendString("open be.mp3 type mpegvideo alias song1", NULL, 0, 0);
//mciSendString("open 16bit.mp3 type mpegvideo alias song2", NULL, 0, 0);
//mciSendString("play song2 repeat", NULL, 0, 0);
bool menuB=true;
int mouseX=0;
int mouseY=0;
int player_X_int=0;
BITMAP KARTA_BITMAP;
//GetObject(white, sizeof , &bm);

//mciSendString("open attack.mp3 type mpegvideo alias song", NULL, 0, 0);
///////////////////////////////---------------------------------------------------------------|\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
}
//label:while(menuB==true)
{
    //BitBlt(SGWndDC,0,0,1280,800,menu,0,0,SRCCOPY);
  // if((sgGetMouseButtons()==1))
//{

//mouseY = sgGetMouseY();
//mouseX = sgGetMouseX();
    //if(((mouseY>404)&&(mouseX>470))&&((mouseY<494)&&(mouseX<954)))
   // {
        menuB=false;
  //  }
//}
//}
if(menuB==false)
{
    TransparentBlt(Mir,0,0,1280,800,whitelist,0,0,1280,800,RGB ( 255, 255, 255));
BitBlt(SGWndDC,0,0,1280,800,Mir,0,0,SRCCOPY);
TransparentBlt(SGWndDC,player_X,player_Y,94,88,right,0,0,94,88,RGB ( 255, 255, 255));

    for(int i=0;i!=1;i++)
{


sgWndFreeze(true);
BitBlt(SGWndDC,0,0,1280,800,Mir,0,0,SRCCOPY);
TransparentBlt(SGWndDC,player_X,player_Y,94,88,right,0,0,94,88,RGB ( 255, 255, 255));
TransparentBlt(SGWndDC,player_X,player_Y,94,88,right2,0,0,94,88,RGB ( 255, 255, 255));
TransparentBlt(SGWndDC,player_X,player_Y,94,88,right3,0,0,94,88,RGB ( 255, 255, 255));
TransparentBlt(SGWndDC,player_X,player_Y,94,88,right4,0,0,94,88,RGB ( 255, 255, 255));
TransparentBlt(SGWndDC,player_X,player_Y,94,88,right5,0,0,94,88,RGB ( 255, 255, 255));
TransparentBlt(SGWndDC,player_X,player_Y,94,88,right6,0,0,94,88,RGB ( 255, 255, 255));
TransparentBlt(SGWndDC,player_X,player_Y,94,88,right7,0,0,94,88,RGB ( 255, 255, 255));
TransparentBlt(SGWndDC,player_X,player_Y,94,88,right8,0,0,94,88,RGB ( 255, 255, 255));
TransparentBlt(SGWndDC,player_X,player_Y,94,88,right9,0,0,94,88,RGB ( 255, 255, 255));
TransparentBlt(SGWndDC,player_X,player_Y,94,88,right10,0,0,94,88,RGB ( 255, 255, 255));
TransparentBlt(SGWndDC,player_X,player_Y,94,88,right11,0,0,94,88,RGB ( 255, 255, 255));
TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkright,0,0,94,88,RGB ( 255, 255, 255));
TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkright2,0,0,94,88,RGB ( 255, 255, 255));
TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkright3,0,0,94,88,RGB ( 255, 255, 255));
TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkright4,0,0,94,88,RGB ( 255, 255, 255));
TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkright5,0,0,94,88,RGB ( 255, 255, 255));
TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkright6,0,0,94,88,RGB ( 255, 255, 255));
TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkright7,0,0,94,88,RGB ( 255, 255, 255));
TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkright8,0,0,94,88,RGB ( 255, 255, 255));
TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkright9,0,0,94,88,RGB ( 255, 255, 255));
TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkright10,0,0,94,88,RGB ( 255, 255, 255));
TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkright11,0,0,94,88,RGB ( 255, 255, 255));
TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkleft,0,0,94,88,RGB ( 255, 255, 255));
TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkleft2,0,0,94,88,RGB ( 255, 255, 255));
TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkleft3,0,0,94,88,RGB ( 255, 255, 255));
TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkleft4,0,0,94,88,RGB ( 255, 255, 255));
TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkleft5,0,0,94,88,RGB ( 255, 255, 255));
TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkleft6,0,0,94,88,RGB ( 255, 255, 255));
TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkleft7,0,0,94,88,RGB ( 255, 255, 255));
TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkleft8,0,0,94,88,RGB ( 255, 255, 255));
TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkleft9,0,0,94,88,RGB ( 255, 255, 255));
TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkleft10,0,0,94,88,RGB ( 255, 255, 255));
TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkleft11,0,0,94,88,RGB ( 255, 255, 255));

TransparentBlt(SGWndDC,player_X,player_Y,94,88,left,0,0,94,88,RGB ( 255, 255, 255));
TransparentBlt(SGWndDC,player_X,player_Y,94,88,left2,0,0,94,88,RGB ( 255, 255, 255));
TransparentBlt(SGWndDC,player_X,player_Y,94,88,left3,0,0,94,88,RGB ( 255, 255, 255));
TransparentBlt(SGWndDC,player_X,player_Y,94,88,left4,0,0,94,88,RGB ( 255, 255, 255));
TransparentBlt(SGWndDC,player_X,player_Y,94,88,left5,0,0,94,88,RGB ( 255, 255, 255));
TransparentBlt(SGWndDC,player_X,player_Y,94,88,left6,0,0,94,88,RGB ( 255, 255, 255));
TransparentBlt(SGWndDC,player_X,player_Y,94,88,left7,0,0,94,88,RGB ( 255, 255, 255));
TransparentBlt(SGWndDC,player_X,player_Y,94,88,left8,0,0,94,88,RGB ( 255, 255, 255));
TransparentBlt(SGWndDC,player_X,player_Y,94,88,left9,0,0,94,88,RGB ( 255, 255, 255));
TransparentBlt(SGWndDC,player_X,player_Y,94,88,left10,0,0,94,88,RGB ( 255, 255, 255));
TransparentBlt(SGWndDC,player_X,player_Y,94,88,left11,0,0,94,88,RGB ( 255, 255, 255));
sgWndFreeze(false);

}


    while(player_LIVES>0)
    {


        dark_X_int=dark_X;
        player_X_int=player_X;
   fireball_script(deadlol,fireball_R,fireball_L,Mir);
printf("%d %d",player_Y,dark_Y);
   if((dark_Y<=player_Y+88)&&(dark_Y+88>=player_Y)&&(ground_dark==true)&&(((dark_Direction==true)&&(dark_X_int+97>=player_X_int))||((dark_Direction==false)&&(dark_X_int<player_X_int+96))))
        {
            printf("%d %d",dark_Y,player_Y);
            player_LIVES--;

            if(dark_Direction==true)
            {
                player_X+=100;
                TransparentBlt(SGWndDC,player_X,player_Y,94,88,right,0,0,94,88,RGB ( 255, 255, 255));
            }
             if(dark_Direction==false)
            {
                player_X-=100;
                TransparentBlt(SGWndDC,player_X,player_Y,94,88,right,0,0,94,88,RGB ( 255, 255, 255));
            }
        }

                              for(int i=26;i!=69;i++)
                                                {


                                                    if((GetPixel(SGWndDC,player_X_int+i,player_Y+88)==RGB(124,252,0)||(GetPixel(SGWndDC,player_X_int+i,player_Y+88)==RGB(68,116,244))))
                                                    {

                                                        groundPixel_player++;
                                                    }



                                                    if((GetPixel(SGWndDC,dark_X_int+i,dark_Y+88)==RGB(124,252,0)||(GetPixel(SGWndDC,dark_X_int+i,dark_Y+88)==RGB(68,116,244)))&&(dark_lives!=0))
                                                    {
                                                        groundPixel_dark++;
                                                    }




                                                }


                                    if(groundPixel_player>0)
                                        {

                                            player_fall=false;
                                             ground_player=true;
                                             groundPixel_player=0;
                                        }
                                    else
                                    {
                                         player_fall=true;
                                          ground_player=false;
                                          groundPixel_player=0;
                                    }
                                     if(groundPixel_dark>0)
                                        {
                                            dark_fall=false;
                                             ground_dark=true;
                                             groundPixel_dark=0;
                                        }
                                    else
                                    {
                                         dark_fall=true;
                                             ground_dark=false;
                                             groundPixel_dark=0;

                                    }

                                if(ground_player==false)
                                {
                                    player_fall=true;
                                    player_fallC++;

                                        if((player_fallC==15)&&(LEFTorRIGHT==1))
                                            {

                                                player_fallC=0;
                                                 player_Y++;
                                               BitBlt(SGWndDC,player_X,player_Y-1,95,88,Mir,player_X,player_Y-1,SRCCOPY);
                                                TransparentBlt(SGWndDC,player_X,player_Y,95,88,fallR,0,0,94,88,RGB ( 255, 255, 255));
                                            }
                                          if((player_fallC==15)&&(LEFTorRIGHT==0))
                                            {

                                                player_fallC=0;
                                                 player_Y++;
                                                BitBlt(SGWndDC,player_X,player_Y-1,95,88,Mir,player_X,player_Y-1,SRCCOPY);
                                                TransparentBlt(SGWndDC,player_X,player_Y,94,88,fallL,0,0,94,88,RGB ( 255, 255, 255));
                                            }

                                }

                                if((ground_dark==false)&&(dark_lives!=0))
                                {
                                    dark_fall=true;
                                    dark_fallC++;

                                        if(dark_fallC==15)
                                            {

                                                dark_fallC=0;
                                                 dark_Y++;
                                               BitBlt(SGWndDC,dark_X,dark_Y-1,94,89,Mir,dark_X,dark_Y-1,SRCCOPY);
                                                TransparentBlt(SGWndDC,dark_X,dark_Y,94,88,darkleft,0,0,94,88,RGB ( 255, 255, 255));
                                            }

                                }
   ///////////////////////////////

                darkscript_LEFTforRIGHT(darkleft,darkleft2,darkleft3,darkleft4,darkleft5,darkleft6,darkleft7,darkleft8,darkleft9,darkleft10,darkleft11,Mir);
                darkscript_RIGHTforLEFT(darkright,darkright2,darkright3,darkright4,darkright5,darkright6,darkright7,darkright8,darkright9,darkright10,darkright11,Mir);
//               ////////////////    /////////////////1/////
//////////////////////RIGHT//////////////////////RIGHT//////////////////////RIGHT//////////////////////RIGHT//////////////////////RIGHT//////////////////////RIGHT
//////////////////////RIGHT//////////////////////RIGHT//////////////////////RIGHT//////////////////////RIGHT//////////////////////RIGHT//////////////////////RIGHT//////////////////////RIGHT//////////////////////RIGHT//////////////////////RIGHT
//////////////////////RIGHT//////////////////////RIGHT//////////////////////RIGHT//////////////////////RIGHT//////////////////////RIGHT//////////////////////RIGHT//////////////////////RIGHT//////////////////////RIGHT//////////////////////RIGHT//////////////////////RIGHT//////////////////////RIGHT
//////////////////////RIGHT//////////////////////RIGHT//////////////////////RIGHT//////////////////////RIGHT//////////////////////RIGHT//////////////////////RIGHT//////////////////////RIGHT//////////////////////RIGHT//////////////////////RIGHT//////////////////////RIGHT
//////////////////////RIGHT
                        if(GetAsyncKeyState(VK_RIGHT)&&(player_fall==false))
                            {
                                LEFTorRIGHT=1;
                                for(int i=0;i!=88;i++)
                                    {
                                         if(GetPixel(SGWndDC,player_X+69,player_Y+i)==RGB(68,116,244)||(GetPixel(SGWndDC,player_X+69,player_Y+i)==RGB(1,0,0)))
                                                 {
                                                     wall_player_R_Pixel++;
                                                 }

                                    }

                                if(wall_player_R_Pixel>0)
                                    {

                                        wall_player_R_Pixel=0;
                                        wall_player_R=true;
                                    }
                                else
                                {
                                    wall_player_R=false;
                                }


    ///////////////////////////////////////////////////////////////////////////
            fireball_VK_EDITION(fireball_R,fireball_R,Mir);
            darkscript_LEFTforRIGHT_VK_EDITION(darkleft,darkleft2,darkleft3,darkleft4,darkleft5,darkleft6,darkleft7,darkleft8,darkleft9,darkleft10,darkleft11,Mir);
            darkscript_RIGHTforLEFT_VK_EDITION(darkright,darkright2,darkright3,darkright4,darkright5,darkright6,darkright7,darkright8,darkright9,darkright10,darkright11,Mir);
        ////////////////////////////////////////////////////////////////
                                 if(wall_player_R==true)
                                 {
                                    while(wall_player_R_1!=1)
                                    {
                                        wall_player_R_1++;
                                        player_walk=0;
                                        BitBlt(SGWndDC,player_X-1,player_Y,player_X+94,player_Y,Mir,player_X-1,player_Y,SRCCOPY);
                                        TransparentBlt(SGWndDC,player_X,player_Y,94,88,right,0,0,94,88,RGB ( 255, 255, 255));

                                    }
                                 }
                                player_R_script(right,right2,right3,right4,right5,right6,right7,right8,right9,right10,right11,Mir);
                            }


                            //////////////////////////////// LEEEEEEEEEEEFTTTTTTTTTTTTTT//////////////////////////////// LEEEEEEEEEEEFTTTTTTTTTTTTTT
                            //////////////////////////////// LEEEEEEEEEEEFTTTTTTTTTTTTTT//////////////////////////////// LEEEEEEEEEEEFTTTTTTTTTTTTTT
                            //////////////////////////////// LEEEEEEEEEEEFTTTTTTTTTTTTTT//////////////////////////////// LEEEEEEEEEEEFTTTTTTTTTTTTTT
                            ///////////////////////
                            //////////LLLLLLLLLLLLLLLLEEEEEEEEEEEEEEEEEEEFTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT
                            //////////////////////////////// LEEEEEEEEEEEFTTTTTTTTTTTTTT//////////////////////////////// LEEEEEEEEEEEFTTTTTTTTTTTTTT
                                    ///////////////////////////////// LEEEEEEEEEEEFTTTTTTTTTTTTTT
                                      if(GetAsyncKeyState(VK_LEFT)&&(player_fall==false))
                            {
                                LEFTorRIGHT=0;
                                for(int i=0;i!=88;i++)
                                    {
                                         if(GetPixel(SGWndDC,player_X+25,player_Y+i)==RGB(68,116,244)||(GetPixel(SGWndDC,player_X+25,player_Y+i)==RGB(1,0,0)))
                                                 {
                                                     wall_player_L_Pixel++;
                                                 }

                                    }
                                if(wall_player_L_Pixel>0)
                                    {

                                        wall_player_L_Pixel=0;
                                        wall_player_L=true;
                                    }
                                else
                                {
                                    wall_player_L=false;
                                }
    ///////////////////////////////////////////////////////////////////////////
                                  fireball_VK_EDITION(fireball_R,fireball_L,Mir);
                                    darkscript_LEFTforRIGHT_VK_EDITION(darkleft,darkleft2,darkleft3,darkleft4,darkleft5,darkleft6,darkleft7,darkleft8,darkleft9,darkleft10,darkleft11,Mir);
                                     darkscript_RIGHTforLEFT_VK_EDITION(darkright,darkright2,darkright3,darkright4,darkright5,darkright6,darkright7,darkright8,darkright9,darkright10,darkright11,Mir);
        ////////////////////////////////////////////////////////////////
                                 if(wall_player_L==true)
                                 {
                                    while(wall_player_L_1!=1)
                                    {
                                        wall_player_L_1++;
                                        player_walk_L=0;

                                        BitBlt(SGWndDC,player_X,player_Y,95,88,Mir,player_X,player_Y,SRCCOPY);
                                        TransparentBlt(SGWndDC,player_X,player_Y,94,88,left,0,0,94,88,RGB ( 255, 255, 255));

                                    }
                                 }
                                 if(wall_player_L==false)
                                     {
                                         direction_right=false;
                                         wall_player_L_1=0;
                                        player_walk_L++;
                                            if(player_walk_L==1)
                                                    {
                                                    player_X--;
                                                   BitBlt(SGWndDC,player_X,player_Y,95,88,Mir,player_X,player_Y,SRCCOPY);
                                                    TransparentBlt(SGWndDC,player_X,player_Y,94,88,left,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                                            if(player_walk_L==60)
                                                    {
                                                    player_X--;
                                                    BitBlt(SGWndDC,player_X,player_Y,95,88,Mir,player_X,player_Y,SRCCOPY);
                                                    TransparentBlt(SGWndDC,player_X,player_Y,94,88,left2,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                                            if(player_walk_L==120)
                                                    {
                                                    player_X--;
                                                    BitBlt(SGWndDC,player_X,player_Y,95,88,Mir,player_X,player_Y,SRCCOPY);
                                                    TransparentBlt(SGWndDC,player_X,player_Y,94,88,left3,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                                             if(player_walk_L==180)
                                                    {
                                                    player_X--;
                                                    BitBlt(SGWndDC,player_X,player_Y,95,88,Mir,player_X,player_Y,SRCCOPY);
                                                    TransparentBlt(SGWndDC,player_X,player_Y,94,88,left4,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                                             if(player_walk_L==240)
                                                    {
                                                    player_X--;
                                                    BitBlt(SGWndDC,player_X,player_Y,95,88,Mir,player_X,player_Y,SRCCOPY);
                                                    TransparentBlt(SGWndDC,player_X,player_Y,94,88,left5,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                                             if(player_walk_L==300)
                                                    {
                                                    player_X--;
                                                    BitBlt(SGWndDC,player_X,player_Y,95,88,Mir,player_X,player_Y,SRCCOPY);
                                                    TransparentBlt(SGWndDC,player_X,player_Y,94,88,left6,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                                             if(player_walk_L==360)
                                                    {
                                                    player_X--;
                                                    BitBlt(SGWndDC,player_X,player_Y,95,88,Mir,player_X,player_Y,SRCCOPY);
                                                    TransparentBlt(SGWndDC,player_X,player_Y,94,88,left7,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                                             if(player_walk_L==420)
                                                    {
                                                    player_X--;
                                                    BitBlt(SGWndDC,player_X,player_Y,95,88,Mir,player_X,player_Y,SRCCOPY);
                                                    TransparentBlt(SGWndDC,player_X,player_Y,94,88,left8,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                                             if(player_walk_L==480)
                                                    {
                                                    player_X--;
                                                    BitBlt(SGWndDC,player_X,player_Y,95,88,Mir,player_X,player_Y,SRCCOPY);
                                                    TransparentBlt(SGWndDC,player_X,player_Y,94,88,left9,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                                             if(player_walk_L==540)
                                                    {
                                                    player_X--;
                                                    BitBlt(SGWndDC,player_X,player_Y,95,88,Mir,player_X,player_Y,SRCCOPY);
                                                    TransparentBlt(SGWndDC,player_X,player_Y,94,88,left10,0,0,94,88,RGB ( 255, 255, 255));
                                                    }
                                             if(player_walk_L==600)
                                                    {
                                                    player_walk_L=0;
                                                    player_X--;
                                                    BitBlt(SGWndDC,player_X,player_Y,95,88,Mir,player_X,player_Y,SRCCOPY);
                                                    TransparentBlt(SGWndDC,player_X,player_Y,94,88,left11,0,0,94,88,RGB ( 255, 255, 255));
                                                    }

                                    }



                            }



    }
    if(player_LIVES==0)
    {
        menuB=true;
        printf("LOL NOOB???B??B?");
        player_X=100;
        player_Y=300;
        dark_X=600;
        dark_Y=300;
        player_LIVES=2;
    //    goto label;
    }





}



}


}






