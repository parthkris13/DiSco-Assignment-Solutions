#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> vis;
vector<int> parent;
queue<int> q;

void retrace (int a) {
	vis[a] = true;
	if (parent[a] == 0){
		vis[0] = true;
		return;
	}
	else {
		retrace(parent[a]);
	}
}
int main(){
	int n, a, b, m, x, p;
	cin >> n;
	parent.resize(n);
	adj.resize(n);
	vis.resize(n);
	vis.assign(n, false);
	for (int i = 0; i < n-1; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	x = 0;
	cin >> m;
	q.push(x);
	vis[x] = true;
	while (!q.empty()) {
		x = q.front();
		for (int j = 0; j < adj[x].size(); j++) {
			p = adj[x][j];
			if (!vis[p]){
				q.push(p);
				vis[p] = true;
				parent[p] = x;
			}
		}
		q.pop();
	}

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		vis.assign(n, false);
		retrace(a);
		x = b;
		while (!vis[x]) {
			x = parent[x];
		}
		cout << x << endl;
	}
}