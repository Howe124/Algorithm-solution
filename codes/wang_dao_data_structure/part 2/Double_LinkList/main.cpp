#include "Double_LinkList.h"

/*链表用的动态内存分配malloc，因此删除操作需要free掉空间
如果需要删除/插入的结点是最后一个结点，需要加判断做特殊处理（就无需修改后继结点的prior指针）*/

int main() {
    DLinkList l;
    Create_DLinklist(l);
    Empty(l);
    PrintList(l);
    DestroyList(l);
    PrintList(l);
    return 0;
}

//初始化双链表：
DNode InitializeDLinkList(DLinkList &l) {
    l = (DNode *) malloc(sizeof(DNode));
    l->prior = NULL;
    l->next = NULL;
}

//创建双链表
DLinkList Create_DLinklist(DLinkList &l) {
    l = (DNode *) malloc(sizeof(DNode));
    l->prior = NULL;
    DNode *p = l;
    int x;
    scanf("%d", &x);
    while (x != 9999) {
        p->next = (DNode *) malloc(sizeof(DNode));
        p->next->prior = p;
        p->next->data = x;
        p = p->next;
        scanf("%d", &x);
    }
    p->next = NULL;
    return l;
}

//判空操作：
bool Empty(DLinkList l) {
    if (l->next == NULL) {
        printf("表为空\n");
        return true;
    }
    printf("表不为空\n");
    return false;
}

//插入操作：
bool InsertDNode(DNode *p, DNode *n) {
    if (p == NULL || n == NULL)
        return false;
    if (p->next != NULL)    //如果p有后继结点，才更改后继节点的prior
        p->next->prior = n;
    n->next = p->next;
    p->next = n;
    n->prior = p;
    return true;
}

//删除操作：删除形参结点的后继结点
bool DelDNode(DNode *l) {
    if (l == NULL || l->next == NULL)
        return false;
    DNode *del = l->next;
    if (del->next != NULL)
        del->next->prior = l;
    l->next = del->next;
    free(del);
    return true;
}

//销毁双链表
void DestroyList(DLinkList &l) {
    DNode *del = l;
    while (l != NULL) {
        del = l;
        l = l->next;
        free(del);
    }
}

//遍历双链表
void PrintList(DLinkList l) {
    while (l->next != NULL) {
        l = l->next;
        printf("%-5d", l->data);
    }
    printf("\n");
}

//按位查找

//按值查找