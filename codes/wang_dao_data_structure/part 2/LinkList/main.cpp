#include "LinkList.h"

/*//初始化链表，l指针分配一个头结点的空间，将next=null，data不存数据
void InitializeList(LinkList &l) {
    l = (LNode *) malloc(sizeof(LNode));//此空间是头结点
    l->next = NULL;
 }*/

//尾插法创建一个单链表，给头指针创建一个头结点，通过一个指针指向表尾，不断地在表尾插入数据,正常思路
LinkList CreateLinkList_TailInsert(LinkList &l) {
    l = (LNode *) malloc(sizeof(LNode));    //创建头结点
    LNode *tail = l;    //用tail指向表尾
    int x;    //x存放即将存入链表的数据
    scanf("%d", &x);    //读入数据
    while (x != 999) {     //不断向链表输入数据，直到输入999退出
        tail->next = (LNode *) malloc(sizeof(LNode));   //表尾指向一个新开辟的空间
        tail = tail->next;  //tail继续指向表尾结点
        tail->data = x;     //保存数据
        scanf("%d", &x); //继续读入数据
    }
    tail->next = NULL;  //创表结束，尾结点next指向null
    return l;
}

//头插法创建一个单链表：给头指针创建一个头结点，在头结点一直进行后插操作，可用于链表的逆置
LinkList CreateLinkList_HeadInsert(LinkList &l) {
    l = (LNode *) malloc(sizeof(LNode));    //初始化，分配头结点
    l->next = NULL;     //初始化，分配头结点
    int x = 0;          //x存放即将存入链表的数据
    LNode *p;
    scanf("%d", &x);        //读入数据
    while (x != 9999) {     //不断向链表输入数据，直到输入9999退出
//        NextInsertNote(l, x);       //在头结点上用尾插法插入数据，即实现一直在表头输入
        p = (LNode *) malloc(sizeof(LNode));
        p->data = x;
        p->next = l->next;
        l->next = p;
        scanf("%d", &x);
    }
    return l;
}

//试试思路正常创表，试玩发现就是尾插法
LinkList Create_list(LinkList &l) {
    l = (LNode *) malloc(sizeof(LNode));
    LNode *p = l;
    int x;
    scanf("%d", &x);
    while (x != 9999) {
        p->next = (LNode *) malloc(sizeof(LNode));
        p = p->next;
        p->data = x;
        scanf("%d", &x);
    }
    p->next = NULL;
    return l;
}

/*创建一个新的结点，从头结点获取next，从需要倒置的结点获取data，再把头结点next连到新的结点上，然后还需要一个指针释放前驱的空间
链表逆置的实现：通过头插法创表的思路来实现，p一直指向头结点，原来需要倒置的表只有data有用，next信息已经无用了*/
LinkList linkList_Reverse(LinkList &l) {
    LinkList p = (LNode *) malloc(sizeof(LNode));   //用于指向头结点
    p->next = NULL;
    LNode *del;         //中转指针
    while (l->next != NULL) {
        del = (LNode *) malloc(sizeof(LNode));  //指定结点的后插操作，可用后插函数代替
        del->next = p->next;        //指定结点的后插操作
        p->next = del;              //指定结点的后插操作
        del->data = l->next->data;  //指定结点的后插操作
        del = l;                    //保存需要free的结点
        l = l->next;                //指向下一个结点
        free(del);                  //free掉原来的空间
    }
    l = p;
    return l;
}

//再次试试逆置
LinkList List_Reverse(LinkList &l) {
    LinkList p = (LNode *) malloc(sizeof(LNode));
    p->next = NULL;
    LinkList pp;
    while (l->next != NULL) {
        pp = l;
        l = l->next;
        free(pp);
        pp = (LNode *) malloc(sizeof(LNode));
        pp->next = p->next;
        p->next = pp;
        pp->data = l->data;
    }
    l = p;
    return l;
}

//链表判空操作
bool Empty(LinkList l) {
    if (l->next == NULL) {
        printf("表空\n");
        return true;
    }
    printf("表不为空\n");
    return false;
}

//遍历链表
void PrintList(LinkList l) {
    while (l->next) {
        l = l->next;
        printf("%-5d", l->data);
    }
    printf("\n");
}

