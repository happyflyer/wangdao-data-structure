# 栈

## 1. 顺序栈

### 1.1. 定义

用顺序存储方式实现的栈。

```cpp
#define MaxSize 10
typedef struct
{
    ElemType data[MaxSize];
    int top; // 栈顶指针
} SqStack;
```

$MaxSize*sizeof(ElemType)+4B$

### 1.2. 初始化栈

```cpp
// 初始化栈
void InitStack(SqStack &S)
{
    S.top = -1;
}
```

```cpp
// 判断栈空
bool StackEmpty(SqStack S)
{
    return S.top == -1;
}
```

```cpp
// 判断栈满
bool StackFull(SqStack S)
{
    return S.top == MaxSize - 1;
}
```

### 1.3. 进栈

```cpp
// 进栈
bool Push(SqStack &S, int x)
{
    if (StackFull(S))
    {
        return false;
    }
    // S.top++;
    // S.data[S.top] = x;
    S.data[++S.top] = x;
    return true;
}
```

### 1.4. 出栈

```cpp
// 出栈，数据还残留在内存中，只是逻辑上被删除了
bool Pop(SqStack &S, int &x)
{
    if (StackEmpty(S))
    {
        return false;
    }
    // x = S.data[S.top];
    // S.top--;
    x = S.data[S.top--];
    return true;
}
```

### 1.5. 获取栈顶元素

```cpp
// 读取栈顶元素
bool GetTop(SqStack &S, int &x)
{
    if (StackEmpty(S))
    {
        return false;
    }
    x = S.data[S.top];
    return true;
}
```

### 1.6. 另一种初始化栈的方式

```cpp
// 初始化栈
void InitStack(SqStack &S)
{
    S.top = 0;
}
```

```cpp
// 判断栈空
bool StackEmpty(SqStack S)
{
    return S.top == 0;
}
```

```cpp
// 判断栈满
bool StackFull(SqStack S)
{
    return S.top == MaxSize;
}
```

### 1.7. 顺序栈的缺点

栈的大小不可改变。

### 1.8. 共享栈

两个栈共享同一片内存空间，两个栈从两边往中间增长。

```cpp
#define MaxSize 10
typedef struct
{
    ElemType data[MaxSize];
    int top0;
    int top1;
} ShStack;
```

```cpp
// 初始化共享栈
void InitStack(ShStack &S)
{
    S.top0 = -1;
    S.top1 = MaxSize;
}
```

```cpp
// 判断栈满
bool StackFull(ShStack S)
{
    return S.top0 + 1 == S.top1;
}
```

## 2. 链栈

### 2.1. 定义

```cpp
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkStack;
```

### 2.2. 初始化

```cpp
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
```

```cpp
// 判断栈空
bool StackEmpty(LinkStack S)
{
    return S->next == NULL;
}
```

### 2.3. 进栈

```cpp
// 进栈
bool Push(LinkStack &S, int x)
{
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = x;
    s->next = S->next;
    S->next = s;
    return true;
}
```

### 2.4. 出栈

```cpp
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
```

### 2.5. 获取栈顶元素

```cpp
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
```
