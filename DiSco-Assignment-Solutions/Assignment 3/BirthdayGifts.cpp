#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int adj1[9][9],adj2[9][9];
int n,m,p,q,u,v,a[9],b[9],flg=0;
int fact(int k)
{
    int p = k;
    while(--k)
    {
        p = p*k;
    }
    return p;
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        adj1[u][v]=1;
        adj1[v][u]=1;
    }
    cin>>p>>q;
    for(int i=0;i<q;i++){
        cin>>u>>v;
        adj2[u][v]=1;
        adj2[v][u]=1;
    }
    if(n==p&&m==q)
    {
        for(int i=0;i<n;i++)
        {
            a[i]=i;
            b[i]=i;
        }
        for(int i=0;i<fact(n);i++)
        {
            next_permutation(b,b+n);
            int flag=0;
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<n;k++)
                {
                    if(adj1[j][k]!=adj2[b[j]][b[k]])
                    {
                        flag=1;
                        break;
                    }
                }
            }
            if(flag==0)
            {
                printf("YES\n");
                flg=1;
                for(int t=0;t<n;t++)
                {
                    printf("%d - %d\n",t,b[t]);
                }
                break;
            }
        }
        if(flg==0)
            printf("NO\n");
    }
    else
        printf("NO\n");
    return 0;
}
