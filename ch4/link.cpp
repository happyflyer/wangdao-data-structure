#include <stdio.h>
#include <stdlib.h>
typedef struct StringNode
{
    char ch;
    struct StringNode *next;
} StringNode, *String;

bool InitString(String &S)
{
    S = (StringNode *)malloc(sizeof(StringNode));
    if (S == NULL)
    {
        return false;
    }
    S->next = NULL;
    return true;
}

int main(int argc, char const *argv[])
{
    String S;
    InitString(S);
    return 0;
}
