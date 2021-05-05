#include <stdio.h>
#include <stdlib.h>
#define MaxValue 10000
#define MaxBit 6
#include "Haffman.h"
int main()
{
    int i,j,n=4;
    if(n>MaxBit)
    {
        printf("error!");
        return 0;
    }
    int weight[]={3,1,5,7};
    HaffNode *myHaffTree=(HaffNode *)malloc(sizeof(HaffNode)*(2*n-1));
    Code *myHaffCode=(Code *)malloc(sizeof(Code)*n);
    Haffman(weight,n,myHaffTree);
    HaffmanCode(myHaffTree,n,myHaffCode);
    for(i=0;i<n;i++)
    {
        printf("Weight=%d,Code=",myHaffCode[i].weight);
        for(j=myHaffCode[i].start;j<n;j++)
        {
            printf("%d",myHaffCode[i].bit[j]);
        }
        printf("\n");
    }
}