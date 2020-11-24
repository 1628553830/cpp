#include<iostream>
using namespace std;
int main()
{
    int N;
    string M;
    cin>>N;
    while(N--)
    {
        cin>>M;
        cout<<"6"+M.substr(6)<<endl;
    } 
    cin.get();
    cin.get();
}