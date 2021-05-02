#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef char DataType;
#include "GList2.h"
int main()
{
    char str1[]="(((a,b,c),d),e,a,(c,(f,j)),(f))";
    char str2[]="(((a,b,c),d),e,a,(c,(f,j)),(f))";
    char hstr[100];
    GLNode2 *h,*p;
    h=CreatGList(str1);
    DecomposeStr(str2,hstr);
    printf("表头%s\n表尾%s\n",hstr,str2);
    p=GListSearch(h,'l');
    if(p!=NULL) printf("存在\n");
    else printf("不存在\n");
}