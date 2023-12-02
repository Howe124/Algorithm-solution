#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
//    string kaishi, jieshu, sw = "";
//    vector<int> kai(8), jie(8);
    int kaishi, jieshu, year1, year2, month1, month2, day1, day2, flag = 0;
    cin >> kaishi >> jieshu;
    year1 = kaishi / 10000000 % 10 * 1000 + kaishi / 1000000 % 10 * 100 + kaishi / 100000 % 10 * 10 +
            kaishi / 10000 % 10;
    year2 = jieshu / 10000000 % 10 * 1000 + jieshu / 1000000 % 10 * 100 + jieshu / 100000 % 10 * 10 +
            jieshu / 10000 % 10;
    month1 = kaishi / 1000 % 10 * 10 + kaishi / 100 % 10;
    month2 = jieshu / 1000 % 10 * 10 + jieshu / 100 % 10;
    day1 = kaishi / 10 % 10 * 10 + kaishi % 10;
    day2 = jieshu / 10 % 10 * 10 + jieshu % 10;
//    cout << year1 << month1 << day1 << endl;
//    cout << year2 << month2 << day2;

//    cin >> kaishi >> jieshu;
//    for (int i = 0; i < 8; ++i) {
//        sw[0] = kaishi[i];
//        kai[i] = stoi(sw);
//    }
//    for (int i = 0; i < 8; ++i) {
//        sw[0] = jieshu[i];
////        jie[i] = stoi(sw);
////    }
//    year1 = kai[0] * 1000 + kai[1] * 100 + kai[2] * 10 + kai[3];
//    year2 = jie[0] * 1000 + jie[1] * 100 + jie[2] * 10 + jie[3];


    for (int i = year1; i <= year2; ++i) {
        for (int j = 1; j <= 12; ++j) {
            for (int k = 1; k <= 31; ++k) {
                if (i == year1 && (j <= month1 && k < day1)) break;
                if (i == year2 && (j >= month2 && k > day2)) break;
                int key = 0;
                if (k == 31 && (j == 4 || j == 6 || j == 9 || j == 11)) break;    //判断大小月份
                if (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0)) {   //满足闰年要求
                    if (j == 2 && k >= 30) break;                   //为2月29号以上就跳出
                } else { if (j == 2 && k >= 29) break; }              //为2月30号以上就跳出
                key = (k % 10 * 1000) + (k / 10 % 10 * 100) + (j % 10 * 10) + (j / 10 % 10);
                if (key == i) flag++;
            }
        }
    }
    cout << flag;
    return 0;
}