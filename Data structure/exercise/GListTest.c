#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char DataType;
#include "GList.h"

int main()
{
    char str1[]="(((a,b,c),d),e,a,(c,(f,j)),(f))";
    char str2[]="(((a,b,c),d),e,a,(c,(f,j)),(f))";
    char hstr[100];
    GLNode *h,*p;
    int depth,number,length;
    h=CreatGList(str1);
    DecomposeStr(str2,hstr);
    printf("表头%s\n表尾%s\n",hstr,str2);
    depth=GListDepth(h);
    printf("深度=%d\n",depth);
    length=GListLength(h);
    printf("长度=%d\n",length);
    number=GListAtomNum(h);
    printf("原子个数=%d\n",number);
    p=GListSearch(h,'p');
    if(p!=NULL) printf("存在\n");
    else printf("不存在\n");
    GListPrint(h,0);
    DestroyGList(h);
    return 0;
}