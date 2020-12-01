#include <stdio.h>
#define MaxSize 10
typedef struct
{
    int data[MaxSize];
    int top; // 栈顶指针
} SqStack;

// 初始化栈
void InitStack(SqStack &S)
{
    S.top = -1;
}

// 判断栈空
bool StackEmpty(SqStack S)
{
    return S.top == -1;
}

// 判断栈满
bool StackFull(SqStack S)
{
    return S.top == MaxSize - 1;
}

// 进栈
bool Push(SqStack &S, int x)
{
    if (StackFull(S))
    {
        return false;
    }
    // S.top++;
    // S.data[S.top] = x;
    S.data[++S.top] = x;
    return true;
}

// 出栈，数据还残留在内存中，只是逻辑上被删除了
bool Pop(SqStack &S, int &x)
{
    if (StackEmpty(S))
    {
        return false;
    }
    // x = S.data[S.top];
    // S.top--;
    x = S.data[S.top--];
    return true;
}

// 读取栈顶元素
bool GetTop(SqStack &S, int &x)
{
    if (StackEmpty(S))
    {
        return false;
    }
    x = S.data[S.top];
    return true;
}

int main()
{
    SqStack S;
    InitStack(S);
    Push(S, 1);
    Push(S, 2);
    Push(S, 3);
    Push(S, 4);
    Push(S, 5);
    // 打印操作
    int i = S.top;
    while (i > -1)
    {
        printf("%d\n", S.data[i--]);
    }
    int x;
    Pop(S, x);
    // printf("%d\n", x);
    // 打印操作
    i = S.top;
    while (i > -1)
    {
        printf("%d\n", S.data[i--]);
    }
    return 0;
}
