#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<bool> vis;
vector<int> parent;
int dest;
int s, d;

void printPath(int a) {
	if (parent[a] != 0)
		printPath(parent[a]);
	cout << a << " ";
}

void dfs(int x) {
	if (x == s) {
		if (!vis[d])
			return;
	}
	vis[x] = true;
	for (int i = 0; i < adj[x].size(); i++)
		if (!vis[adj[x][i]]) {
			parent[adj[x][i]] = x;
			dfs(adj[x][i]);
		}

}

int main() {
	int n, m, d, a, b;
	cin >> n >> m >> dest;

	adj.resize(n+1);
	parent.resize(n+1);
	vis.resize(n+1);
	vis.assign(n+1, false);

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
	}

	cin >> s >> d;
	dfs(1);
	if (vis[dest]) {
		cout << "YES" << endl;
		printPath(dest);
	}
	else cout << "NO";
}