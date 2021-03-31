#include<stdio.h>
int main()
{
    int maxsize1(int a[],int n);
    int maxsize2(int a[],int n);
    int maxsize3(int a[],int n);
    int n,a[10000],max1,max2,max3;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    max1 = maxsize1(a,n);
    max2 = maxsize2(a,n);
    max3 = maxsize3(a,n);
    printf("%d",max3);
}

int maxsize1(int a[],int n)
{
    int thissum,maxsum = 0;
    for(int i = 0;i < n;i++)
        for(int j = i;j < n;j++)
            {   
                thissum = 0;
                for(int k = i;k <= j;k++)
                    thissum += a[k];
                if(thissum > maxsum) maxsum = thissum;
            }
    if(maxsum < 0) maxsum = 0;        
    return maxsum;        
}

int maxsize2(int a[],int n)
{
    int thissum,maxsum = 0;
    for(int i = 0;i < n;i++)
        {   thissum=0;
            for(int j = i;j < n;j++)
                {
                    thissum += a[j];
                    if(thissum > maxsum) maxsum = thissum;
                }    
        }
    if(maxsum < 0) maxsum = 0;        
    return maxsum;        
}

int maxsize3(int a[],int n)
{
    int thissum = 0,maxsum = 0;
    for(int i = 0;i < n;i++)
        {  
            thissum += a[i];
            if(thissum > maxsum) maxsum = thissum;
            if(thissum < 0) thissum = 0;
        }
    if(maxsum < 0) maxsum = 0;        
    return maxsum;        
}