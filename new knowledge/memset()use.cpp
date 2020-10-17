#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    int a[10]{1,2,3,4,5,6,7,8,9,0};
    memset(a,1,sizeof(a));//非零值不能用memset,因为memset是以一个字节为单位赋值的（char就是一个字节的），而int是四个字节
    for(int i=0;i<10;i++)
    cout<<a[i]<<" ";
    cout<<endl;
    string b[3]{"abc","ccc","lalala"};
    memset(b,0,sizeof(b));//理论上讲所有的字符都将变成'\0',即空字符串
    for(int i=0;i<3;i++)
    cout<<b[i]<<"*";
    cin.get();
    cin.get();
}
//总结：memset函数的第一个参数为数组名或者地址或者指针。
//     第二个参数是把每个字节都赋值为这个数。
//     第三个参数是赋值的字节数