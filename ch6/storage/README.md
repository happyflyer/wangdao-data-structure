# 图的存储结构

## 1. 邻接矩阵法

- $V=\{A,B,C,D,E\}$ 用一维数组存储。
- $E=\{(A,B),(A,C),(A,E),(B,C),(C,D),(C,E)\}$ 用二维数组存储。

二维数组行号表示起始端点，列号表示终止端点，值表示该边是否存在或该边的权重。二维数组又称为邻接矩阵。

结点数为 $n$ 的图 $G=(V,E)$ 的邻接矩阵是 $n \times n$ 的。

将 $G$ 的顶点编号为 $V_1,V_2,...,V_n$ （数组下标），若 $<V_i,V_j> \in E$，则 $A[i][j]=1$，否则 $A[i][j]=0$。

$$
A[i][j]=
\begin{cases}
  1,(V_i,V_j)或<V_i,V_j>是E(G)的边\\
  0,(V_i,V_j)或<V_i,V_j>不是E(G)的边\\
\end{cases}
$$

![邻接矩阵1](adjacency-matrix1.jpg)

![邻接矩阵2](adjacency-matrix2.jpg)

![邻接矩阵3](adjacency-matrix3.jpg)

![邻接矩阵4](adjacency-matrix4.jpg)

![邻接矩阵5](adjacency-matrix5.jpg)

![邻接矩阵5-2](adjacency-matrix5-2.jpg)

![邻接矩阵5-3](adjacency-matrix5-3.jpg)

- 邻接矩阵法的空间复杂度为：$O(n^2)$，适用于稠密图。
- 无向图的邻接矩阵为对称矩阵。
- 无向图中第 $i$ 行（或第 $i$ 列）非 $0$ 元素（非正无穷）的个数为第 $i$ 个顶点的度。
- 有向图中第 $i$ 行（第 $i$ 列）非 $0$ 元素（非正无穷）的个数为第 $i$ 个顶点的出度（入度）。

![邻接矩阵6](adjacency-matrix6.jpg)

![邻接矩阵7](adjacency-matrix7.jpg)

## 2. 邻接表法

邻接矩阵法存储稀疏图会有很多空间浪费。

![邻接表1](adjacency-list1.jpg)

![邻接表2](adjacency-list2.jpg)

![邻接表3](adjacency-list3.jpg)

![邻接表4](adjacency-list4.jpg)

![邻接表5](adjacency-list5.jpg)

![邻接表6](adjacency-list6.jpg)

## 3. 十字链表

在邻接表中寻找所有的出边（以该顶点为弧尾的弧）非常容易，但是寻找某个顶点的入边非常困难，需要遍历整个边表。

![十字链表1](cross-list1.jpg)

![十字链表2](cross-list2.jpg)

![十字链表3](cross-list3.jpg)

## 4. 邻接多重表

![邻接多重表1](adjacency-multiple-list1.jpg)

![邻接多重表2](adjacency-multiple-list2.jpg)

![邻接多重表3](adjacency-multiple-list3.jpg)

![邻接多重表4](adjacency-multiple-list4.jpg)