//指定结点的后插操作：判断指定结点是否为null，不为null创建新的结点，存入数据，交换next
bool NextInsertNote(LNode *l, ElemType element) {
    if (l == NULL) return false;
    LNode *newnode = (LNode *) malloc(sizeof(LNode));
    newnode->data = element;
    newnode->next = l->next;
    l->next = newnode;
    return true;
}

//指定结点的前插操作：判断结点是否为空，不为空创建新的结点，交换两个结点的数据，然后进行后插操作，逻辑上完成了前插操作
bool FrontInsertNote(LNode *l, ElemType element) {
    if (l == NULL) return false;
    LNode *p = (LNode *) malloc(sizeof(LNode));
    p->data = l->data;
    l->data = element;
    p->next = l->next;
    l->next = p;
    return true;
}

/* 按位序插入结点：
判断位序是否小于1，循环找到位序的前一个指针（因为要通过位序前一个结点的next来插入结点），此时如果位序超出了链表范围，
 指针会指向null并退出，如果位序合法，会找到位序前一个指针创建一个新的结构体空间，通过交换next插入结点（交换顺序不能变）；
此函数不需要知道链表长度，只要判断到位序前面的结点为空，就证明插入插入的位序不合法，返回false       */
bool InsertNode(LinkList &l, int position, ElemType element) {
    if (position < 1) return false;
    LNode *p = GetLNode(l, position - 1); //定位结点的前驱
/*    LNode *p = l;   //l要用来指向头结点，因此需要一个新的指针来定位
    int pos = 0;    //用来记当前p指向了第几个结点

    while (p != NULL && pos < position - 1) {   //找到位序的前一个结点，并用p指向它
        p = p->next;
        pos++;
    }*/
    NextInsertNote(p, element);         //可以通过调用InsertNextList后插函数完成结点的插入，与后几行一样
/*    if (p == NULL) return false;      //判断是p=null退出了循环，还是找到了位序的前一个结点
    LNode *new_node = (LNode *) malloc(sizeof(LNode));     //创建需要插入的新结点
    new_node->data = element;   //新结点的数据赋值
    new_node->next = p->next;   //交换next
    p->next = new_node;
    return true;*/
}

//按位序删除结点,前面判断和操作都一样，最后删除的结点需要新增一个结点指针指向它，因为需要把那片不用的空间释放掉
bool DelPosNode(LinkList &l, int position, ElemType &element) {
    if (position < 1) return false;
    int pos = 0;
    LNode *p = l;
    while (p != NULL && pos < position - 1) {
        p = p->next;
        pos++;
    }
    if (p == NULL || p->next == NULL) return false;//比插入多了一个判断，判断需要删除的结点是否为null
    LNode *pp = p->next;    //令pp指向被删除的结点
    element = pp->data;     //返回被删除的数据
    p->next = pp->next;     //从链表中删除此节点
    free(pp);               //释放这片不用的空间
    return true;
}

//删除指定结点,后继结点的data和next向前节点覆盖，释放那个后继结点；如果删除的是链表中的最后一个元素，会有Bug无法执行
bool DelNode(LNode *&l, ElemType &element) {
    if (l == NULL) return false;
//    if(l->next==NULL) return false;
    LNode *p = l->next;
    l->data = p->data;
    l->next = p->next;
    free(p);
    return true;
}

//按位查找结点,
LNode *GetLNode(LinkList l, int position) {
    if (position < 0) return NULL;
    int pos = 0;
    LNode *p = l;
    while (p != NULL && pos < position) {
        p = p->next;
        pos++;
    }
    return p;
}

//按值查找结点
LNode *LocateElement(LinkList l, ElemType element) {
    LNode *p = l->next;
    while (p != NULL && p->data != element) {
        p = p->next;
    }
    return p;
}

//求表长
int length(LinkList l) {
    int len = 0;
    while (l->next != NULL) {
        len++;
        l = l->next;
    }
    return len;
}

