#include<bits/stdc++.h>
using namespace std;
string s[32]
{
   "char","double","enum","float","int","long","short",
   "signed","struct","union","unsigned","void","for",
   "do","while","break","continue","if","else","goto",
   "switch","case","default","return","auto","extern",
   "register","static","const","sizeof","typedef","volatile"
};
bool check(string a)
{
    if(isdigit(a[0]))return false;

    for(int i=0;i<a.length();i++)
    if(!isalnum(a[i])&&a[i]!='_')return false;
    
    for(int i=0;i<32;i++)
        if(s[i]==a)return false;
    return true;

}
int main()
{
    string a;int n;
    cin>>n;cin.get();
    while(n--)
    {
        getline(cin,a);
        if(check(a))cout<<"yes\n";
        else cout<<"no\n";
    }
    cin.get();
    cin.get();
}