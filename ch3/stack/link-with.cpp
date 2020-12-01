#include <stdio.h>
#include <stdlib.h>
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkStack;

// 初始化一个链栈，带头结点
bool InitStack(LinkStack &S)
{
    S = (LNode *)malloc(sizeof(LNode));
    if (S == NULL)
    {
        return false;
    }
    S->next = NULL;
    return true;
}

// 判断栈空
bool StackEmpty(LinkStack S)
{
    return S->next == NULL;
}

// 进栈
bool Push(LinkStack &S, int x)
{
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = x;
    s->next = S->next;
    S->next = s;
    return true;
}

// 出栈
bool Pop(LinkStack &S, int &x)
{
    if (StackEmpty(S))
    {
        return false;
    }
    LNode *q = S->next;
    x = q->data;
    S->next = q->next;
    free(q);
    return true;
}

// 读取栈顶元素
bool GetTop(LinkStack &S, int &x)
{
    if (StackEmpty(S))
    {
        return false;
    }
    x = S->next->data;
    return true;
}

int main()
{
    LinkStack S;
    InitStack(S);
    Push(S, 1);
    Push(S, 2);
    Push(S, 3);
    Push(S, 4);
    Push(S, 5);
    // 打印操作
    LNode *i = S->next;
    while (i != NULL)
    {
        printf("%d\n", i->data);
        i = i->next;
    }
    int x;
    Pop(S, x);
    // printf("%d\n", x);
    // 打印操作
    i = S->next;
    while (i != NULL)
    {
        printf("%d\n", i->data);
        i = i->next;
    }
    return 0;
}
