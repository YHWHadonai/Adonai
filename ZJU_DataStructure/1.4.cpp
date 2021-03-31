#include<stdio.h>
#define MAXSIZE 100005
int main()
{
    int Data[MAXSIZE],Next[MAXSIZE],list[MAXSIZE],firstadd,n,k;
    scanf("%d %d %d",&firstadd,&n,&k);
    for(int i=0;i<n;i++)
    {
        int tempadd,tempdata,tempnext;
        scanf("%d %d %d",&tempadd,&tempdata,&tempnext);
        Data[tempadd]=tempdata;
        Next[tempadd]=tempnext;
    }
    int sum=0;
    while(firstadd!=-1)
    {
        list[sum++]=firstadd;
        firstadd=Next[firstadd];
    }
    for(int i=0;i<sum-sum%k;i+=k)
        for(int j=0;j<k/2;j++)
        {
            int t=list[i+j];
            list[i+j]=list[i+k-j-1];
            list[i+k-j-1]=t;
        }
    for(int i=0;i<sum-1;i++)
        printf("%05d %d %05d\n",list[i],Data[list[i]],list[i+1]);
    printf("%05d %d -1\n",list[sum-1],Data[list[sum-1]]);
    return 0;        
}