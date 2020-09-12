#include<stdio.h>
#include<windows.h>
#include"sg.h"

struct pony
{
    int sprite,jumptime,jumpupdate,x,y,lives,groundpixel,fallspeed,sleep,sleep_non,pose_R,pose_L,sprite_L,sleep_L,wall_dark_L;
    bool direction,idle,jump;
    int walk_R,walk_L;
    bool wall_R,wall_L;
    int wall_RC,wall_LC;
    int jump_wall_LC,jump_wall_RC;
    bool jump_wall_L,jump_wall_R;
    bool ground;
    int falltimer;
    char mass[100];

};

int mouseX,mouseY;
int lime=124+(252<<8)+(0<<16);
int blue=68+(116<<8)+(244<<16);
int height=800;
int width = 1500;
int Mir_X=1500;


int main()
{

sgCreateWindow(1280,800);
        HBITMAP imagezs=(HBITMAP)LoadImage(0,"right1.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
        HDC rightz=CreateCompatibleDC(SGWndDC);
        sgSelectTool(rightz,imagezs);
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
                HBITMAP image=(HBITMAP)LoadImage(0,"right1.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
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
                 HBITMAP imagez2=(HBITMAP)LoadImage(0,"left1.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC leftz=CreateCompatibleDC(SGWndDC);
                sgSelectTool(leftz,imagez2);
                HBITMAP image12=(HBITMAP)LoadImage(0,"left1.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
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

                HBITMAP mir= CreateCompatibleBitmap (SGWndDC,Mir_X, 800);
                HDC Mir= CreateCompatibleDC (SGWndDC);
                sgSelectTool(Mir,mir);

                BitBlt(Mir,0,0,Mir_X,800,whitelist,0,0,SRCCOPY);
//FILE * pFile;
//pFile = fopen ("myfile.txt","w");
int *data = new int [width * height];
for (int i = 0; i < width; i++)
for (int j = 0; j < height; j++)
{
    data[i + j * width] = GetPixel(Mir, i, j);
//    fprintf (pFile,"%d,",data[i + j * width]);
}
//fclose (pFile);


pony player;
pony dark;
player.jumptime=0;
player.direction=true;
dark.direction=false;
player.ground=false;
player.sprite_L=0;
player.falltimer=0;
dark.falltimer=0;
player.walk_R=0;
player.walk_L=0;
player.fallspeed=2000;
player.sleep=1000;
player.sleep_non=1000;
player.sleep_L=1000;
player.pose_R=0;
player.sleep_L=1000;
player.sprite_L=0;
player.walk_L=0;


player.pose_L=0;
player.idle==true;
player.sprite=0;
player.jump=false;
player.jumpupdate=200;
bool menuB=true;
label:while(menuB==true)
{
BitBlt(SGWndDC,0,0,1280,800,menu,0,0,SRCCOPY);
    if((sgGetMouseButtons()==1))
        {
            mouseY = sgGetMouseY();
            mouseX = sgGetMouseX();
                if(((mouseY>404)&&(mouseX>470))&&((mouseY<494)&&(mouseX<954)))
                    {
                        menuB=false;
                        player.x=200;
                        player.y=200;
                        player.lives=10;
                        dark.x=700;
                        dark.y=200;
                        dark.lives=3;
                        player.direction=true;
                        dark.direction=false;
                        BitBlt(SGWndDC,0,0,1280,800,Mir,0,0,SRCCOPY);
                        TransparentBlt(SGWndDC,player.x,player.y,94,88,right,0,0,94,88,RGB ( 255, 255, 255));
                        TransparentBlt(SGWndDC,dark.x,dark.y,94,88,darkright,0,0,94,88,RGB ( 255, 255, 255));

                    }
        }
}
while(player.lives>0)
    {

        if(player.jump==false)
        {
            for(int i=26;i!=69;i++)
            {
                if((data[player.x+i + (player.y+88) * width]==lime)||(data[player.x+i + (player.y+88) * width]==blue))
                {

                player.groundpixel++;
                break;
                }
            }

             if(player.groundpixel>0)
            {

                player.ground=true;
                player.groundpixel=0;
            }
        else
            {
                player.ground=false;
                player.groundpixel=0;
            }

        if(player.ground==false)player.falltimer++;
        if(player.falltimer==player.fallspeed)
            {
                player.idle=true;
                player.y++;
                player.falltimer=0;
                if(player.direction==true)
                    {
                        BitBlt(SGWndDC,player.x,player.y-1,94,88,Mir,player.x,player.y-1,SRCCOPY);
                        TransparentBlt(SGWndDC,player.x,player.y,94,88,right,0,0,94,88,RGB ( 255, 255, 255));
                    }
                else
                    {
                        BitBlt(SGWndDC,player.x,player.y-1,94,88,Mir,player.x,player.y-1,SRCCOPY);
                        TransparentBlt(SGWndDC,player.x,player.y,94,88,left,0,0,94,88,RGB ( 255, 255, 255));
                    }

            }


        }

        for(int i=26;i!=69;i++)
            {
                if((data[dark.x+i + (dark.y+88) * width]==lime)||(data[dark.x+i + (dark.y+88) * width]==blue))
                {
                    dark.groundpixel++;
                    break;
                }
            }

         if(dark.groundpixel>0)
            {
                dark.ground=true;
                dark.groundpixel=0;
            }
        else
            {
                dark.ground=false;
                dark.groundpixel=0;
            }

        if(dark.ground==false)dark.falltimer++;
        if(dark.falltimer==player.fallspeed)
            {
                dark.y++;
                dark.falltimer=0;
                if(dark.direction==true)
                    {
                        BitBlt(SGWndDC,dark.x,dark.y-1,94,88,Mir,dark.x,dark.y-1,SRCCOPY);
                        TransparentBlt(SGWndDC,dark.x,dark.y,94,88,darkright,0,0,94,88,RGB ( 255, 255, 255));
                    }
                else
                    {
                        BitBlt(SGWndDC,dark.x,dark.y-1,94,88,Mir,dark.x,dark.y-1,SRCCOPY);
                        TransparentBlt(SGWndDC,dark.x,dark.y,94,88,darkleft,0,0,94,88,RGB ( 255, 255, 255));
                    }

            }

if((player.y<=dark.y+88)&&(player.y+88>=dark.y)&&(dark.x+93<player.x)&&(dark.ground==true)&&(dark.lives>0))
    {
        ///////////////////////////////////////////////////////////////////////////////////////////
    }
if(GetAsyncKeyState(VK_RIGHT)&&!(GetAsyncKeyState(VK_LEFT))&&(player.ground==true))
{

     if(player.direction==false)
                {
                    player.sleep_L=1000;
                    player.sprite_L=0;
                    player.walk_L=0;
                    player.pose_L=0;
                }
    player.direction=true;
    for(int i=0;i!=88;i++)
        {

            if(data[player.x+69+(player.y+i) * width]==blue)
                {
                    player.wall_RC++;
                    break;
                }
        }
        if(player.wall_RC>0)
                {
                    player.wall_R=true;
                    player.wall_RC=0;
                }
            else
                {
                        player.wall_R=false;
                        player.wall_RC=0;
                }
    if((player.wall_R==true)&&(player.idle==true))
    {
        player.idle=false;
        player.sleep=1000;
        player.sprite=0;
        player.walk_R=0;
        player.pose_R=0;

        BitBlt(SGWndDC,player.x-1,player.y,95,88,Mir,player.x-1,player.y,SRCCOPY);
        TransparentBlt(SGWndDC,player.x,player.y,94,88,rightz,0,0,94,88,RGB ( 255, 255, 255));
    }

    if(player.wall_R==false)
        {

            player.idle=true;
            player.walk_R++;

            if(player.pose_R==11)
                {
                    player.sleep=1000;
                    player.sprite=0;
                    player.walk_R=0;
                    player.pose_R=0;
                }

            if(player.walk_R==player.sleep)
            {
                player.pose_R++;
                player.sleep+=player.sleep_non;
                player.x++;
                player.sprite++;
                sprintf(player.mass,"right%d.bmp",player.sprite);
                HBITMAP image=(HBITMAP)LoadImage(0,player.mass,IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC right=CreateCompatibleDC(SGWndDC);
                sgSelectTool(right,image);
                BitBlt(SGWndDC,player.x-1,player.y,95,88,Mir,player.x-1,player.y,SRCCOPY);
                TransparentBlt(SGWndDC,player.x,player.y,94,88,right,0,0,94,88,RGB ( 255, 255, 255));
            }
        }
}

if(GetAsyncKeyState(VK_LEFT)&&!(GetAsyncKeyState(VK_RIGHT))&&(player.ground==true))
{

      if(player.direction==true)
                {
                    player.sleep=1000;
                    player.sprite=0;
                    player.walk_R=0;
                    player.pose_R=0;
                }
             player.direction=false;
    for(int i=0;i!=88;i++)
        {
            if(data[player.x+25+(player.y+i) * width]==blue)
                {
                    player.wall_LC++;
                    break;
                }
        }

        if(player.wall_LC>0)
                {
                    player.wall_L=true;
                    player.wall_LC=0;
                }
            else
                {
                        player.wall_L=false;
                        player.wall_LC=0;
                }
        if((player.wall_L==true)&&(player.idle==true))
    {

        player.idle=false;
        player.sleep_L=1000;
        player.sprite_L=0;
        player.walk_L=0;
        player.pose_L=0;

        BitBlt(SGWndDC,player.x-1,player.y,95,88,Mir,player.x-1,player.y,SRCCOPY);
        TransparentBlt(SGWndDC,player.x,player.y,94,88,leftz,0,0,94,88,RGB ( 255, 255, 255));
    }

    if(player.wall_L==false)
        {
            player.idle=true;
            player.walk_L++;
            if(player.pose_L==11)
                {
                    player.sleep_L=1000;
                    player.sprite_L=0;
                    player.walk_L=0;
                    player.pose_L=0;

                }

            if(player.walk_L==player.sleep_L)
                {
                    player.pose_L++;
                    player.sleep_L+=player.sleep_non;
                    player.x--;
                    player.sprite_L++;
                    sprintf(player.mass,"left%d.bmp",player.sprite_L);
                    HBITMAP image=(HBITMAP)LoadImage(0,player.mass,IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                    HDC left=CreateCompatibleDC(SGWndDC);
                    sgSelectTool(left,image);
                    BitBlt(SGWndDC,player.x,player.y,95,88,Mir,player.x,player.y,SRCCOPY);
                    TransparentBlt(SGWndDC,player.x,player.y,94,88,left,0,0,94,88,RGB ( 255, 255, 255));


                }
        }
}

if(GetAsyncKeyState(VK_SPACE)&&(player.ground==true)&&(player.jump==false))
{
player.jump=true;
}
if((player.jump==true)&&(player.jumptime!=80000))
{
    player.idle=false;
    player.ground=false;
    player.jumptime++;
    if(player.jumptime==player.jumpupdate)
    {
    player.jumpupdate+=2000;
    player.y--;
    if(player.direction==true)
    {
    BitBlt(SGWndDC,player.x,player.y,94,89,Mir,player.x,player.y,SRCCOPY);
    TransparentBlt(SGWndDC,player.x,player.y,94,88,fallR,0,0,94,88,RGB ( 255, 255, 255));
    }
    else
    {
    BitBlt(SGWndDC,player.x,player.y,94,89,Mir,player.x,player.y,SRCCOPY);
    TransparentBlt(SGWndDC,player.x,player.y,94,88,fallL,0,0,94,88,RGB ( 255, 255, 255));
    }

    }
    if((GetAsyncKeyState(VK_RIGHT))&&!(GetAsyncKeyState(VK_LEFT)))
        {
            player.direction=true;

        }

}
if(player.jumptime==80000)
{
    player.jumptime=0;
    player.jumpupdate=2000;
    player.jump=false;
}
 if(!(GetAsyncKeyState(VK_RIGHT))&&!(GetAsyncKeyState(VK_LEFT))&&(player.ground==true)&&!(GetAsyncKeyState(VK_SPACE)))
{


    if(player.idle==true)
    {


        player.idle=false;


                if(player.direction==true)
                    {
                            player.sleep=1000;
                            player.sprite=0;
                            player.walk_R=0;
                            player.pose_R=0;
                            BitBlt(SGWndDC,player.x-1,player.y,95,88,Mir,player.x-1,player.y,SRCCOPY);
                            TransparentBlt(SGWndDC,player.x,player.y,94,88,rightz,0,0,94,88,RGB ( 255, 255, 255));
                    }
                else
                    {
                        player.sleep_L=1000;
                        player.sprite_L=0;
                        player.walk_L=0;
                        player.pose_L=0;
                        BitBlt(SGWndDC,player.x-1,player.y,95,88,Mir,player.x-1,player.y,SRCCOPY);
                        TransparentBlt(SGWndDC,player.x,player.y,94,88,leftz,0,0,94,88,RGB ( 255, 255, 255));
                    }

    }
}
    }















}
