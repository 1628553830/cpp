#include<iostream>
#include<vector>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include <math.h>
#define line1 abs(0.2*sin(time))+0.1
#define line2 exp(-time)
#define M_PI       3.14159265358979323846   // pi
using namespace std;
const double speed_max = 25/3;
const int xi = 0.8*1e5;
const int yi = 1.11*1e5;
const double min_time = 0.13;
const double Min_step = 0.15195;
const double Max_step = 0.23550;
struct T
{
   double x,y;
   double dx,dy;
   double direction;
   double distance=0;
};
struct runinfo
{
   double power;
   double speed;
   bool   is_shake=false;
   double distance=0;
   double direction;
   double x,y;
   double time=0;
};
double Distance=0;
double stepdistance=0;
double totaltime=0;
int    stepcount=0;
vector<T>Data;//原始数据
vector<runinfo>runData;//跑步数据
void   Bigpoint_init();//初始化数据
double Bigpoint_powerfunctionline(double);//读取体力
double Bigpoint_getdirection(double,double);//计算方向
double Bigpoint_getrandomstep(double,double);//获取随机步幅
void   Bigpoint_solve();//处理数据
void   Bigpoint_output();//输出数据
void   Bigpoint_getrundirection(double,runinfo*);//获取跑步方向和坐标
void   Bigpoint_getrunposition(double,runinfo*);//获取跑步坐标
void   Bigpoint_stepmark(double);//标记步子
int    Bigpoint_doubletoint(double,int);//小数扩大为整数
int    main()
{
       Bigpoint_init();
       Bigpoint_solve();
}
void   Bigpoint_init()
{
    freopen("road.txt","r",stdin);
    double x,y;
    while(cin>>x>>y)
    {
         Data.push_back({x,y});
    }
    for(int i=1;i<Data.size();i++)
    {
         x=abs(Data[i].x-Data[i-1].x)*xi;
         y=abs(Data[i].y-Data[i-1].y)*yi;
         Distance += sqrt(x*x+y*y);
         Data[i-1].dx=Data[i].x-Data[i-1].x;
         Data[i-1].dy=Data[i].y-Data[i-1].y;
         Data[i].distance=Distance;
         Data[i-1].direction = Bigpoint_getdirection(Data[i-1].dx,Data[i-1].dy);
    }
    Data.back().dx=Data[Data.size()-2].dx;
    Data.back().dy=Data[Data.size()-2].dy;
    Data.back().direction = Data[Data.size()-2].direction;

}
double Bigpoint_powerfunctionline(double time)
{
       return max(line1,line2);
}
double Bigpoint_getdirection(double dx,double dy)
{
    double result = atan2(dy,dx);
    result = result*(180.0/M_PI);
    if(result<0)result += 360;
    result = 360 - result;
    result += 90;
    if(result >=360)result -=360;
    return result;
}
double Bigpoint_getrandomstep(double minstep,double maxstep)
{
       double result;
       int Mx=Bigpoint_doubletoint(maxstep,5);
       int Mn=Bigpoint_doubletoint(minstep,5);
       srand(time(0));
       result = rand()%((int)(Mx - Mn + 1)) + Mn;
       while(result>maxstep)
       {
           result/=10;
       }
       return result;
}
int    Bigpoint_doubletoint(double x,int num)
{  
       while(num--)
       {
           x*=10;
       }
       return x;
}
void   Bigpoint_getrundirection(double distance,runinfo* it)
{
     srand(time(0));
     double direction=0;
     for(int i=Data.size()-1;i>=0;i--)
     {
         direction = Data[i].direction;
         if(distance>=Data[i].distance)break;
     }
     it->direction = direction;
} 
void   Bigpoint_getrunposition(double distance,runinfo* it)
{
     double x=0,y=0;
     for(int i=Data.size()-1;i>=0;i--)
     {
         x = Data[i].x;
         y = Data[i].y;
         if(distance>=Data[i].distance)
         {
            it->x=x+(distance-Data[i].distance)*cos(atan2(Data[i].dy,Data[i].dx))/xi;
            it->y=y+(distance-Data[i].distance)*sin(atan2(Data[i].dy,Data[i].dx))/yi;
            break;
         }
     }
}
void   Bigpoint_stepmark(double distance)
{
       for(int i=runData.size()-1;i>0;i--)
       {
           if(runData[i].distance<=distance)
           {
               runData[i].is_shake = true;
               break;
           }
       }
}
void   Bigpoint_solve()
{
     //处理速度，体力，距离，方向，坐标
     runData.push_back({});
     runData.push_back({});
     for(int i=1;;i++)
     {
         runData[i].time = runData[i-1].time + min_time;
         runData[i].power = Bigpoint_powerfunctionline(runData[i].time);
         runData[i].speed = runData[i].power * 25 / 3;
         runData[i].distance = runData[i-1].distance + runData[i].speed * min_time;
         Bigpoint_getrundirection(runData[i].distance,&runData[i]);
         Bigpoint_getrunposition(runData[i].distance,&runData[i]);
         if(runData[i].distance>=Distance)
         break;
         runData.push_back({});
     }
     //处理步频
     double step;
     runData.erase(runData.begin());
     while(stepdistance<Distance)
     {
         step=Bigpoint_getrandomstep(Min_step,Max_step);
         stepdistance+=step;
         stepcount++;
         Bigpoint_stepmark(stepdistance);
     }
     totaltime = runData.back().time;
     Bigpoint_output();
}
void   Bigpoint_output()
{
     int temptime;
     freopen("solution.txt","w",stdout);
     freopen("CON", "r", stdin);
     for(int i=0;i<runData.size();i++)
     {
         printf("%.6lf|%.6lf|%0.lf|%.2lf|%.0lf|%d",runData[i].x,runData[i].y,runData[i].direction,runData[i].speed,runData[i].power*100,runData[i].is_shake);
         if(i!=runData.size()-1)cout<<endl;
     }

     freopen("CON", "w", stdout);
     //输出总距离
     cout<<"总距离:"<<(int)Distance<<"米\n";
     //输出总时间
     cout<<"总时间:"
         <<((int)totaltime/3600)/10<<((int)totaltime/3600)%10
         <<":"<<((int)totaltime%3600/60)/10<<((int)totaltime%3600/60)%10
         <<":"<<((int)totaltime%60)/10<<((int)totaltime%60)%10<<endl;
     //输出总步数
     cout<<"总步数:"
         <<stepcount<<endl;
     //输出平均配速
     temptime= 1000/ (Distance / totaltime);
     cout<<"平均配速:"
         <<((int)temptime%3600/60)<<"'"
         <<((int)temptime%60)/10<<((int)temptime%60)%10<<"''"<<endl;
    //输出平均步频
     cout<<"平均步频:"
         <<(int)(stepcount / totaltime * 60)<<endl;
    //输出平均速度
     cout.precision(2);
     cout<<"平均速度:"
         <<fixed<<Distance/totaltime<<endl;
     //system("pause");
     fclose(stdout);
     fclose(stdin);  
}

