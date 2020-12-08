#include<graphics.h>
#include<conio.h>
//Î§Æå
int main()
{
    initgraph(600,600);
    setbkcolor(WHITE);
    cleardevice();
    setlinestyle(PS_SOLID,2);
    setcolor(BLACK);
    for(int i=0;i<=600;i+=30)
    {
        line(0,i,600,i);
        line(i,0,i,600);
    }
    getch();
    closegraph();
    return 0;
}