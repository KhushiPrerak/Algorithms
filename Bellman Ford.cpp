//Given a graph and a source vertex src in graph, find shortest paths from src to all vertices in the given graph. 
//The graph may contain negative weight edges.
// Can also be used to detect negative weight cycle in a graph.

// For Input:
// 1
// 5 8
// 0 1 -1 0 2 4 1 2 3 1 3 2 1 4 2 3 2 5 3 1 1 4 3 -3
// Your Output should be:
// 0 --> 0
// 1 --> -1
// 2 --> 2
// 3 --> -2
// 4 --> 1


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Edge {
    public:
    int u;
    int v;
    int wt;
};

void BellmanFord(vector<Edge> edges, int v, int e, int src){
    vector<int> ans(v,INT_MAX);
    ans[src]=0;  
    for(int i=0;i<v-1;i++){
        for(int j=0;j<e;j++){
            Edge e1 = edges[j];
            int u = e1.u;
            int v = e1.v;
            int wt = e1.wt;
            if(ans[u]==INT_MAX) continue;
            else {
                ans[v] = min(ans[v],ans[u]+wt);
            }
        }
    }
    
    for(int i=0;i<e;i++){
        Edge e1 = edges[i];
        int u = e1.u;
        int v = e1.v;
        int wt = e1.wt;
        if(ans[u]!=INT_MAX && ans[v] > ans[u] + wt) {
            // Negative weight cycle found 
            cout<<"Negative weight cycle found! Can't calculate shortest path!"<<endl;
            return;
        }
    }
   
    //Negative weight cycle not found
    
    for(int i=0;i<v;i++){
        cout<<i<<" --> "<<ans[i]<<endl;
    }
    
}

int main(){
	int t;
	cin>>t;
	while(t--){
	    int v,e;
	    cin>>v>>e;
	    vector<Edge> edges;
	    for(int i=0;i<e;i++){
	        Edge e1;
	        int u,v,w;
	        cin>>u>>v>>w;
	        e1.u = u;
	        e1.v = v;
	        e1.wt = w;
	        edges.push_back(e1);
	    }
	    BellmanFord(edges,v,e,0);
	}
	return 0;
}
