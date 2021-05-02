typedef struct GListNode
{
    int tag;
    struct GListNode *tail;
    union
    {
        DataType atom;
        struct GListNode *head;
    }val;
}GLNode2;
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
GLNode2 *CreatGList(char str[])
{
    GLNode2 *h;
    char hstr[200];
    int len=strlen(str);
    if(strcmp(str,"()")==0) h=NULL;
    else h=(GLNode2 *)malloc(sizeof(GLNode2));
    if(len==1)
    {
        h->tag=0;
        h->val.atom=str[0];
        h->tail==NULL;
    }
    else
    {
        DecomposeStr(str,hstr);
        if(strlen(hstr)==1)
        {
            h->tag=0;
            h->val.atom=hstr[0];
        }
        else
        {
            h->tag=1;
            h->val.head=CreatGList(hstr);
        }
        if(strcmp(str,"()")!=0) h->tail=CreatGList(str);
        else h->tail=NULL;
    }
    return h;
}
GLNode2 *GListSearch(GLNode2 *h,DataType x)
{
    GLNode2 *p;
    if(h==NULL) return NULL;
    if(h->tag==0 && h->val.atom==x) return h;
    if(h->tag==0 && h->tail!=NULL)
    {
        p=GListSearch(h->tail,x);
        if(p!=NULL) return p;
    }
    if(h->tag==1 && h->val.head!=NULL)
    {
        p=GListSearch(h->val.head,x);
        if(p!=NULL) return p;
    }
    if(h->tag==1 && h->tail!=NULL)
    {
        p=GListSearch(h->tail,x);
        if(p!=NULL) return p;
    }
    return NULL;
}