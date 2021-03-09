# [王道考研 数据结构](https://www.bilibili.com/video/BV1b7411N798)

## 1. 绪论

### 1.1. 基本概念

- 数据
- 数据元素、数据项
- 数据对象、数据结构
- 数据类型、抽象数据类型（ADT）

### 1.2. 三要素

- **逻辑结构**
  - 集合
  - 线性结构
  - 树形结构
  - 图状结构（网状结构）
- **物理结构**（存储结构）
  - 顺序存储
  - 链式存储
  - 索引存储
  - 散列存储
- **数据的运算**

逻辑结构：

- 线性结构
- 非线性结构

存储结构：

- 顺序存储
- 非顺序存储

数据的存储结构：

- 如果采用顺序存储，则各个数据元素在物理上必须是联系的；若采用非顺序存储，则各个数据元素在物理上可以是离散的。
- 数据的存储结构会影响存储空间分配的方便程度。
- 数据的存储结构会影响对数据运算的速度。

数据的运算：

- 运算的定义是针对逻辑结构的。
- 运算的实现是针对存储结构的。

### 1.3. 数据类型

数据类型是一个值的集合和定义在此几何上的一组操作的总称。

- 原子类型。其值不可再分的数据类型。
- 结构类型。其值可以再分解为若干成分（分量）的数据类型

抽象数据类型（Abstract Data Type，ADT）是抽象数据组织及与之相关的操作。

抽象数据类型只关心：

- 逻辑结构
- 数据的运算

### 1.4. 在讨论一种数据结构时

1. 定义逻辑结构，数据元素之间的关系
2. 定义数据的运算，针对现实需求，应该对这种逻辑结构进行什么样的运算
3. 确定某种存储结构，实现数据结构，并实现一些对数据结构的基本运算

### 1.5. 算法

程序 = 数据结构 + 算法

- 数据结构：如何把现实世界的问题信息化，将信息存进计算机。同时还要实现对数据结构的基本操作。
- 算法：如何处理这些信息，以解决实际问题。

算法的特性：

- 有穷性：一个算法必须总在执行有穷步之后结束，且每一步都可在有穷时间内完成。
- 确定性：算法中每条指令必须有明确的含义，对于相同的输入只能得到相同输出。
- 可行性：算法中描述的操作都可以通过已经实现的基本运算执行有限次来实现。
- 输入：一个算法有零个或多个输入，这些输入取自于某个特定的对象的集合。
- 输出：一个算法有一个或多个输出，这些输出是与输入有着某种也行关系的量。

算法必须是有穷的，而程序可以是无穷的。

“好”算法的特质：

- 正确性：能正确解决问题。
- 可读性：无歧义地描述每步操作。
- 健壮性：输入非法数据时，算法能够适当地做出反应或进行处理，而不会产生莫名其妙的输出结果。
- 高效率和低存储量需求：执行速度快，时间复杂度低；不费内存，空间复杂度低。

#### 1.5.1. 时间复杂度

时间开销 $T(n)$ 与问题规模 $n$ 的关系。

1. 找到一个基本操作（最深层循环、递归型循环）
2. 分析改基本操作的执行次数 $x$ 与问题规模 $n$ 的关系 $x=f(n)$
3. $x$ 的数量级 $O(x)$ 就是算法时间复杂度 $T(n)$

用 $O$ 表示同阶，同等数量级。即当 $n\to+\infty$ 时，二者之比为常数。

- $T_1(n)=O(n)$
- $T_2(n)=O(n^2)$
- $T_3(n)=O(n^3)$

$$
T(n)=O(f(n))
\iff
\lim \limits_{n\to+\infty} \frac{T(n)}{f(n)}=k
$$

**加法规则**（只保留更高阶的项）：

$$
T(n)
=T_1(n)+T_2(n)
=O(f(n)) + O(g(n))
=O(max(f(n),g(n)))
$$

**乘法规则**：

$$
T(n)
=T_1(n) \times T_2(n)
=O(f(n)) \times O(g(n))
=O(f(n) \times g(n))
$$

举例：

$$
\begin{aligned}
T_3(n)
&=n^3+n^2log_2n\\
&=O(n^3)+O(n^2log_2n)\\
&=O(n^3)
\end{aligned}
$$

算法的时间复杂度（**常对幂指阶**）：

$$
O(1) < O(log_2n) < O(n) < O(nlog_2n) < O(n^2) < O(n^3) < O(2^n) < O(n!) < O(n^n)
$$

- 结论一：顺序执行的代码只会影响常数项，可以忽略。
- 结论二：只需挑循环中的一个基本操作，分析它的执行次数与 $n$ 的关系即可。
- 结论三：如果有多层嵌套循环，只需关注最深层循环循环了几次。

查找长度为 $n$ 的数组中的一个元素：

最好情况

$$
T(n)=O(1)
$$

最坏情况

$$
T(n)=O(n)
$$

平均情况：被查找的元素出现在任意位置的概率相同，都为 $\frac{1}{n}$

$$
T(n)
=(1+2+3+...+n) \times \frac{1}{n}
=\frac{1+n}{2}
=O(n)
$$

