#include <bits/stdc++.h>
using namespace std;
#define INF 99999

int graph[100][100];
int dist[100][100];
int n,m;

void printSol(){
	int sum=0;
	for(int i=0;i<n;i++){
		for(int j=0; j<i; j++){
			if(dist[i][j]!=INF){
				sum += dist[i][j];
			}
		}
	}
	cout << sum << endl;
}

void fw(){
	int i,j,k;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			dist[i][j]=graph[i][j];
		}
	}
	for(k=0;k<n;k++){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(dist[i][k] + dist[k][j] < dist[i][j]){
					dist[i][j]=dist[i][k]+dist[k][j];
				}
			}
		}
	}
	printSol();
}

int main(){
	cin >> n >> m;
	int a,b,c;
	for(int i=0; i<n; i++){
		for(int j=0;j<n;j++){
			graph[i][j]=INF;
		}
	}
	for(int i=0; i<m; i++){
		cin >> a >> b >> c;
		graph[a][b] = c;
		graph[b][a] = c;
	}
	fw();
	return 0;
}