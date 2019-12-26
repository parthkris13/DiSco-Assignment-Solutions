#include <bits/stdc++.h>
using namespace std;
int v[1000][1000];
string adj[1000];
int n,m,ans;
string s;
int issafe(int i ,int j )
{
    if( i>=0 && j>=0 && j<n && i<n )
        return 1;
    return 0;
}
void dfs(int i,int j,int k)
{
    v[i][j] = 1;
    if(k == m )
    {
        ans++;
    }
    if( issafe(i+1,j) && adj[i+1][j] == s[k] && !v[i+1][j] )
        dfs(i+1,j,k+1);
    if( issafe(i-1,j) && adj[i-1][j] == s[k] && !v[i-1][j] )
        dfs(i-1,j,k+1);
    if( issafe(i+1,j+1) && adj[i+1][j+1] == s[k] && !v[i+1][j+1] )
        dfs(i+1,j+1,k+1);
    if( issafe(i+1,j-1) && adj[i+1][j-1] == s[k] && !v[i+1][j-1] )
        dfs(i+1,j-1,k+1);
    if( issafe(i-1,j-1) && adj[i-1][j-1] == s[k] && !v[i-1][j-1] )
        dfs(i-1,j-1,k+1);
    if( issafe(i-1,j+1) && adj[i-1][j+1] == s[k] && !v[i-1][j+1] )
        dfs(i-1,j+1,k+1);
    if( issafe(i,j-1) && adj[i][j-1] == s[k] && !v[i][j-1] )
        dfs(i,j-1,k+1);
    if( issafe(i,j+1) && adj[i][j+1] == s[k] && !v[i][j+1] )
        dfs(i,j+1,k+1);
    v[i][j] = 0;
    
}
int main()
{
    cin>>n;
    for(int i = 0;i<n;i++ )
        cin>>adj[i];
    cin>>m;
    cin>>s;
    for( int i =0 ;i<n ;i++ )
    {
        for ( int j =0 ;j< n; j++ )
        {
            if( adj[i][j] == s[0])
            {
                dfs(i,j,1);
                memset(v,0,sizeof(v));
            }
        }
    }
    cout<<ans<<endl;
}