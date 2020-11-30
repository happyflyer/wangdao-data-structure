#include <stdio.h>
#include <stdlib.h>
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

// 初始化一个循环单链表，带头结点，头结点不存储数据
bool InitList(LinkList &L)
{
    // 分配一个头结点
    L = (LNode *)malloc(sizeof(LNode));
    if (L == NULL)
    {
        return false;
    }
    L->next = L;
    return true;
}

// 判断循环单链表是否为空
bool Empty(LinkList L)
{
    return L->next == L;
}

// 判断 p 结点是否为表尾结点
bool isTail(LinkList L, LNode *p)
{
    return p->next == L;
}

int main()
{
    LinkList L;
    InitList(L);
    return 0;
}
