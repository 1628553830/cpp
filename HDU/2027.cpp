#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n=0,letter[5]{};
   string a;
   cin>>n;
   cin.get();
   while(n--)
   {
      getline(cin,a);
      for(int i=0;i<a.length();i++)
      switch (a[i])
      {
      case 'a':
          letter[0]++;
          break;
      case 'e':
          letter[1]++;
          break;
      case 'i':
          letter[2]++;
          break;
      case 'o':
          letter[3]++;
          break;
      case 'u':
          letter[4]++;
          break;
      }
      cout<<"a:"<<letter[0]<<endl;
      cout<<"e:"<<letter[1]<<endl;
      cout<<"i:"<<letter[2]<<endl;
      cout<<"o:"<<letter[3]<<endl;
      cout<<"u:"<<letter[4]<<endl;
      memset(letter,0,sizeof(letter));
      if(n)cout<<endl;
   }
   cin.get();
}