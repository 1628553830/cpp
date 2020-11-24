#include<iostream>
#include<string.h>
using namespace std;
int letter[26],total=0;
void T(int,int);
int main()
{
    int N;
    cin>>N;
    while(N--)
    {
        for(int i=0;i<26;i++)
           cin>>letter[i];
        T(0,0);
        cout<<total<<endl;
        total=0;
    }
    cin.get();
    cin.get();
    
}
void T(int sum,int a)
{
    for(int i=a;i<26&&sum+i+1<=50;i++)
       {
           if(letter[i])
           {
              letter[i]--;
              total++;
              T(sum+i+1,i);
              letter[i]++;
           }
       }
    return;
}