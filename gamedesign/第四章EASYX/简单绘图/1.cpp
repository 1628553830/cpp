#include<graphics.h>
#include<conio.h>
int main()
{
    initgraph(640,480);
    unsigned long color[]{BLACK,WHITE,BLUE,GREEN,RED,BROWN,YELLOW};
    for(int i=0;i<=480;i++)
    {
        setlinecolor(color[i/48%7]);
        line(0,i,640,i);
    }
    getch();
    closegraph();
    return 0;
}