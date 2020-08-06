#include<bits/stdc++.h>
#include <list>
#include<string>
using namespace std;
class graph{
    int n;
    list<int>*al;
public:
    graph(int n);
    void edge(int u,int v);
    void Prim(graph g);
};
void graph::Prim(graph g){
    int ans[n];
    bool mst[n];
    for(int i=0;i<n;i++){
        ans[i]=-1,mst[i]=false;
    }
    for(int c=0;c<n;c++){
        if(mst[c]==false){
            mst[c]=true;
        }
        list<int>::iterator i;
        for (i = al[c].begin(); i != al[c].end(); ++i){
                if(mst[*i]==false && ans[*i]==-1){
                    ans[*i]=c;
                }
        }
    }
    for(int i=1;i<n-1;i++){
        if(ans[i]==-1){
            continue;
        }
        else{
            cout<<ans[i]+1<<" "<<i+1<<",";
        }
    }
    cout<<ans[n-1]+1<<" "<<n;
}
graph::graph(int n){
    this->n=n;
    al=new list<int>[n];
}
void graph::edge(int u,int v){
u=u-1;
v=v-1;
al[u].push_back(v);
al[v].push_back(u);
}
int main(){
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    graph g(n);
    cout << "Enter edges separated by a comma(to end press '.'): ";
    char d = ',';
    while(d != '.'){
        int x,y;
        cin >> x >> y;
        g.edge(x,y);
        cin >> d;
    }
    g.Prim(g);
    return 0;
}
