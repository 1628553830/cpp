#include<iostream>
using namespace std;
int main()
{
      char flower[]="rose";
      char *pd,**ps;
      pd=flower;
      ps=&pd;
      cout<<ps[0]<<" is a kind of flower\n";
      cin.get();

}