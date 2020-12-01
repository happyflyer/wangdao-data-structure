# 队列

## 1. 队列的顺序实现

### 1.1. 定义

用顺序存储方式实现的队列。

```cpp
#define MaxSize 10
typedef struct
{
    ElemType data[MaxSize];
    int front, rear; // 队头、队尾指针
} SqQueue;
```

$MaxSize*sizeof(ElemType)+8B$

### 1.2. 初始化队列

```cpp
// 初始化队列
void InitQueue(SqQueue &Q)
{
    Q.front = Q.rear = 0;
}
```

```cpp
// 判断队列是否为空
bool QueueEmpty(SqQueue Q)
{
    return Q.rear == Q.front;
}
```

```cpp
// 判断队列是否已满
bool QueueFull(SqQueue Q)
{
    return (Q.rear + 1) % MaxSize == Q.front;
}
```

```cpp
// 获取队长
int Length(SqQueue Q)
{
    return (Q.rear + MaxSize - Q.front) % MaxSize;
}
```

### 1.3. 入队

队尾指针指向队尾元素的下一个位置。

```cpp
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
```

### 1.4. 出队

```cpp
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
```

### 1.5. 获取队头元素

```cpp
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
```

### 1.6. 不要浪费最后一个空位

加入辅助变量。

#### 1.6.1. size

```cpp
#define MaxSize 10
typedef struct
{
    ElemType data[MaxSize];
    int front, rear;
    int size;
} SqQueue;
```

- 初始时：`Q.front = Q.rear = 0;`，`Q.size = 0;`
- 入队：`Q.size++;`
- 出队：`Q.size--;`
- 队满条件：`Q.size == MaxSize;`
- 队空条件：`Q.size == 0;`

#### 1.6.2. tag

```cpp
#define MaxSize 10
typedef struct
{
    ElemType data[MaxSize];
    int front, rear;
    int tag;
} SqQueue;
```

- 初始时：`Q.front = Q.rear = 0;`，`Q.tag = 0;`
- 入队：`Q.tag = 1;`，只有入队操作，才能导致队满。
- 出队：`Q.tag = 0;`，只有出队操作，才能导致队空。
- 队满条件：`Q.front == Q.rear && Q.tag == 1;`
- 队空条件：`Q.front == Q.rear && Q.tag == 0;`

### 1.7. 队尾指针指向队尾元素

入队：

```cpp
Q.rear = (Q.rear + 1) % MaxSize;
Q.data[Q.rear] = x;
```

初始化：

```cpp
Q.front = 0;
Q.rear = MaxSize - 1;
```

判空：

```cpp
(Q.rear + 1) % MaxSize == Q.front;
```

判满（牺牲一个存储单元）：

```cpp
(Q.rear + 2) % MaxSize == Q.front;
```

## 2. 队列的链式实现

### 2.1. 定义

```cpp
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode;
typedef struct
{
    LNode *front, *rear; // 队列的队头、队尾指针
} LinkQueue;
```

### 2.2. 初始化

```cpp
// 初始化队列
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
```

```cpp
// 判断队列是否为空
bool QueueEmpty(LinkQueue Q)
{
    return Q.rear == Q.front;
}
```

### 2.3. 入队

```cpp
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
```

### 2.4. 出队

```cpp
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
```

### 2.5. 获取队头元素

```cpp
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
```

### 2.6. 不带头结点

```cpp
// 初始化队列
bool InitQueue(LinkQueue &Q)
{
    Q.front = Q.rear = NULL;
    return true;
}
```

```cpp
// 判断队列是否为空
bool QueueEmpty(LinkQueue Q)
{
    return Q.front = NULL;
}
```

```cpp
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
```

```cpp
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
```

```cpp
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
```
