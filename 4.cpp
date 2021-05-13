#include<iostream>
#include<cmath>
using namespace std;
string nums;
int main()
{
      nums="0000000000000000";
      int position;
      int jinwei;
      freopen("1.txt","w",stdout);
      for(int i=0;i<pow(2,16);i++)
      {
            position=0;
            while(nums[position]=='0'&&position<15)position++;
            for(int j=position;j>=0;j--)
            cout<<"#define B"<<nums.substr(j)<<" "<<i<<endl;
            for(int j=15;j>=0;j--)
            {
                jinwei=0;
                if(nums[j]=='1')jinwei=1;
                nums[j]='1'-nums[j]+'0';
                if(!jinwei)break;
            }
      }
      fclose(stdout);
}