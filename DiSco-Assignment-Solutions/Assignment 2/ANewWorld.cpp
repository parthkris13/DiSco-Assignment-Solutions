#include<bits/stdc++.h>
using namespace std;

#define int long long
queue<int> q;
vector<int>parent;
vector<vector<int>> adj;
vector<bool> vis;

void printPath(int d) {
	if (parent[d] != 0)
		printPath(parent[d]);
	cout << d << " ";
}
int32_t main() {
	int n, m, s, d, x;
	cin >> n >> m;
	adj.resize(n+1);
	vis.assign(n+1, 0);
	parent.resize(n+1);
	parent.assign(n+1, -1);
	vector<int>dist (n+1, 3000);		
	for (int i = 0; i < m; i++) {
		cin >> s >> d;
		adj[s].push_back(d);
		adj[d].push_back(s);
	}
	cin >> s >> d;
	
	q.push(s);
	vis[s] = true;
	dist[s] = 0;
	parent[s] = 0;
	while(!q.empty()) {
		x = q.front();
		vis[x] = true;
		for (int j = 0; j < adj[x].size(); j++)
			if (!vis[adj[x][j]]) {
				dist[adj[x][j]] = dist[x] + 1;
				parent[adj[x][j]] = x;
				q.push(adj[x][j]);
			}
		q.pop();
	}
	if (vis[d])
	{	cout << dist[d] << endl;
	printPath(d);
	}
	else 
	 cout << -1 << endl;
	return 0;
}

/*
11 9
2 1
1 3
6 7
7 8
9 7
10 4
5 1
1 4
4 11
2 10

11 10
2 1
2 10
1 3
6 7
7 8
9 7
10 4
5 1
1 4
4 11
2 10
*/