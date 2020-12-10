#include"stringtransfer.cpp"
void windowtitle(wchar_t *s)
{ 
   string str;
   Wchar_tToString(str,s);
   SetWindowText(GetHWnd(),(LPCTSTR)str.c_str());
}