计算时间复杂度情况：

- 最好时间复杂度
- **最坏时间复杂度**
- **平均时间复杂度**

> 算法的性能问题只有在 $n$ 很大时（$n\to+\infty$）才会暴露出来。

#### 1.5.2. 空间复杂度

空间开销（内存开销） $S(n)$ 与问题规模 $n$ 的关系。

普通程序只需要关注存储空间大小与问题规模相关的变量：

1. 找到所占空间大小与问题规模相关的变量。
2. 分析所占空间 $x$ 与问题规模 $n$ 的关系 $x=f(n)$。
3. $x$ 的数量级 $O(x)$ 就是算法时间复杂度 $S(n)$。

函数递归调用带来的内存开销。（函数调用栈）

空间复杂度 = 递归调用的深度。也有的情况，每一层递归调用的空间大小不一样。

递归程序：

1. 找到递归调用的深度 $x$ 与问题规模 $n$ 的关系 $x=f(n)$。
2. $x$ 的数量级 $O(x)$ 就是算法时间复杂度 $S(n)$。
3. 有的算法各层函数所需的存储空间不同，分析方法略有差别。

加法规则：

$$
O(f(n)) + O(g(n))
=O(max(f(n),g(n)))
$$

乘法规则：

$$
O(f(n)) \times O(g(n))
=O(f(n) \times g(n))
$$

常对幂指阶：

$$
O(1) < O(log_2n) < O(n) < O(nlog_2n) < O(n^2) < O(n^3) < O(2^n) < O(n!) < O(n^n)
$$

## 2. [线性表](ch2/README.md#线性表)

