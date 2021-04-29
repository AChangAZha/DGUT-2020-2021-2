#include <stdio.h>
#include <stdlib.h>
int main()
{
    void countFile(FILE *);
    FILE  *fp;
    if((fp = fopen("a.txt", "r")) == NULL)
    { 
        printf("不能打开文件！\n");
    	exit(0);
    }
    countFile(fp);
	if(fclose(fp))
    {
        printf("不能正常关闭文件！\n");
        exit(0);
    }
	return 0;
}
void countFile(FILE *fp)
{
    char ch;
    int a=1,b=0,c=0,d=0,e=0;
    while ((ch=fgetc(fp))!=EOF)
    {
        if(ch=='\n') a++;
        else if(ch>='A' && ch<='Z') b++;
        else if(ch>='a' && ch<='z') c++;
        else if(ch>='0' && ch<='9') d++;
        else e++;
    }
    printf("文本文件的行数：%d\n",a);
    printf("大写字母个数：%d\n",b);
    printf("小写字母个数：%d\n",c);
    printf("数字字符个数：%d\n",d);
    printf("其他字符的个数：%d",e);
}