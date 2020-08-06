#include <iostream>
using namespace std;

struct Node
{
    int data;
    int index;
    struct Node* left;
    struct Node* right;
};

Node* insert(struct Node *nd,int x,int index)
{
    if(nd==NULL)
    {
        nd=new Node;
        nd->data=x;
        nd->index=index;
  
    }
    else
    {
        if(x>nd->data)
        nd->right= insert(nd->right,x,2*index+1);
        else
        nd->left= insert(nd->left,x,2*index);
    }
    return nd;
}

void createarray(a,Node* nd)
{
    if (nd != NULL) 
    {
        createarray(a,nd->left); 
        createarray(a,nd->right); 
    } 
}
    
    int n1,n2;
    for(int i=0;i<a.size();i++)
    {
        n1=i+1;
        n2=a.size()-1;
        while(n1<n2)
        if(a[i]+a[n1]+a[n2]<0)
         n1++;
        else if(a[i]+a[n1]+a[n2]>0)
         n2--;
        else
        return 1;
    }
    return 0;
}

int main()
{   
    struct Node* nd=NULL;    
    int q,x;
    char c;
    cin>>q;
    int i=0;
    int a[q];
    while(q--)
    {
        cin>>x;
        nd=insert(nd,x,1);
        
    }createarray(a,nd);
    
    if(triplet(a))
    cout<<"YES";
    else
    cout<<"NO";
    return 0;
}
