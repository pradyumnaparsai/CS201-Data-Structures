#include <iostream>
#include <queue>
using namespace std;

void printqueue(queue<int> Queue)
{
    while (!Queue.empty()) {
        cout << Queue.front() << " ";
        Queue.pop();
    }
}

void reversequeue(queue<int>& q)
{
    if (q.empty())
        return;
    int data = q.front();
    q.pop();
    reversequeue(q);
    q.push(data);
}


int main()
    {
        int n;
        cout<<"Enter the size of the queue: ";
        cin>>n;
        queue<int> q;
        cout<<"Enter the "<<n<<" values: ";
        for(int i=0; i<n; i++)
        {   int a;
            cin>>a;
            q.push(a);
        }
        reversequeue(q);
        cout<<"Reversed queue is : ";
        printqueue(q);
        return 0;
    }
