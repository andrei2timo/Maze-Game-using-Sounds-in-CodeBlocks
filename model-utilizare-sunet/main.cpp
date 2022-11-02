#include <iostream>
#include <fstream>
#include <windows.h>
#include <graphics.h>
#include <mmsystem.h>
using namespace std;

int a[100][100],i,j, m, n;
int x, y;///coordonatele caracterului
char dir;///directia de deplasare: w , a ,  s , d

int main()
{
    ifstream f("date.in");

    f>>m>>n;
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            f>>a[i][j];
    int i1, j1;
    f>>i1>>j1;


    ///--------------------
    int W,H,L=30;
    W=n*L;
    H=m*L;

    int top=100, left=200;///coordonatele coltului din stanga sus pt fereastra
    initwindow(W,H,"*********",left,top);
    PlaySound("1.wav", NULL, SND_FILENAME|SND_LOOP|SND_ASYNC);
    int x, y,ok=0,game_over=1;
    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++)
        {
            x=(j-1)*L;
            y=(i-1)*L;
            if(a[i][j]==0)
                readimagefile("0.jpg",x,y,x+L,y+L);
            if(a[i][j]==1)
                readimagefile("1.jpg",x,y,x+L,y+L);
            if(a[i][j]==3)
                readimagefile("3.jpg",x,y,x+L,y+L);
            if(a[i][j]==2)
                readimagefile("2.jpg",x,y,x+L,y+L);

        }

    x=(j1-1)*L;
    y=(i1-1)*L;
    readimagefile("D.jpg",x,y,x+L,y+L);

    char ch;
    ch=getch();
    while(game_over==1)
    {


        ch=getch();
        x=(j1-1)*L;
        y=(i1-1)*L;

        if(ch==KEY_RIGHT && (a[i1][j1+1]==1 || a[i1][j1+1]==2))
        {

            readimagefile("1.jpg",x,y,x+L,y+L);
            j1++;
            x=(j1-1)*L;
            y=(i1-1)*L;
            readimagefile("D.jpg",x,y,x+L,y+L);
            if(ok==1 && a[i1+1][j1]==3)
            {
                a[i1+1][j1]=1;
                readimagefile("1.jpg",x,y,x+L,y+L);
                x=(j1-1)*L;
                y=(i1-1)*L;
                readimagefile("S.jpg",x,y,x+L,y+L);
            }
        }

        if(ch==KEY_LEFT && (a[i1][j1-1]==1 || a[i1][j1-1]==2))
        {

            readimagefile("1.jpg",x,y,x+L,y+L);
            j1--;
            x=(j1-1)*L;
            y=(i1-1)*L;
            readimagefile("A.jpg",x,y,x+L,y+L);
        }

        if(ch==KEY_UP && (a[i1-1][j1]==1 || a[i1-1][j1]==2))
        {

            readimagefile("1.jpg",x,y,x+L,y+L);
            i1--;
            x=(j1-1)*L;
            y=(i1-1)*L;
            readimagefile("W.jpg",x,y,x+L,y+L);
        }

        if(ch==KEY_DOWN && (a[i1+1][j1]==1 || a[i1+1][j1]==2))

        {
            readimagefile("1.jpg",x,y,x+L,y+L);
            i1++;
            x=(j1-1)*L;
            y=(i1-1)*L;
            readimagefile("S.jpg",x,y,x+L,y+L);
            if(ok==1 && a[i1+1][j1]==3)
            {
                a[i1+1][j1]=1;
                readimagefile("1.jpg",x,y,x+L,y+L);
                x=(j1-1)*L;
                y=(i1-1)*L;
                readimagefile("S.jpg",x,y,x+L,y+L);

            }
            if(i1==9 && j1==11)
        {
            ok=1;
            PlaySound("2.wav", NULL, SND_FILENAME|SND_ASYNC);
            delay(800);
            PlaySound("1.wav", NULL, SND_FILENAME|SND_LOOP|SND_ASYNC);


        }
        if(i1==14 && j1==13 && ok==1)
        {
            PlaySound("3.wav", NULL, SND_FILENAME|SND_ASYNC);
            delay(800);
            PlaySound("1.wav", NULL, SND_FILENAME|SND_LOOP|SND_ASYNC);


        }


        }


        if(i1==15 && j1==15)
            break;





    }
    cleardevice();
    readimagefile("4.jpg",0,0,W,H);
    PlaySound("4.wav", NULL, SND_FILENAME|SND_ASYNC);
    getch();

    delay(10000);
    return 0;
}
