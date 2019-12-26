#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>adj;
vector<bool> vis;
vector<int> dist;
stack<int> rt;
queue<int>q;

void print(){
	if(!rt.empty()){
		cout<<endl;
		for(int i=0; !rt.empty(); i++){
			cout<<rt.top()<<" ";
			rt.pop();
		}
		cout << endl;
	}
}

int main(){
	int n,a,b,p;
	char ch;
	cin >> n;
	adj.resize(n);
	vis.resize(n);
	dist.resize(n);
	dist.assign(n,-1);
	vis.assign(n,false);
	for(int i=0;i<n-1;i++){
		cin >> a >> b >> ch;
		if(ch=='L'){
			adj[a].insert(adj[a].begin(),1,b);
		}
		else adj[a].push_back(b);
	}
	int x=0;
	vis[x]=true;
	dist[0]=0;
	q.push(x);
	while(!q.empty()){
		x=q.front();
		if(dist[x]%2==1){
			print();
			cout << x << " ";
		}
		else rt.push(x);
		for(int i=0;i<adj[x].size();i++){
			p=adj[x][i];
			if(!vis[p]){
				vis[p]=true;
				dist[p]=dist[x]+1;
				q.push(p);
			}
		}
		q.pop();
	}
	print();
}