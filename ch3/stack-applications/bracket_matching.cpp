#include <stdio.h>
#include <string>
#define MaxSize 10
typedef struct
{
    char data[MaxSize];
    int top;
} SqStack;

void InitStack(SqStack &S)
{
    S.top = -1;
}

bool StackEmpty(SqStack S)
{
    return S.top == -1;
}

bool StackFull(SqStack S)
{
    return S.top == MaxSize - 1;
}

bool Push(SqStack &S, char x)
{
    if (StackFull(S))
    {
        return false;
    }
    S.data[++S.top] = x;
    return true;
}

bool Pop(SqStack &S, char &x)
{
    if (StackEmpty(S))
    {
        return false;
    }
    x = S.data[S.top--];
    return true;
}

bool GetTop(SqStack &S, char &x)
{
    if (StackEmpty(S))
    {
        return false;
    }
    x = S.data[S.top];
    return true;
}

bool bracketCheck(char str[], int length)
{
    SqStack S;
    InitStack(S);
    for (int i = 0; i < length; i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            Push(S, str[i]);
        }
        else
        {
            if (StackEmpty(S))
            {
                return false;
            }
            char topElem;
            Pop(S, topElem);
            if (str[i] == ')' && topElem != '(')
            {
                return false;
            }
            if (str[i] == ']' && topElem != '[')
            {
                return false;
            }
            if (str[i] == '}' && topElem != '{')
            {
                return false;
            }
        }
    }
    return StackEmpty(S);
}

int main()
{
    char c[MaxSize + 1] = {"({([])}[])"};
    printf("%d\n", bracketCheck(c, MaxSize));
    return 0;
}
