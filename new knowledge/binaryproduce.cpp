#include<iostream>
#include<cmath>
using namespace std;
int main()
{
      string nums="000000000000000000000000";
      int position;
      int jinwei;
      int wei;
      int length=nums.length();
      cout<<"输入位数(最大24,最小1):";
      cin>>wei;            
      freopen("1.txt","w",stdout);
      for(int i=0;i<pow(2,wei);i++)
      {

            position=length-wei;
            while(nums[position]=='0'&&position<length)position++;
            for(int j=position;j>=length-wei;j--)
            cout<<"#define B"<<nums.substr(j)<<" "<<i<<endl;
            for(int j=length-1;j>=length-wei;j--)
            {
                jinwei=0;
                if(nums[j]=='1')jinwei=1;
                nums[j]='1'-nums[j]+'0';
                if(!jinwei)break;
            }
      }
      fclose(stdout);
      freopen("CON", "w", stdout);
      cout<<"complete!";      
      cin.get();
      cin.get();
}
