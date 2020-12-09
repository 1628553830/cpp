#include<conio.h>
#include<graphics.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
#include"start.cpp"
#define High 640
#define Width 640

LOGFONT standard;
int status[4][4]{};//棋子状态
int updatestatus[4][4]{};
int T_score,score;//分数
int qipan_x1,qipan_y1,qipan_x2,qipan_y2;//棋盘坐标
extern string str;//用来显示不同数字
string str1="退出游戏";//用来显示按钮的专用字符串

void setup();//初始化界面                                  1
void show();//显示实时动画                                 0
void drawqipan(int,int);//画棋盘                           1
void shownum();//显示更新后的棋子弹跳动画                   1
void updateWithInput();//输入的更新                        0
void updateWithoutInput();//不需要输入的更新                1
int  ReadTopScore();//读取分数                             0
void gameover();//游戏结束，更新最高分                      1
void calulate(int,int);//用来计算实时状态                   0
bool check();//用来是否能进行下去                           1

int main()
{
    //startui();
    setup();
    while(1)
    {
        show();
        updateWithInput();
        updateWithoutInput();
    }
}

void setup()
{
   initgraph(Width,High);//初始化画布
   windowtitle(L"2048");//设置窗口标题
   setbkmode(TRANSPARENT);//设置背景透明
   setbkcolor(RGB(69,167,168));//设置背景颜色
   cleardevice();//填充背景
   score=1000;
   T_score=ReadTopScore();
   qipan_x1=140;
   qipan_x2=500;
   qipan_y1=60;
   qipan_y2=580;

   //设置字体样式
   settextcolor(WHITE);
   settextstyle(0,0,_T("Consolas"));
   gettextstyle(&standard);
   standard.lfWidth=0;
   standard.lfQuality=ANTIALIASED_QUALITY;
   standard.lfWeight=1000;

   //初始化进入动画
   int speed=36;
   BeginBatchDraw();
   for(int i=585;speed;i-=speed)
   {
       _tcscpy(standard.lfFaceName,_T("Consolas"));
       cleardevice();
       drawqipan(0,i);
       FlushBatchDraw();
       Sleep(10);
       speed--;
   }
   speed=0;
   for(int i=-45;i<=0;i+=speed)
   {
       _tcscpy(standard.lfFaceName,_T("Consolas"));
       cleardevice();
       drawqipan(0,i);
       FlushBatchDraw();
       Sleep(13);
       speed++;
   }   
   EndBatchDraw();
   srand((unsigned)time(NULL)); 
   int x,y;
   x=rand()%4;
   y=rand()%4;
   status[x][y]=2;
   updatestatus[x][y]=1;
   x=rand()%4;
   y=rand()%4;
   while(status[x][y])
   {
     x=rand()%4;
     y=rand()%4;
   }
   status[x][y]=2;
   updatestatus[x][y]=1;
   shownum();
}
void drawqipan(int x,int y)
{

   RECT r;
   string TEXT;
   //棋盘最底部
       //阴影
   setfillcolor(RGB(53,129,129));  
   solidrectangle(qipan_x1+10+x,qipan_y1+10+y,qipan_x2+10+x,qipan_y2+10+y);  
       //棋盘   
   setfillcolor(RGB(62,203,210));
   solidrectangle(qipan_x1+x,qipan_y1+y,qipan_x2+x,qipan_y2+y);

   //棋盘左上角分数

       //底色
   setfillcolor(RGB(130,218,220));
   solidrectangle(qipan_x1+x+15,qipan_y1+y+15,qipan_x1+x+15+160,qipan_y1+y+15+135);
       //文本
   r={qipan_x1+x+15,qipan_y1+y+15,qipan_x1+x+15+160,qipan_y1+y+15+135};
   standard.lfHeight=30;
   settextstyle(&standard);
   drawtext(_T("SCORE:"),&r,DT_CENTER);
   
   IntToString(TEXT,score);
   standard.lfHeight=80;
   settextstyle(&standard);
   drawtext((LPCTSTR)TEXT.c_str(),&r,DT_VCENTER|DT_CENTER|DT_SINGLELINE);
   
   //棋盘右上角top分数

      //底部
   setfillcolor(RGB(130,218,220));
   solidrectangle(qipan_x1+x+15+160+15,qipan_y1+y+15,qipan_x1+x+15+160+15+160,qipan_y1+y+15+60);
      //文本
   r={qipan_x1+x+15+160+15,qipan_y1+y+15,qipan_x1+x+15+160+15+160,qipan_y1+y+15+60};
   IntToString(TEXT,T_score);
   TEXT="TOP:"+TEXT;
   standard.lfHeight=40;
   settextstyle(&standard);
   drawtext((LPCTSTR)TEXT.c_str(),&r,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
  
   //右上角退出按钮
      //阴影部分
    setfillcolor(RGB(53,129,129));
    solidrectangle(qipan_x1+x+15+160+15+5,qipan_y1+y+15+60+15+5,qipan_x1+x+15+160+15+160+5,qipan_y1+y+15+60+60+15+5); 
      //主体
    setfillcolor(RGB(130,218,220));
    solidrectangle(qipan_x1+x+15+160+15,qipan_y1+y+15+60+15,qipan_x1+x+15+160+15+160,qipan_y1+y+15+60+60+15); 
    r={qipan_x1+x+15+160+15,qipan_y1+y+15+60+15,qipan_x1+x+15+160+15+160,qipan_y1+y+15+60+60+15};
    if(str1=="退出游戏")
      {
        standard.lfHeight=30;_tcscpy(standard.lfFaceName,_T("宋体"));
      }
    else 
    {
        standard.lfHeight=35;_tcscpy(standard.lfFaceName,_T("Consolas"));
    }
    settextstyle(&standard);
    drawtext((LPCTSTR)str1.c_str(),&r,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
    

   //棋盘主部分
      //底色
   setfillcolor(RGB(212,254,253));
   solidrectangle(qipan_x1+x,qipan_y1+160+y,qipan_x2+x,qipan_y2+y);
      //格子
   setfillcolor(RGB(198,244,242));
   for(int i=0;i<16;i++)
   {
       solidrectangle(qipan_x1+x+(i%4)*85+20,qipan_y1+160+y+(i/4)*85+20,qipan_x1+x+(i%4)*85+20+65,qipan_y1+160+y+(i/4)*85+20+65);
   }
   
}
void shownum()
{
   int ridus=0;
   RECT r;
   BeginBatchDraw();
   for(int i=0;i<=10;i++)
   {
   ridus=i<=5?i:10-i;
   for(int j=0;j<4;j++)
   for(int k=0;k<4;k++)//把整个数组此时此刻状态全部画出来
   {
   if(!updatestatus[j][k])continue;
   int px1=qipan_x1+20+k*85,py1=qipan_y1+160+20+j*85;
   //还原棋盘底色
   setfillcolor(RGB(212,254,253));
   solidrectangle(px1-5-2,py1-5-2,px1+5+65+2,py1+5+65+2);
   FlushBatchDraw();
   //填充阴影
   setfillcolor(RGB(163,195,194));
   solidrectangle(px1+2-ridus,py1+2-ridus,px1+ridus+2+65,py1+ridus+2+65);
   //填充底色
   switch (status[j][k])
   {
   case 2:
       setfillcolor(RGB(146,244,243));
       break;
   case 4:
       setfillcolor(RGB(0,220,244));
       break;
   case 8:
       setfillcolor(RGB(0,166,244));
       break;
   case 16:
       setfillcolor(RGB(114,159,252));
       break;
   case 32:
       setfillcolor(RGB(0,120,225));
       break;
   case 64:
       setfillcolor(RGB(46,79,146));
       break;
   case 128:
       setfillcolor(RGB(3,65,228));
       break;
   case 256:
       setfillcolor(RGB(96,84,218));
       break;
   case 512:
       setfillcolor(RGB(165,128,234));
       break;
   case 1024:
       setfillcolor(RGB(176,99,253));
       break;
   case 2048:
       setfillcolor(RGB(157,1,232));
       break;
   }
   solidrectangle(px1-2-ridus,py1-2-ridus,px1+ridus-2+65,py1+ridus-2+65);

   //填充文字阴影
   IntToString(str,status[j][k]);
   r={px1-ridus,py1-ridus,px1+ridus+65,py1+ridus+65};
   switch(status[j][k])
   {
       case 2:settextcolor(RGB(121,191,189));
       break;
       case 4:settextcolor(RGB(20,173,189));
       break;
       case 8:settextcolor(RGB(21,136,191));
       break;
       case 16:settextcolor(RGB(101,131,197));
       break;
       case 32:settextcolor(RGB(22,106,179));
       break;
       case 64:settextcolor(RGB(53,74,121));
       break;
       case 128:settextcolor(RGB(24,67,180));
       break;
       case 256:settextcolor(RGB(87,80,175));
       break;
       case 512:settextcolor(RGB(136,109,184));
       break;
       case 1024:settextcolor(RGB(140,93,200));
       break;
       case 2048:settextcolor(RGB(131,22,175));
       break;

   }
   _tcscpy(standard.lfFaceName,_T("Consolas"));
   standard.lfHeight=35;
   standard.lfWeight=500;
   settextstyle(&standard);
   drawtext((LPCTSTR)str.c_str(),&r,DT_VCENTER|DT_CENTER|DT_SINGLELINE);
   //填充文字
   r={px1-2-ridus,py1-2-ridus,px1+ridus-2+65,py1+ridus-2+65};
   settextcolor(WHITE);
   drawtext((LPCTSTR)str.c_str(),&r,DT_VCENTER|DT_CENTER|DT_SINGLELINE);
   }
   FlushBatchDraw();
   Sleep(10);
   }
   EndBatchDraw();
}
void updateWithInput()
{
   if(kbhit())
   {
       char input;
       input=getch();
       if(input=='a'||input=='A')
       calulate(-1,0);
       else if(input=='s'||input=='S')
       calulate(0,-1);
       else if(input=='w'||input=='W')
       calulate(0,1);
       else if(input=='d'||input=='D')
       calulate(1,0);
   }
}
void updateWithoutInput()
{
   T_score=T_score<score?score:T_score;
   for(int i=0;i<4;i++)
   for(int j=0;j<4;j++)
   {
       if(status[i][j]==2048)
       {
           gameover();
       }
   }
   if(check())
   gameover();
}
void show()
{
   //move动画

   //显示动画
}
int  ReadTopScore()
{
  freopen("TOP.txt","r",stdin);
  int a;
  scanf("%d",&a);
  fclose(stdin);
  return a;
}
void gameover()
{
   str1="GAME OVER";
   show();
   BeginBatchDraw();
   RECT r;
   bool flag1=false,flag2=false;
   freopen("TOP.txt","w",stdout);
   while(1)
   {
       MOUSEMSG m;
       m=GetMouseMsg();
       if(m.x<=qipan_x1+15+160+15+160&&m.x>=qipan_x1+15+160+15&&m.y<=qipan_y1+15+60+60+15&&m.y>=qipan_y1+15+60+15)
       {
          flag2=true;
          if(m.uMsg==WM_LBUTTONDOWN)break;
          setfillcolor(RGB(53,129,129));
          solidrectangle(qipan_x1+15+160+15+5,qipan_y1+15+60+15+5,qipan_x1+15+160+15+160+5,qipan_y1+15+60+60+15+5); 
          setfillcolor(RGB(53,129,129));
          solidrectangle(qipan_x1+15+160+15,qipan_y1+15+60+15,qipan_x1+15+160+15+160,qipan_y1+15+60+60+15); 
          r={qipan_x1+15+160+15,qipan_y1+15+60+15,qipan_x1+15+160+15+160,qipan_y1+15+60+60+15};
          standard.lfHeight=35;
          _tcscpy(standard.lfFaceName,_T("Consolas"));
          settextstyle(&standard);
          drawtext((LPCTSTR)str1.c_str(),&r,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
          if(flag1!=flag2){FlushBatchDraw();flag1=true;}
       }
       else
       {
          flag2=false;
          setfillcolor(RGB(53,129,129));
          solidrectangle(qipan_x1+15+160+15+5,qipan_y1+15+60+15+5,qipan_x1+15+160+15+160+5,qipan_y1+15+60+60+15+5); 
          setfillcolor(RGB(130,218,220));
          solidrectangle(qipan_x1+15+160+15,qipan_y1+15+60+15,qipan_x1+15+160+15+160,qipan_y1+15+60+60+15); 
          r={qipan_x1+15+160+15,qipan_y1+15+60+15,qipan_x1+15+160+15+160,qipan_y1+15+60+60+15};
          standard.lfHeight=35;
          _tcscpy(standard.lfFaceName,_T("Consolas"));
          settextstyle(&standard);
          drawtext((LPCTSTR)str1.c_str(),&r,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
          if(flag1!=flag2){FlushBatchDraw();flag1=false;}
       }
   }
   printf("%d",T_score);
   fclose(stdout);
   exit(0);
}
void calulate(int x,int y)
{
   
}
bool check()
{
    int directions[4][2]={{0,1},{0,-1},{-1,0},{1,0}};
    for(int i=0;i<4;i++)
    {
        for(int k=0;k<4-directions[i][0];k++)
        for(int j=0;j<4-directions[i][1];j++)
        {
            if(status[k][j]==status[k+directions[i][0]][j+directions[i][1]])return true;
        }
    }
    return false;
}