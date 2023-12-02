#include <iostream>

using namespace std;
int main(){
    long double ld = 1.0;//Sn:和
    int n = 1, k = 0;//n是分母,k接收输入的值
    cin >> k;
    while (true) {
        n++;
        ld = ld + 1.0 / n;
        if (ld > k) {
            break;
        }
    }
    cout << n;
    return 0;
}
