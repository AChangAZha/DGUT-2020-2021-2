/* Brute-Force算法 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DString.h"
int BFIndex(DString S,int start,DString T)
{
    int i=start,j=0,v;
    while (i<S.length && j<T.length)
    {
        if(S.str[i]==T.str[j])
        {
            i++;
            j++;
        }
        else
        {
            i=i-j+1;
            j=0;
        }
    }
    if(j==T.length) v=i-T.length;
    else v=-1;
    return v; 
}
void main()
{
    DString myString1,myString2;
    int max1=29,max2=9;
    int pos=0;
    Initiate(&myString1,max1,"Data Structure Data Structure");
    Initiate(&myString2,max2,"Structure");
    pos=BFIndex(myString1,pos,myString2);
    printf("第一次查早时 pos=%d\n",pos);
    pos=BFIndex(myString1,pos+1,myString2);
    printf("第二次查找时 pos=%d\n",pos);
    Destroy(&myString1);
    Destroy(&myString2);
}