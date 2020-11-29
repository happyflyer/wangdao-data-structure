#include <stdio.h>
#include <stdlib.h>
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

// 初始化一个空的单链表，不带头结点
bool InitList(LinkList &L)
{
    L = NULL;
    return true;
}

// 判断单链表是否为空
bool Empty(LinkList L)
{
    return L == NULL;
}

bool InsertNextNode(LNode *p, int e);

// 在第 i 个位置插入元素 e，不带头结点
bool ListInsert(LinkList &L, int i, int e)
{
    // i 的值必须是合法的位序
    if (i < 1)
    {
        return false;
    }
    // 插入第 1 个结点的操作与其他结点的操作不同
    if (i == 1)
    {
        LNode *s = (LNode *)malloc(sizeof(LNode));
        s->data = e;
        s->next = L;
        L = s;
        return true;
    }
    LNode *p;
    int j = 1;                     // 当前 p 指向的是第几个结点
    p = L;                         // 指向第 0 个结点
    while (p != NULL && j < i - 1) // 循环找到第 i-1 个结点
    {
        p = p->next;
        j++;
    }
    // if (p == NULL)
    // {
    //     return false;
    // }
    // LNode *s = (LNode *)malloc(sizeof(LNode));
    // s->data = e;
    // s->next = p->next;
    // p->next = s;
    // return true;
    InsertNextNode(p, e);
}

// 后插操作：在结点 p 后插入元素 e
bool InsertNextNode(LNode *p, int e)
{
    if (p == NULL)
    {
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL) // 内存分配失败，可写可不写
    {
        return false;
    }
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

// 前插操作：在结点 p 前插入元素 e
bool InsertPriorNode(LNode *p, int e)
{
    if (p == NULL)
    {
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->next = p->next;
    p->next = s;
    s->data = p->data;
    p->data = e;
    return true;
}

// 前插操作：在结点 p 前插入结点 s
bool InsertPriorNode(LNode *p, LNode *s)
{
    if (p == NULL || s == NULL)
    {
        return false;
    }
    s->next = p->next;
    p->next = s;
    int temp = s->data;
    s->data = p->data;
    p->data = temp;
    return true;
}

int main()
{
    LinkList L;
    InitList(L);
    ListInsert(L, 1, 1);
    ListInsert(L, 2, 2);
    ListInsert(L, 3, 3);
    ListInsert(L, 4, 4);
    ListInsert(L, 5, 5);
    ListInsert(L, 3, 100);
    // 打印操作
    LNode *p = L;
    while (p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
    return 0;
}
