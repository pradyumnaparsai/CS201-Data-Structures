#include<bits/stdc++.h>

using namespace std;
int visited[10000]={0};
void bfs(list <int> *l,int n,int s)
{
    list<int> q;

    q.push_back(s);
    visited[s]=1;
    list <int>::iterator i;

    while(!q.empty())
    {
        s=q.front();
        cout<<s<<" ";
        q.pop_front();
        for(i=l[s].begin();i!=l[s].end();i++)
        {
            if(visited[*i]==0)
            {
                q.push_back(*i);
                visited[*i]=1;
            }
        }
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
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==0)
            bfs(l,n,i);

    }

}
