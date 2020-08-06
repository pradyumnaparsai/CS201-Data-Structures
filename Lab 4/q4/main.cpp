#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};

Node* newNode(int data)
{
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

Node* insert(int arr[], Node* parent,
                       int i, int n)
{

    if (i < n)
    {
        Node* temp = newNode(arr[i]);
        parent = temp;
        parent->left = insert(arr,
                   parent->left, 2 * i + 1, n);
        parent->right = insert(arr,
                  parent->right, 2 * i + 2, n);
    }
    return parent;
}

void inOrder(Node* parent)
{
    if (parent != NULL)
    {
        inOrder(parent->left);
        cout << parent->data <<" ";
        inOrder(parent->right);
    }
}

void printPostorder(struct Node* node)
{
    if (node == NULL)
        return;
    printPostorder(node->left);
    printPostorder(node->right);
    cout << node->data << " ";
}
void printPreorder(struct Node* node)
{
    if (node == NULL)
        return;
    cout << node->data << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}
int main()
{
    int n;
    cout<<"Enter the number of nodes: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the values: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    Node* parent = NULL;
    parent=insert(arr, parent, 0, n);
    cout<<"Pre-order: ";
    printPreorder(parent);
    cout<<"\n";
    cout<<"In-order: ";
    inOrder(parent);
    cout<<"\n";
    cout<<"Post-order: ";
    printPostorder(parent);
    cout<<"\n";
    cout<<"Level-order: ";
     for(int i=0;i<n;i++)
    {cout<<arr[i]<<" ";}
    cout<<"\n";
    cout<<"Height of the tree: ";
    int height=0;
    for(int i=n; i>0;)
    {
        height++;
        i=i/2;
    }
    cout<<height-1;
}
