#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> wts;
vector<int> sums;
vector<bool> lr;

bool checkBST(int d){
	if(adj[d].size()==0)
		return true;
	else {
		if(adj[d].size()==1){
			if(lr[d] == true){
				if(wts[adj[d][0]] < wts[d]){
					return checkBST(adj[d][0]);
				}
			}
			else{
				if(wts[adj[d][0]] > wts[d]){
					return checkBST(adj[d][0]);
				}
			}
		}
		else{
			if(wts[adj[d][0]] < wts[d] && wts[adj[d][1]] > wts[d]){
				return (checkBST(adj[d][0]) && checkBST(adj[d][1]));
			}
		}
	return false;	
	}
}

int dfs(int d){
	for(int i=0; i<adj[d].size(); i++){
		sums[d]+= dfs(adj[d][i]);	
	}
	return sums[d];
}

int main(){
	int n,a,b;
	char ch;
	cin >> n;
	adj.resize(n);
	lr.resize(n);
	lr.assign(n,false);
	for(int i=0;i<n-1;i++){
		cin >> a >> b >> ch;
		if(ch=='L'){
			adj[a].insert(adj[a].begin(),1,b);
			lr[a]=true;
		}
		else adj[a].push_back(b);
	}
	for(int i=0; i<n; i++){
		cin >> a;
		wts.push_back(a);
		sums.push_back(a);
	}
	sums[0]=dfs(0);
	int max=0;
	int index=1025;
	int flag=0;
	for(int i=0;i<n;i++){
		if(!(adj[i].size()==0)){
			if(checkBST(i)){
				if(sums[i]>max){
					max = sums[i];
					index = i;
					flag = 1;
				}
			}
		}
	}
	if(flag==0)
		cout << "No Such Nodes";
	else cout << index << endl;
	return 0;
}