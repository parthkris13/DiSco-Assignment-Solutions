#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> adj;
vector<pair<int,pair<int,int>>> edges;
vector <bool> vis;
vector <bool> mstEdg;

bool checkVisited(){
	queue <int> q;
	int x=0;
	vis[x]=0;
	q.push(x);
	while(!q.empty()){
		x=q.front();
		for(int i=0; i<adj[x].size(); i++){
			if(!vis[adj[x][i].first]){
				q.push(adj[x][i].first);
				vis[adj[x][i].first]=true;
			}
		}
		q.pop();
	}
	for(bool b : vis){
		if(!b)
			return b;
	}
	return true;
}

int main(){
	int n,m,a,b,c;
	cin >> n >> m;
	adj.resize(n);
	vis.resize(n);
	mstEdg.resize(m);
	vis.assign(n,false);
	mstEdg.assign(n,false);
	int power=0;
	for(int i=0; i<m; i++){
		cin >> a >> b >>c;
		edges.push_back(make_pair(c,make_pair(a,b)));
	}
	sort(edges.begin(), edges.end());
	pair<int,int> p;
	for(int i=0; !checkVisited(); i++){
		p=edges[i].second;
		if(!(vis[p.first] && vis[p.second])){
			adj[p.first].push_back(make_pair(p.second,edges[i].first));
			adj[p.second].push_back(make_pair(p.first, edges[i].first));
			vis.assign(n,false);
			mstEdg[i]=true;
			power+=edges[i].first;
		}
	}
	cout << power << endl;
	for(int i=0; i<m; i++){
		if(mstEdg[i]){
			cout << edges[i].second.first << " " << edges[i].second.second << endl;

		}
	}
}