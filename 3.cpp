#include<iostream>
#include<stdlib.h>
#define uint unsigned int
#define uchar unsigned char 
using namespace std;
struct Time
{
   uchar month,date;
   uint year;
};
uint  calculateday(struct Time*a,struct Time*b)
{
      uchar i;
      uint result=0;
      struct Time tmp;
      if(a->year!=b->year)
      {
          tmp.year=b->year;
          tmp.month=12;
          tmp.date=31;
          result=calculateday(&tmp,b);
          tmp.year=a->year;
          tmp.month=1;
          tmp.date=1;
          result+=calculateday(a,&tmp);
      }
      else
      {
          for(i=b->month;i<a->month;i++)
          {
              switch (i)
              {
              case 1:
              case 3:
              case 5:
              case 7:
              case 8:
              case 10:
              case 12:result+=31;
                     break;
              case 2:result=b->year%4==0&&b->year%100!=0||b->year%400==0?result+29:result+28;
                     break;
              default:result+=30;
                     break;
              } 
         }
         result=result+a->date-b->date;
      }
      return result;
} 
int main()
{
     Time a,b;
     a.year=2021;
     a.month=1;
     a.date=25;
     b.year=2020;
     b.month=1;
     b.date=25;
     cout<<calculateday(&a,&b);
     system("pause");
}