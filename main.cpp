#include <iostream>
#include <graphics.h>
#include <winbgim.h>
#include <windows.h>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <MMSystem.h>

using namespace std;

int wWidth, wHeight;
int wleft, wtop;
char title[20];

struct tree{
    int tx = rand()%wWidth;
    int ty1 = 0;
    int ty2 = wHeight/3;
    int ty3 = 2*wHeight/3;
    int h = 40+(rand()%60);
    int w = 5+(rand()%10);
    int r1 = 20+(rand()%30);
    int r2 = 25+(rand()%40);
};

void drawTree(int x, int y, int h, int w, int r1, int r2)
{
    setcolor(BROWN);
    rectangle(x-w/2,y-h,x+w/2,y);
    setfillstyle(SOLID_FILL,BROWN);
    floodfill(x,y-h+1,BROWN);
    floodfill(x,y-1,BROWN);
    setcolor(GREEN);
    setfillstyle(SOLID_FILL,GREEN);
    fillellipse(x,y-h-r2,r1,r2);
}

int main()
{
    DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
    DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);

    cout << screenWidth << " "  << screenHeight << endl;

    srand(time(0));

    wHeight = 768;
    wWidth = 432;
    strcpy(title, "Game");
    wleft = screenWidth/2-wWidth/2;
    wtop = 0;

    int p = 0;

    initwindow(wWidth,wHeight,title,wleft,wtop);

    while(1){
        ifstream f("best.txt");
        int best;
        f >> best;
        cout << best << endl;

        int score = 0;
        int speed;
        char s[50],b[50];

        setfillstyle(SOLID_FILL,LIGHTGREEN);
        floodfill(wWidth-1,wHeight-1,WHITE);

        int px = wWidth/2;
        int py = wHeight-wHeight/9;
        int pw = 30;
        int ph = 50;
       // setcolor(WHITE);
       // setfillstyle(SOLID_FILL,WHITE);
       // fillellipse(cx,cy,r,r);

        readimagefile("player1v3.jpg",px-pw/2,py-ph/2,px+pw/2,py+ph/2);

        tree t1,t2,t3,t4,t5, t6,t7,t8,t9,t10, t11,t12,t13,t14,t15;

        drawTree(t1.tx,t1.ty1,t1.h,t1.w,t1.r1,t1.r2);
        drawTree(t2.tx,t2.ty1,t2.h,t2.w,t2.r1,t2.r2);
        drawTree(t3.tx,t3.ty1,t3.h,t3.w,t3.r1,t3.r2);
        drawTree(t4.tx,t4.ty1,t4.h,t4.w,t4.r1,t4.r2);
        drawTree(t5.tx,t5.ty1,t5.h,t5.w,t5.r1,t5.r2);

        drawTree(t6.tx,t6.ty2,t6.h,t6.w,t6.r1,t6.r2);
        drawTree(t7.tx,t7.ty2,t7.h,t7.w,t7.r1,t7.r2);
        drawTree(t8.tx,t8.ty2,t8.h,t8.w,t8.r1,t8.r2);
        drawTree(t9.tx,t9.ty2,t9.h,t9.w,t9.r1,t9.r2);
        drawTree(t10.tx,t10.ty2,t10.h,t10.w,t10.r1,t10.r2);

        drawTree(t11.tx,t11.ty3,t11.h,t11.w,t11.r1,t11.r2);
        drawTree(t12.tx,t12.ty3,t12.h,t12.w,t12.r1,t12.r2);
        drawTree(t13.tx,t13.ty3,t13.h,t13.w,t13.r1,t13.r2);
        drawTree(t14.tx,t14.ty3,t14.h,t14.w,t14.r1,t14.r2);
        drawTree(t15.tx,t15.ty3,t15.h,t15.w,t15.r1,t15.r2);

        if(p == 0){
            settextstyle(3, HORIZ_DIR, 4);
            int tw = textwidth("Click to start");
            setcolor(WHITE);
            outtextxy(wWidth/2-tw/2,wHeight/2,"Click to start");


            while(1){
                if(ismouseclick(WM_LBUTTONDOWN)) break;
            }
            //getch();
        }

        PlaySound(TEXT("music2.wav"),NULL,SND_ASYNC);

        int page = 1;

        int x = 1;
        int y = 10;

        while(1){
            clearmouseclick(WM_LBUTTONDOWN);

            p = 1;
            speed = 10+score*0.125;

            setfillstyle(SOLID_FILL,LIGHTGREEN);
            floodfill(wWidth-1,wHeight-1,WHITE);

            px = mousex();

           // if(GetAsyncKeyState(VK_LEFT)) cx -= speed;
           // if(GetAsyncKeyState(VK_RIGHT)) cx += speed;

           // if(cx <= 0) cx = 0;
           // if(cx >= wWidth) cx = wWidth;

           // setcolor(WHITE);
           // setfillstyle(SOLID_FILL,WHITE);
           // fillellipse(cx,cy,r,r);

            y = 10 - speed*0.3;
            if(y <= 3) y = 3;
            x++;

            if(x <= y)readimagefile("player1v3.jpg",px-pw/2,py-ph/2,px+pw/2,py+ph/2);
            else readimagefile("player2v3.jpg",px-pw/2,py-ph/2,px+pw/2,py+ph/2);

            if(x >= 2*y) x = 1;

            cout << y  << " " << x << endl;


            t1.ty1 += speed;
            t2.ty1 += speed;
            t3.ty1 += speed;
            t4.ty1 += speed;
            t5.ty1 += speed;

            t6.ty2 += speed;
            t7.ty2 += speed;
            t8.ty2 += speed;
            t9.ty2 += speed;
            t10.ty2 += speed;

            t11.ty3 += speed;
            t12.ty3 += speed;
            t13.ty3 += speed;
            t14.ty3 += speed;
            t15.ty3 += speed;

            drawTree(t1.tx,t1.ty1,t1.h,t1.w,t1.r1,t1.r2);
            drawTree(t2.tx,t2.ty1,t2.h,t2.w,t2.r1,t2.r2);
            drawTree(t3.tx,t3.ty1,t3.h,t3.w,t3.r1,t3.r2);
            drawTree(t4.tx,t4.ty1,t4.h,t4.w,t4.r1,t4.r2);
            drawTree(t5.tx,t5.ty1,t5.h,t5.w,t5.r1,t5.r2);

            drawTree(t6.tx,t6.ty2,t6.h,t6.w,t6.r1,t6.r2);
            drawTree(t7.tx,t7.ty2,t7.h,t7.w,t7.r1,t7.r2);
            drawTree(t8.tx,t8.ty2,t8.h,t8.w,t8.r1,t8.r2);
            drawTree(t9.tx,t9.ty2,t9.h,t9.w,t9.r1,t9.r2);
            drawTree(t10.tx,t10.ty2,t10.h,t10.w,t10.r1,t10.r2);

            drawTree(t11.tx,t11.ty3,t11.h,t11.w,t11.r1,t11.r2);
            drawTree(t12.tx,t12.ty3,t12.h,t12.w,t12.r1,t12.r2);
            drawTree(t13.tx,t13.ty3,t13.h,t13.w,t13.r1,t13.r2);
            drawTree(t14.tx,t14.ty3,t14.h,t14.w,t14.r1,t14.r2);
            drawTree(t15.tx,t15.ty3,t15.h,t15.w,t15.r1,t15.r2);

            sprintf(s,"Score: %d",score);
            settextstyle(3, HORIZ_DIR , 3);
            setcolor(WHITE);
            outtextxy(10,10,s);


            if(t1.ty1-t1.h-2*t1.r2 >= wHeight &&
               t2.ty1-t2.h-2*t2.r2 >= wHeight &&
               t3.ty1-t3.h-2*t3.r2 >= wHeight &&
               t4.ty1-t4.h-2*t4.r2 >= wHeight &&
               t5.ty1-t5.h-2*t5.r2 >= wHeight){

                score++;

                t1.tx = 1+(rand()%wWidth);
                t1.ty1 = 0;
                t1.h = 40+(rand()%60);
                t1.w = 5+(rand()%10);
                t1.r1 = 20+(rand()%30);
                t1.r2 = 25+(rand()%40);

                t2.tx = 1+(rand()%wWidth);
                t2.ty1 = 0;
                t2.h = 40+(rand()%60);
                t2.w = 5+(rand()%10);
                t2.r1 = 20+(rand()%30);
                t2.r2 = 25+(rand()%40);

                t3.tx = 1+(rand()%wWidth);
                t3.ty1 = 0;
                t3.h = 40+(rand()%60);
                t3.w = 5+(rand()%10);
                t3.r1 = 20+(rand()%30);
                t3.r2 = 25+(rand()%40);

                t4.tx = 1+(rand()%wWidth);
                t4.ty1 = 0;
                t4.h = 40+(rand()%60);
                t4.w = 5+(rand()%10);
                t4.r1 = 20+(rand()%30);
                t4.r2 = 25+(rand()%40);

                t5.tx = 1+(rand()%wWidth);
                t5.ty1 = 0;
                t5.h = 40+(rand()%60);
                t5.w = 5+(rand()%10);
                t5.r1 = 20+(rand()%30);
                t5.r2 = 25+(rand()%40);
            }

            if(t6.ty2-t6.h-2*t6.r2 >= wHeight &&
               t7.ty2-t7.h-2*t7.r2 >= wHeight &&
               t8.ty2-t8.h-2*t8.r2 >= wHeight &&
               t9.ty2-t9.h-2*t9.r2 >= wHeight &&
               t10.ty2-t10.h-2*t10.r2 >= wHeight){

                score++;

                t6.tx = 1+(rand()%wWidth);
                t6.ty2 = 0;
                t6.h = 40+(rand()%60);
                t6.w = 5+(rand()%10);
                t6.r1 = 20+(rand()%30);
                t6.r2 = 25+(rand()%40);

                t7.tx = 1+(rand()%wWidth);
                t7.ty2 = 0;
                t7.h = 40+(rand()%60);
                t7.w = 5+(rand()%10);
                t7.r1 = 20+(rand()%30);
                t7.r2 = 25+(rand()%40);

                t8.tx = 1+(rand()%wWidth);
                t8.ty2 = 0;
                t8.h = 40+(rand()%60);
                t8.w = 5+(rand()%10);
                t8.r1 = 20+(rand()%30);
                t8.r2 = 25+(rand()%40);

                t9.tx = 1+(rand()%wWidth);
                t9.ty2 = 0;
                t9.h = 40+(rand()%60);
                t9.w = 5+(rand()%10);
                t9.r1 = 20+(rand()%30);
                t9.r2 = 25+(rand()%40);

                t10.tx = 1+(rand()%wWidth);
                t10.ty2 = 0;
                t10.h = 40+(rand()%60);
                t10.w = 5+(rand()%10);
                t10.r1 = 20+(rand()%30);
                t10.r2 = 25+(rand()%40);
            }

            if(t11.ty3-t11.h-2*t11.r2 >= wHeight &&
               t12.ty3-t12.h-2*t12.r2 >= wHeight &&
               t13.ty3-t13.h-2*t13.r2 >= wHeight &&
               t14.ty3-t14.h-2*t14.r2 >= wHeight &&
               t15.ty3-t15.h-2*t15.r2 >= wHeight){

                score++;

                t11.tx = 1+(rand()%wWidth);
                t11.ty3 = 0;
                t11.h = 40+(rand()%60);
                t11.w = 5+(rand()%10);
                t11.r1 = 20+(rand()%30);
                t11.r2 = 25+(rand()%40);

                t12.tx = 1+(rand()%wWidth);
                t12.ty3 = 0;
                t12.h = 40+(rand()%60);
                t12.w = 5+(rand()%10);
                t12.r1 = 20+(rand()%30);
                t12.r2 = 25+(rand()%40);

                t13.tx = 1+(rand()%wWidth);
                t13.ty1 = 0;
                t13.h = 40+(rand()%60);
                t13.w = 5+(rand()%10);
                t13.r1 = 20+(rand()%30);
                t13.r2 = 25+(rand()%40);

                t14.tx = 1+(rand()%wWidth);
                t14.ty3 = 0;
                t14.h = 40+(rand()%60);
                t14.w = 5+(rand()%10);
                t14.r1 = 20+(rand()%30);
                t14.r2 = 25+(rand()%40);

                t15.tx = 1+(rand()%wWidth);
                t15.ty3 = 0;
                t15.h = 40+(rand()%60);
                t15.w = 5+(rand()%10);
                t15.r1 = 20+(rand()%30);
                t15.r2 = 25+(rand()%40);
            }

            if((px+pw/2 >= t1.tx-t1.w/2 && px-pw/2 <= t1.tx+t1.w/2 && py-ph/2 <= t1.ty1 && py+ph/2 >= t1.ty1-t1.w) ||
               (px+pw/2 >= t2.tx-t2.w/2 && px-pw/2 <= t2.tx+t2.w/2 && py-ph/2 <= t2.ty1 && py+ph/2 >= t2.ty1-t2.w) ||
               (px+pw/2 >= t3.tx-t3.w/2 && px-pw/2 <= t3.tx+t3.w/2 && py-ph/2 <= t3.ty1 && py+ph/2 >= t3.ty1-t3.w) ||
               (px+pw/2 >= t4.tx-t4.w/2 && px-pw/2 <= t4.tx+t4.w/2 && py-ph/2 <= t4.ty1 && py+ph/2 >= t4.ty1-t4.w) ||
               (px+pw/2 >= t5.tx-t5.w/2 && px-pw/2 <= t5.tx+t5.w/2 && py-ph/2 <= t5.ty1 && py+ph/2 >= t5.ty1-t5.w) ||

               (px+pw/2 >= t6.tx-t6.w/2 && px-pw/2 <= t6.tx+t6.w/2 && py-ph/2 <= t6.ty2 && py+ph/2 >= t6.ty2-t6.w) ||
               (px+pw/2 >= t7.tx-t7.w/2 && px-pw/2 <= t7.tx+t7.w/2 && py-ph/2 <= t7.ty2 && py+ph/2 >= t7.ty2-t7.w) ||
               (px+pw/2 >= t8.tx-t8.w/2 && px-pw/2 <= t8.tx+t8.w/2 && py-ph/2 <= t8.ty2 && py+ph/2 >= t8.ty2-t8.w) ||
               (px+pw/2 >= t9.tx-t9.w/2 && px-pw/2 <= t9.tx+t9.w/2 && py-ph/2 <= t9.ty2 && py+ph/2 >= t9.ty2-t9.w) ||
               (px+pw/2 >= t10.tx-t10.w/2 && px-pw/2 <= t10.tx+t10.w/2 && py-ph/2 <= t10.ty2 && py+ph/2 >= t10.ty2-t10.w) ||

               (px+pw/2 >= t11.tx-t11.w/2 && px-pw/2 <= t11.tx+t11.w/2 && py-ph/2 <= t11.ty3 && py+ph/2 >= t11.ty3-t11.w) ||
               (px+pw/2 >= t12.tx-t12.w/2 && px-pw/2 <= t12.tx+t12.w/2 && py-ph/2 <= t12.ty3 && py+ph/2 >= t12.ty3-t12.w) ||
               (px+pw/2 >= t13.tx-t13.w/2 && px-pw/2 <= t13.tx+t13.w/2 && py-ph/2 <= t13.ty3 && py+ph/2 >= t13.ty3-t13.w) ||
               (px+pw/2 >= t14.tx-t14.w/2 && px-pw/2 <= t14.tx+t14.w/2 && py-ph/2 <= t14.ty3 && py+ph/2 >= t14.ty3-t14.w) ||
               (px+pw/2 >= t15.tx-t15.w/2 && px-pw/2 <= t15.tx+t15.w/2 && py-ph/2 <= t15.ty3 && py+ph/2 >= t15.ty3-t15.w)){

                    PlaySound(TEXT("hit.wav"),NULL,SND_ASYNC);

                    settextstyle(3, HORIZ_DIR, 4);
                    int tw = textwidth("GAME OVER");
                    int th = textheight("GAME OVER");
                    setcolor(WHITE);
                    outtextxy(wWidth/2-tw/2,100,"GAME OVER");
                    settextstyle(3, HORIZ_DIR , 3);
                    int sw = textwidth(s);
                    int sh = textheight(s);
                    outtextxy(wWidth/2-sw/2,100+th,s);
                    int rw = textwidth("Click to restart");
                    outtextxy(wWidth/2-rw/2,wHeight/2+50,"Click to restart");
                    if(score > best) best = score;
                    sprintf(b,"Best: %d",best);
                    settextstyle(3, HORIZ_DIR , 3);
                    int bw = textwidth(b);
                    outtextxy(wWidth/2-bw/2,100+th+sh,b);

                    setvisualpage(1-page);
                    ofstream f("best.txt");
                    f << best;
                    f.close();
                    cout << best << endl;

                    while(1){
                        if(ismouseclick(WM_LBUTTONDOWN))
                            break;
                        }
                    break;
                }

            cout << score << " " << speed << endl;

            setactivepage(page);
            setvisualpage(1-page);

            cleardevice();

            page = 1 - page;

            delay(10);
        }
    }

    getch();
    closegraph();

    return 0;
}
