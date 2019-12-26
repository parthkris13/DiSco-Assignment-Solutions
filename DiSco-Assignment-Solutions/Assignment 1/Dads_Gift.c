#include<stdio.h>
#include <math.h>
int allposs(int b[],int num_terms,int tot_sum);
int main()
{
    int n;
    scanf("%d",&n);
    int m;
    scanf("%d",&m);
    int a[n];
    for(int i=0;i<=n-1;i++)
    {
        scanf("%d",&a[i]);
    }
    allposs(a,n,m);
}
int allposs(int b[],int num_terms,int tot_sum)
{
    int diff=tot_sum;
    int ind=0;
    int count=0;
    int final_count=0;
    for(int i=0;i<=(1<<num_terms);i++)
    {
        count=0;
        int sum=0;
        for(int j=0;j<=num_terms-1;j++)
        {
            if((i&(1<<j))!=0)
                {
                    sum+=b[j];
                    count++;
                }
        }
        if((tot_sum-sum)<=diff&&(tot_sum-sum)>=0)
        {
            diff=tot_sum-sum;
            ind=i;
            final_count=count;
        }
    }
    printf("%d\n",final_count);
    for(int j=0;j<num_terms;j++)
        {
            if((ind&(1<<j))!=0)
                printf("%d ",j+1);
        }
}
