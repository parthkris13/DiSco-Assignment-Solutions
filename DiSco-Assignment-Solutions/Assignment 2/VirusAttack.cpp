#include<bits/stdc++.h>

using namespace std;

queue<int> q;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> compA;
int aff = 0;

int main() {
	int n, m, p, a, b, x;

	cin >> n >> m >> aff;
	adj.resize(n+1);
	vis.resize(n+1);
	vis.assign(n+1, false);
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 0; i < aff; i++) {
		cin >> a;
		compA.push_back(a);
		vis[a] = true;
	}

	for (int i = 0; i < aff; i++) {
		x = compA[i];
		for (int j = 0; j < adj[x].size(); j++) {
			if (!vis[adj[x][j]]){
				vis[adj[x][j]] = true;
				aff++;
				compA.push_back(adj[x][j]);
			}
		}
	}

	if (aff == n)
		cout << "Black Out";
	else {
		cout << (n - aff) << endl;
		for (int i = 0; i < n; i++)
			if (!vis[i+1])
				cout << i+1 << " ";
	}
}

/*
7 5 1
1 2
1 3
1 4
7 6
5 7
1

4 5 3
1 2
2 3
3 4
1 4
2 4
1 4 2

*/