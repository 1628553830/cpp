#include<iostream>
using namespace std;
int main()
{
    string a="Hello World!",b;
    b=a.substr(0,5);//前一个参数是元素位置,后一个参数是截取位数
    b=a.substr(3);//从位置三开始往后一直截取直到末尾
}