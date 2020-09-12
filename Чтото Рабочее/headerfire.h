#ifndef HEADERFIRE_H
#define HEADERFIRE_H
#include "sg.h"
void fireballMove()
{

     HBITMAP fireballRD=(HBITMAP)LoadImage(0,"fireballR.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
                HDC fireballR=CreateCompatibleDC(SGWndDC);
                sgSelectTool(fireballR,fireballRD);
    int firerange=0;
    bool firelaunched=false;
    int xFire=0;
    int yFire=0;
    printf("IEASIESA\n");

    if((firerange!=100)&&(firelaunched==true))
                         {
                             printf("IEASIESA\n");

                             xFire+=2;
                             firerange+=2;
                             TransparentBlt ( SGWndDC, xFire,yFire,26,14,fireballR,0,0,26,14, RGB ( 255, 255, 255 )  );
                           Sleep(5);



                         }
                         if(firerange==100)
                         {
                        firerange=0;
                             firelaunched=false;


                         }
}
#endif
