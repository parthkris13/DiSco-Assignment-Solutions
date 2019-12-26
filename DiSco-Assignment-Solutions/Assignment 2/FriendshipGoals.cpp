#include <bits/stdc++.h>
using namespace std;
int v[1000];
int g =1 ;
int adj[1000][1000];
int n,m,ans;
void dfs(int i,int k)
{
    v[i] = k;
    for( int j = 0; j< n; j++ )
        if( adj[i][j] && v[j] == 0 )
            dfs(j,k);   
}
int main()
{
    cin>>n>>m;
    for(int i = 0;i<m;i++ )
    {
        char a,b;
        cin>>a>>b;
        adj[a-65][b-65] = 1;
        adj[b-65][a-65] = 1;
    }
    for( int i =0 ;i<n ;i++)
    {
        if( !v[i])
        {
            dfs(i, g);
            g++;
        }
    }
    cout<<g-1<<endl;
    for( int i=1 ;i<g ; i++)
    {
        for( int j =0 ; j< n;j++)
            if(v[j] == i)
                cout<<(char)(j+65);
        cout<<endl;
    }

}