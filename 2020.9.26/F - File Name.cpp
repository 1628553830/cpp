/*
F - File Name
You can not just take the file and send it. When Polycarp trying to send a file in the social network "Codehorses", he encountered an unexpected problem. If the name of the file contains three or more "x" (lowercase Latin letters "x") in a row, the system considers that the file content does not correspond to the social network topic. In this case, the file is not sent and an error message is displayed.
Determine the minimum number of characters to remove from the file name so after that the name does not contain "xxx" as a substring. Print 0 if the file name does not initially contain a forbidden substring "xxx".
You can delete characters in arbitrary positions (not necessarily consecutive). If you delete a character, then the length of a string is reduced by 1. For example, if you delete the character in the position 2 from the string "exxxii", then the resulting string is "exxii".
Input
The first line contains integer n (3≤n≤100) — the length of the file name.
The second line contains a string of length n consisting of lowercase Latin letters only — the file name.
Output
Print the minimum number of characters to remove from the file name so after that the name does not contain "xxx" as a substring. If initially the file name dost not contain a forbidden substring "xxx", print 0.
Examples
Input
6
xxxiii
Output
1
Input
5
xxoxx
Output
0
Input
10
xxxxxxxxxx
Output
8
Note
In the first example Polycarp tried to send a file with name contains number 33, 
written in Roman numerals. But he can not just send the file, 
because it name contains three letters "x" in a row. 
To send the file he needs to remove any one of this letters.
*/
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
   /*
   string s;int length,ans=0;
   cin>>length>>s;
   for(int i=1,pos;i<length;i++)
   {
      pos=i-1;
      while(s[i]=='x'&&s[i]==s[i-1]&&i<length){if(i-pos+1>2)ans++;i++;}
   }
   cout<<ans;
   cin.get();
   cin.get();
   */
   string s;int length,ans=0;
   cin>>length>>s;
   for(int i=0;i<length-1;i++)
   if(s[i]=='x')
   {
       int count=1;//要把第一个x算进去。
       while(s[i]==s[i+1]&&i<length-1){count++;i++;}
       ans=count>2?ans+count-2:ans;
   }
   cout<<ans;
   cin.get();
   cin.get();
}