#include<iostream>
#include<math.h>
using namespace std;

struct node
{
	int data;
	struct node *left;
	struct node *right;
} ;

node* newnode(int data) 
{ 
    node* nd = new node; 
    nd->data = data; 
    nd->left = nd->right = NULL; 
    return (nd); 
} 
node* createNode(int arr[], node* nd, 
                       int i, int n) 
{ 
    
    if (i < n) 
    { 
        node* temp = newnode(arr[i]); 
        nd = temp; 
        nd->left = createNode(arr, 
                   nd->left, 2 * i + 1, n); 
  
        nd->right = createNode(arr, 
                  nd->right, 2 * i + 2, n); 
    } 
    return nd; 
} 
int treeheight(node *nd,int i,int x)
{
    if(i==x)
    return 1;
    int h1=treeheight(nd->left,i+1,x);
    int h2=treeheight(nd->right,i+1,x);
    return h1+h2;
    
}

int main()
{
    int n;
    cin>>n;
    int val[n];
    
    node *nd=new node;
    for(int i=0;i<n;i++)
    {
        val[i]=i;
    }
    int x;
    cin>>x;
    nd=createNode(val,nd,0,n);
    
    int height = -1;
    for(int i=n;i>0;)
    {
        height++;
        i=i/2;
    }
    if(x!=height)
    cout<<treeheight(nd,0,x)<<" ";
    else
    cout<<(n-pow(2,height)+1);
    
    
    int y=height-x;
   if(n-pow(2,height)+1>(pow(2,height)/2))
   {
        if(height==y)
        {
            cout<<(n-pow(2,height)+1)<<" ";
        }
        else
         cout<<treeheight(nd,0,y)<<" ";
   }
   else
   {
        if(height==y)
         cout<<(n-pow(2,height)+1)+(pow(2,height-1)/2)<<" ";
        else
         cout<<treeheight(nd,0,y)/2<<" ";   
   }
    
    return 0;
}