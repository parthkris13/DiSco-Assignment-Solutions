#include <bits/stdc++.h> 
using namespace std; 
int graph[5][5]={{INT_MAX}};
  
int travellingSalesmanProblem(int s,int n) 
{ 
    vector<int> vertex; 
    for (int i = 0; i < n; i++) 
        if (i != s) 
            vertex.push_back(i); 
  
    int min_path = INT_MAX; 
    do {
        int current_pathweight = 0; 
          
        int k = s; 
        for (int i = 0; i < vertex.size(); i++) { 
            current_pathweight += graph[k][vertex[i]]; 
            k = vertex[i]; 
        } 
        current_pathweight += graph[k][s]; 
        min_path = min(min_path, current_pathweight); 
         
    } while (next_permutation(vertex.begin(), vertex.end())); 
    return min_path; 
} 

int main() 
{   
    int n,m;
    int x,y,w;
    cin>>n>>m;
    
    for(int i=0;i<m;i++){
        cin>>x>>y>>w;
        graph[x][y]=w;
        graph[y][x]=w;
    }
    int s = 0; 
    cout << travellingSalesmanProblem(s,n) << endl; 
    return 0; 
} 