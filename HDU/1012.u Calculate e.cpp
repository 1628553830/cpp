#include<iostream>
using namespace std;
int main()
{
    double e=1,sum=1;
    cout.precision(9);
    cout<<"n e\n"
          "- -----------\n"
          "0 1\n"
          "1 2\n"
          "2 2.5\n";
    for(int i=1;i<=9;i++)
    {
        sum*=i;
        e+=1/sum;
        if(i>=3)
        cout<<i<<" "<<fixed<<e<<endl;
    }
    cin.get();
    cin.get();
    return 0;
}