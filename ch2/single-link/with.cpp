#include <stdio.h>
#include <stdlib.h>
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

// 初始化一个空的单链表，带头结点，头结点不存储数据
bool InitList(LinkList &L)
{
    // 分配一个头结点
    L = (LNode *)malloc(sizeof(LNode));
    if (L == NULL)
    {
        return false;
    }
    L->next = NULL;
    return true;
}

// 判断单链表是否为空
bool Empty(LinkList L)
{
    return L->next == NULL;
}

bool InsertNextNode(LNode *p, int e);
LNode *GetElem(LinkList L, int i);

// 在第 i 个位置插入元素 e，带头结点
bool ListInsert(LinkList &L, int i, int e)
{
    // i 的值必须是合法的位序
    if (i < 1)
    {
        return false;
    }
    // LNode *p;
    // int j = 0;                     // 当前 p 指向的是第几个结点
    // p = L;                         // 指向第 0 个结点
    // while (p != NULL && j < i - 1) // 循环找到第 i-1 个结点
    // {
    //     p = p->next;
    //     j++;
    // }
    LNode *p = GetElem(L, i - 1);
    // if (p == NULL)
    // {
    //     return false;
    // }
    // LNode *s = (LNode *)malloc(sizeof(LNode));
    // s->data = e;
    // s->next = p->next;
    // p->next = s;
    // return true;
    return InsertNextNode(p, e);
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

// 按位序删除结点，带头结点
bool ListDelete(LinkList &L, int i, int &e)
{
    // i 的值必须是合法的位序
    if (i < 1)
    {
        return false;
    }
    // LNode *p;
    // int j = 0;                     // 当前 p 指向的是第几个结点
    // p = L;                         // 指向第 0 个结点
    // while (p != NULL && j < i - 1) // 循环找到第 i-1 个结点
    // {
    //     p = p->next;
    //     j++;
    // }
    LNode *p = GetElem(L, i - 1);
    if (p == NULL) // i 值不合法
    {
        return false;
    }
    if (p->next == NULL) // 第 i-1 个结点后已无其他结点
    {
        return false;
    }
    LNode *q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);
    return true;
}

// 按位查找：返回第 i 个元素，带头结点，头结点看作是第 0 个结点
LNode *GetElem(LinkList L, int i)
{
    if (i < 0)
    {
        return NULL;
    }
    LNode *p;
    int j = 0;                 // 当前 p 指向的是第几个结点
    p = L;                     // 指向第 0 个结点
    while (p != NULL && j < i) // 循环找到第 i-1 个结点
    {
        p = p->next;
        j++;
    }
    return p;
}

// 按值查找，找到数据域 == e 的结点
LNode *LocateElem(LinkList L, int e)
{
    LNode *p = L->next;
    // 从第 1 个结点开始查找数据域为 e 的结点
    while (p != NULL && p->data != e)
    {
        p = p->next;
    }
    // 找到后返回该结点指针，否则返回 NULL
    return p;
}

// 求表的长度
int Length(LinkList L)
{
    int len = 0;
    LNode *p = L;
    while (p->next != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
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
    LNode *p;
    p = L->next;
    while (p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
    // 测试删除操作
    int e = -1;
    if (ListDelete(L, 5, e))
    {
        printf("已删除的元素值为=%d\n", e);
    }
    else
    {
        printf("位序不合法，删除失败\n");
    }
    // 打印操作
    p = L->next;
    while (p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
    // 测试按位查找
    printf("位序为4的结点为=%s\n", GetElem(L, 4));
    // 测试按值查找
    printf("元素值为4的结点=%s\n", LocateElem(L, 4));
    return 0;
}
