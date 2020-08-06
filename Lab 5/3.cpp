#include<iostream>
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
        cout<<index<<endl;
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
Node* Replacement(Node* nd)
{
    Node* temp=nd;
    while(temp&&temp->left)
    {
        temp=temp->left;
    }
    return temp;
}
Node* deletenode(Node* nd,int x)
{
    if(nd==NULL)
    {
        cout<<"Tree is empty!\n";
        return nd;
    }
    else
    {
        if(x>nd->data)
        nd->right= deletenode(nd->right, x);
        else if(x<nd->data)
        nd->left= deletenode(nd->left, x);
        else
        {cout<<nd->index<<endl;
            if(nd->left==NULL)
            {
                Node* temp=nd->right;
                delete nd;
                return temp;
            }
            else if(nd->right==NULL)
            {
                Node* temp=nd->left;
                delete nd;
                return temp;
            }
            Node* temp=Replacement(nd->right);
            swap(nd->data,temp->data);
            nd->right=deletenode(nd->right,x);
        }
        return nd;
    }
}
int main()
{   
    struct Node* nd=NULL;    
    int q,x;
    char c;
    cin>>q;
    int i=0;
    while(q--)
    {
        cin>>c>>x;
        if(c=='i')
        {
            nd=insert(nd,x,1);
        }
        else if(c=='d')
        {
            nd=deletenode(nd,x);
        }
          
    }

    return 0;
}


