#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int score;
    struct node *next;
}student;
int main()
{
    student *list1=NULL,*list2=NULL,*p;
    int Insert(student **list);
    student *Add(student *list1,student *list2);
    void Destroy(student **list);
    printf("请输入list1：\n");
    Insert(&list1);
    printf("请输入list2：\n");
    Insert(&list2);
    Add(list1,list2);
    printf("输出新链表：\n");
    for(p=list1;p!=NULL;p=p->next)
    {
        printf("%d ",p->score);
    }
    Destroy(&list1);
    return 1;
}
int Insert(student **list)  /* 实现输入和排序功能 */
{
    student *p,*s=NULL;
    int i=1,x;
    do{
        printf("请输入第%d个学生的成绩或输入-1结束输入：",i);
        scanf("%d",&x);
        if(x==-1) return 1;  /* 输入-1结束输入 */
        if((s=(student *)malloc(sizeof(student)))==NULL)
        {
            printf("不能成功分配储存块！\n");
            exit(0);
        }
        p=*list;  
        if(i==1 || p->score>x)  /* 若输入的成绩小于首节点的成绩，则将新节点插入首节点之前 */
        {
            s->score=x;
		    s->next=p;
		    *list=s; /* 头指针指向新的首结点 */ 
        }
        else  /* 若输入的成绩大于或等于首节点的成绩 */
        {
            while(1)
            {
                if((p->next!=NULL && x<=p->next->score) || p->next==NULL)
                /* 在链表中寻找第一个大于新成绩的节点并将新节点插入其之前，若没找到则插入链尾 */
                {
                    s->score=x;
	    	        s->next=p->next;
                    p->next=s;
                    break;
                }
                p=p->next;
            }
        }
        i++;
    }while(1);
}
student *Add(student *list1,student *list2)
{
    student *p=list1,*q,*min;
    int temp;
    while (p->next!=NULL)
    {
        p=p->next;
    }
    p->next=list2; /* 拼接list1和list2 */
    for(p=list1;p!=NULL;p=p->next) /* 对新链表排序 */
    {
        min=p;
        for(q=p->next;q!=NULL;q=q->next)
        {
            if(q->score<min->score) min=q;
        }
        temp=p->score;
        p->score=min->score;
        min->score=temp;
    }
    return list1;
}
void Destroy(student **list)
{
    student *p,*p1;
    p=*list;
    while (p!=NULL)
    {
        p1=p;
        p=p->next;
        free(p1);
    }
    *list=NULL;
}