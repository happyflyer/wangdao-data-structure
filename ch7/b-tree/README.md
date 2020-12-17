# B 树

![B树1](b-tree1.png)

![B树2](b-tree2.png)

![B树3](b-tree3.png)

![B树4](b-tree4.png)

## 1. 插入

![B树5](b-tree5.png)

### 1.1. 直接插入

![B树6](b-tree6.png)

### 1.2. 向上分裂

![B树7](b-tree7.png)

![B树8](b-tree8.png)

![B树9](b-tree9.png)

![B树10](b-tree10.png)

## 2. 删除

![B树11](b-tree11.png)

### 2.1. 终端结点

![B树12](b-tree12.png)

- 直接删除。

![B树13](b-tree13.png)

- 兄弟够借。

![B树14](b-tree14.png)

![B树15](b-tree15.png)

- 兄弟不够借。

![B树16](b-tree16.png)

![B树17](b-tree17.png)

### 2.2. 非终端结点

![B树18](b-tree18.png)

- 删除前驱节点的最大值。

![B树19](b-tree19.png)

![B树20](b-tree20.png)

- 删除后继结点的最小值。

![B树21](b-tree21.png)

![B树22](b-tree22.png)

- 合并子结点。

![B树23](b-tree23.png)

![B树24](b-tree24.png)
