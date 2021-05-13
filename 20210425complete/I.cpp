#include<iostream>
using namespace std;
int main()
{
    int n,nums[100000];
    bool used[100000]{};
    bool flag=true;
    cin>>n;
    cin>>nums[0];
    for(int i=1;i<n;i++)
    {
        cin>>nums[i];
        if(nums[i-1]>=nums[i])
        {
            if(!used[i-1])
            {
                used[i-1]=1;
                nums[i-1]--;
            }
            used[i]=1;
        }
        else 
        {
            used[i]=1;
            nums[i]--;
        }
        if(nums[i-1]>nums[i])
        {
           flag=false;
           break;
        }
    }
    if(flag)
    {
        cout<<"Yes\n";
    }
    else
    {
        cout<<"No\n";
    }
    cin.get();
    cin.get();
}
