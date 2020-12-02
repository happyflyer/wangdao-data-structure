#include <stdio.h>
#define MAXLEN 255
typedef struct
{
    char ch[MAXLEN];
    int length;
} SString;

void InitString(SString &S)
{
    S.length = 0;
}

// 求串长
int StrLength(SString S)
{
    return S.length;
}

// 求子串
bool SubString(SString &Sub, SString S, int pos, int len)
{
    // 子串范围越界
    if (pos + len - 1 > S.length)
    {
        return false;
    }
    for (int i = pos; i < pos + len; i++)
    {
        Sub.ch[i - pos + 1] = S.ch[i];
    }
    Sub.length = len;
    return true;
}

// 比较操作
int StrCompare(SString S, SString T)
{
    for (int i = 1; i <= S.length && i <= T.length; i++)
    {
        if (S.ch[i] != T.ch[i])
        {
            return S.ch[i] - T.ch[i];
        }
    }
    // 扫描过所有字符都相同，则长度长的串更大
    return S.length - T.length;
}

// 定位操作
int Index(SString S, SString T)
{
    int i = 1, n = StrLength(S), m = StrLength(T);
    SString sub;
    while (i <= n - m + 1)
    {
        SubString(sub, S, i, m);
        if (StrCompare(sub, T) != 0)
        {
            ++i;
        }
        else
        {
            return i;
        }
    }
    return 0;
}

// 定位操作
int Index2(SString S, SString T)
{
    int k = 1; // 记录主串中的匹配开始位置
    int i = k, j = 1;
    while (i <= S.length && j <= T.length)
    {
        if (S.ch[i] == T.ch[j])
        {
            ++i;
            ++j;
        }
        else
        {
            k++;
            i = k;
            j = 1;
        }
    }
    if (j > T.length)
    {
        return k;
    }
    else
    {
        return 0;
    }
}

// 求模式串 T 的 next 数组
void get_next(SString T, int next[])
{
    int i = 1, j = 0;
    next[1] = 0;
    while (i < T.length)
    {
        if (j == 0 || T.ch[i] == T.ch[j])
        {
            ++i;
            ++j;
            // 若 pi=pj，则 next[j+1]=next[j]+1
            next[i] = j;
        }
        else
        {
            // 否则令 j=next[j]，循环继续
            j = next[j];
        }
    }
}

// KMP 算法
int Index_KMP(SString S, SString T)
{
    int i = 1, j = 1;
    int next[T.length + 1];
    get_next(T, next); // 时间复杂度：$O(m)$
    while (i <= S.length && j <= T.length) // 时间复杂度：$O(n)$
    {
        if (j == 0 || S.ch[i] == T.ch[j])
        {
            ++i;
            ++j;
        }
        else
        {
            j = next[j];
        }
    }
    if (j > T.length)
    {
        return i - T.length;
    }
    else
    {
        return 0;
    }
}

int main(int argc, char const *argv[])
{
    SString S;
    InitString(S);
    return 0;
}
