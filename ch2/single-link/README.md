# 单链表

## 1. typedef 关键词

`typedef` 关键字：数据类型重命名。

```cpp
typedef <数据类型> <别名>
```

```cpp
int x = 1;
int *p;
```

```cpp
typedef int zhengshu;
typedef int *zhengshuzhizhen;
zhengshu x = 1;
zhengshuzhizhen p;
```

## 2. 定义单链表

结点：

- 数据域
- 指针域

```cpp
struct LNode
{
    ElemType data;
    struct LNode *next;
};
```

```cpp
struct LNode *p = (struct LNode*) malloc(sizeof(struct LNode))
```

```cpp
typedef struct LNode LNode;
LNode *p = (LNode *) malloc(sizeof LNode);
```

高级写法：

```cpp
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;
```

```cpp
struct LNode
{
    ElemType data;
    struct LNode *next;
};
typedef struct LNode LNode;
typedef struct LNode *LinkList;
```

声明一个单链表时，只需要声明一个头指针 `L`，指向单链表的第一个结点。

```cpp
LNode *L; // 强调这是一个结点
```

```cpp
LinkList L; // 强调这是一个单链表
```

## 3. 不带头结点的单链表

```cpp
// 初始化一个空的单链表，不带头结点
bool InitList(LinkList &L)
{
    L = NULL;
    return true;
}
```

```cpp
// 判断单链表是否为空
bool Empty(LinkList L)
{
    return L == NULL;
}
```

写代码更麻烦：

- 对第一个数据结点和后续数据结点的处理需要用不同的代码逻辑。
- 对空表和非空表的处理需要用不同的代码逻辑。

## 4. 带头结点的单链表

头结点：

- `data` 没有数据
- `next` 指向第一个结点，空表时为 `NULL`

```cpp
// 初始化一个空的单链表，带头结点，头结点不存储数据
bool InitList(LinkList &L)
{
    // 分配一个头结点
    L = (LNode *)malloc(sizeof(LNode));
    if (L == NULL)
    {
        return false;
    }
    L->next = NULL;
    return true;
}
```

```cpp
// 判断单链表是否为空
bool Empty(LinkList L)
{
    return L->next == NULL;
}
```

写代码更方便。

## 5. 按位序插入

### 5.1. 带头结点

`ListInsert(&L,i,e)` 步骤：

1. 找到第 $i-1$ 个结点 `p`
2. 申请一个结点 `s`，存入数据元素 `e`
3. 修改 `s` 的后继结点为 `p` 的后继结点
4. 修改 `p` 的后继结点为 `s`

当插入位置 $i=1$ 时，可以把头结点看作为第 $0$ 个结点，以上逻辑同上适用。

```cpp
// 在第 i 个位置插入元素 e，带头结点
bool ListInsert(LinkList &L, int i, int e)
{
    // i 的值必须是合法的位序
    if (i < 1)
    {
        return false;
    }
    LNode *p;
    int j = 0;                     // 当前 p 指向的是第几个结点
    p = L;                         // 指向第 0 个结点
    while (p != NULL && j < i - 1) // 循环找到第 i-1 个结点
    {
        p = p->next;
        j++;
    }
    if (p == NULL)
    {
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}
```

- 最好时间复杂度：$O(1)$
- 最坏时间复杂度：$O(n)$
- 平均时间复杂度：$O(n)$

### 5.2. 不带头结点

插入位序 $i=1$ 时的步骤：

1. 申请一个结点 `s`，存入数据元素 `e`
2. 修改 `s` 的后继结点为 `L` 指向的结点
3. 修改 `L` 指向结点 `s`

插入位序 $i>1$ 时的步骤：

```cpp
// 在第 i 个位置插入元素 e，不带头结点
bool ListInsert(LinkList &L, int i, int e)
{
    // i 的值必须是合法的位序
    if (i < 1)
    {
        return false;
    }
    // 插入第 1 个结点的操作与其他结点的操作不同
    if (i == 1)
    {
        LNode *s = (LNode *)malloc(sizeof(LNode));
        s->data = e;
        s->next = L;
        L = s;
        return true;
    }
    LNode *p;
    int j = 1;                     // 当前 p 指向的是第几个结点
    p = L;                         // 指向第 0 个结点
    while (p != NULL && j < i - 1) // 循环找到第 i-1 个结点
    {
        p = p->next;
        j++;
    }
    if (p == NULL)
    {
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}
```

## 6. 指定结点的后插操作

1. 申请一个结点 `s`，存入数据元素 `e`
2. 修改 `s` 的后继结点为 `p` 的后继结点
3. 修改 `p` 的后继结点为 `s`

```cpp
// 后插操作：在结点 p 后插入元素 e
bool InsertNextNode(LNode *p, int e)
{
    if (p == NUll)
    {
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL) // 内存分配失败，可写可不写
    {
        return false;
    }
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}
```

时间复杂度：$O(1)$

## 7. 指定结点的前插操作

思路一：

```cpp
bool InsertPriorNode(LinkList L, LNode *p, int e);
```