/*考研真题：----------------------------------------------------------------------------------------------------------
    设线性表 L=(a1,a2,a3......an-2,an-1,an)采用带头结点的单链表保存，链表中的结点定义如下:
                                typedef struct node {
                                    int data;
                                    struct node* next;
                                }NODE;
    请设计一个空间复杂度为 O(1)且时间上尽可能高效的算法，重新排列L中的各结点，得到线性表 L'=(a1,an,a2,an-1,a3,an-2,......)要求如下：
    ①给出算法的基本设计思想根据设计思想。②采用c或C++语言描述算法，关键之处给出注释。③说明你所设计的算法的时间复杂度。*/
/*  1.题目解答：空间复杂度为O（1），说明不能创建新的空间，要在原有的空间修改链表，
    2.思路：通过双指针同步遍历的方法，找到中间的结点，将链表分割为两个部分L1 L2，再将L2链表进行逆置，最后进行链表的插入合并
    分三步实现               */
//①找到中间结点分割链表
bool find_middle(LinkList &l1, LinkList &l2) {
    if (l1 == NULL) return false;
    LNode *mid = l1->next;
    LNode *tail = l1->next;
    if (l1->next == NULL || l1->next->next == NULL) return false;      //结点为0和1个不符合题意不做考虑
    while (tail->next != NULL && tail->next->next != NULL) {
        tail = tail->next->next;
        mid = mid->next;
    }
    l2 = (LNode *) malloc(sizeof(LNode));
    l2->next = mid->next;
    mid->next = NULL;
    return true;
}

//②逆置链表
LinkList Reverse(LinkList &l2) {
    LNode *r, *s, *t;
    if (l2->next == NULL || l2->next->next == NULL) return l2; //空表或只有1位结点不需要逆置
    r = l2->next;       //定位第1个结点
    s = r->next;        //定位第2个结点
    t = s->next;        //定位第3个结点
    r->next = NULL;     //倒置后第一个结点为表尾，next插入null
    while (t != NULL) { //t指向null循环结束
        s->next = r;    //后驱结点指向前驱结点
        r = s;
        s = t;
        t = t->next;
    }
    s->next = r;        //最后还需要链接一次前驱
    l2->next = s;
    return l2;
}

//③交叉合并
LinkList merge(LinkList &l1, LinkList &l2) {
    if (l1->next == NULL || l2->next == NULL) return l1;   //只有一位数会分割在l1，所以两种情况 1.一位数据在l1；2.都没有数据，返回空表
    LNode *r = l1->next, *s, *t = l2->next;//r s用于交换l1 l2数据，t用来定位l2，防止l2链表地址位置丢失
    while (t != NULL) {       //t=null证明没有元素需要合并了结束循环
        s = t;              //获取l2链表位置
        t = t->next;        //t指向后驱结点
        s->next = r->next;  //l2结点链接l1后继结点
        r->next = s;        //l1结点链接l2
        r = r->next->next;  //定位下一个l1结点，在此节点后面继续插入数据
    }
    return l1;
}

int main() {
    //基础操作：
//    bool ret;   //接受返回值
//    ElemType del;   //接受返回值
    LinkList l1; //创建头指针
    LinkList l2;
//    Empty(l1);
    printf("创建的表为：\n");
    CreateLinkList_TailInsert(l1);  //创建一个单链表
    PrintList(l1);
//    InsertNode(l1, 1, 20);
//    InsertNode(l1, 2, 30);
//    InsertNode(l1, 2, 455);
//    PrintList(l1);
//    LNode *p = l1->next->next;
//    DelNode(p, del);
//    PrintList(l1);
//    NextInsertNote(p, 33);
//    PrintList(l1);
//    FrontInsertNote(p, 22);
//    PrintList(l1);
//    DelPosNode(l1, 2, del);
//    PrintList(l1);
//    FrontInsertNote(LocateElement(l1, 33), 32);
//    PrintList(l1);
//    linkList_Reverse(l1);
////    List_Reverse(l1);
//    PrintList(l1);
//    Empty(l1);
//---------------------------------------------------------------------------------------------------------------------
    //真题实现的主函数
    find_middle(l1, l2);
    printf("分割上表\nl1：\n");
    PrintList(l1);
    printf("l2：\n");
    PrintList(l2);
    Reverse(l2);
    printf("倒置l2：\n");
    PrintList(l2);
    merge(l1, l2);
    printf("合并为：\n");
    PrintList(l1);
    return 0;
}