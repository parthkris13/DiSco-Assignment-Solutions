#include <bits/stdc++.h>
using namespace std;
int v[100002];
int adj[1000][1000] ;
int c[100000]; 
queue < int > q;
void bfs(int a,int n)
{
    v[a] = 1;
    
    for (int i = 0; i <=n; ++i) 
        c[i] = -1; 
    q.push(a);
    c[a] = 1;
    while( !q.empty())
    {
        int h  = q.front();
        q.pop();
        for( int i =1 ; i<=n ;i++)
        {
            if( adj[h][i] == 1 && ! v[i])
            {
                q.push(i);
                v[i] = 1;
                c[i] = 1 - c[h];
            }
            else if( adj[h][i] == 1 && c[i] == c[h])
            {
                cout<<"NO";
                exit(0);
            }


        }
    }

}
int main()
{
    int n,m ;
    cin>>n>>m;
    for(int i = 0;i<m;i++ )
    {
        int a,b;
        cin>>a>>b;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }
    bfs(1,n);
    cout<<"YES"<<endl;
    for( int i =1 ;i <=n;i++)
    {
        if(c[i] == 1)
            cout<<"R";
        else
            cout<<"B";    
    }
}