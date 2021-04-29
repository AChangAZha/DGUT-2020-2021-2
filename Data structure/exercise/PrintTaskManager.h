/* 打印任务管理器 */
typedef struct node
{
    int id;
    char *text;
    struct node *next;
}Task;
typedef struct
{
    Task *front;
    Task *rear;
}Queue;
void InitaskManager(Queue *taskmanager)
{
    taskmanager->front=taskmanager->rear=NULL;
}
void AppendPrintTask(Queue *taskmanager,int tid,char *text)
{
    Task *p;
    p=(Task *)malloc(sizeof(Task));
    p->text=(char *)malloc((strlen(text)+1));
    strcpy(p->text,text);
    p->id=tid;
    p->next=NULL;
    if(taskmanager->rear!=NULL) taskmanager->rear->next=p;
    taskmanager->rear=p;
    if(taskmanager->front==NULL) taskmanager->front=p;
}
int PrintFirstTask(Queue *taskmanager)
{
    Task *p=taskmanager->front;
    if(p==NULL) return 0;
    else
    {
        printf("Task id:%d\n",p->id);
        printf("Task context:%s\n",p->text);
    }
    taskmanager->front=taskmanager->front->next;
    if(taskmanager->front==NULL) taskmanager->rear=NULL;
    free(p->text);
    free(p);
    return 1;
}
void PrintAllTask(Queue *taskmanager)
{
    Task *p=taskmanager->front;
    while(p!=NULL)
    {
        printf("Task id:%d\n",p->id);
        printf("Task context:%s\n",p->text);
        p=p->next;
    }
}
void ClearPrintTask(Queue taskmanager)
{
    Task *p,*p1;
    p=taskmanager.front;
    while(p!=NULL)
    {
        p1=p;
        p=p->next;
        free(p1->text);
        free(p1);
    }
}