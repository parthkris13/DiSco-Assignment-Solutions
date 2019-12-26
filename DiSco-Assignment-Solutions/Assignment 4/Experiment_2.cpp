#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> >g[10005];
vector<vector<int> >E;
int n,m;
int dsu[10005];

int root(int u){
  if(dsu[u] == u)return u;
  return dsu[u]=root(dsu[u]);
}

int connected(int u,int v){
  return root(u) == root(v);
}

void join(int u,int v){
  dsu[root(u)] = root(v);
  return;
}

int main(){
	cin>>n>>m;
  for(int i=1;i<=m;++i){
    int u,v;cin>>u>>v;
    int w;cin>>w;
    g[u].push_back({v,w});
    g[v].push_back({u,w});
    E.push_back({w,u,v});
  }
  sort(E.begin(),E.end());
  
  int ans = 0;
  vector<pair<int,int> >fields;

  for(int i=0;i<n;++i)dsu[i]=i;

  for(int i=0;i<m;++i){
    int u,v,w;
    u = E[i][1];
    v = E[i][2];
    w = E[i][0];
    if(!connected(u,v)){
      join(u,v);
      ans+=w;
      fields.push_back({u,v});
    }
  }
  cout<<ans<<'\n';
  for(int i=0;i<fields.size();++i){
    cout<<fields[i].first<<' '<<fields[i].second<<'\n';
  }
	return 0;
}