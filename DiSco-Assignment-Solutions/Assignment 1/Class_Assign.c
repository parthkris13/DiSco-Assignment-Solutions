#include<stdio.h>
int N;
int a[500][500];
int check_reflexive()
{
    int i;
    for(i=0;i<N;i++)
        if(a[i][i]!=1)
            return 0;
    return 1;
}
int check_symmetric()
{
    int i,j;
    for(i=0;i<N;i++)
        for(j=0;j<i+1;j++)
            if(a[i][j]!=a[j][i])
                return 0;
    return 1;
}
int check_transitive()
{
    int i,j,k;
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            if(a[i][j])
                for(k=0;k<N;k++)
                    if(a[j][k])
                    {
                        if(a[i][k]!=1)
                        return 0;
                    }
    return 1;
}
int main()
{
    int M,i,j;
    scanf("%d %d",&N,&M);
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
        a[i][j]=0;
    while(M--)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        a[x-1][y-1]=1;
    }
    int reflexive = check_reflexive();
    int symmetric = check_symmetric();
    int transitive = check_transitive();
    if(reflexive&&symmetric&&transitive)
    {
        printf("Reflexive\n");
        printf("Symmetric\n");
        printf("Transitive\n");
        printf("Equivalence\n");
    }
    else
    {
        if(reflexive)
        printf("Reflexive\n");
        if(symmetric)
        printf("Symmetric\n");
        if(transitive)
        printf("Transitive\n");
    }
    return 0;
}