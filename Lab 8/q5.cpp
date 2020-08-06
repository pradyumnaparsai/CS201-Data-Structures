#include<bits/stdc++.h>
using namespace std;
int visited[1000]={0};
int parent[1000]={0};
int s[1000]={0};
int last,ct=0;
stack<int>st;
int detectcycle(list<int> *l,int n,int *temp,int v)
{
    //temp=0 indicating the node is pushed into the stack
    //temp=1 visited node
    if(temp[v]==0)
    {
        temp[v]=1;
        s[v]=1;

        list <int> :: iterator i;
        for(i=l[v].begin();i!=l[v].end();i++)
        {
            parent[*i]=v;
            if(temp[*i]==0&&detectcycle(l,n,temp,*i))
            {
                return 1;
            }
            else if(s[*i]==1)
            {
                last=*i;
                return 1;
            }
        }
    }
    s[v]=0;
    return 0;
}

void dfs(list<int> *l,int n,int v)
{
    visited[v]=1;
    list <int > ::iterator i;
    for( i=l[v].begin();i!=l[v].end();i++)
    {
        if(visited[*i]==0)
            dfs(l,n,*i);
    }
}

void reverse(list<int> *l,list <int> *l1, int n)
{
    for(int i=1;i<=n;i++)
    {
        list <int>:: iterator j;
        for(j=l[i].begin();j!=l[i].end();j++)
        {
            l1[*j].push_back(i);
        }
    }
}

void fillbyft(list<int>*l,int v,int n)
{
    visited[v]=1;
    list<int>::iterator i;
    for(i=l[v].begin();i!=l[v].end();i++)
    {
        if(visited[*i]==0)
            fillbyft(l,*i,n);
    }
    st.push(v);
}
void SCC(list<int>*l,int n)
{
    int c=0;
    for(int i=0;i<n;i++)
        visited[i+1]=0;
    for(int i=0;i<n;i++)
        if(visited[i+1]==0)
            fillbyft(l,i+1,n);
    list<int>l1[n+1];
    reverse(l,l1,n);
    for(int i=0;i<n;i++)
        visited[i+1]=0;
    while(!st.empty())
    {
        int v=st.top();
        st.pop();
        if(visited[v]==0)
        {
            dfs(l1,n,v);
            c++;
        }
    }
    cout<<"\nThe number of strongly connected components are: "<<c;
}

int main()
{
    char c='y';
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    list<int>l[n+1];
    cout << "Enter edges separated by a comma(to end press '.'): ";
    char d = ',';
    while(d != '.'){
        int x,y;
        cin >> x >> y;
        l[x].push_back(y);
        cin >> d;
    }
    while(c=='y'||c=='Y')
    {
        int ch;
        cout<<"Enter the operation you want to perform: \n";
        cout<<"1) To check if there is a cycle in graph\n";
        cout<<"2) To check whether the graph is strongly connected\n";
        cout<<"3) To find number of strongly connected components in graph: \t";
        cin>>ch;
        if(ch==1)
        {
            int f=0;
            int temp[n+1]={0};
            for(int i=0;i<n;i++)
            {
                if(detectcycle(l,n,temp,i+1))
                {
                    f=1;
                    break;
                }
            }
            if(f==0)
                cout<<"\nGiven graph is acyclic";
            else
            {
                cout<<"\nGraph has a cycle with vertices: ";
                int i=last;
                int a[1000];
                do
                {
                    ct++;
                    i=parent[i];
                }while(i!=last);
                for(int j=ct-1;j>=0;j--)
                {
                    a[j]=i;
                    i=parent[i];
                }
                for(int j=0;j<ct;j++)
                    cout<<a[j]<<" ";
            }
        }
        if(ch==2)
        {
            dfs(l,n,1);
            int i;
            for( i=1;i<=n;i++)
                if(visited[i]==0)
                break;
            if(i<=n)
                cout<<"\nGraph is not strongly connected"<<endl;
            else
            {
                for( i=1;i<=n;i++)
                    visited[i]=0;
                list<int> l1[n+1];
                reverse(l,l1,n);
                dfs(l1,n,1);
                for( i=1;i<=n;i++)
                    if(visited[i]==0)
                        break;
                if(i<=n)
                    cout<<"\nGraph is not strongly connected"<<endl;
                else
                    cout<<"\nGraph is strongly connected"<<endl;
            }
        }
        if(ch==3)
        {
            SCC(l,n);
        }
    cout<<"\nDo you want to continue?(y or n):";
    cin>>c;
    }
}
