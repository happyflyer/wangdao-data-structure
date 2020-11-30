# 双链表

```cpp
typedef struct DNode
{
   ElemType data;
   struct DNode *prior, *next;
} DNode, *DLinkList;
```

## 1. 初始化

```cpp
// 初始化一个双链表，带头结点
bool InitDLinkList(DLinkList &L)
{
    L = (DNode *)malloc(sizeof(DNode));
    if (L == NULL)
    {
        return false;
    }
    L->prior = NULL; // 头结点的 prior 永远指向 NULL
    L->next = NULL;
    return true;
}
```

```cpp
// 判断双链表是否为空
bool Empty(DLinkList L)
{
    return L->next == NULL;
}
```

## 2. 插入

```cpp
// 后插操作：在 p 结点之后插入 s 结点
bool InsertNextDNode(DNode *p, DNode *s)
{
    if (p == NULL || s == NULL)
    {
        return false;
    }
    s->next = p->next;
    if (p->next != NULL) // 如果 p 结点不是表尾结点
    {
        p->next->prior = s;
    }
    s->prior = p;
    p->next = s;
}
```

## 3. 删除

```cpp
// 删除操作：删除 p 结点的后继结点 q
bool DeleteNextDNode(DNode *p)
{
    if (p == NULL)
    {
        return false;
    }
    DNode *q = p->next;
    if (q == NULL) // p 结点没有后继结点
    {
        return false;
    }
    p->next = q->next;
    if (q->next != NULL) // q 结点不是表尾结点
    {
        q->next->prior = p;
    }
    free(q);
    return true;
}
```

## 4. 遍历

```cpp
while (p != NULL) // 后向遍历
{
    printf("%d\n", p->data);
    p = p->next;
}
```

```cpp
while (p != NULL) // 前向遍历
{
    printf("%d\n", p->data);
    p = p->prior;
}
```

```cpp
while (p->prior != NULL) // 前向遍历，跳过头结点
{
    printf("%d\n", p->data);
    p = p->prior;
}
```

双链表不可随机存取，按位查找、按值查找都智能用遍历的方式实现。

- 时间复杂度 $O(n)$
