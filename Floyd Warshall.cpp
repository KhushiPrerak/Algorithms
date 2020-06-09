// Used to find the shortest distances between every pair of vertices in a given edge weighted directed Graph.

// Input:
// 0 1 43
// 1 0 6
// INF INF 0

// Expected output:
// 0 1 7
// 1 0 6
// INF INF 0 


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define INF pow(10,7)

void floydWarshall(int** adj, int n){
    for(int k=0;k<n;k++){
        for(int u=0;u<n;u++){
            for(int v=0;v<n;v++){
                adj[u][v] = min(adj[u][v], adj[u][k]+adj[k][v]);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(adj[i][j]==INF){
                cout<<"INF"<<" ";
            } else {
                cout<<adj[i][j]<<" ";
            }
        }
        cout<<endl;
    }
}

int main(){
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int** adj = new int*[n];
	    for(int i=0;i<n;i++){
	        adj[i] = new int[n];
	        for(int j=0;j<n;j++){
	            cin>>adj[i][j];
	        }
	    }
	    floydWarshall(adj,n);
	}
	return 0;
}
