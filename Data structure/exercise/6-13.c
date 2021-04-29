#include <stdio.h>
void fun1(int n)
{
    int i;
    if(n>1) fun1(n-1);
    for(i=1;i<=n;i++)
    {
        printf("%d ",n);
    }
    printf("\n");
}
void fun2(int n)
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)
        {
            printf("%d ",i);
        }   
        printf("\n");
    }
}
int main()
{
    fun1(1000);
}