/* 括号匹配 */
#include <string.h>
#include <stdio.h>
#define MaxStackSize 100
typedef char DataType;
#include "SeqStack.h"
void ExpIsCorrect(char exp[],int n)
{
    SeqStack myStack;
    int i;
    char c;
    StackInitiate(&myStack);
    for(i=0;i<n;i++)
    {
        if((exp[i]=='(') || (exp[i]=='[') || (exp[i]=='{')) StackPush(&myStack,exp[i]);
        else if(exp[i]==')' && StackNotEmpty(myStack) && StackTop(myStack,&c) && c=='(') StackPop(&myStack,&c);
        else if(exp[i]==')' && StackNotEmpty(myStack) && StackTop(myStack,&c) && c!='(')
        {
            printf("左右括号配对次序不正确！\n");
            return;
        }
        else if(exp[i]==']' && StackNotEmpty(myStack) && StackTop(myStack,&c) && c=='[') StackPop(&myStack,&c);
        else if(exp[i]==']' && StackNotEmpty(myStack) && StackTop(myStack,&c) && c!='[')
        {
            printf("左右括号配对次序不正确！\n");
            return;
        }
        else if(exp[i]=='}' && StackNotEmpty(myStack) && StackTop(myStack,&c) && c=='{') StackPop(&myStack,&c);
        else if(exp[i]=='}' && StackNotEmpty(myStack) && StackTop(myStack,&c) && c!='{')
        {
            printf("左右括号配对次序不正确！\n");
            return;
        }
        else if(((exp[i]==')') || (exp[i]==']') || (exp[i]=='}')) && !StackNotEmpty(myStack))
        {
            printf("右括号多于左括号！\n");
            return;
        }
        int j;
        /* for(j=0;j<myStack.top;j++)
        {
            printf("%c",myStack.stack[j]);
        }
        printf("\n"); */
    }
    if(StackNotEmpty(myStack)) printf("左括号多于右括号！\n");
    else printf("左右括号匹配正确！\n");
}
void main()
{
    char a[100];
    while (1)
    {
        scanf("%s",&a);
        if(strcmp(a,"END")==0) break;
        int n=strlen(a);
        ExpIsCorrect(a,n);
    }
}