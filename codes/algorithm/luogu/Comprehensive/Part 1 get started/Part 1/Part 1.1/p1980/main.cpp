#include <iostream>

using namespace std;

int main() {
    int n, x, num, key = 0;
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        num = i;
        while (num != 0) {
            if (num % 10 == x) {
                key++;
            }
                num /= 10;
            }
    }
    cout << key;
    return 0;
}