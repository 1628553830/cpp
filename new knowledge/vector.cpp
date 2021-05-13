#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
     int nums[4];
     //vector<typename>arrayname,创建一个容器
     vector<double>a;
     //vector<typename>arrayname(element_num),创建一个初始状态能容纳element_num个元素的容器
     vector<double>b(2);
     //vector<typename>arrayname(element_num,num),创建一个初始状态能容纳element_num个元素,每个元素为num的容器
     vector<double>c(14,0);
     //vector<typename>arrayname(vector),创建一个与vector一样的容器
     vector<double>d(a); 
     //vector<typename>arrayname(nums,nums+4),复制nums数组部分数据到容器中
     vector<double>e(nums,nums+4);
     //arrayname.push_back(const T& x):向量尾部增加一个元素X
     a.push_back(1);
     //iterator insert(iterator it,const T& x):向量中迭代器指向元素前增加一个元素x
     a.insert(a.begin(),1);
     //iterator insert(iterator it,int n,const T& x):向量中迭代器指向元素前增加n个相同的元素x
     a.insert(a.begin(),10,1);
     //iterator insert(iterator it,const_iterator first,const_iterator last):向量中迭代器指向元素前插入另一个相同类型向量的[first,last)间的数据
     a.insert(a.begin(),b.begin(),b.end());
     //iterator erase(iterator it):删除向量中迭代器指向元素
     a.erase(a.begin());
     //iterator erase(iterator first,iterator last):删除向量中[first,last)中元素
     a.erase(a.begin(),a.end());
     //void pop_back():删除向量中最后一个元素
     a.pop_back();
     //void clear():清空向量中所有元素
     a.clear();
     //reference at(int pos):返回pos位置元素的引用
     a.at(1);
     //reference front():返回首元素的引用
     a.front();
     //reference back():返回尾元素的引用
     a.back();
     //iterator begin():返回向量头指针，指向第一个元素
     a.begin();
     //iterator end():返回向量尾指针，指向向量最后一个元素的下一个位置
     a.end();
     //reverse_iterator rbegin():反向迭代器，指向最后一个元素
     a.rbegin();
     //reverse_iterator rend():反向迭代器，指向第一个元素之前的位置
     a.rend();
     //bool empty() const:判断向量是否为空，若为空，则向量中无元素
     a.empty();
     //int size() const:返回向量中元素的个数
     a.size();
     //int capacity() const:返回当前向量所能容纳的最大元素值
     a.capacity();
     //int max_size() const:返回最大可允许的vector元素数量值
     a.max_size();
     //void swap(vector&):交换两个同类型向量的数据
     a.swap(b);
     //void assign(int n,const T& x):设置向量中前n个元素的值为x
     a.assign(12,1);
     //void assign(const_iterator first,const_iterator last):向量中[first,last)中元素设置成当前向量元素
     a.assign(b.begin(),b.end());
     //reserve 容器反转
     a.reserve(a.size());
     //algorithm reverse()方法容器反转
     reverse(a.begin(),a.end());
}