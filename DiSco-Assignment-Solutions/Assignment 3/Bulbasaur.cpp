#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> dist;
vector<bool> vis;
queue<int> q;

int main() {
	int n, x, p, min = 10000;
	cin >> n;
	adj.resize(n);
	dist.resize(n);
	vis.resize(n);
	vis.assign(n, false);
	for (int i = 1; i < n; i++) {
		cin >> x;
		adj[x].push_back(i);
	}
	x = 0;
	vis[x] = true;
	q.push(x);
	dist[x] = 0;
	while(!q.empty()){
		x = q.front();
		for (int i = 0; i < adj[x].size(); i++) {
			p = adj[x][i];
			if(!vis[p]) {
				vis[p] = true;
				dist[p] = dist[x] + 1;
				q.push(p);
			}
		}
		if (adj[x].size() == 0)
			if (dist[x] < min)
				min = dist[x];
		q.pop();
	}

	for (int i = 0; i < n; i++)
		if (dist[i] == min && adj[i].size() == 0)
			cout << i << " ";
}