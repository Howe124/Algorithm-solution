#include <stdio.h>

#define size 10
//静态数组
typedef struct {
    int data[size];
    int length;
} line;

//初始化静态数组
void csh(line &l) {
    for (int i = 0; i < size; i++) {
        l.data[i] = 0;
        l.length = 0;
    }
}

//静态数组插入数据
bool zeng(line &l, int wei, int key) {
    if (wei > 0 && wei <= l.length + 1 && wei < size + 1) {
        for (int i = l.length; i >= wei - 1; --i) {
            l.data[i] = l.data[i - 1];
        }
        l.data[wei - 1] = key;
        l.length++;
        return true;
    }
    printf("数据输入有误，请重新输入。\n");
    return false;
}

//静态数组按位删除元素
bool del(line &l, int wei,int &e) {
    e=l.data[wei-1];
    if (wei > 0 && wei <= l.length) {
        for (int i = wei; i < l.length; i++) {
            l.data[i - 1] = l.data[i];
        }
        l.length--;
            printf("删除的元素为: %d\n",e);
        return true;
    }
    printf("数据输入有误，请重新输入。\n");
    return false;
}

//遍历数组
void viewlist(line l) {
    for (int i = 0; i < l.length; ++i) {
        printf("%d\t", l.data[i]);
    }
    printf("\n");
}

int main() {
    line l;
    csh(l);
    zeng(l, 1, 3);
    zeng(l, 1, 1);
    zeng(l, 2, 2);
    zeng(l, 4, 4);
    zeng(l, 1, 5);
    zeng(l, 1, 5);
    viewlist(l);
    int e;
    del(l, 5,e);
    viewlist(l);
    return 0;
}


