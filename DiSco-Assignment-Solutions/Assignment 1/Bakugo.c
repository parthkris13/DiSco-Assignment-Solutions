#include<stdio.h>
void allposs(char d[],int n);
int main()
{
    int n;
    scanf("%d",&n);
    int p_i=0;
    char d[n-2];
    char blank=getchar();
    for(int i=0;i<=n-1;i++)
    {
        char p=getchar();
        blank=getchar();
        if(p!='B'&&p!='M')
            {
                d[p_i]=p;
                p_i++;
            }
    }
    allposs(d,n);
    return 0;
}
void allposs(char d[],int n)
{
    for(int i=0;i<=(1<<(n-2));i++)
    {
        int count=0;
        for(int j=0;j<=n-3;j++)
            {
                if((i&(1<<j))!=0)
                    count++;
 
            }
        if(count==((n-2)/2))
        {
            printf("M: ");
            for(int j=0;j<=n-3;j++)
            {
                if((i&(1<<j))==0)
                   printf("%c ",d[j]);
            }
            printf("| B: ");
            for(int j=0;j<=n-3;j++)
            {
                if((i&(1<<j))!=0)
                    printf("%c ",d[j]);
            }
            printf("\n");
        }
    }
}