#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Edge {
    public:
    int source;
    int dest;
    int weight;
};

bool compare(Edge e1, Edge e2) {
    return e1.weight < e2.weight;
}

int find(int x,vector<int>& parent){
    if(parent[x]==x) return x;
    int px= find(parent[x], parent);
    parent[x]=px;
    return px;
}

void merge(int x, int y, vector<int>& parent){
    int lx = find(x,parent);
    int ly = find(y,parent);
    
    parent[lx] = ly;
}

void kruskal(Edge *input, int n, int e) {
    sort(input, input + e, compare);
    Edge *output = new Edge[n-1];
    vector<int> parent(n);
    for(int i = 0; i < n; i++) {
        parent[i] = i;
    }
    int count = 0;
    int i = 0;
    while(count != n -1) {
        int x = input[i].source;
        int y = input[i].dest;
        if(find(x,parent)!=find(y,parent)) {
            output[count++] = input[i];
            merge(x,y,parent);
        }
        i++;
    }
    
    for(int i = 0; i < n-1; i++) {
        int s= output[i].source;
        int d= output[i].dest;
        int w=output[i].weight;
        if( s<d) {
            cout <<s << " " << d<< " "<< w << endl;
        } 
        else {
            cout <<d << " " << s << " "<< w<< endl;
        }
    }
}

int main()
{
    int n,e;
    cin>>n>>e;
    Edge *input = new Edge[e];

    for(int i=0;i<e;i++){
        int s,d,w;
        cin>>s>>d>>w;
        input[i].source = s;
        input[i].dest = d;
        input[i].weight = w;
    }
    kruskal(input,n,e);
    return 0;
}
