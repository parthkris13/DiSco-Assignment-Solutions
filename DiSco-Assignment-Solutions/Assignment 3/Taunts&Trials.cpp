#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> lr;
queue<int> q;
vector<int> cost;

int main() {
	int n, a, b, p, m;
	char ch;
	cin >> n;
	adj.resize(n);
	cost.resize(n);
	cost.assign(n, 0);
	lr.resize(n);
	lr[0] = 0;

	for (int i = 0; i < n-1; i++) {
		cin >> a >> b >> ch;
		adj[a].push_back(b);
		if (ch == 'L')
			lr[b] = -1;
		else
			lr[b] = 1;
	}

	int x = 0;
	q.push(x);
	while (!q.empty()){
		x = q.front();
		for (int i = 0; i < adj[x].size(); i++){
			p = adj[x][i];
			q.push(p);
			cost[p] = cost[x] + lr[p];
		}
		q.pop();
	}

	cin >> m;
	int flag;
	for (int i = 0; i < m; i++) {
		flag = 0;
		cin >> a;
		for (int j = 0; j < n; j++) {
			if (cost[j] == a) {
				flag++;
				cout << j << " ";
			}
		}
		if (flag == 0)
			cout << "No Nodes";
		cout << endl;
	}
}