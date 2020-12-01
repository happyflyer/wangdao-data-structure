#include <stdio.h>
#include <stdlib.h>
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode;
typedef struct
{
    LNode *front, *rear; // 队列的队头、队尾指针
} LinkQueue;

// 初始化队列，带头结点
bool InitQueue(LinkQueue &Q)
{
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL)
    {
        return false;
    }
    s->next = NULL;
    Q.front = Q.rear = s;
    return true;
}

// 判断队列是否为空
bool QueueEmpty(LinkQueue Q)
{
    return Q.rear == Q.front;
}

// 入队
bool EnQueue(LinkQueue &Q, int x)
{
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = x;
    s->next = NULL;
    Q.rear->next = s;
    Q.rear = s;
    return true;
}

// 出队
bool DeQueue(LinkQueue &Q, int x)
{
    if (QueueEmpty(Q))
    {
        return false;
    }
    LNode *q = Q.front->next;
    x = q->data;
    Q.front->next = q->next;
    if (Q.rear == q) // 如果是最后一个结点出队
    {
        Q.rear = Q.front;
    }
    free(q);
    return true;
}

// 读取队头元素
bool GetHead(LinkQueue &Q, int &x)
{
    if (QueueEmpty(Q))
    {
        return false;
    }
    LNode *q = Q.front->next;
    x = q->data;
    return true;
}

int main()
{
    LinkQueue Q;
    InitQueue(Q);
    EnQueue(Q, 1);
    EnQueue(Q, 2);
    EnQueue(Q, 3);
    EnQueue(Q, 4);
    EnQueue(Q, 5);
    // 打印操作
    LNode *i = Q.front->next;
    while (i != NULL)
    {
        printf("%d\n", i->data);
        i = i->next;
    }
    int x;
    DeQueue(Q, x);
    // printf("%d\n", x);
    // 打印操作
    i = Q.front->next;
    while (i != NULL)
    {
        printf("%d\n", i->data);
        i = i->next;
    }
    return 0;
}
