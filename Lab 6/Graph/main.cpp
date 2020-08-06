#include<bits/stdc++.h>

using namespace std;

void add_edge(vector<int> graph[],int u,int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}
void print(vector<int> graph[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<graph[i].size();j++){
            cout<<graph[i].at(j)<<"\t";
        }
        cout<<"\n";
    }

}

int main()
{
    int u,v,e,n;
    //n number of vertices
    //e number of edges
    cin>>n;
    cin>>e;
    vector<int> graph[n];
    for(int i=0;i<e;i++){
        cin>>u>>v;
        add_edge(graph,u,v);
    }
    print(graph,n);
}
