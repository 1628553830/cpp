#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    double length[201][201]{};
    int N,x1,y1,x2,y2;
    cout.precision(3);
    for(int i=2;i<=201;i++)
    {
        length[0][i-1]+=length[i-2][0]+sqrt((i-2)*(i-2)+(i-1)*(i-1));
       for(int j=1;j<i;j++)
       {
        length[j][i-1-j]+=length[j-1][i-j]+sqrt(2);
       }
    }
    cin>>N;
    while(N--)
    {
        cin>>x1>>y1>>x2>>y2;
        cout<<fixed<<abs(length[x1][y1]-length[x2][y2])<<endl;
    }
    cin.get();
    cin.get();
}