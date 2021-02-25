#include<conio.h>
#include<graphics.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
#include"start.cpp"
#define High 640
#define Width 640
//引用windows api
#pragma comment(lib,"Winmm.lib")

LOGFONT standard;//字体参数
RECT r;//矩形坐标
int status[4][4]{};//棋子状态
bool updatestatus[4][4]{};
bool flag=false;
int T_score,score;//分数
int qipan_x1,qipan_y1,qipan_x2,qipan_y2;//棋盘坐标
MOUSEMSG m;//鼠标消息
extern string str;//用来显示不同数字

void setup();//初始化界面                                  1
void show();//显示实时动画                                 1
void drawqipan(int,int);//画棋盘,按q退出                    1
void shownewnum();//显示更新后的新棋子弹跳动画               1
void shownum();//显示旧棋子                                 1
void updateWithInput();//输入的更新                        1
void updateWithoutInput();//不需要输入的更新                1
int  ReadTopScore();//读取分数                             1
void gameover();//游戏结束，更新最高分                      1
bool calulate(int,int);//用来计算实时状态                   1
bool check();//用来是否能进行下去                           1
void produce();//用来生成随机数                             1


int main()
{
    startui();
    setup();
    show();
    while(1)
    {
        if(flag)show();
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
   score=0;
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
   
}
void drawqipan(int x,int y)//x,y表示坐标
{
   BeginBatchDraw();
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
   standard.lfHeight=66;
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
   standard.lfHeight=35;
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
    standard.lfHeight=35;
    settextstyle(&standard);
    drawtext(_T("Q TO QUIT"),&r,DT_CENTER|DT_VCENTER|DT_SINGLELINE);

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
   EndBatchDraw();
}
void shownewnum()
{
   int ridus=0;
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
   settextstyle(&standard);
   drawtext((LPCTSTR)str.c_str(),&r,DT_VCENTER|DT_CENTER|DT_SINGLELINE);
   //填充文字
   r={px1-2-ridus,py1-2-ridus,px1+ridus-2+65,py1+ridus-2+65};
   settextcolor(WHITE);
   drawtext((LPCTSTR)str.c_str(),&r,DT_VCENTER|DT_CENTER|DT_SINGLELINE);
   }
   FlushBatchDraw();
   Sleep(15);
   }
   EndBatchDraw();
}
void shownum()
{
   BeginBatchDraw();
   for(int i=0;i<4;i++)
   for(int j=0;j<4;j++)
   {
       if(status[i][j]&&!updatestatus[i][j])//旧棋子
       {
   int px1=qipan_x1+20+j*85,py1=qipan_y1+160+20+i*85;
   //填充阴影
   setfillcolor(RGB(163,195,194));
   solidrectangle(px1+2,py1+2,px1+2+65,py1+2+65);
   //填充底色
   switch (status[i][j])
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
   solidrectangle(px1-2,py1-2,px1-2+65,py1-2+65);

   //填充文字阴影
   IntToString(str,status[i][j]);
   r={px1,py1,px1+65,py1+65};
   switch(status[i][j])
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
   settextstyle(&standard);
   drawtext((LPCTSTR)str.c_str(),&r,DT_VCENTER|DT_CENTER|DT_SINGLELINE);
   //填充文字
   r={px1-2,py1-2,px1-2+65,py1-2+65};
   settextcolor(WHITE);
   drawtext((LPCTSTR)str.c_str(),&r,DT_VCENTER|DT_CENTER|DT_SINGLELINE);
       }
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
       {if(calulate(-1,0)){produce();flag=true;}}
       else if(input=='s'||input=='S')
       {if(calulate(0,1)){produce();flag=true;}}
       else if(input=='w'||input=='W')
       {if(calulate(0,-1)){produce();flag=true;}}
       else if(input=='d'||input=='D')
       {if(calulate(1,0)){produce();flag=true;}}
       else if(input=='q'||input=='Q')
       {
           freopen("C:\\Users\\Varocol\\Desktop\\c\\gamedesign\\2048\\Score\\TOP.txt","w",stdout);
           printf("%d",T_score);
           fclose(stdout);
           closegraph();
           exit(0);
       }
   }
}
void updateWithoutInput()
{
   T_score=T_score<score?score:T_score;
   if(!check())
   gameover();
}
void show()
{

   //显示动画
   drawqipan(0,0);//绘制棋盘
   shownum();//展示旧棋子
   shownewnum();//展示新棋子
   memset(updatestatus,0,sizeof(updatestatus));
   flag=false;
}
int  ReadTopScore()
{
  freopen("C:\\Users\\Varocol\\Desktop\\c\\gamedesign\\2048\\Score\\TOP.txt","r",stdin);
  int a;
  scanf("%d",&a);
  fclose(stdin);
  return a;
}
void gameover()
{
   show();
   setfillcolor(RGB(53,129,129));
   solidrectangle(qipan_x1+15+160+15+5,qipan_y1+15+60+15+5,qipan_x1+15+160+15+160+5,qipan_y1+15+60+60+15+5); 
   setfillcolor(RGB(130,218,220));
   solidrectangle(qipan_x1+15+160+15,qipan_y1+15+60+15,qipan_x1+15+160+15+160,qipan_y1+15+60+60+15); 
   r={qipan_x1+15+160+15,qipan_y1+15+60+15,qipan_x1+15+160+15+160,qipan_y1+15+60+60+15};
   standard.lfHeight=35;
  _tcscpy(standard.lfFaceName,_T("Consolas"));
   settextstyle(&standard);
   drawtext(_T("GAME OVER"),&r,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
   while(1)
   {
       MOUSEMSG m;
       m=GetMouseMsg();
       if(m.x<=qipan_x1+15+160+15+160&&m.x>=qipan_x1+15+160+15&&m.y<=qipan_y1+15+60+60+15&&m.y>=qipan_y1+15+60+15)
       {
          if(m.uMsg==WM_LBUTTONDOWN)break;
          setfillcolor(RGB(53,129,129));
          solidrectangle(qipan_x1+15+160+15+5,qipan_y1+15+60+15+5,qipan_x1+15+160+15+160+5,qipan_y1+15+60+60+15+5); 
          setfillcolor(RGB(53,129,129));
          solidrectangle(qipan_x1+15+160+15,qipan_y1+15+60+15,qipan_x1+15+160+15+160,qipan_y1+15+60+60+15); 
          r={qipan_x1+15+160+15,qipan_y1+15+60+15,qipan_x1+15+160+15+160,qipan_y1+15+60+60+15};
          standard.lfHeight=35;
          _tcscpy(standard.lfFaceName,_T("Consolas"));
          settextstyle(&standard);
          drawtext(_T("GAME OVER"),&r,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
       }
       else
       {
          setfillcolor(RGB(53,129,129));
          solidrectangle(qipan_x1+15+160+15+5,qipan_y1+15+60+15+5,qipan_x1+15+160+15+160+5,qipan_y1+15+60+60+15+5); 
          setfillcolor(RGB(130,218,220));
          solidrectangle(qipan_x1+15+160+15,qipan_y1+15+60+15,qipan_x1+15+160+15+160,qipan_y1+15+60+60+15); 
          r={qipan_x1+15+160+15,qipan_y1+15+60+15,qipan_x1+15+160+15+160,qipan_y1+15+60+60+15};
          standard.lfHeight=35;
          _tcscpy(standard.lfFaceName,_T("Consolas"));
          settextstyle(&standard);
          drawtext(_T("GAME OVER"),&r,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
       }
   }
   EndBatchDraw();
   closegraph();
   freopen("C:\\Users\\Varocol\\Desktop\\c\\gamedesign\\2048\\Score\\TOP.txt","w",stdout);
   printf("%d",T_score);
   fclose(stdout);
   exit(0);
}
bool calulate(int x,int y)
{
   int previous[4][4];
   for(int i=0;i<4;i++)
   for(int j=0;j<4;j++)
   previous[i][j]=status[i][j];
   if(x==0)
   {
       if(y==-1)
       for(int i=0;i<4;i++)
       for(int j=0;j<3;j++)
       {
           int num=j+1;
           while(!status[num][i]&&num<4)num++;
           if(num==4)break;
           if(!status[j][i]){status[j][i]=status[num][i];status[num][i]=0;j--;}
           else if(status[num][i]==status[j][i]){status[j][i]*=2;score+=status[j][i];status[num][i]=0;updatestatus[j][i]=1;}
       }
       else
       for(int i=0;i<4;i++)
       for(int j=3;j>0;j--)
       {
           int num=j-1;
           while(!status[num][i]&&num>=0)num--;
           if(num==-1)break;
           if(!status[j][i]){status[j][i]=status[num][i];status[num][i]=0;j++;}
           else if(status[num][i]==status[j][i]){status[j][i]*=2;score+=status[j][i];status[num][i]=0;updatestatus[j][i]=1;}
       }
   }
   else
   {
       if(x==-1)
       for(int i=0;i<4;i++)
       for(int j=0;j<3;j++)
       {
           int num=j+1;
           while(!status[i][num]&&num<4)num++;
           if(num==4)break;
           if(!status[i][j]){status[i][j]=status[i][num];status[i][num]=0;j--;}
           else if(status[i][num]==status[i][j]){status[i][j]*=2;score+=status[j][i];status[i][num]=0;updatestatus[i][j]=1;}
       }
       else 
       for(int i=0;i<4;i++)
       for(int j=3;j>0;j--)
       {
           int num=j-1;
           while(!status[i][num]&&num>=0)num--;
           if(num==-1)break;
           if(!status[i][j]){status[i][j]=status[i][num];status[i][num]=0;j++;}
           else if(status[i][num]==status[i][j]){status[i][j]*=2;score+=status[j][i];status[i][num]=0;updatestatus[i][j]=1;}
       }
   }
   for(int i=0;i<4;i++)
   for(int j=0;j<4;j++)
   {
       if(status[i][j]!=previous[i][j])return true;
   }
   return false;
}
bool check()
{
    for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
    if(!status[i][j])return true;
    for(int i=0;i<4;i++)
    for(int j=0;j<3;j++)
    if(status[i][j]==status[i][j+1])return true;
    for(int i=0;i<4;i++)
    for(int j=0;j<3;j++)
    if(status[j][i]==status[j+1][i])return true;
    return false;
}
void produce()
{
    int ans=0,a;
    int xulie[16][2];
    for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
    {
       if(!status[i][j]){xulie[ans][0]=i;xulie[ans++][1]=j;}
    }
    if(!ans)return;
    a=rand()%ans;
    status[xulie[a][0]][xulie[a][1]]=2;
    updatestatus[xulie[a][0]][xulie[a][1]]=1;//弹跳新棋子
}