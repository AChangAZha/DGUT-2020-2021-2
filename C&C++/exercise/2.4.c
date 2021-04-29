#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE  *fp;
    long num;
	char name[20];
	int score;
    if((fp = fopen("a.txt", "w")) == NULL){ 
        printf("Can't Open File!");
    	exit(0);
    }
	printf("输入若干包括学号、姓名和成绩（以负数结束）：\n");
	scanf("%ld%s%d",&num,name,&score); 
    while (score>=0)
    {
        fprintf(fp,"%ld %s %d\n",num,name,score);
        scanf("%ld%s%d",&num,name,&score);
    }
	fclose(fp);   /* 关闭文件 */
    if((fp = fopen("a.txt", "r")) == NULL){ 
        printf("Can't Open File!");
    	exit(0);
    }
	printf("输出文件内容如下：\n");
	fscanf(fp,"%ld%s%d",&num,name,&score);
    do
    {
        printf("%ld %s %d\n",num,name,score);
    } while ((fscanf(fp,"%ld%s%d",&num,name,&score))!=EOF);
	fclose(fp);   /* 关闭文件 */
	return 0;
}