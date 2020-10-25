#include<bits/stdc++.h>
int main()
{
   long n;int ans=1;
   scanf("%ld",&n);
   for(int i=2;i<=sqrt(n);)
   {
     if(n%i==0){ans++;n/=i;}
     else i++;
   }
   if(ans%2)printf("Nancy\n");
   else printf("Johnson\n");
   system("pause");
}