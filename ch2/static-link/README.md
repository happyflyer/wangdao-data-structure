# 静态链表

## 1. 定义

- 单链表：各个结点在内存中星罗棋布、散落天涯。
- 静态链表：分配一整片连续的内存空间，各个结点集中安置。

| 内存地址 | 数据域 | 游标域 |
| -------- | ------ | ------ |
| ...      | ...    | ...    |
| 0        | 头     | 2      |
| 1        | $e_2$  | 6      |
| 2        | $e_1$  | 1      |
| 3        | $e_4$  | -1     |
| 4        | ...    | ...    |
| 5        | ...    | ...    |
| 6        | $e_3$  | 3      |
| 7        | ...    | ...    |
| 8        | ...    | ...    |
| 9        | ...    | ...    |
| ...      | ...    | ...    |

- 游标充当 “指针”。
- 游标为 `-1` 表示已经到达表尾。

每个数据元素 $4B$，每个游标 $4B$（每个结点共 $8B$），设其实地址为 $addr$，则 $e_1$ 的存放地址为：

$$
addr + 8*2
$$

```cpp
#define MaxSize 10
typedef struct
{
    ElemType data;
    int next;
} SNode;
```

高级写法：

```cpp
typedef struct
{
    int data;
    int next;
} SLinkList[MaxSize];
```

```cpp
SLinkList a;
```

```cpp
struct Node
{
    int data;
    int next;
};
typedef struct Node SLinkList[MaxSize];
```

```cpp
struct Node a[MaxSize];
```

## 2. 初始化

```cpp
SLinkList a;
a[0]->next = -1;
for (int i = 1; i < a.length; i++)
{
    a[i].next = -2;
}
```

## 3. 查找

查找某个位序的结点，需要从头结点出发，挨个往后遍历结点。

- 时间复杂度 $O(n)$

区别：

- 位序：各个结点在逻辑上的顺序。
- 数组下标：各个结点在物理上的位置。

## 4. 插入

1. 找到一个空的结点，存入数据元素。
2. 从头结点出发，找到位序为 $i-1$ 的结点。
3. 修改新结点的 `next`。
4. 修改 $i-1$ 结点的 `next`。

## 5. 删除

1. 从头结点出发找到前驱结点。
2. 修改前驱结点的 `next`。
3. 被删除结点的 `next` 设置为 `-2`。
