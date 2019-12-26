 #include <bits/stdc++.h>
using namespace std;
int v[100002];
int adj[1000][1000] ;
stack <int> st;
vector <int> ans;
set <int> s;
void dfs(int a,int n)
{
    v[a] = 1;
    for(int i = 0;i<n;i++)
    {
        if(adj[a][i] && !v[i] )
        {
            st.push(i);
            dfs(i,n);
            st.pop();
        }
        else if (adj[a][i] && v[i])
        {
            stack<int> t ;
            t= st;
            while (!t.empty() )
            {
                int y = t.top();
                s.insert( y );
                t.pop();
            }
        }
    }
    v[a] = 0;
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
    }
    for( int i = 0 ;i <n ; i++ )
    {
        if ( !v[i] )
        {
            st.push(i);
            dfs(i,n);
            st.pop();
        }
    }
    if( s.size() == 0 )
        cout<<"No Deadlock ";
    else
    {
        cout<<"Deadlock"<<endl;
        for( auto i : s)
            cout<<i<<" ";
    }
}