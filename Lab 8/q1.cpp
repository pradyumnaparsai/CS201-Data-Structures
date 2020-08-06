#include <iostream>
#include <queue>

using namespace std;

struct node{
    int data;
    node* next;
};

class AdjMat{
public:

    int size;
    bool** ptr;

    AdjMat(){
        size = 0;
        ptr = NULL;
    }

    AdjMat(int n){
        size = n;
        ptr = new bool*[n];
        for(int i=0;i<n;i++){
           ptr[i] = new bool[n];
           for(int j=0;j<n;j++)
                ptr[i][j] = false;
        }
    }

    void insertEdge(int v, int k){
        ptr[v-1][k-1] = true;
    }


    void printEdges(){
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++)
                if(ptr[i][j])
                cout << i+1 << " " << j+1 << ", ";
        }
        cout << endl;
    }

    int inDegree(int v){
        int indegree = 0;
        for(int i=0;i<size;i++)
            if(ptr[i][v-1])
            indegree++;
        return indegree;
    }

    int outDegree(int v){
        int outdegree = 0;
        for(int i=0;i<size;i++)
            if(ptr[v-1][i])
            outdegree++;
        return outdegree;
    }

    void transposeGraph(bool** transpose){
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(ptr[i][j])
                    transpose[j][i] = true;
            }
        }
    }

    bool** getptr(){
        return ptr;
    }

    void neighbour(int v){
        for(int i=0;i<size;i++)
        if(ptr[v-1][i])
            cout  << i+1 << " ";
        cout << endl;
    }


};

class AdjacencyList{
public:

    int size;
    node** ptr;


    AdjacencyList(){
        size = 0;
        ptr = NULL;
    }

    AdjacencyList(int n){
        size = n;
        ptr = new node*[n];
        int i;
        for(i=0;i<n;i++)
            ptr[i] = NULL;
    }

   void insertEdge(int i, int j){
        node* temp = ptr[i-1];
        node* t = new node();
        t->data = j;
        t->next = NULL;
        if(temp!=NULL){
            while(temp->next!=NULL)
                temp = temp->next;
            temp->next = t;
        }
        else ptr[i-1] = t;
    }

    void printEdges(){
        int i;
        for(i=0;i<size;i++){
            node* temp = ptr[i];
            while(temp!=NULL){
                cout << i+1 << " " << temp->data << ",";
                temp = temp->next;
            }
        }
        cout << endl;
    }

    int outDegree(int v){
        int outdegree = 0;
        node* temp = ptr[v-1];
        while(temp!=NULL){
            outdegree++;
            temp = temp->next;
        }
        return outdegree;
    }

    int inDegree(int v){
        int i,indegree = 0;
        for(i=0;i<size;i++){
            node* temp = ptr[i];
            while(temp!=NULL){
                if(temp->data == v)
                    indegree++;
                temp = temp->next;
            }
        }
        return indegree;
    }

    void transposeGraph(AdjacencyList& transpose){
        for(int i=0;i<size;i++){
            node* temp = ptr[i];
            while(temp!=NULL){
                transpose.insertEdge(temp->data,i+1);
                temp = temp->next;
            }
        }
    }

    void neighbour(int v){
        node* temp = *(ptr+v-1);
        while(temp!=NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){


    int option;
    cout << "1) Use Adjacency List" << endl << "2) Use Adjacency Matrix" << endl;
    cin >> option;

    if(option == 1){
        int n;
        cout << "Enter the number of nodes: ";
        cin >> n;

        AdjacencyList adList(n);
        cout << "Enter edges separated by a comma: "; 
        char c = ',';
        int i,j;
        while(c != '.'){
        cin >> i >> j;
        adList.insertEdge(i,j);
        cin >> c;
        }

        cout << "Enter the vertex: ";
        cin >> i;
        cout << endl;

        cout << "Indegree: " << adList.inDegree(i) << endl;
        cout << "Outdegree: " << adList.outDegree(i) << endl;
        cout << "The neighbour of " << i << " are: ";
        adList.neighbour(i);

        AdjacencyList reverse(n);
        adList.transposeGraph(reverse);
        cout << "Reversed Graph is: ";
        reverse.printEdges();

    }

    else if(option == 2){
        int n;
        cout << "Enter the number of nodes: ";
        cin >> n;

        AdjMat adMat(n);
        cout << "Enter edges separated by a comma: ";

        char c = ',';
        int i,j;
        while(c != '.'){
        cin >> i >> j;
        adMat.insertEdge(i,j);
        cin >> c;
        }

 
        cout << "Enter the vertex: ";
        cin >> i;

        cout << endl;
        cout << "Indegree: " << adMat.inDegree(i) << endl;
        cout << "Outdegree: " << adMat.outDegree(i) << endl;
        cout << "The neighbour of " << i << " are: ";
        adMat.neighbour(i);

        AdjMat reverse(n);
        adMat.transposeGraph(reverse.getptr());
        cout << "Reversed Graph is: ";
        reverse.printEdges();

    }
    return 0;
}