- 需要传入头结点
- 时间复杂度：$O(n)$

**思路二**：

1. 在结点 `p` 后插入一个结点 `s`，`s` 的数据元素为 `e`
2. 修改 `s` 的数据元素为 `p` 的数据元素
3. 修改 `p` 的数据元素为 `e`

- 不需要传入头结点
- 时间复杂度：$O(1)$

```cpp
// 前插操作：在结点 p 前插入元素 e
bool InsertPriorNode(LNode *p, int e)
{
    if (p == NULL)
    {
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->next = p->next;
    p->next = s;
    s->data = p->data;
    p->data = e;
    return true;
}
```

```cpp
// 前插操作：在结点 p 前插入结点 s
bool InsertPriorNode(LNode *p, LNode *s)
{
    if (p == NULL || s == NULL)
    {
        return false;
    }
    s->next = p->next;
    p->next = s;
    int temp = s->data;
    s->data = p->data;
    p->data = temp;
    return true;
}
```

## 8. 按位序删除（带头结点）

`ListDelete(&L,i,&e)` 步骤：

1. 找到第 $i-1$ 个结点 `p` 和被删除结点 `q`
2. 修改 `e` 的值为 `q` 的数据元素值
3. 修改 `p` 的后继结点为 `q` 的后继结点
4. 释放 `q`

```cpp
// 按位序删除结点
bool ListDelete(LinkList &l, int i, int &e)
{
    // i 的值必须是合法的位序
    if (i < 1)
    {
        return false;
    }
    LNode *p;
    int j = 0;                     // 当前 p 指向的是第几个结点
    p = L;                         // 指向第 0 个结点
    while (p != NULL && j < i - 1) // 循环找到第 i-1 个结点
    {
        p = p->next;
        j++;
    }
    if (p == NULL) // i 值不合法
    {
        return false;
    }
    if (p->next == NULL) // 第 i-1 个结点后已无其他结点
    {
        return false;
    }
    LNode *q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);
    return true;
}
```

- 最好时间复杂度：$O(1)$
- 最坏时间复杂度：$O(n)$
- 平均时间复杂度：$O(n)$

## 9. 指定结点删除

类似于前插操作，`DeleteNode(LNode *p)` 的步骤：

1. 声明一个指针 `q` 指向结点 `p` 的后继结点
2. 修改 `p` 的数据元素为 `q` 的数据元素
3. 修改 `p` 的后继结点为 `q` 的后继结点
4. 释放 `q`

> 但是如果结点 p 是表尾结点，此方法将不适用，因为找不到 p 的后继结点。只能从表头开始查找并删除。

## 10. 单链表的局限性

无法逆向检索，有时候不太方便。

- 带头结点和不带头结点的区别
- “封装”的好处

## 11. 按位查找（带头结点）

```cpp
// 按位查找：返回第 i 个元素，带头结点，头结点看作是第 0 个结点
LNode *GetElem(LinkList L, int i)
{
    if (i < 0)
    {
        return NULL;
    }
    LNode *p;
    int j = 0;                 // 当前 p 指向的是第几个结点
    p = L;                     // 指向第 0 个结点
    while (p != NULL && j < i) // 循环找到第 i-1 个结点
    {
        p = p->next;
        j++;
    }
    return p;
}
```

- 时间复杂度：$O(n)$

## 12. 按值查找（带头结点）

```cpp
// 按值查找，找到数据域 == e 的结点
int LocateElem(LinkList L, int e)
{
    LNode *p = L->next;
    // 从第 1 个结点开始查找数据域为 e 的结点
    while (p != NULL && p->data != e)
    {
        p = p->next;
    }
    // 找到后返回该结点指针，否则返回 NULL
    return p;
}
```

- 时间复杂度：$O(n)$

## 13. 求表的长度

```cpp
// 求表的长度
int Length(LinkList L)
{
    int len = 0;
    LNode *p = L;
    while (p->next != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}
```

- 时间复杂度：$O(n)$

## 14. 单链表的建立

单链表的建立步骤：

1. 初始化一个单链表
2. 每次取一个数据元素，插入到表尾/表头

### 14.1. 尾插法

思路一：

1. 初始化单链表
2. 设置变量 `length` 记录链表长度
3. `while` 循环：
   1. 每次取一个数据元素 `e`
   2. `ListInsert(L, length+1, e)` 插到尾部
   3. `length++`

- 时间复杂度：$O(n^2)$

**思路二**：

1. 初始化单链表
2. 设置指针 `r` 指向表尾元素
3. `while` 循环：
   1. 在 `r` 之后插入结点 `s`
   2. 修改 `r` 指向 `s`

```cpp
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
```

- 时间复杂度：$O(n)$

### 14.2. 头插法

1. 初始化单链表
2. `while` 循环：
   1. 每次取一个数据元素 `e`
   2. `InsertNextNode(L, e)`

```cpp
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
```

- 时间复杂度：$O(n)$

> 养成好习惯：只要是初始化单链表，就先把头指针指向 NULL。

头插法的重要应用：链表的逆置。

```cpp
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
```
