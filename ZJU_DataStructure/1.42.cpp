#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100005

int main()
{
    int Data[MAXSIZE];
    int Next[MAXSIZE];
    int list[MAXSIZE];
    int FirstAdd,n,k;
    scanf("%d %d %d",&FirstAdd,&n,&k);
    for(int i = 0;i <n ;i++)
    {
        int tempadd,tempnext,tempdata;
        scanf("%d %d %d",&tempadd,&tempdata,&tempnext);
        Data[tempadd] = tempdata;
        Next[tempadd] = tempnext;
    }
    int sum=0;
    while (FirstAdd != -1)
    {
        list[sum++] = FirstAdd;
        FirstAdd = Next[FirstAdd];
    }
    for(int i = 0 ;i < sum - sum % k ;i += k)
    {
        for(int j = 0 ; j < k / 2 ;j++)
        {
            int temp;
            temp = list[j + i];
            list[i + j] = list[k - j + i - 1];
            list[k - j + i - 1] = temp;
        }
    }
    for(int i = 0;i < sum - 1;i++)
        printf("%05d %d %05d\n",list[i],Data[list[i]],list[i+1]);
    printf("%05d %d -1\n",list[sum-1],Data[list[sum-1]]);    
}

