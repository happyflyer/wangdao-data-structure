# 顺序表

顺序表：用顺序存储方式实现的线性表。

顺序存储：把逻辑上相邻的元素存储在物理位置上也相邻的存储单元中，元素之间的关系由存储单元的邻接关系来体现。

- $LOC(L)$
- $LOC(L)+sizeof(ElemType)$
- $LOC(L)+2*sizeof(ElemType)$
- $...$

## 1. 静态分配

```cpp
#define MaxSize 10
typedef struct
{
    ElemType data[MaxSize];
    int length;
} SqList;
```

```cpp
void InitList(SqList &L)
{
    // for (int i = 0; i < MaxSize; i++)
    // {
    //     L.data[i] = 0;
    // }
    L.length = 0;
}
```

$MaxSize*sizeof(ElemType)$

- 使用“静态数组”实现
- 大小一旦确定就无法改变

## 2. 动态分配

```cpp
#define InitSize 10
typedef struct
{
    ElemType *data;
    int MaxSize;
    int length;
} SeqList;
```

```cpp
void InitList(SeqList &L)
{
    // 用 malloc 函数申请一篇连续的存储空间
    L.data = (int *)malloc(InitSize * sizeof(int));
    L.length = 0;
    L.MaxSize = InitSize;
}
```

```cpp
void IncreaseSize(SeqList &L, int len)
{
    int *p = L.data;
    L.data = (int *)malloc((L.MaxSize + len) * sizeof(int));
    for (int i = 0; i < L.length; i++)
    {
        L.data[i] = p[i]; // 时间复杂度高
    }
    L.MaxSize += len;
    free(p);
}
```

- `malloc`：动态申请一整片连续的内存空间
- `free`：释放内存空间

```c
L.data = (ElemType *) malloc(sizeof(ElemType) * InitSize)
```

C++ 可以使用 `new`，`delete` 关键字。

- 使用“动态数组”实现
- `L.data = (ElemType *) malloc(sizeof(ElemType) * InitSize)`
- 顺序表存满时，可再用 `malloc` 动态扩展顺序表的最大容量
- 需要将数据元素复制到新的存储区域，并用 `free` 函数释放原区域

## 3. 顺序表的特点

- **随机访问**：即可以在 $O(1)$ 时间内找到第 $i$ 个元素。
- 存储密度高：每个结点只存储数据元素。
- 扩展容量不方便：静态分配不能扩展容量，动态分配可以扩展但时间复杂度高。
- 插入、删除元素操作不方便，需要移动大量元素。

## 4. 插入操作

$$
L=(\alpha_1,\alpha_2,\alpha_3,\alpha_4,\alpha_5)
$$

$$
[a_0,a_1,a_2,a_3,a_4]
$$

```cpp
bool ListInsert(SqList &L, int i, int e)
{
    // i 的值必须是合法的位序
    if (i < 1 || i > L.length + 1)
    {
        return false;
    }
    // 如果存储空间已满，则不能插入
    if (L.length >= MaxSize)
    {
        return false;
    }
    // 插入操作
    for (int j = L.length; j >= i; j--)
    {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return true;
}
```

插入位置之后的元素都要后移。

- 最好时间复杂度：$O(1)$
- 最坏时间复杂度：$O(n)$
- 平均时间复杂度：$O(n)$

## 5. 删除操作

```cpp
bool ListDelete(SqList &L, int i, int &e)
{
    // i 的值必须是合法的位序
    if (i < 1 || i > L.length)
    {
        return false;
    }
    // 删除操作
    e = L.data[i - 1];
    for (int j = i; j < L.length; j++)
    {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return true;
}
```

删除位置之后的元素都要前移。

- 最好时间复杂度：$O(1)$
- 最坏时间复杂度：$O(n)$
- 平均时间复杂度：$O(n)$

代码要点：

- 代码中注意位序 $i$ 与数组下标的区别。
- 算法要有健壮性，注意判断 $i$ 的合法性。
- 移动元素时，从靠前的元素开始？还是从表尾元素开始？
- 分析代码，理解为什么有的参数需要加 `&`（C++ 语法中的引用）。

## 6. 按位查找

```cpp
int GetElem(SqList L, int i)
{
    // i 的值必须是合法的位序
    if (i < 1 || i > L.length)
    {
        return false;
    }
    return L.data[i - 1];
}

```

- 时间复杂度：$O(1)$

## 7. 按值查找

```cpp
int LocateElem(SqList L, int e)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
        {
            return i + 1;
        }
    }
    return 0;
}
```

- 最好时间复杂度：$O(1)$
- 最坏时间复杂度：$O(n)$
- 平均时间复杂度：$O(n)$
