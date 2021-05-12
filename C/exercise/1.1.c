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
    double salary,max;
    char name[10];
    double max_list(staff *list);
    void Destroy(staff **list);
    do{
        printf("请输入第%d个员工的姓名和基本工资(基本工资为0时结束输入)：",i);
        scanf("%s%lf",name,&salary);
        if(salary==0) break;   /* 输入基本工资为0时输入结束 */
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
        i++;
    }while(1);
    max=max_list(list);
    printf("最高基本工资的职工信息：\n");
    for(p1=list;p1!=NULL;p1=p1->next)
    {
        if(p1->salary==max) printf("姓名：%s 基本工资：%lf\n",p1->name,p1->salary);
    }
    Destroy(&list);
    return 0;
}
double max_list(staff *list)
{
    staff *p;
    double max;
    max=list->salary;
    for(p=list->next;p!=NULL;p=p->next)
    {
        if(p->salary>max)
        max=p->salary;
    }
    return max;
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