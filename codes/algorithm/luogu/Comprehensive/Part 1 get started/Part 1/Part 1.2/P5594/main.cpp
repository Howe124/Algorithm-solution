#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n, m, k;    //分别代表:①有几个人,②有多少天是有空的(有多少天有空就有多少道题),③总共有多少天的时间
    set<int> total; //通过一个set储存列数(第几列就代表是这个人做的第几套题目),set会自动去重,所以size一下就知道有几套题目了
    cin >> n >> m >> k;
    vector<vector<int>> youkong(n, vector<int>(m)); //外层代表一个人,内层代表此人有空闲的是哪几天
    for (int i = 0; i < n; ++i) {           //将数传入
        for (int j = 0; j < m; ++j) {
            cin >> youkong[i][j];
        }
    }
    for (int i = 0; i < k; ++i) {   //有多少天就打印多少次
        total.clear();              //清空set重新计数
        for (int j = 0; j < n; ++j) {   //行遍历
            for (int l = 0; l < m; ++l) {   //列遍历
                if (youkong[j][l] == i + 1) {   //如果此时youkong其中的数等于天数,就证明这一天教练要准备题目了,要做题
                    total.insert(l);            //l第几列就是第几套题目,把列数传入
                }
            }
        }
        cout << total.size() << " ";            //打印出里面有几个数据,即教练需要准备几种不同的题目
    }
    return 0;
}