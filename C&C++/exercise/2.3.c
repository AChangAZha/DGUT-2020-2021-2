#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE  *fp1,*fp2;
	char ch1,ch2;
    /* a1,a2分别用于当前读取字符位置,b1,b2分别表示两个文本的行数,flag用于判断两文本内容是否相同 */
    int a1=0,a2=0,b1=1,b2=1,flag=0;
    if((fp1 = fopen("a1.txt", "r")) == NULL)
    { 
        printf("不能打开文件a1.txt！\n");
    	exit(0);
    }
    if((fp2 = fopen("a2.txt", "r")) == NULL)
    { 
        printf("不能打开文件a2.txt！\n");
    	exit(0);
    }
    /* 仅判断文件内容是否相同，不比较文件的形式，若遇换行符则跳过 */
    do
    {
        /* 分别读取两个文本的一个字符，并记录字符位置 */
        ch1=fgetc(fp1);
        ch2=fgetc(fp2);
        a1++;
        a2++;
        if(ch1=='\n' && ch2=='\n') /* 若同时读到两个本文的换行符 */
        {
            /* 行数+1，位置重置为0 */
            b1++;
            b2++;
            a1=0;
            a2=0;
        }
        /* 若读到其中一个文本的换行符 */
        else if(ch1=='\n' && ch2!='\n')
        {
            /* 跳过换行符，直到读取到非换行符的字符 */
            do
            {
                ch1=fgetc(fp1);
                b1++; /* 行数+1 */
            } while (ch1=='\n');
            a1=1; /* 位置变为1 */
        }
        else if(ch2=='\n' && ch1!='\n')
        {
            do
            {
                ch2=fgetc(fp2);
                b2++;
            } while (ch2=='\n');
            a2=1;
        }
        if(ch1!=ch2) /* 判断两个字符是否相等 */
        {
            flag=1; /* 标记flag=1 */
            break; /* 跳出循环 */
        }
    }while(ch1!=EOF && ch2!=EOF); /* 读取到其中一个文件的末尾时循环结束 */
    if (flag==0) /* 判断两个文本内容是否相同 */
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
        if(ch1!=EOF && ch2==EOF) 
            printf("两个文件内容首次不同位于a1.txt第%d行第%d个位置\n",b1,a1);
        /* 例如：a1.txt: 123和a2.txt: 12,仅输出a1.txt的字符位置 */
        else if(ch2!=EOF && ch1==EOF) printf("两个文件内容首次不同位于a2.txt第%d行第%d个位置\n",b2,a2);
        /* 例如：a1.txt: 12和a2.txt: 123,仅输出a2.txt的字符位置 */
        else printf("两个文件内容首次不同位于a1.txt第%d行第%d个位置，a2.txt第%d行第%d个位置\n",b1,a1,b2,a2);
        /* 例如：a1.txt: 123和a2.txt: 1\n13,由于换行符不参与文件内容的比较，输出两个文件的字符位置可能不同 */
    }
	if(fclose(fp1))
    {
        printf("不能正常关闭文件a1.txt！\n");
        exit(0);
    }
    if(fclose(fp2))
    {
        printf("不能正常关闭文件a2.txt！\n");
        exit(0);
    }
	return 0;
}