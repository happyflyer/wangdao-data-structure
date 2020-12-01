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

// 初始化队列，不带头结点
bool InitQueue(LinkQueue &Q)
{
    Q.front = Q.rear = NULL;
    return true;
}

// 判断队列是否为空
bool QueueEmpty(LinkQueue Q)
{
    return Q.front = NULL;
}

// 入队
bool EnQueue(LinkQueue &Q, int x)
{
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = x;
    s->next = NULL;
    if (Q.front == NULL)
    {
        Q.front = s;
        Q.rear = s;
    }
    else
    {
        Q.rear->next = s;
        Q.rear = s;
    }
    return true;
}

// 出队
bool DeQueue(LinkQueue &Q, int x)
{
    if (QueueEmpty(Q))
    {
        return false;
    }
    LNode *q = Q.front;
    x = q->data;
    Q.front = q->next;
    if (Q.rear == q) // 如果是最后一个结点出队
    {
        Q.front = NULL;
        Q.rear = NULL;
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
    LNode *q = Q.front;
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
    LNode *i = Q.front;
    while (i != NULL)
    {
        printf("%d\n", i->data);
        i = i->next;
    }
    int x;
    DeQueue(Q, x);
    // printf("%d\n", x);
    // 打印操作
    i = Q.front;
    while (i != NULL)
    {
        printf("%d\n", i->data);
        i = i->next;
    }
    return 0;
}
