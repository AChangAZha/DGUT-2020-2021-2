#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE  *fp;     
	int a=0,b=0,c=0,d=0,e=0;
    long num;
	char name[20];
	int score;
    if((fp = fopen("a.txt", "r")) == NULL)
    { 
        printf("Can't Open File!");
    	exit(0);
    }
    while ((fscanf(fp,"%ld%s%d",&num,name,&score))!=EOF)
    {
        printf("%ld %s %d ",num,name,score);
        switch (score/10)
        {
            case 9:a++;printf("A\n");break;
            case 8:b++;printf("B\n");break;
            case 7:c++;printf("C\n");break;
            case 6:d++;printf("D\n");break;
            default:e++;printf("E\n");break;
        }
    }
	fclose(fp);   /* 关闭文件 */
	/* 输出统计结果 */
	printf("等级A的人数：%d    ",a);
	printf("等级B的人数：%d    ",b);
	printf("等级C的人数：%d\n",c);
	printf("等级D的人数：%d    ",d);
	printf("等级E的人数：%d\n",e);
	return 0;
}
