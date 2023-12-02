#include <iostream>

using namespace std;

int main() {
    int ap[10], h, flag = 0;
    for (int i = 0; i < 10; ++i) {
        cin >> ap[i];
    }
    cin >> h;
    for (int i = 0; i < sizeof(ap) / sizeof(ap[0]); ++i) {
        if (h + 30 >= ap[i]) {
            flag++;
        }
    }
    cout << flag;
    return 0;
}