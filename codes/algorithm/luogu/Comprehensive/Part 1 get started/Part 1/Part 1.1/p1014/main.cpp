#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int n, m, i;
    cin >> n;
    m = n;
    string str = "0";
    if (n < 0) m *= -1;
    while (m != 0) {
        str += to_string(m % 10); //需要用函数转成string类型
        m /= 10;
    }
    if (n < 0) cout << "-";
    cout << stoi(str);
}
