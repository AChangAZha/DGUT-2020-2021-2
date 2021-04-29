#include <stdio.h> 
#include <stdlib.h> 
struct Student{		/* 学生结构体 */ 
	long num;		/* 学号 */ 
	char name[20];	/* 姓名 */ 
	int score;		/* 成绩 */ 
};
int main() 
{ 
	FILE *fp;			/* 文件指针 */ 
	struct Student stu; /* 结构变量 */ 
	if((fp=fopen("a.dat","wb"))==NULL){ /* 以写方式打开文件 */ 
		printf("Can't Open File!"); 
		exit(0); 
	} 
	printf("输入若干包括学号、姓名和成绩（以负数成绩结束输入）：\n"); 
	do
	{
		scanf("%ld%s%d",&stu.num,stu.name,&stu.score);
		if(stu.score<0) break;
		fwrite(&stu,sizeof(stu),1,fp);
	} while (1);
	fclose(fp); /* 关闭文件 */ 
	if((fp=fopen("a.dat","rb"))==NULL){ /* 以读方式打开文件 */ 
		printf("Can't Open File!"); 
		exit(0); 
	} 
	printf("输出文件内容如下：\n"); 
	while(fread(&stu,sizeof(stu),1,fp))
	{
		printf("%ld %s %d\n",stu.num,stu.name,stu.score);
	}
	fclose(fp);
	return 0; 
}