#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> vis;
vector<int> dist;
vector<int> par;
queue<int> q;

void printpath(int d) {
	if (par[d] != -1)
		printpath(par[d]);
	cout << d << " ";
}

int main() {
	int n, m, a, b, p, x;
	cin >> n >> m;
	adj.resize(n);
	vis.resize(n);
	vis.assign(n, false);
	dist.resize(n);
	dist.assign(n, 0);
	par.resize(n);
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	cin >> a >> b;
	x = a;
	vis[x] = true;
	par[x] = -1;
	q.push(x);
	while(!q.empty()) {
		x = q.front();
		for (int i = 0; i < adj[x].size(); i++) {
			p = adj[x][i];
			if (!vis[p]) {
				vis[p] = true;
				dist[p] = dist[x] - 1;
				par[p] = x;
				q.push(p);
			}
			else
				if (dist[p] < dist[x] + 1 && par[x] != p) {
					dist[p] = dist[x] - 1;
					par[p] = x;
				}
		}
		q.pop();
	}
	printpath(b);
}