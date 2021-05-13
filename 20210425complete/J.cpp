#include<iostream>
using namespace std;
int main()
{
    int n,max=-1,count=0,temp;
    int nums[100000];
    cin>>n;
    scanf("%d",&nums[0]);
    for(int i=1;i<n;i++)
    {
        scanf("%d",&nums[i]);
        if(nums[i]<=nums[i-1])
          {
              count++; 
          }
        else
          {
             max=max<count?count:max;
             count=0;
          }
    }
    max=max<count?count:max;
    /*for(int i=0;i<n-1;)
    {
        int j;
        count=0;
        temp=nums[i];
        for(j=i+1;j<n&&nums[j]<=temp;j++)
        {
                count++;
                temp=nums[j];
        }
        max=max<count?count:max;
        i=j;
    }*/
    cout<<max<<endl;
    cin.get();
    cin.get();
}
