#include <stdio.h>
#include <stdlib.h>

int main()
{
    char meu_time[8];
    fgets(meu_time, 8, stdin);
    printf("%s\n", meu_time);
    return 0;
}
