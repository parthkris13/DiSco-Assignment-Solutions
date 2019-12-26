#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> adj;
vector<bool> vis;
vector<int> parent;
vector<int> dist;
queue<int> bfs;
void printPath(int b) {
	if (parent[b] == 0)
		cout << b << " ";
	else {
		printPath(parent[b]);
		cout << b << " ";	
	}
}

int main() {
	int n, m, p, q, u, v, c;
	cin >> n >> m >> p >> q;
	adj.resize(n+1);
	vis.resize(n+1);
	parent.resize(n+1);
	dist.resize(n+1);
	parent.assign(n+1, -1);
	dist.assign(n+1, 4500001);
	vis.assign(n+1, false);
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> c;
		adj[u].push_back(make_pair(v, c));
		adj[v].push_back(make_pair(u, c));
	}

	int x = p;
	vis[x] = true;
	parent[x] = 0;
	dist[x] = 0;
	bfs.push(x);
	for (int i = 0; !bfs.empty(); i++) {
		x = bfs.front();
		for (int j = 0; j < adj[x].size(); j++) {
			if (!vis[adj[x][j].first]) {
				vis[adj[x][j].first] = true;
				dist[adj[x][j].first] = dist[x] + adj[x][j].second;
				parent[adj[x][j].first] = x;
				bfs.push(adj[x][j].first);
			}
			else {
				if (dist[x] + adj[x][j].second < dist[adj[x][j].first]){
					dist[adj[x][j].first] = dist[x] + adj[x][j].second;
					parent[adj[x][j].first] = x;
				}
			}
		}
		bfs.pop();
	}

	cout << dist[q] << endl;

	printPath(q);
}