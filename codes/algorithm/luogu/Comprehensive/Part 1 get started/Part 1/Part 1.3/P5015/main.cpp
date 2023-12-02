#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    getline(cin, s);

    //1 95分
//    int len = s.size();
//    for (int i = 0; i < len; ++i) {
//        if (s[i] == ' ' || s[i] == '\n') {
//            len--;
//        }
//    }

    //2
    int len = 0;
    for (int i = 0; i < s.size(); ++i) {
        if(s[i]>='A'&&s[i]<='Z') {
            len++;
        }
        if(s[i]>='a'&&s[i]<='z') {
            len++;
        }
        if(s[i]>='0'&&s[i]<='9') {
            len++;
        }
    }

    cout << len;
    return 0;
}