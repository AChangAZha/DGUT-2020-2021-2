#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a;
    while (1)
    {
        scanf("%d", &a);
        printf("%d", a % 11);
    }
}
