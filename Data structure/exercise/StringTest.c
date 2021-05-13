/* 串 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DString.h"
void main()
{
    DString S1, S2;
    int max1 = 10, max2 = 10;
    Initiate(&S1, max1, "latau");
    Initiate(&S2, max1, "latau");
    Compare(S1, S2);
    Destroy(&S1);
    Destroy(&S2);
    // DString myString1,myString2,myString3;
    // int i,max1=5,max2=9,max3=0;
    // Initiate(&myString1,max1,"Data ");
    // Initiate(&myString2,max2,"Structure");
    // Initiate(&myString3,max3," ");
    // printf("初始myString2串：         ");
    // for(i=0;i<myString2.length;i++)
    // {
    //     printf("%c",myString2.str[i]);
    // }
    // printf("    maxLength=%d",myString2.maxLength);
    // printf("    length=%d\n",myString2.length);
    // Insert(&myString2,0,myString1);
    // printf("插入子串后myString2串：   ");
    // for(i=0;i<myString2.length;i++)
    // {
    //     printf("%c",myString2.str[i]);
    // }
    // printf("    maxLength=%d",myString2.maxLength);
    // printf("    length=%d\n",myString2.length);
    // Delete(&myString2,0,5);
    // printf("删除子串后myString2串：   ");
    // for(i=0;i<myString2.length;i++)
    // {
    //     printf("%c",myString2.str[i]);
    // }
    // printf("    maxLength=%d",myString2.maxLength);
    // printf("    length=%d\n",myString2.length);
    // SubString(&myString2,0,5,&myString3);
    // printf("取子串后myString3串：     ");
    // for(i=0;i<myString3.length;i++)
    // {
    //     printf("%c",myString3.str[i]);
    // }
    // printf("    maxLength=%d",myString3.maxLength);
    // printf("    length=%d\n",myString3.length);
    // Destroy(&myString1);
    // Destroy(&myString2);
    // Destroy(&myString3);
}