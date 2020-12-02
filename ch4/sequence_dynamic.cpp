#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 255
typedef struct
{
    char *ch;
    int length;
} HString;

void InitString(HString &S)
{
    S.ch = (char *)malloc(MAXLEN * sizeof(char));
    S.length = 0;
}

int main(int argc, char const *argv[])
{
    HString S;
    InitString(S);
    return 0;
}
