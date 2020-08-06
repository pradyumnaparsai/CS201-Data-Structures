#include<bits/stdc++.h>

using namespace std;
int visited[10000]={0};
void bfs(list <int> *l,int n,int s)
{
    list<int> q;
    for(int i=0;i<n;i++)
        visited[i+1]=0;
    q.push_back(s);
    visited[s]=1;
    list <int>::iterator i;

    while(!q.empty())
    {
        s=q.front();
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

int ispath(list <int> *l,int n,int u,int v)
{
    bfs(l,n,v);
    if(visited[u]==1)
        return 1;
    return 0;
}

int dist[1000];
int shortpath(list <int> *l,int n,int v,int u)
{
    int s;
    for(int i=0;i<n;i++)
        dist[i+1]=INT_MAX;
    dist[u]=0;
    list <int> q;
    q.push_back(u);
    visited[u]=1;
    for(int i=0;i<n;i++)
        visited[i+1]=0;
    while(!q.empty())
    {
        int s=q.front();
        q.pop_front();
        list<int>::iterator j;
        for(j=l[s].begin();j!=l[s].end();j++)
        {
            if(visited[*j]==0)
            {
                visited[*j]=1;
                dist[*j]=dist[s]+1;
                q.push_back(*j);
            }
            if(*j==v)
                return dist[v];
        }
    }
}

int main()
{
    int n;
    char c='y';

    while(c=='y'||c=='Y')
    {
        cout<<"Enter the operation you want to perform\n1)To check whether a path exists between any two vertices\n2)To compute shortest distance between two nodes \n3)To compute diameter of tree:\t" ;
        int ch;
        cin>>ch;
        if(ch==1||ch==2)
        {
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

        if(ch==1)
        {
            int u,v;
            cout<<"Enter two vertices: ";
            cin>>u>>v;
            if(ispath(l,n,u,v)==1)
                cout<<"There exists a path the nodes "<<endl;
            else
            {
                if(ispath(l,n,v,u)==1)
                    cout<<"There exists a path between the nodes "<<endl;
                else
                    cout<<"There does not exists a path between the nodes"<<endl;
            }

        }
        if(ch==2)
        {
            int u,v;
            cout<<"\nEnter two vertices: ";
            cin>>u>>v;
            if(ispath(l,n,u,v)==0&&ispath(l,n,v,u)==0)
                cout<<"\nThere is no path between these vertices";
            else
            {
                if(ispath(l,n,u,v)==1&&ispath(l,n,v,u)==1)
                    cout<<"Shortest path length between "<<u<<" and "<<v<<" is: "<<min(shortpath(l,n,u,v),shortpath(l,n,v,u))<<endl;
                else if(ispath(l,n,u,v)==0)
                    cout<<"Shortest path length between "<<u<<" and "<<v<<" is: "<<shortpath(l,n,v,u)<<endl;
                else
                    cout<<"Shortest path length between "<<u<<" and "<<v<<" is: "<<shortpath(l,n,u,v)<<endl;
            }
        }
        }
        if(ch==3)
        {
            cout << "Enter the number of nodes: ";
            cin >> n;

            list<int>l[n+1];
            cout << "Enter edges separated by a comma(to end press '.'): ";
            char c = ',';
            while(c != '.'){
                int x,y;
                cin >> x >> y;
                l[x].push_back(y);
                 l[y].push_back(x);
                cin >> c;
            }



            int max=INT_MIN;
            for(int i=1;i<=n;i++)
            {
                for(int j=i+1;j<=n;j++)
                {
                    if(shortpath(l,n,i,j)>max)
                        max=shortpath(l,n,i,j);
                }
            }
            cout<<"Diameter of the tree is: "<<max<<endl;
        }
        cout<<"\nDo you want to continue( y or n ): ";
        cin>>c;

    }


    return 0;
}
