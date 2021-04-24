#include<array>
#include<vector>
#include<iostream>
using namespace std;
int main()
{
    //vector
    vector<int>a(0);//vector<typename>XX(num_element);
    int c;
    cin>>c;
    vector<double>b(c);//创建一个c个元素的b数组

    //array
    array<double,4>d;//array<typename,num_element>XX;
    array<double,4>e{1.0,2.0,3.0,4.0};
    array<int,4>g;
    d.at(1)=0;
    b.at(1)=0;
    d=e;             //可以复制数组长度必须相等
    //一般数组
    int f[10];

}