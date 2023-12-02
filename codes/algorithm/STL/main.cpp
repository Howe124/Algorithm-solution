//c语言头文件
//#include <stdio.h>
//#include <stdlib.h>

#pragma GCC optimize(2) //开启o2优化
//c++头文件
#include <iostream>     //输出输出流
#include <cstdlib>      //动态分配内存
#include <algorithm>    //算法
#include <iterator>     //迭代器
#include <vector>       //动态数组
#include <stack>        //栈
#include <queue>        //队列
#include <set>          //集合
#include <map>          //映射
#include <string>       //字符串
#include <utility>      //此乃二元组的头文件
#include <list>
#include <deque>
//#include <bits/stdc++.h>



using namespace std;    //告诉编译器要使用命名空间std，即：{std::cout << " " << std::endl;} 中的std::可以省略掉

void vector_text() {

    vector<int> vec = {1, 2, 3, 4};
    cout << vec.front() << endl;    //头元素
    cout << vec.back() << endl;     //尾元素

    vector<int> vec1 = vec;
    vector<int> vec11(1e1, 3);  //长度为10的1次方，初值为3，数据很大的时候要提前声明大小，节省很多时间

    cout << "------------------------------------------------------------------------------------------------" << endl;
    vector<int> vec111;
    vec111.push_back(8);    //尾插
    vec111.push_back(7);

    vec111.pop_back();      //尾删
    vec111.clear(); //清空数组操作
    vec111.resize(5);   //重新定义数组长度和初值(初值不写默认0)
    cout << vec111.empty() << endl;

    for (auto &ele : vec111) {  //打印数组中元素
        cout << ele << "  ";
    }
    cout << endl;

    cout << "------------------------------------------------------------------------------------------------" << endl;
    cout << vec[1] << endl;
    vec[1] = 3;
    cout << vec[1] << endl;

}

void stack_text() {
    stack<int> stk;
    stk.push(3);
    stk.push(2);
    stk.push(1);
    cout << stk.top() << endl;  //访问栈顶元素
    stk.pop();                  //删除栈顶元素
    cout << stk.top() << endl;  //访问栈顶元素
    cout << stk.size() << endl;

}

void queue_text() {
    queue<int> que;
    que.push(4);
    que.push(5);
    que.push(6);
    cout << que.front() << endl;
    cout << que.back() << endl;
    cout << "------------------------------------------------------------------------------------------------" << endl;
    que.pop();
    cout << que.front() << endl;
    cout << que.back() << endl;
    cout << "------------------------------------------------------------------------------------------------" << endl;
    cout << que.size() << endl;
    cout << que.empty() << endl;

}

void priority_queue_text() {     //   堆,
    priority_queue<int> pque;   //大顶堆，最大的数在堆顶
    pque.push(3);
    pque.push(2);
    pque.push(4);
    pque.push(1);
    cout << pque.top() << endl; //top为堆顶，是最大的元素
    pque.pop();                 //删除的也是堆顶
    cout << pque.top() << endl;
    cout << "------------------------------------------------------------------------------------------------" << endl;
    priority_queue<int, vector<int>, greater<int>> pquee;   //小顶堆，最小的数在堆顶
    pquee.push(3);
    pquee.push(2);
    pquee.push(4);
    pquee.push(1);
    cout << pquee.top() << endl; //top为堆顶，是最小的元素
    pquee.pop();                 //删除的也是堆顶
    cout << pquee.top() << endl;
}

void set_text() {    //集合：内部的数有序且不可重复
    set<int> se;
    se.insert(6);   //插入元素
    se.insert(3);
    se.insert(6);
    se.insert(4);
    //第一种遍历
    for (auto &ele : se) {
        cout << ele << " ";
    }
    cout << endl;
    cout << "------------------------------------------------------------------------------------------------" << endl;
    se.erase(4);    //删除元素
    //使用迭代器遍历
    for (set<int>::iterator it = se.begin(); it != se.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "------------------------------------------------------------------------------------------------" << endl;
    //查看集合内是否有该元素，第一种方法
    if (se.find(4) != se.end()) {   //.find()查看集合内是否有该元素，有的话返回指向4的迭代器，没有返回.end()的迭代器
        cout << "YES" << endl;
    } else cout << "NO" << endl;
    //查看集合内是否有该元素，第二种方法
    if (se.count(4)) {   //.count返回set集合内 4 的数量，set内，每个元素只能出现一次，所以.count()只有0和1
        cout << "YES" << endl;
    } else cout << "NO" << endl;
}

void map_text() {
    map<int, int> mp;
    mp[0] = 1;
    mp[5] = 7;
    mp[3] = 2;
    mp[9999] = 6666;
//用迭代器遍历map
    for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
    cout << "------------------------------------------------------------------------------------------------" << endl;
//第二种方法遍历map,基于C++11
    for (auto &ele : mp) {
        cout << ele.first << " " << ele.second << endl;
    }
    cout << "------------------------------------------------------------------------------------------------" << endl;
//擦除数据（擦除的是下标）
    mp.erase(0);
    for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
        cout << it->first << " " << it->second << endl;    //s:试试直接对it解引用？cout<<*it<<endl;
    }
    cout << "------------------------------------------------------------------------------------------------" << endl;

//.find();
    if (mp.find(9999) != mp.end()) {
        cout << "yes" << endl;
    } else { cout << "no" << endl; }
//.count查看下标在map中数量（因为有唯一性所以只有0/1）
    cout << mp.count(2) << endl;
}

void string_text() {
    string str = "strin";
    string str1(3, 'g');       //赋初值三位初始化为g
    cout << str + str1 << endl;        //字符串拼接打印
    str += str1;
    str[7] = 'b';
    cout << str << endl;
    cout << "------------------------------------------------------------------------------------------------" << endl;
//取子串.substr()
    cout << str.substr(0, 6) << endl;   //取下标为0的元素，向后一共取6位
    cout << "------------------------------------------------------------------------------------------------" << endl;
//查找字符串.find()
    cout << str.find("ggb") << endl;    //可以看见返回的值是下标;
    cout << "------------------------------------------------------------------------------------------------" << endl;
//string转成其他类型
    string st = "54321";
    int i = stoi(st);        //string to int
    cout << i << " ";
    long double lb = stold(st);//string
    cout << lb << " ";
    string s = to_string(lb);
    cout << s << " " << endl;
}

void pair_text() {
    pair<int, char> p = {1, 65};
    cout << p.first << " " << p.second << "\n";
    pair<double, pair<int, char>> pp = {1.0, p};
    cout << pp.first << " " << pp.second.first << " " << pp.second.second << "\n";
}

void deque_text() {
    deque<int> l = {5, 1, 3, 4};
    for (auto &ele : l) {
        cout << ele << " ";
    }
    cout << "\n";
    cout << "------------------------------------------------------------------------------------------------" << endl;

    l[1] = 3;
//    l.erase(l.begin()+2);
//    l.clear();
    cout << "是否为空:" << l.empty() << "\n";
    for (auto &ele : l) {
        cout << ele << " ";
    }
    cout << "\n";
}

int main() {
//    vector_text();
//    stack_text();
//    queue_text();
//    priority_queue_text();
//    set_text();
//    map_text();
//    string_text();
//    pair_text();
    deque_text();
//    system("pause");
    return 0;
}
