#include<stdio.h>
int main()
{
int n;
scanf("%d",&n);
int a[n];
for(int i=0;i<=n-1;i++)
    scanf("%d",&a[i]);
int arr_final[n];
int count=0;
int flag;
for(int i=0;i<=n-1;i++)
{
    flag=0;
    for(int j=0;j<=n-1;j++)
    {
        if((a[j]%a[i])==0&&a[j]!=a[i])
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        arr_final[count]=a[i];
        count++;
    }
}
printf("%d\n",count);
for(int i=0;i<=count-1;i++)
    printf("%d ",arr_final[i]);
}