#include <stdio.h>
#define MaxSize 10
typedef struct
{
    int data[MaxSize];
    int front, rear; // 队头、队尾指针
} SqQueue;

// 初始化队列
void InitQueue(SqQueue &Q)
{
    Q.front = Q.rear = 0;
}

// 判断队列是否为空
bool QueueEmpty(SqQueue Q)
{
    return Q.rear == Q.front;
}

// 判断队列是否已满
bool QueueFull(SqQueue Q)
{
    return (Q.rear + 1) % MaxSize == Q.front;
}

// 获取队长
int Length(SqQueue Q)
{
    return (Q.rear + MaxSize - Q.front) % MaxSize;
}

// 入队
bool EnQueue(SqQueue &Q, int x)
{
    if (QueueFull(Q))
    {
        return false;
    }
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}

// 出队
bool DeQueue(SqQueue &Q, int x)
{
    if (QueueEmpty(Q))
    {
        return false;
    }
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}

// 读取队头元素
bool GetHead(SqQueue &Q, int &x)
{
    if (QueueEmpty(Q))
    {
        return false;
    }
    x = Q.data[Q.front];
    return true;
}

int main()
{
    SqQueue Q;
    InitQueue(Q);
    EnQueue(Q, 1);
    EnQueue(Q, 2);
    EnQueue(Q, 3);
    EnQueue(Q, 4);
    EnQueue(Q, 5);
    // 打印操作
    int i = Q.front;
    while (i < Q.rear)
    {
        printf("%d\n", Q.data[i]);
        i = (i + 1) % MaxSize;
    }
    int x;
    DeQueue(Q, x);
    // printf("%d\n", x);
    // 打印操作
    i = Q.front;
    while (i < Q.rear)
    {
        printf("%d\n", Q.data[i]);
        i = (i + 1) % MaxSize;
    }
    return 0;
}
