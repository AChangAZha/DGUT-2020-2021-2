/* 串 */
typedef struct
{
    char *str;
    int maxLength;
    int length;
}DString;
void Initiate(DString *S,int max,char *string)
{
    int i;
    S->str=(char *)malloc(sizeof(char)*max);
    S->maxLength=max;
    S->length=strlen(string);
    for(i=0;i<S->length;i++)
    {
        S->str[i]=string[i];
    }
}
int Insert(DString *S,int pos,DString T)
{
    int i;
    if(pos<0)
    {
        printf("参数pos出错！");
        return 0;
    }
    else
    {
        if(S->length+T.length>S->maxLength)
        {
            realloc(S->str,(S->length+T.length)*sizeof(char));
            S->maxLength=S->length+T.length;
        }
        for(i=S->length-1;i>=pos;i--)
        {
            S->str[i+T.length]=S->str[i];
        }
        for(i=0;i<T.length;i++)
        {
            S->str[pos+i]=T.str[i];
        }
        S->length+=T.length;
        return 1;
    }
}
int Delete(DString *S,int pos,int len)
{
    int i;
    if(S->length<=0)
    {
        printf("数组中未存放字符无元素可删！\n");
        return 0;
    }
    else if(pos<0 || len<0 || pos+len>S->length)
    {
        printf("参数pos和len不合法");
        return 0;
    }
    else
    {
        for(i=pos+len;i<=S->length-1;i++)
        {
            S->str[i-len]=S->str[i];
        }
        S->length=S->length-len;
        return 1;
    }
}
int SubString(DString *S,int pos,int len,DString *T)
{
    int i;
    if(pos<0 || len<0 || pos+len>S->length)
    {
        printf("参数pos和len出错！");
        return 0;
    }
    if(len>T->maxLength)
    {
        T->str=(char *)malloc(len*sizeof(char));
        T->maxLength=len;
    }
    for(i=0;i<len;i++)
    {
        T->str[i]=S->str[pos+i];
    }
    T->length=len;
    return 1;
}
void Compare(DString S,DString T)
{
    int i=0;
    while (i<S.length && i<T.length)
    {
        if(S.str[i]<T.str[i])
        {
            printf("小于\n");
            break;
        }
        if(S.str[i]>T.str[i])
        {
            printf("大于\n");
            break;
        }
        i++;
    }
    if(i==S.length || i==T.length)
    {
        if(i!=T.length) printf("小于\n");
        else if(i!=S.length) printf("大于\n");
        else printf("等于\n");
    }
}
void Destroy(DString *S)
{
    free(S->str);
    S->maxLength=0;
    S->length=0;
}
