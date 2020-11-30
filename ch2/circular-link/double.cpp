#include <stdio.h>
#include <stdlib.h>
typedef struct DNode
{
    int data;
    struct DNode *prior, *next;
} DNode, *DLinkList;

// 初始化一个循环双链表，带头结点
bool InitDLinkList(DLinkList &L)
{
    L = (DNode *)malloc(sizeof(DNode));
    if (L == NULL)
    {
        return false;
    }
    L->prior = L;
    L->next = L;
    return true;
}

// 判断双链表是否为空
bool Empty(DLinkList L)
{
    return L->next == L;
}

// 判断 p 结点是否为表尾结点
bool isTail(DLinkList L, DNode *p)
{
    return p->next == L;
}

// 后插操作：在 p 结点之后插入 s 结点
bool InsertNextDNode(DNode *p, DNode *s)
{
    if (p == NULL || s == NULL)
    {
        return false;
    }
    s->next = p->next;
    p->next->prior = s;
    s->prior = p;
    p->next = s;
    return true;
}

// 删除操作：删除 p 结点的后继结点 q
bool DeleteNextDNode(DLinkList L, DNode *p)
{
    if (p == NULL || isTail(L, p))
    {
        return false;
    }
    DNode *q = p->next;
    p->next = q->next;
    q->next->prior = p;
    free(q);
    return true;
}

int main()
{
    DLinkList L;
    InitDLinkList(L);
    return 0;
}
