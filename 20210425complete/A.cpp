#include<iostream>
using namespace std;    
const int maxn =2e5;    
int test1=11,result1=11,test2=1,result2=1,n,count=0;    
bool flag=true;
struct T
{
     char c;
     int x;
}operation[maxn];
bool  used[maxn]{};
int   mem[5];
void  dfs(int,int,int);
int main()
{
    cin>>n;
    cin.get();
    for(int i=0;i<n;i++)
    {
        //scanf("%c",&operation[i].c);
        //scanf("%d",&operation[i].x);
        cin>>operation[i].c>>operation[i].x;
        switch (operation[i].c)
        {
        case '&':result1 &= operation[i].x;
                 result2 &= operation[i].x;
        break;
        case '|':result1 |= operation[i].x;
                 result2 |= operation[i].x;
        break;
        case '^':result1 ^= operation[i].x;
                 result2 ^= operation[i].x;
        break;
        }
    }
    dfs(test1,test2,1);
    //if(result1==test1&&result2==test2)
       //count=0;
    cout<<count<<endl;
    for(int i=0;i<count;i++)
    {
        cout<<operation[mem[i]].c<<" "<<operation[mem[i]].x<<endl;
    }
    cin.get();
    cin.get();
}
void  dfs(int present1,int present2,int step)
{  
    int temp1,temp2;
    for(int i=0;i<n&&flag;i++)
    {
         if(!used[i])
         {
             used[i]=1;
             temp1=present1;
             temp2=present2;
             switch (operation[i].c)
             {
                case '&':present1 &= operation[i].x;
                         present2 &= operation[i].x;
                break;
                case '|':present1 |= operation[i].x;
                         present2 |= operation[i].x;
                break;
                case '^':present1 ^= operation[i].x;
                         present2 ^= operation[i].x;
                break;
             } 
             
             if(present1==result1||present2==result2)
             {
                  flag=false;
                  count=step;
             }
             else if(step<5)
             {
                 dfs(present1,present2,step+1);
             }
             if(!flag)
             {
                 mem[step-1]=i;
             }
             used[i]=0;
             present1=temp1;
             present2=temp2;
         }
    }
}