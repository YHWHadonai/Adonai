#include<stdio.h>
void search(int a[],int n)
{
    int thissum,maxsum=a[0]-1,c1,c2;
    for(int i=0;i<n;i++)
    {   
        thissum=0;
        for(int j=i;j<n;j++)
        {
            thissum+=a[j];
            if(thissum>maxsum)
            {
                maxsum=thissum;
                c1=i;
                c2=j;
            }
        }
    }
    if(maxsum<0){
        maxsum=0;
        c1=0;c2=n-1;
    }
    printf("%d %d %d",maxsum,a[c1],a[c2]);
}
int main()
{
    int n,a[10000];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    search(a,n);
}