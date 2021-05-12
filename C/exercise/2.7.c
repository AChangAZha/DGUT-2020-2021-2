#include <stdio.h> 
#include <stdlib.h> 
#define size sizeof(struct Student)
struct Student{		/* 学生结构体 */ 
	long num;		/* 学号 */ 
	char name[20];	/* 姓名 */ 
	int score;		/* 成绩 */ 
};
int main() 
{ 
    void FileCreate(FILE *fp); /* 创建文件函数(数据按成绩升序排列) */
    void FilePrint(FILE *fp); /* 输出文件内容函数 */
    void mergeFile(FILE *fp1,FILE *fp2,FILE *fp3); /* 归并文件函数 */
	FILE *fp1,*fp2,*fp3;
    int i;
	if((fp1=fopen("a1.dat","wb"))==NULL){ /* 以写方式打开文件a1.dat */ 
		printf("Can't Open File!"); 
		exit(0); 
	} 
    if((fp2=fopen("a2.dat","wb"))==NULL){ /* 以写方式打开文件a2.dat */ 
		printf("Can't Open File!"); 
		exit(0); 
	} 
	printf("输入若干包括学号、姓名和成绩保存到a1.dat中（以负数成绩结束输入）：\n"); 
    FileCreate(fp1);
    fclose(fp1); /* 关闭a1.dat */
    printf("-----------------------------------------------------------------\n");
    printf("输入若干包括学号、姓名和成绩保存到a2.dat中（以负数成绩结束输入）：\n"); 
    FileCreate(fp2);
    fclose(fp2); /* 关闭a2.dat */
    printf("-----------------------------------------------------------------\n");
    if((fp1=fopen("a1.dat","rb"))==NULL){ /* 以读方式打开文件a1.dat */ 
		printf("Can't Open File!"); 
		exit(0); 
	} 
    if((fp2=fopen("a2.dat","rb"))==NULL){ /* 以读方式打开文件a2.dat */ 
		printf("Can't Open File!"); 
		exit(0); 
	} 
    if((fp3=fopen("a3.dat","wb"))==NULL){ /* 以写方式打开文件a3.dat */ 
		printf("Can't Open File!"); 
		exit(0); 
	} 
    mergeFile(fp1,fp2,fp3); /* 归并a1.dat和a2.dat到a3.dat */
    fclose(fp3); /* 关闭a3.dat */
    rewind(fp1); 
    rewind(fp2);
    if((fp3=fopen("a3.dat","rb"))==NULL){ /* 以读方式打开文件d3.dat */ 
		printf("Can't Open File!"); 
		exit(0); 
	}
	printf("输出a1.dat内容如下：\n"); 
    FilePrint(fp1);
    printf("-----------------------------------------------------------------\n");
    printf("输出a2.dat内容如下：\n"); 
    FilePrint(fp2);
    printf("-----------------------------------------------------------------\n");
    printf("将a1.dat和a2.dat归并到a3.dat，输出a3.dat内容如下：\n"); 
    FilePrint(fp3);
    /* 关闭所有文件 */
    fclose(fp1); 
    fclose(fp2);
    fclose(fp3);
	return 0;
}
void FileCreate(FILE *fp) /* 创建 */
{
    struct Student *stu=NULL; /* 动态结构体数组，初始化为NULL */
    struct Student temp;
    int i,j,n=0; /* n为数组长度 */
    do
    {
        scanf("%ld%s%d",&temp.num,temp.name,&temp.score);
        if(temp.score<0) break; /* 以负数成绩表示输入结束 */
        /* 使用realloc函数更改stu存储块的大小 */
        stu=(struct Student*)realloc(stu,size*(n+1));
        for(i=0;i<n;i++)
        {
            /* 在原结构体数组中寻找第一个成绩大于新输入的成绩的元素 */
            if(stu[i].score>temp.score) break;
        }
        for(j=n;j>i;j--) /* 后移 */
        {
            stu[j]=stu[j-1];
        }
        stu[i]=temp; /* 插入 */
        n++; /*  */
    } while (1);
    fwrite(stu,size,n,fp); /* 将结构体数组写入文件 */
    free(stu); /* 释放结构体数组 */
}
void FilePrint(FILE *fp) /* 输出 */
{
    struct Student temp;
    while(fread(&temp,size,1,fp))
	{
		printf("%ld %s %d\n",temp.num,temp.name,temp.score);
	}
}
void mergeFile(FILE *fp1,FILE *fp2,FILE *fp3) /* 归并 */
{
    struct Student *stu1=NULL,*stu2=NULL; /* 动态结构体数组，初始化为NULL */
    struct Student temp;
    /* len1和len2分别为两数组的长度；a,b初始指向两数组第一个元素 */
    int len1=0,len2=0,a=0,b=0;
    /* 读a1.dat和a2.dat，将数据保存在两个数组中 */
    while(fread(&temp,size,1,fp1))
	{
        stu1=(struct Student*)realloc(stu1,size*(len1+1));
		stu1[len1]=temp;
        len1++;
	}   
    while(fread(&temp,size,1,fp2))
	{
        stu2=(struct Student*)realloc(stu2,size*(len2+1));
		stu2[len2]=temp;
        len2++;
	}
    /* 两数组已经按成绩升序排序 */
    while (a<len1 && b<len2)
    {
        /* 从两个数组的第一个元素开始比较大小 */
        if(stu1[a].score<stu2[b].score)
        {
            /* 较小者写入文件a3.dat */
            fwrite(&stu1[a],size,1,fp3);
            a++; /* a后移,b不动,继续比较 */
        }
        else
        {
            fwrite(&stu2[b],size,1,fp3);
            b++; /* b后移,a不动 */
        }
    }
    /* 若上述循环结束后stu1或stu2中还有未写入a3.dat中的元素，将其依次写入 */
    if(a<len1)
    {
        while (a<len1)
        {
            fwrite(&stu1[a],size,1,fp3);
            a++;
        }
    }
    if(b<len2)
    {
        while (b<len2)
        {
            fwrite(&stu2[b],size,1,fp3);
            b++;
        }
    }
    free(stu1);
    free(stu2);
}