#include <stdio.h>
#define MaxSize 10
typedef struct
{
    int data[MaxSize];
    int length;
} SqList;

// 初始化顺序表，静态分配
void InitList(SqList &L)
{
    // for (int i = 0; i < MaxSize; i++)
    // {
    //     L.data[i] = 0;
    // }
    L.length = 0;
}

// 插入元素操作，要将元素 e 放到数组 L 下标为 i-1 的位置
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

// 删除元素操作
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

// 按位查找
int GetElem(SqList L, int i)
{
    // i 的值必须是合法的位序
    if (i < 1 || i > L.length)
    {
        return false;
    }
    return L.data[i - 1];
}

// 按值查找
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

int main()
{
    SqList L;
    InitList(L);
    ListInsert(L, 1, 1);
    ListInsert(L, 2, 2);
    ListInsert(L, 3, 3);
    ListInsert(L, 4, 4);
    ListInsert(L, 5, 5);
    ListInsert(L, 3, 100);
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
