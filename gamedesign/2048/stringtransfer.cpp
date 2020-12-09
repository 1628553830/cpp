#include<iostream>
#include<graphics.h>

using namespace std;


void Wchar_tToString(std::string& szDst, wchar_t*wchar)
{
wchar_t * wText = wchar;
DWORD dwNum = WideCharToMultiByte(CP_OEMCP,NULL,wText,-1,NULL,0,NULL,FALSE);//WideCharToMultiByte的运用
char *psText;  // psText为char*的临时数组，作为赋值给std::string的中间变量
psText = new char[dwNum];
WideCharToMultiByte (CP_OEMCP,NULL,wText,-1,psText,dwNum,NULL,FALSE);//WideCharToMultiByte的再次运用
szDst = psText;// std::string赋值
delete []psText;// psText的清除
}

void IntToString(string& s,int num)
{
    s="";
    if(!num)s="0";
    while(num)
    {
        s=char(num%10+'0')+s;
        num/=10;
    }
}