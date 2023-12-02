#include <iostream>
#include <stack>

using namespace std;

int main() {
    int a;
    stack<int> stk;
    while (true) {
        cin >> a;
        if (a == 0) break;
        stk.push(a);
    }
    while (stk.empty() != 1) {
        cout << stk.top() << " ";
        stk.pop();
    }
    return 0;
}