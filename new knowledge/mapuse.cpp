#include<iostream>
#include<map>
using namespace std;
int main()
{  
    //映射的定义'<>'内要有两个类型，第一个为索引，即键值，第二个为其对应的值
    map<string,int>m;   
     
    //插入操作，map里面元素基本单元类型为pair
    m.insert(pair<string,int>("perple",2));

    //拷贝操作
    map<string,int>n(m);
    
    //检查是否为空,不为空则返回元素个数
    if(m.empty())cout<<"EMPTY!";
    else cout<<m.size();

    //交换两个容器
    m.swap(n);

    //返回键值即元素对应的值
    cout<<m["perple"];
    
    //清除所有元素，即重置
    m.clear();

    //删除pos迭代器所指的元素，返回下一个元素的迭代器
    m.erase("perple");
    m.erase(m.begin());//参数也可以是地址
  
    //删除[m.begin(),m.begin()++)的元素;这里元素的排序是按照键值来的
    m.erase(m.begin(),++m.begin());

    //查找和统计
    m.find("perple");//寻找是否存在perple这个元素，不存在则返回m.end();
    m.count("perple");//寻找键值为perple的元素个数，因为map容器元素互斥，即不允许重复键值，所以找到就是1，没有就是0
   
    //便历map
    map<string,int>::iterator it;
    for(it=m.begin();it!=m.end();it++)//it 的类型为指针
    cout<<(*it).first<<(*it).second;//pair类型用.first访问第一个元素.second访问第二个元素；

}