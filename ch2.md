# 线性表

## 1. 定义

线性表（Linear List）是具有相同数据类型的 $n$ $(n \geq 0)$ 个数据元素的有序序列。

- **相同数据类型**
- **有序**
- **序列**

其中 $n$ 为**表长**。当 $n=0$ 时线性表是一个**空表**。

$$
L=(\alpha_1,\alpha_2,...,\alpha_i,\alpha_{i+1},...,\alpha_n)
$$

- $\alpha_i$ 是线性表中的 “第 $i$ 个” 元素线性表中的**位序**。
- $\alpha_1$ 是**表头元素**，$\alpha_n$ 是**表尾元素**。
- 出第一个元素外，每个元素有且仅有一个**直接前驱**；除最后一个元素外，每个元素有且仅有一个**直接后继**。

> 注意：位序是从 $1$ 开始的，而数组下标是从 $0$ 开始的。

## 2. 基本操作

- `InitList(&L)`：初始化表。构造一个空的线性表 $L$，分配内存空间。
- `DestroyList(&L)`：销毁操作。销毁线性表，并释放线性表 $L$ 所占用的内存。
- `ListInsert(&L,i,e)`：插入操作。在表 $L$ 中的第 $i$ 个位置插入指定元素 $e$。
- `ListDelete(&L,i,&e)`：插入操作。删除表 $L$ 中的第 $i$ 个位置的元素，并用 $e$ 返回删除元素的值。
- `LocateElem(L,e)`：按值查找操作。在表 $L$ 中查找查找具有给行关键字值的元素。
- `GetElem(L,i)`：按位查找操作。获取表 $L$ 中的第 $i$ 个位置的元素的值。
- `Length(L)`：求表长。返回线性表 $L$ 的长度，即 $L$ 中所有元素的个数。
- `PrintList(L)`：输出操作。按前后顺粗输出线性表 $L$ 的所有元素值。
- `Empty(L)`：判空操作。若 $L$ 为空表，则返回 `true`，否则返回 `false`。

Tips：

- 对数据的操作（记忆思路）：创销、增删改查。
- C 语言函数的定义：<返回值类型> 函数名(<参数 1 类型> 参数 1, <参数 2 类型> 参数 2, ...)。
- 实际开发中，可根据实际需求定义其他的基本操作。
- 函数名和参数的形式、命名都可改变（参考：严蔚敏《数据结构》）。（可读性）
- 什么时候要传入引用 `&`：对参数的修改结果需要 “带回来”。（C++ 语法）

为什么要实现对数据结构的基本操作：

- 团队合作编程，你定义的数据结构要让别人能够很方便的使用（封装）。
- 将常用的操作、运算封装成函数，避免重复工作，降低出错风险。

存储/物理结构：

- 顺序表（顺序存储）
- 链表（链式存储）

## 3. 顺序表

顺序表：用顺序存储方式实现的线性表。

顺序存储：把逻辑上相邻的元素存储在物理位置上也相邻的存储单元中，元素之间的关系由存储单元的邻接关系来体现。

- $LOC(L)$
- $LOC(L)+sizeof(ElemType)$
- $LOC(L)+2*sizeof(ElemType)$
- $...$

### 3.1. 静态分配

```c
#define MaxSize 10
typedef struct
{
    ElemType data[MaxSize];
    int length;
} SqList;
```

$MaxSize*sizeof(ElemType)$

- 使用“静态数组”实现
- 大小一旦确定就无法改变

### 3.2. 动态分配

```c
#define InitSize 10
typedef struct
{
    ElemType *data;
    int MaxSize;
    int length;
} SeqList;
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

### 3.3. 顺序表的特点

- **随机访问**：即可以在 $O(1)$ 时间内找到第 $i$ 个元素。
- 存储密度高：每个节点只存储数据元素。
- 扩展容量不方便：静态分配不能扩展容量，动态分配可以扩展但时间复杂度高。
- 插入、删除元素操作不方便，需要移动大量元素。

### 3.4. 插入操作

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

### 3.5. 删除操作

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

### 3.6. 按位查找

### 3.7. 按值查找
