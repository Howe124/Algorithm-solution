#include <iostream>
#include <vector>
#include <algorithm>

long int n, total;  //分别题中给出的正整数个数,和符合题目要求的正整数个数
using namespace std;

int main() {
    cin >> n;
    vector<int> num(n); //用于存放正整数
    vector<bool> flag(n, true); //用于标记这个数是否已经出现过,去重
    for (int i = 0; i < n; ++i) {   //写入正整数
        cin >> num[i];
    }
    sort(num.begin(), num.end());   //将传入的数进行排序
    for (int i = 0; i < n; ++i) {   //开始枚举
        for (int j = 0; j < i; ++j) {
            for (int k = 0; k < n; ++k) {
                if (num[i] + num[j] < num[k]) break; //如果小于num[k]则后面的也不符合,所以跳过
                if (num[i] + num[j] == num[k]){ //判断到符合题意的数
                    if(flag[k]){                //判断此数是否已经标记过
                        flag[k] = false;        //没标记过则标记上,后续此数不可再用
                        total++;                //符合题目要求的正整数个数加1
                    }
                }
            }
        }
    }
    cout << total;
    return 0;
}