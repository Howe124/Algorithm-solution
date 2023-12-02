#include <stdio.h>
#include <stdlib.h>

#define Maxsize 10
typedef int ElemType;

typedef struct {
    ElemType *data;
    int Max;
    int length;
} SqList;

//为动态数分配空间
void Initialise(SqList &l) {
    l.data = (ElemType *) malloc(Maxsize * sizeof(ElemType));
    l.Max = Maxsize;
    l.length = 0;
}

//为动态数组增加空间
void IncreaseList(SqList &l, ElemType size) {
    ElemType *p = l.data;
    l.data = (ElemType *) malloc((l.Max + size) * sizeof(ElemType));
    for (int i = 0; i < l.length; ++i) {
        l.data[i] = p[i];
    }
    l.Max += size;
    free(p);
}

//遍历数组
void PrintList(SqList l) {
    for (int i = 0; i < l.length; ++i) {
        printf("%d\t", l.data[i]);
    }
    printf("\n");
}

//数组插入元素,判断插入位置是否合法，判断是否表是否已满，从表尾开始向后移动元素，最后插入指定位置
bool InsertList(SqList &l, int position, ElemType element) {
    if (position < 1 || position > l.length + 1 || l.length == l.Max) {
        return false;
    }
    for (int i = l.length; i >= position; --i) {
        l.data[i] = l.data[i - 1];
    }
    l.data[position - 1] = element;
    l.length++;
    return true;
}

//数组删除元素,判断删除位置是否合法，保存被删除元素，向前前移覆盖
bool DelList(SqList &l, int position, ElemType &del) {
    if (position < 1 || position > l.length)
        return false;
    del = l.data[position - 1];
    for (int i = position; i < l.length; ++i) {
        l.data[i - 1] = l.data[i];
    }
    l.length--;
    return true;
}

//按位查找
ElemType GetElement(SqList l, int position) {
    if (position < 1 || position > l.length)
        return 0;
    return l.data[position - 1];
}

//按值查找
ElemType LocateElement(SqList l, ElemType key) {
    for (int i = 0; i < l.length; ++i) {
        if (l.data[i] == key) {
            return i + 1;
        }
    }
    return 0;
}

int main() {
    ElemType ele = 0;
//    bool ret;
    SqList l;
    Initialise(l);
    printf("数组最大空间=%d\n", l.Max);
    InsertList(l, 1, 20);
    InsertList(l, 1, 1);
    InsertList(l, 3, 50);
    InsertList(l, 3, 60);
    PrintList(l);
    IncreaseList(l, 5);
    printf("数组最大空间=%d\n", l.Max);
    DelList(l, 1, ele);
    PrintList(l);
    printf("%d\n", GetElement(l, 3));
    printf("%d\n", LocateElement(l, 50));
    return 0;
}
