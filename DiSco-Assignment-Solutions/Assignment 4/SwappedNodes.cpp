#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>adj;
vector<pair<int,int>>wts;
vector<int>order;

void dfs(int d){
	if(adj[d].size()==0){
		order.push_back(d);
	}
	else{
		dfs(adj[d][0]);
		order.push_back(d);
		dfs(adj[d][1]);
	}
}

int main(){
	int n,a,b;
	char ch;
	cin>>n;
	adj.resize(n);
	for(int i=0;i<n-1;i++){
		cin >> a >> b >> ch;
		if(ch=='L'){
			adj[a].insert(adj[a].begin(),1,b);
		}
		else adj[a].push_back(b);
	}
	dfs(0);
	for(int i=0; i<n; i++){
		cin >> a;
		wts.push_back(make_pair(a,i));
	}
	sort(wts.begin(), wts.end());
	for(int i=0; i<n; i++){
		if(wts[i].second != order[i])
			cout << order[i] << " ";
	}
	return 0;
}