# 循环链表

## 1. 循环单链表

### 1.1. 定义

- 单链表：表尾结点的 `next` 指针指向 `NULL`。
- 循环单链表：表尾结点的 `next` 指针指向头结点。

```cpp
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;
```

```cpp
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
```

```cpp
// 判断循环单链表是否为空
bool Empty(LinkList L)
{
    return L->next == L;
}
```

```cpp
// 判断 p 结点是否为表尾结点
bool isTail(LinkList L, LNode *p)
{
    return p->next == L;
}
```

### 1.2. 特性

- 单链表：从一个结点出发，只能找到后续的各个结点。
- 循环单链表：从一个结点出发，可以找到其他任何一个结点。

如果经常操作循环单链表的头部或尾部，可以让 `L` 指向表尾结点。

- 单链表和循环单链表：从头结点找到尾部，时间复杂度为 $O(n)$。
- 循环单链表：从尾部找到头部，时间复杂度为 $O(1)$。

> 插入、删除时需要修改 L。

## 2. 循环双链表

### 2.1. 定义

- 双链表：表头结点的 `prior` 指向 `NULL`，表尾结点的 `next` 指向 `NULL`。
- 循环双链表：表头结点的 `prior` 指向表尾结点，表尾结点的 `next` 指向表头结点。

```cpp
typedef struct DNode
{
    int data;
    struct DNode *prior, *next;
} DNode, *DLinkList;
```

```cpp
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
```

```cpp
// 判断双链表是否为空
bool Empty(DLinkList L)
{
    return L->next == L;
}
```

```cpp
// 判断 p 结点是否为表尾结点
bool isTail(DLinkList L, DNode *p)
{
    return p->next == L;
}
```

### 2.2. 后插

```cpp
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
```

### 2.3. 后删

```cpp
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
```
