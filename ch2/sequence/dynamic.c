#include <stdlib.h>
#define InitSize 10
typedef struct
{
    int *data;
    int MaxSize;
    int length;
} SeqList;

// 初始化顺序表，动态分配
void InitList(SeqList &L)
{
    // 用 malloc 函数申请一篇连续的存储空间
    L.data = (int *)malloc(InitSize * sizeof(int));
    L.length = 0;
    L.MaxSize = InitSize;
}

// 增加动态数组的长度
void IncreaseSize(SeqList &L, int len)
{
    int *p = L.data;
    L.data = (int *)malloc((L.MaxSize + len) * sizeof(int));
    for (int i = 0; i < L.length; i++)
    {
        L.data[i] = p[i]; // 时间复杂度高
    }
    L.MaxSize += len;
    free(p)
}

int main()
{
    SeqList L;
    InitList(L);
    // 往顺序表里面插入元素
    IncreaseSize(L, 5);
    return 0;
}
