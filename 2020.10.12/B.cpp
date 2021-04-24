#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
    double x1,x2,y1,y2;
    while (cin>>x1>>y1>>x2>>y2)
    {
       printf("%.2f\n",sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));
    }
    cin.get();
    cin.get();
}