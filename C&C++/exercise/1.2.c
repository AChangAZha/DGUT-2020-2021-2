#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    char name[10];
    double salary;
    struct node *next;
}staff;
int main()
{
    staff *list=NULL,*p1,*p2=NULL;
    int i=1;
    double sum=0,ave=0,salary;
    char name[10];
    int count_list(staff *list,double x);
    void Destroy(staff **list);
    do{
        printf("请输入第%d个员工的姓名和基本工资(基本工资为0时结束输入)：",i);
        scanf("%s%lf",&name,&salary);
        if(salary==0) break;
        if((p1=(staff *)malloc(sizeof(staff)))==NULL)
        {
            printf("不能成功分配储存块！\n");
            exit(0);
        }
        strcpy(p1->name,name);
        p1->salary=salary;
        p1->next=NULL;
        if(i==1) list=p1;
        else p2->next=p1;
        p2=p1;
        sum=sum+p1->salary;
        i++;   /* 计数器+1 */
    }while(1);
    ave=sum/(i-1);
    printf("超过平均基本工资的人数为%d,平均基本工资为%lf",count_list(list,ave),ave);
    Destroy(&list);
    return 0;
}
int count_list(staff *list,double x)
{
    int count=0;
    staff *p;
    for(p=list;p!=NULL;p=p->next)
    {
        if(p->salary>x) count++;
    }
    return count;
}
void Destroy(staff **list)
{
    staff *p,*p1;
    p=*list;
    while (p!=NULL)
    {
        p1=p;
        p=p->next;
        free(p1);
    }
    *list=NULL;
}