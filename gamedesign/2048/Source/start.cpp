#include<conio.h>
#include<graphics.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
#include"windowtitle.cpp"
string str;
void startui()
{   
   mciSendString(_T("open C:\\Users\\Varocol\\Desktop\\c\\gamedesign\\2048\\music\\1.mp3 alias bkmusic"),NULL,0,NULL);
   mciSendString(_T("play bkmusic repeat"),NULL,0,NULL);
   //初始化背景
   initgraph(640,480);
   setbkcolor(GREEN);
   setbkmode(TRANSPARENT);
   cleardevice();
   windowtitle(L"开始界面");
   //初始化结构体
   LOGFONT f;//存储字体属性
   RECT r{0,0,640,480};
   settextstyle(0,0,_T("Consolas"));
   gettextstyle(&f);
   f.lfWeight=0;
   f.lfWidth=0;
   f.lfQuality=ANTIALIASED_QUALITY;
   
   //输出黑字2
   settextcolor(BLACK);
   f.lfHeight=200;
   _tcscpy(f.lfFaceName,_T("黑体"));
   settextstyle(&f);
   drawtext(_T("2"),&r,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
   Sleep(1000);
   cleardevice();
   //输出白字20
   settextcolor(WHITE);
   f.lfHeight=200;
   _tcscpy(f.lfFaceName,_T("宋体"));
   settextstyle(&f);
   drawtext(_T("20"),&r,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
   Sleep(1000);
   cleardevice();
   //输出蓝字204
   settextcolor(BLUE);
   f.lfHeight=200;
   _tcscpy(f.lfFaceName,_T("楷体"));
   settextstyle(&f);
   drawtext(_T("204"),&r,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
   Sleep(1000);
   cleardevice();
   //输出阴影部分
   settextcolor(BLACK);
   f.lfHeight=250;
   _tcscpy(f.lfFaceName,_T("Consolas"));
   settextstyle(&f);
   outtextxy(95,120,_T("2048"));
   //输出红字2048
   settextcolor(RED);
   drawtext(_T("2048"),&r,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
   Sleep(1000);

   //输出Power by Group 7510
   wchar_t s[23]=L"▂Powered by Group 7510"; 
   wchar_t current[24];
   current[22]='\0';
   current[23]='\0';
   settextcolor(BLACK);
   f.lfHeight=50;
   settextstyle(&f);
   for(int i=0;i<22;i++)
   {
      bool flag=true;
      for(int j=0;j<22;j++)
      {
          if(flag)
          {
              current[j]=s[j];
              if(s[j]==L'▂')
              {wchar_t temp;temp=s[j+1];s[j+1]=s[j];s[j]=temp;flag=false;}
          }
          else current[j]=L' ';
      }
      Wchar_tToString(str,current);//把wchar_t类型转换成string
      drawtext((LPCTSTR)str.c_str(),&r,DT_CENTER|DT_BOTTOM|DT_SINGLELINE);
      Sleep(200);
      settextcolor(GREEN);
      drawtext((LPCTSTR)str.c_str(),&r,DT_CENTER|DT_BOTTOM|DT_SINGLELINE);
      settextcolor(BLACK);
   }
   while(!kbhit())
   {
       BeginBatchDraw();
       static bool flag=true;
       if(flag)
       {
           current[21]=' ';
           current[22]=' ';
           Wchar_tToString(str,current);
           outtextxy(60,430,(LPCTSTR)str.c_str());
           FlushBatchDraw();
           Sleep(500);
           flag=!flag;
       }
       else
       {
           
           current[21]=L'▂';
           current[22]='\0';
           Wchar_tToString(str,current);
           outtextxy(60,430,(LPCTSTR)str.c_str());
           FlushBatchDraw();
           Sleep(500);
           settextcolor(GREEN);
           outtextxy(60,430,(LPCTSTR)str.c_str());
           settextcolor(BLACK);
           flag=!flag;
       }
   }
   EndBatchDraw();//用完以后一定要记得关闭
   closegraph();
   fflush(stdin);
}