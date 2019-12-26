#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> adj[64],path;
int n,p,parent[64],a[64],x;
bool vis[64];
void dfs(int start,int sum)
{
    sum = sum + a[start];
    if(adj[start].size()==1&&sum==x)
    {
        path.push_back(start);
        for(auto it:path)
            printf("%d ",it);
        printf("\n");
        path.pop_back();
    }
    else
    {
        vis[start]=true;
        path.push_back(start);
        for(auto it:adj[start])
        {
            if(!vis[it])
            {
                dfs(it,sum);
            }
        }
        path.pop_back();
    }
    sum = sum - a[start];
}
int main()
{
    cin>>n;
    for(int i=1;i<n;i++)
    {
        cin>>p;
        adj[i].push_back(p);
        adj[p].push_back(i);
    }
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cin>>x;
    dfs(0,0);
    return 0;
}
