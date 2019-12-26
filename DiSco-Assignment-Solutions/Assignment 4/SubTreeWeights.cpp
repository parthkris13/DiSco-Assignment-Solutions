#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> adj[100];
int m=1000;
int weight[100];

void display(){
	for(int i=0; i<n; i++){
		m=min(m,weight[i]);
	}
	for(int i=0; i<n; i++){
		if(m==weight[i]){
			cout << i << " " << weight[i] << endl;
			return;
		}
	}
}

void dfs(int node, int parent){
	for(auto it : adj[node]){
		if(it==parent)
			continue;
		dfs(it,node);
		weight[node]+=weight[it];
	}
}
int main(){
	cin >> n;
	int a,b;
	for(int i=0; i<n-1; i++){
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i=0; i<n; i++){
		cin >> weight[i];
	}
	dfs(0,0);
	display();
}

