#include <stdio.h>
int BSearch(int a[],int x,int low,int high)
{
    int mid;
    if(low>high) return -1;
    mid=(low+high)/2;
    if(x==a[mid]) return mid;
    else if(x<a[mid]) return BSearch(a,x,low,mid-1);
    else return BSearch(a,x,mid+1,high);
}
int main()
{
    int a[]={1,2,5,7,9,11,45,46};
    int x=49;
    int bn;
    bn=BSearch(a,x,0,7);
    if (bn==-1) printf("x不在数组中\n");
    else printf("x在a[%d]\n",bn);
}