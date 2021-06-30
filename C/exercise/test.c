#include <stdio.h>
int fun(char *s, char c)
{
    int i = 0, j = 0, n = 0;
    for (i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == c)
        {
            for (j = i + 1; s[j] != '\0'; j++)
                s[j - 1] = s[j];
        }
        else
            n++;
    }
    return n;
}
int main()
{
    int d;
    char s[100];
    char c;
    c = 'a';
    scanf("%s", s);
    d=fun(s, c);
    printf("%s", s);
    printf("%d", d);
}