- [定义](ch2/README.md#1-定义)
- [基本操作](ch2/README.md#2-基本操作)
- [顺序表](ch2/sequence/README.md#顺序表)
  - [静态分配](ch2/sequence/README.md#1-静态分配)
  - [动态分配](ch2/sequence/README.md#2-动态分配)
- [单链表](ch2/single-link/README.md#单链表)
  - [带头结点](ch2/single-link/README.md#4-带头结点的单链表)
  - [不带头结点](ch2/single-link/README.md#3-不带头结点的单链表)
- [双链表](ch2/double-link/README.md#双链表)
- [循环链表](ch2/circular-link/README.md#循环链表)
  - [循环单链表](ch2/circular-link/README.md#1-循环单链表)
  - [循环双链表](ch2/circular-link/README.md#2-循环双链表)
- [静态链表](ch2/static-link/README.md#静态链表)
- [顺序表 V.S 链表](ch2/README.md#9-顺序表-vs-链表)

## 3. [栈和队列](ch3/README.md#栈和队列)

- [栈](ch3/stack/README.md#栈)
  - [顺序栈](ch3/stack/README.md#1-顺序栈)
  - [共享栈](ch3/stack/README.md#18-共享栈)
  - [链栈](ch3/stack/README.md#2-链栈)
- [队列](ch3/queue/README.md#队列)
  - [队列的顺序实现](ch3/queue/README.md#1-队列的顺序实现)
  - [队列的链式实现](ch3/queue/README.md#2-队列的链式实现)
  - [双端队列](ch3/README.md#3-双端队列)
- [栈的应用](ch3/stack-applications/README.md#栈的应用)
  - [括号匹配](ch3/stack-applications/README.md#1-括号匹配)
  - [表达式求值](ch3/stack-applications/README.md#2-表达式求值)
  - [递归](ch3/stack-applications/README.md#3-递归)
- [队列的应用](ch3/README.md#5-队列的应用)
- [矩阵的压缩存储](ch3/matrix/README.md#矩阵的压缩存储)
  - [对称矩阵](ch3/matrix/README.md#3-对称矩阵)
  - [三角矩阵](ch3/matrix/README.md#4-三角矩阵)
  - [三对角矩阵](ch3/matrix/README.md#5-三对角矩阵)
  - [稀疏矩阵](ch3/matrix/README.md#6-稀疏矩阵)

## 4. [串](ch4/README.md#串)

- [定义](ch4/README.md#1-定义)
- [基本操作](ch4/README.md#2-基本操作)
- [串的存储结构](ch4/README.md#3-串的存储结构)
  - [顺序存储](ch4/README.md#31-顺序存储)
  - [链式存储](ch4/README.md#32-链式存储)
- [基本操作的实现](ch4/README.md#4-基本操作的实现)
  - [求子串](ch4/README.md#41-求子串)
  - [串的比较](ch4/README.md#42-串的比较)
  - [求串在主串中的位置](ch4/README.md#43-求串在主串中的位置)
- [朴素模式匹配算法](ch4/README.md#5-朴素模式匹配算法性能分析)
- [KMP 算法](ch4/README.md#6-KMP-算法)
  - [改进思路](ch4/README.md#61-改进思路)
  - [next 数组](ch4/README.md#62-next-数组)
  - [nextval 数组](ch4/README.md#63-KMP-算法优化)

## 5. [树与二叉树](ch5/README.md#树与二叉树)

- [二叉树](ch5/binary-tree/README.md#二叉树)
  - [二叉树的基本概念](ch5/binary-tree/README.md#二叉树)
    - [定义及特点](ch5/binary-tree/README.md#4-二叉树的性质)
    - [二叉树的存储结构](ch5/binary-tree-storage/README.md#二叉树的存储结构)
  - [二叉树的遍历](ch5/binary-tree-traversal/README.md#二叉树的遍历)
  - [线索二叉树](ch5/binary-tree-traversal/README.md#7-线索二叉树)
  - [二叉树的应用](ch5/binary-tree-applications/README.md#二叉树的应用)
    - [二叉排序树](ch5/binary-tree-applications/README.md#1-二叉排序树)
    - [平衡二叉树](ch5/binary-tree-applications/README.md#2-平衡二叉树)
    - [哈夫曼树和哈夫曼编码](ch5/binary-tree-applications/README.md#3-哈夫曼树)
- [树和森林](ch5/README.md#树与二叉树)
  - [树的基本概念](ch5/README.md#1-树的基本概念)
  - [树的存储结构](ch5/tree-storage/README.md#树的存储结构)
  - [树和森林的遍历](ch5/tree-traversal/README.md#树与森林)
  - [树和森林及二叉树的转换](ch5/tree-traversal/README.md#树与森林)
  - [树的应用：查并集](ch5/tree-applications/README.md#1-并查集)

## 6. [图](ch6/README.md#图)

- [逻辑结构](ch6/README.md#图)
  - [图的定义](ch6/README.md#图)
  - [相关概念](ch6/concept/README.md#图的基本概念)
    - [无向图 & 有向图](ch6/concept/README.md#1-无向图-&-有向图)
    - [完全图](ch6/concept/README.md#3-完全图)
    - [子图](ch6/concept/README.md#4-子图)
    - [连通分量 & 强连通分量](ch6/concept/README.md#7-连通分量-&-强连通分量)
    - [带权图(网)](ch6/concept/README.md#11-网)
- [存储结构](ch6/storage/README.md#图的存储结构)
  - [邻接矩阵](ch6/storage/README.md#1-邻接矩阵法)
  - [邻接表](ch6/storage/README.md#2-邻接表法)
  - [十字链表](ch6/storage/README.md#3-十字链表)
  - [邻接多重表](ch6/storage/README.md#4-邻接多重表)
- [基本操作](ch6/operation/README.md#图的基本操作)
- [图的遍历](ch6/traversal/README.md#图的遍历)
  - [广度优先搜索](ch6/traversal/README.md#1-广度优先搜索)
  - [深度优先搜索](ch6/traversal/README.md#2-深度优先搜索)
  - [遍历与连通性](ch6/traversal/README.md#3-遍历与连通性问题)
- [图的应用](ch6/applications/README.md#图的应用)
  - [最小生成树](ch6/applications/README.md#1-最小生成树)
  - [最短路径](ch6/applications/README.md#2-最短路径)
  - [拓扑排序](ch6/applications/README.md#3-拓扑排序)
  - [关键路径](ch6/applications/README.md#4-关键路径)

## 7. [查找](ch7/README.md#查找)

- [查找](ch7/README.md#1-基本概念)
  - [顺序查找](ch7/sequential-search/README.md#顺序查找)
  - [折半查找](ch7/binary-search/README.md#折半查找)
  - [分块查找](ch7/block-search/README.md#分块查找)
  - [B 树](ch7/b-tree/README.md#B-树)
  - [B+ 树](ch7/b-plus-tree/README.md#B+-树)
  - [散列表](ch7/hash-table/README.md#散列表)
- [串](ch4/README.md#串)
  - [基本概念](ch4/README.md#1-定义)
  - [模式匹配(KMP)](ch4/README.md#6-KMP-算法)

## 8. [排序](ch8/README.md#排序)

- [基本概念](ch8/README.md#1-基本概念)
- [内部排序](ch8/README.md#2-内部排序算法)
  - [插入排序](ch8/README.md#2-内部排序算法)
    - [直接插入排序](ch8/direct-insertion-sort/README.md#直接插入排序)
    - [折半插入排序](ch8/binary-insertion-sort/README.md#折半插入排序)
    - [希尔排序](ch8/shell-sort/README.md#希尔排序)
  - [交换排序](ch8/README.md#2-内部排序算法)
    - [冒泡排序](ch8/bubble-sort/README.md#冒泡排序)
    - [快速排序](ch8/quick-sort/README.md#快速排序)
  - [选择排序](ch8/README.md#2-内部排序算法)
    - [简单选择排序](ch8/simple-selection-sort/README.md#简单选择排序)
    - [堆排序](ch8/heap-sort/README.md#堆排序)
  - [归并排序](ch8/merge-sort/README.md#归并排序)
  - [基数排序](ch8/cardinal-sort/README.md#基数排序)
- [外部排序](ch8/external-sort/README.md#外部排序)
  - [失败树](external-sort/README.md#1-失败树)
  - [置换-选择排序](external-sort/README.md#2-置换-选择排序)
  - [最佳归并树](external-sort/README.md#3-最佳归并树)
