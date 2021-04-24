#include<bits/stdc++.h>
#include<iostream>
#include<set>
#define ll long long
using namespace std;
int main(){
   ll t;
   cin >>t;
   ll num=0;
   map<string , int> a;
   while(t--){
    string s;
    cin >>s;
    sort(s.begin(),s.end());//使它按字典序顺序来排（好判断是否一样）
    num +=a[s]++;//首先为什么是ans+=，因为本体要找的是每个字谜有多少个与其一样的字谜，所以ans+=存的是当前字谜之前的配完对的字谜数量，也就是说把n对一样的字谜中n-1相同字谜的数量存了里面。a[s]++的后增就是因为又有一个字谜与之匹配。
   }
   cout<<num<<endl;
     return 0;
}

