#include<stdio.h>
#include<math.h>
void binary(int a,int b[]);
void conv(int b[],int n);
int n;
int main()
{
    scanf("%d",&n);
    printf("%d\n",n*(1<<n-1));
    int size=1<<n;
    int b[n];
    for(int i=0;i<=size-1;i++)
    {
        binary(i,b);
        printf("%d: ",i);
        for(int j=n-1;j>=0;j--)
        {
            if(b[j]==0)
            {
                b[j]=1;
                conv(b,n);
                b[j]=0;
            }
        }
        printf("\n");
    }
}
void binary(int a,int b[])
{
    for(int i=0;i<=n-1;i++)
    {
        b[n-i-1]=a%2;
        a=a/2;
    }
}
void conv(int b[],int n)
{
    int x=0;
    for(int i=0;i<=n-1;i++)
    {
        x+=(1<<i)*b[n-1-i];
    }
    printf("%d ",x);
}
