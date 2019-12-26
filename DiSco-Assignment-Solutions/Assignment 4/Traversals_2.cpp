#include <bits/stdc++.h>
using namespace std;

int inorder[1000], preorder[1000], pos[1000],n;
pair<int,int> g[1000];
int cur=0;

void dfs(int p, int lo, int hi, int dir){
	if(lo>hi) return;
	int v = preorder[cur];
	if(dir == 0) g[p].first = v;
	else g[p].second = v;
	cur++;
	dfs(v,lo,pos[v]-1, 0);
	dfs(v,pos[v]+1, hi, 1);
}
int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> inorder[i];
		pos[inorder[i]] = i;
	}
	for(int i=0; i<n; i++){
		cin >> preorder[i];
	}
	for(int i=0; i<n; i++){
		g[i].first = -1;
		g[i].second = -1;
	}
	cur++;
	dfs(0,0,pos[0]-1,0);
	dfs(0,pos[0]+1,n-1,1);
	int q;
	cin >> q;
	while(q--){
		int x;
		cin >> x;
		if(g[x].first == -1) cout << 'X';
		else cout << g[x].first;
		cout << " ";
		if(g[x].second == -1) cout << 'X';
		else cout << g[x].second;
		cout << '\n';
	}
	return 0;
}
