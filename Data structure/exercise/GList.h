typedef struct GListNode
{
    int tag;
    union 
    {
        DataType atom;
        struct
        {
            struct GListNode *head;
            struct GListNode *tail;
        }sublist;
    }val;
}GLNode;
void DecomposeStr(char str[],char hstr[])
{
    int i,j,tag,n=strlen(str);
    char ch;
    ch=str[0];tag=0;
    for(i=0;i<=n-1;i++)
    {
        if(str[i]==',' && tag==1) break;
        ch=str[i];
        if(ch=='(') tag++;
        if(ch==')') tag--;
    }
    if(i<=n-1 && str[i]==',')
    {
        for(j=0;j<i-1;j++)
        {
            hstr[j]=str[j+1];
        }
        hstr[j]='\0';
        if(str[i]==',') i++;
        str[0]='(';
        for(j=1;i<=n-2;i++,j++)
        {
            str[j]=str[i];
        }
        str[j]=')';
        str[++j]='\0';
    }
    else
    {
        str++;
        strncpy(hstr,str,n-2);
        hstr[n-2]='\0';
        str--;
        strcpy(str,"()");
    }
}
GLNode* CreatGList(char str[])
{
    GLNode *h;
    char hstr[200];
    int len=strlen(str);
    if(strcmp(str,"()")==0) h=NULL;
    else if(len==1)
    {
        h=(GLNode *)malloc(sizeof(GLNode));
        h->tag=0;
        h->val.atom=str[0];
    }
    else
    {
        h=(GLNode *)malloc(sizeof(GLNode));
        h->tag=1;
        DecomposeStr(str,hstr);
        h->val.sublist.head=CreatGList(hstr);
        if(strcmp(str,"()")!=0) h->val.sublist.tail=CreatGList(str);
        else h->val.sublist.tail=NULL;
    }
    return h;
}
int GListDepth(GLNode *h)
{
    int max,dep;
    GLNode *pre;
    if(h==NULL) return 1;
    if(h->tag==0) return 0;
    pre=h;
    for(max=0;pre!=NULL;pre=pre->val.sublist.tail)
    {
        dep=GListDepth(pre->val.sublist.head);
        if(dep>max) max=dep;
    }
    return max+1;
}
int GListLength(GLNode *h)
{
    int number=0;
    GLNode *p;
    for(p=h;p!=NULL;p=p->val.sublist.tail)
    {
        number++;
    }
    return number;
}
int GListAtomNum(GLNode *h)
{
    if(h==NULL) return 0;
    else
    {
        if(h->tag==0) return 1;
        else return GListAtomNum(h->val.sublist.head)+GListAtomNum(h->val.sublist.tail);
    }
}
GLNode *GListSearch(GLNode *h,DataType x)
{
    GLNode *p;
    if(h==NULL) return NULL;
    if(h->tag==0 && h->val.atom==x) return h;
    if(h->tag==1 && h->val.sublist.head!=NULL)
    {
        p=GListSearch(h->val.sublist.head,x);
        if(p!=NULL) return p;
    }
    if(h->tag==1 && h->val.sublist.tail!=NULL)
    {
        p=GListSearch(h->val.sublist.tail,x);
        if(p!=NULL) return p;
    }
    return NULL;
}
void DestroyGList(GLNode *h)
{
    if(h==NULL) return;
    if(h->tag==1 && h->val.sublist.head!=NULL) DestroyGList(h->val.sublist.head);
    if(h->tag==1 && h->val.sublist.tail!=NULL) DestroyGList(h->val.sublist.tail);
    free(h);
}
void GListPrint(GLNode *h,int n)
{
    int i;
    GLNode *p;
    if(h==NULL) return;
    if(h->tag==0)
    {
        for(i=0;i<n;i++) printf("  ");
        printf("%c\n",h->val.atom);
        return;
    }
    for(p=h;p!=NULL;p=p->val.sublist.tail)
    {
        GListPrint(p->val.sublist.head,n+1);
    }
}