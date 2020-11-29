#include <stdio.h>
#include <stdlib.h>
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

bool InitList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode));
    if (L == NULL)
    {
        return false;
    }
    L->next = NULL;
    return true;
}

// 尾插法建立单链表
LinkList List_TailInsert(LinkList &L)
{
    int x;
    L = (LNode *)malloc(sizeof(LNode));
    LNode *s, *r = L; // r 为表尾指针
    scanf("%d", &x);
    while (x != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s; // r 指向新的表尾结点
        scanf("%d", &x);
    }
    r->next = NULL;
    return L;
}

// 头插法建立单链表
LinkList List_HeadInsert(LinkList &L)
{
    int x;
    L = (LNode *)malloc(sizeof(LNode));
    L->next = NULL; // 一定要初始化头结点的 next
    LNode *s;
    scanf("%d", &x);
    while (x != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}

// 头插法实现单链表的逆置
LinkList List_Reverse(LinkList &L)
{
    LinkList L2 = (LNode *)malloc(sizeof(LNode));
    L2->next = NULL;
    LNode *s = L->next;
    while (s != NULL)
    {
        LNode *s2 = (LNode *)malloc(sizeof(LNode));
        s2->data = s->data;
        s2->next = L2->next;
        L2->next = s2;
        s = s->next;
    }
    return L2;
}

int main()
{
    LinkList L;
    List_TailInsert(L);
    // List_HeadInsert(L);
    // 打印操作
    LNode *p;
    p = L->next;
    while (p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
    // 测试单链表逆置
    LinkList L2 = List_Reverse(L);
    // 打印操作
    p = L2->next;
    while (p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
    return 0;
}
