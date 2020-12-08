/*
struct LOGFONT {
	LONG lfHeight;
	LONG lfWidth 
	LONG lfEscapement;
	LONG lfOrientation;
	LONG lfWeight;
	BYTE lfItalic;
	BYTE lfUnderline;
	BYTE lfStrikeOut;
	BYTE lfCharSet;
	BYTE lfOutPrecision;
	BYTE lfClipPrecision;
	BYTE lfQuality;
	BYTE lfPitchAndFamily;
	TCHAR lfFaceName[LF_FACESIZE];
};
lfHeight 
指定高度（逻辑单位）。
lfWidth
指定字符的平均宽度（逻辑单位）。如果为 0，则比例自适应。
lfEscapement
字符串的书写角度，单位 0.1 度，默认为 0。
lfOrientation
每个字符的书写角度，单位 0.1 度，默认为 0。
lfWeight
字符的笔画粗细，范围 0~1000，0 表示默认粗细，使用数字或下表中定义的宏均可。
lfItalic
指定字体是否是斜体。
lfUnderline
指定字体是否有下划线。
lfStrikeOut
指定字体是否有删除线
lfCharSet
指定字符集。可以使用以下预定义的值：
lfOutPrecision
指定文字的输出精度。输出精度定义输出与所请求的字体高度、宽度、字符方向、行距、间距和字体类型相匹配必须达到的匹配程度。可以是以下值：
lfClipPrecision
指定文字的剪辑精度。剪辑精度定义如何剪辑字符的一部分位于剪辑区域之外的字符。可以是以下值：
lfClipPrecision
指定文字的剪辑精度。剪辑精度定义如何剪辑字符的一部分位于剪辑区域之外的字符。可以是以下值：
lfQuality
指定文字的输出质量。输出质量定义图形设备界面 (GDI) 必须尝试将逻辑字体属性与实际物理字体的字体属性进行匹配的仔细程度。可以是以下值：
lfPitchAndFamily
指定以常规方式描述字体的字体系列。字体系列描述大致的字体外观。字体系列用于在所需精确字体不可用时指定字体。1~2 位指定字体间距，可以是以下值：
lfFaceName
字体名称，名称不得超过 31 个字符。如果是空字符串，系统将使用第一个满足其它属性的字体。

#include<graphics.h>
#include<conio.h>
int main()
{
   initgraph(640,480);
   LOGFONT f;   
   setbkcolor(GREEN);
   cleardevice();
   settextstyle(16,0,_T("Consolas"));
   settextcolor(RED);
   gettextstyle(&f);
   
   f.lfHeight=200;
   f.lfWeight=1000;
   f.lfQuality=ANTIALIASED_QUALITY;
   settextstyle(&f);

   RECT r={0,0,640,480};
   drawtext(_T("2048"),&r,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
   _getch();
   
   
}
*/
#include<conio.h>
#include<graphics.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>

int main()
{
   //初始化背景
   initgraph(640,480);
   setbkcolor(GREEN);
   cleardevice();
   //初始化结构体
   LOGFONT f;
   RECT r{0,0,640,480};
   settextstyle(0,0,_T("Consolas"));
   gettextstyle(&f);
   f.lfWeight=1000;
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
   //输出红字2048RED
   settextcolor(RED);
   f.lfHeight=200;
   _tcscpy(f.lfFaceName,_T("Consolas"));
   settextstyle(&f);
   drawtext(_T("2048"),&r,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
   Sleep(1000);
   _getch();
   closegraph();
}