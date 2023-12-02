#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int key = 0, flag = 0;
    string s, ss;           //
    vector<int> num(9);  //用来存前9位数字,需要吧string转成int类型,不然没法做算数的运算
    cin >> s;
    for (int i = 0; i < 11; ++i) {
        if (s[i] == '-') continue; //用于跳过 "-" 符号
        flag++;                         //计数1-9
        ss[0] = s[i];                   //将s中的数存到ss中转一下,下一句转成int类型
        num[flag - 1] = stoi(ss);       //ss的一位数字,用类型转换函数转成int类型存到num
        key += num[flag - 1] * flag;    //题目的算数运算,但是需要转成int类型,切不可直接用string里的数字做运算 ! !
    }

    //查看最后一位识别码是否正确,
    key = key % 11;

    if (s[12] == 'X') {
        if (key == 10) cout << "Right";
        if (key != 10) {
            s.erase(12);
            cout << s << key;
        }
    }
    if (s[12] != 'X') {
        ss[0] = s[12];
        int comp = stoi(ss);
        if (key == comp) cout << "Right";
        if (key != comp) {
            s.erase(12);
            cout << s;
            if (key == 10) cout << "X";
            if (key != 10) cout << key;
        }
    }
    return 0;
}