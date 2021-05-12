#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE  *fp;
    int i;
    char a[10][50];
    char s[50];
    if((fp = fopen("a.txt", "w")) == NULL){ 
        printf("Can't Open File!");
    	exit(0);
    }
	printf("输入10个英文单词\n");
	for(i=0;i<10;i++)
    {
        scanf("%s",a[i]);
        fprintf(fp,"%s ",a[i]);
    }
	fclose(fp);   /* 关闭文件 */
    if((fp = fopen("a.txt", "r")) == NULL){ 
        printf("Can't Open File!");
    	exit(0);
    }
	printf("输出文件内容如下：\n");
    while ((fscanf(fp,"%s",s))!=EOF)
    {
        printf("%s ",s);
    }
	fclose(fp);   /* 关闭文件 */
	return 0;
}