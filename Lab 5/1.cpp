#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *left;
	struct node *right;
} ;

node* newnode(int data) 
{ 
    node* NODE = new node; 
    NODE->data = data; 
    NODE->left = NODE->right = NULL; 
    return (NODE); 
} 
node* createNode(int arr[], node* NODE, 
                       int i, int n) 
{ 
    
    if (i < n) 
    { 
        node* temp = newnode(arr[i]); 
        NODE = temp; 
        NODE->left = createNode(arr, 
        NODE->left, 2 * i + 1, n); 
  
        NODE->right = createNode(arr, 
                  NODE->right, 2 * i + 2, n); 
    } 
    return NODE; 
} 
void odd_traversal(node* NODE, int j)  
{  
    if (NODE==NULL)  
        return;  
    if (j==1)  
        cout <<NODE->data <<" ";  
    else if (j>1)  
    {  
        odd_traversal(NODE->left,j-1);  
        odd_traversal(NODE->right,j-1);
    }  
}
void even_traversal(node* NODE, int j)  
{  
    if (NODE==NULL)  
        return;  
    if (j==1)  
    {
        cout <<NODE->data <<" ";
        return;
    }  
    else if (j>1)  
    {  
        even_traversal(NODE->right,j-1);
        even_traversal(NODE->left,j-1);  
        
    }  
}
void print(node* NODE,int h)  
{  
    for (int i = 1; i <= h; i++)  
    {   if(i%2!=0)
        odd_traversal(NODE, i);  
        else
        even_traversal(NODE,i);
    }
} 

int main()
{
    int n;
    cout<<"Enter number of nodes: ";
    cin>>n;
    int val[n];
    cout<<"Enter "<<n<<" values: ";
    node *NODE=new node;
    for(int i=0;i<n;i++)
    {
        cin>>val[i];
        
    }
    NODE=createNode(val,NODE,0,n);
    int height = -1;
    for(int i=n;i>0;)
    {
        height++;
        i=i/2;
    }
    print(NODE,height+1);
    return 0;
    
}