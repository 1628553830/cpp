/*
D - Diverse Team
There are n students in a school class, the rating of the i-th student on Codehorses is ai. You have to form a team consisting of k students (1≤k≤n) such that the ratings of all team members are distinct.
If it is impossible to form a suitable team, print "NO" (without quotes). Otherwise print "YES", and then print k distinct numbers which should be the indices of students in the team you form. If there are multiple answers, print any of them.
Input
The first line contains two integers n and k (1≤k≤n≤100) — the number of students and the size of the team you have to form.
The second line contains n integers a1,a2,…,an (1≤ai≤100), where ai is the rating of i-th student.
Output
If it is impossible to form a suitable team, print "NO" (without quotes). Otherwise print "YES", and then print k distinct integers from 1 to n which should be the indices of students in the team you form. All the ratings of the students in the team should be distinct. You may print the indices in any order. If there are multiple answers, print any of them.
Assume that the students are numbered from 1 to n.
Examples
Input
5 3
15 13 15 15 12
Output
YES
1 2 5 
Input
5 4
15 13 15 15 12
Output
NO
Input
4 4
20 10 40 30
Output
YES
1 2 3 4 
Note
All possible answers for the first example:
{1 2 5}
{2 3 5}
{2 4 5}
Note that the order does not matter.
*/
#include<iostream>
using namespace std;
int main()
{
   short st_num,gm,gm2,score[100];bool used[101]{};
   cin>>st_num>>gm;
   gm2=gm;
   for(int i=0;i<st_num;i++)
   {cin>>score[i];if(!used[score[i]])gm=gm?gm-1:0;used[score[i]]=true;}
   if(!gm)
   {
     cout<<"YES"<<endl;
     for(int i=0;i<st_num&&gm2;i++)if(used[score[i]]){cout<<i+1<<" ";used[score[i]]=false;gm2--;}
   }
   else cout<<"NO";
   cin.get();
   cin.get();
}