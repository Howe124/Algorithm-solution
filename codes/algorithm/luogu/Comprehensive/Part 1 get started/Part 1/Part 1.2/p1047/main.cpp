#include <iostream>
#include <vector>

using namespace std;


long int l, m, a, b, total;//分别是:马路长度,区域数目,区域起始,区域结束,树木总数

int main() {
    cin >> l >> m;
    vector<bool> road(l, true); //建造马路,长度为l,true代表树都还活着嘞
    for (int i = 0; i < m; ++i) {   //每个区域都遍历一次
        cin >> a >> b;              //从标准缓冲区读入区域的区间
        for (int j = a; j <= b; ++j) {  //移走区域中的树
            road[j] = false;
        }
    }
    for (int i = 0; i <= l; ++i) {  //数一下这条马路还有多少颗树
        if (road[i]) total++;
    }
    cout << total;
    return 0;
}
