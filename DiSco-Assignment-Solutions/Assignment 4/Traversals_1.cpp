#include<bits/stdc++.h>
using namespace std;

int sub[1200],a[1200],n,in_order[1200],post_order[1200],pos[1200];
pair<int,int>g[1200];
int BST[1200];
int cur = 0;

void dfs(int p,int lo,int hi,int dir){
    if(lo>hi) return;
    int v = post_order[cur];
    if(dir == 0) g[p].first = v;
    else g[p].second = v;
    cur++;
    dfs(v,lo,pos[v]-1,0);
    dfs(v,pos[v]+1,hi,1);
}
int main(){
  cin>>n;
  for(int i=0;i<n;++i){
    cin>>in_order[i];
    pos[in_order[i]] = i;
  }
  for(int i=0;i<n;++i){
    cin>>post_order[i];
  }
  for(int i=0;i<n;++i){
    g[i].first = -1;
    g[i].second = -1;
  }
  cur++;
  dfs(0,0,pos[0]-1,0);
  dfs(0,pos[0]+1,n-1,1);
  int q;
  cin>>q;
  while(q--){
    int x;cin>>x;
    if(g[x].first == -1)cout<<'X';
    else cout<<g[x].first;
    cout<<' ';
    if(g[x].second == -1)cout<<'X';
    else cout<<g[x].second;
    cout<<'\n';
  }
    return 0;
}