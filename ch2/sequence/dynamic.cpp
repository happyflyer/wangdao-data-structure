#include <stdio.h>
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
    free(p);
}

// 插入元素操作，要将元素 e 放到数组 L 下标为 i-1 的位置
bool ListInsert(SeqList &L, int i, int e)
{
    // i 的值必须是合法的位序
    if (i < 1 || i > L.length + 1)
    {
        return false;
    }
    // 如果存储空间已满，则不能插入
    if (L.length >= L.MaxSize)
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

// 删除元素操作
bool ListDelete(SeqList &L, int i, int &e)
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

// 按位查找
int GetElem(SeqList L, int i)
{
    // i 的值必须是合法的位序
    if (i < 1 || i > L.length)
    {
        return false;
    }
    return L.data[i - 1];
}

// 按值查找
int LocateElem(SeqList L, int e)
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

int main()
{
    SeqList L;
    InitList(L);
    // 往顺序表里面插入元素
    ListInsert(L, 1, 1);
    ListInsert(L, 2, 2);
    ListInsert(L, 3, 3);
    ListInsert(L, 4, 4);
    ListInsert(L, 5, 5);
    ListInsert(L, 3, 100);
    // 扩充动态数组长度
    printf("动态数组最大容量为=%d\n", L.MaxSize);
    IncreaseSize(L, 5);
    printf("动态数组最大容量为=%d\n", L.MaxSize);
    // 打印操作
    for (int i = 0; i < L.length; i++)
    {
        printf("data[%d]=%d\n", i, L.data[i]);
    }
    // 测试删除操作
    int e = -1;
    if (ListDelete(L, 5, e))
    {
        printf("已删除的元素值为=%d\n", e);
    }
    else
    {
        printf("位序不合法，删除失败\n");
    }
    // 打印操作
    for (int i = 0; i < L.length; i++)
    {
        printf("data[%d]=%d\n", i, L.data[i]);
    }
    // 测试按位查找
    printf("位序为4的元素值为=%d\n", GetElem(L, 4));
    // 测试按值查找
    printf("元素值为4的元素位序为=%d\n", LocateElem(L, 4));
    return 0;
}
