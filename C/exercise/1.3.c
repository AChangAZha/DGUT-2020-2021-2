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
    double n,salary;
    char name[10];
    staff *del_list(staff *list,double n);
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
        i++;
    }while(1);
    printf("输入一个给定基本工资：");
    scanf("%lf",&n);
    printf("删除后的链表:\n");
    list=del_list(list,n);
    for(p1=list;p1!=NULL;p1=p1->next)
    {
        printf("姓名：%s 基本工资：%lf\n",p1->name,p1->salary);
    }
    Destroy(&list);
    return 0;
}
staff *del_list(staff *list,double n)
{
    staff *p1,*p2;
    p1=list;
    while(p1->salary==n)
	{
		p2=p1;
		p1=p1->next;
		free(p2);
        list=p1;
    }  /* 若首节点是被删节点，删除首节点，直至新的首节点不是被删节点 */
    while(p1->next!=NULL)/* 当前p1指向首节点，且首节点不是被删节点 */
    {
        if(p1->next->salary==n)
        {
            p2=p1->next;
            p1->next=p1->next->next;
            free(p2);
            continue;
        }
        p1=p1->next;
    }
    return list;
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