#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main() {
    int am,n;
    vector<int> num;
    cin >> am;
    for (int i = 0; i < am; ++i) {
        cin >> n;
        num.push_back(n);
    }
    for (int i = 0; i < am; ++i) {
        cout << num.back();
        num.pop_back();
    }
    return 0;
}
