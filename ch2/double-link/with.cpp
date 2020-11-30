#include <stdio.h>
#include <stdlib.h>
typedef struct DNode
{
    int data;
    struct DNode *prior, *next;
} DNode, *DLinkList;

// 初始化一个双链表，带头结点
bool InitDLinkList(DLinkList &L)
{
    L = (DNode *)malloc(sizeof(DNode));
    if (L == NULL)
    {
        return false;
    }
    L->prior = NULL; // 头结点的 prior 永远指向 NULL
    L->next = NULL;
    return true;
}

// 判断双链表是否为空
bool Empty(DLinkList L)
{
    return L->next == NULL;
}

// 后插操作：在 p 结点之后插入 s 结点
bool InsertNextDNode(DNode *p, DNode *s)
{
    if (p == NULL || s == NULL)
    {
        return false;
    }
    s->next = p->next;
    if (p->next != NULL) // 如果 p 结点不是表尾结点
    {
        p->next->prior = s;
    }
    s->prior = p;
    p->next = s;
    return true;
}

// 删除操作：删除 p 结点的后继结点 q
bool DeleteNextDNode(DNode *p)
{
    if (p == NULL)
    {
        return false;
    }
    DNode *q = p->next;
    if (q == NULL) // p 结点没有后继结点
    {
        return false;
    }
    p->next = q->next;
    if (q->next != NULL) // q 结点不是表尾结点
    {
        q->next->prior = p;
    }
    free(q);
    return true;
}

// 销毁双链表
void DestroyList(DLinkList &L)
{
    while (L->next != NULL)
    {
        DeleteNextDNode(L);
    }
    free(L);  // 释放头结点
    L = NULL; // 头指针指向 NULL
}

// 创建一个双链表的结点
DNode *CreateDNode(int e)
{
    DNode *s = (DNode *)malloc(sizeof(DNode));
    s->data = e;
    return s;
}

// 获取一个指向双链表的表尾结点的指针
DNode *GetLastDNode(DLinkList L)
{
    DNode *p = L->next;
    while (p->next != NULL)
    {
        p = p->next;
    }
    return p;
}

int main()
{
    DLinkList L;
    InitDLinkList(L);
    // 测试插入操作
    InsertNextDNode(L, CreateDNode(1));
    InsertNextDNode(L, CreateDNode(2));
    InsertNextDNode(L, CreateDNode(3));
    InsertNextDNode(L, CreateDNode(4));
    InsertNextDNode(L, CreateDNode(5));
    // 打印操作
    DNode *p = L->next;
    while (p != NULL) // 后向遍历
    {
        printf("%d\n", p->data);
        p = p->next;
    }
    // 打印操作
    p = GetLastDNode(L);
    while (p != NULL) // 前向遍历
    {
        printf("%d\n", p->data);
        p = p->prior;
    }
    // 打印操作
    p = GetLastDNode(L);
    while (p->prior != NULL) // 前向遍历，跳过头结点
    {
        printf("%d\n", p->data);
        p = p->prior;
    }
    return 0;
}
