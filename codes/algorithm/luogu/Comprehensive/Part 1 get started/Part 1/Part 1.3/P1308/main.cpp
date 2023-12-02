#include <iostream>
#include <string>
using namespace std;
int pos, flag = 0;  //记录位置和匹配到的次数
string s, comp;     //存放输入
int main() {
    getline(cin, comp);
    getline(cin, s);
    s += ' ';       //方便匹配
    for (int i = 0; i < comp.size(); ++i) {
        comp[i] = tolower(comp[i]);//全部转成小写
    }
    for (int i = 0; i < s.size()-1; ++i) {
        s[i] = tolower(s[i]);               //全部转成小写
    }
    for (int i = 0; i < s.size() - 1; ++i) {
        int key = i;
        //两组字符串的首位匹配成功,才开始后续的匹配,但是s的前一位要为空格才是为首位,又但是: s[0] 前面没有空格,所以为第一位时让它短路
        if (i == 0 || comp[0] == s[key] && s[key - 1] == ' ') {
            if (comp.size() == 1 && s[key + 1] == ' ') {    //搜索的只有一位的情况,如果只有comp只有一位,且s下一位为空,则匹配成功
                flag++;                     //记录匹配成功数量
                if (flag == 1) pos = i;     //记录首次匹配成功的位置
                continue;
            }
            bool biao = false;               //用于标记是否匹配成功
            for (int j = 1; j < comp.size(); ++j) { //从comp的第二位开始匹配
                key++;                              //s也从第二位开始匹配
                if (comp[j] != s[key]) {            //如果匹配不成功则跳出循环,匹配失败
                    break;
                }
                if (j == comp.size() - 1) biao = true;      //如果j为最后一位,则证明匹配成功
            }
            if (s[key + 1] == ' ' && biao == true) {   //biao判断是否匹配成功,还需判断s下一位是否为空格,才为完全匹配成功,
                flag++;                 //记录匹配成功数量
                if (flag == 1) pos = i; //记录首次匹配成功的位置
            }
        }
    }
    if (flag){
        cout << flag << ' ' << pos;
    } else cout << "-1";
    return 0;
}