#include<bits/stdc++.h>
using namespace std;
int visited[1000]={0};

void dfs(list<int> *l,int n,int v)
{
    visited[v]=1;
    cout<<v<<" ";
    list <int > ::iterator i;
    for( i=l[v].begin();i!=l[v].end();i++)
    {
        if(visited[*i]==0)
            dfs(l,n,*i);
    }
}
int main()
{
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    list<int>l[n+1];
    cout << "Enter edges separated by a comma(to end press '.'): ";
    char c = ',';
    while(c != '.'){
        int x,y;
        cin >> x >> y;
        l[x].push_back(y);
        cin >> c;
    }

    for(int i=n;i>=1;i--)
    {
        if(visited[i]==0)
            dfs(l,n,i);
    }
    return 0;
}
