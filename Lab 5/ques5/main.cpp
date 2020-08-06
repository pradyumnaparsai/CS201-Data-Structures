#include<iostream>

using namespace std;

int heap[100];
int fr=-1, rear=-1;

int findMin(){
  return heap[fr];}

int findMax()
{
 int maxm;
  maxm= heap[fr];
  for(int i=fr; i<=rear;i++)
  {
   if(heap[i]> maxm)
    maxm= heap[i];
  }
  return maxm;
 }

void heapify(int i)
{
 int minm= i;
 int val;
 int l= 2*i+1, r= 2*i+2;
 if(l< rear && heap[minm] > heap[l])
  minm= l;
 if(r< rear && heap[minm] > heap[r])
  minm= r;
 if(minm!=i)
 {
  val= heap[i];
  heap[i]= heap[minm];
  heap[minm]= val;
  heapify(minm);
 }
}

int deleteMin()
{
 int val,i,l,r;
 val= heap[rear];
 heap[fr]= val;
 rear= rear-1;
 heapify(fr);

}

int delete_max()
{
 int check,key;
 for(int i=fr;i<rear;i++)
 {
  check=0;
  for(int j=fr;j<rear-i; j++)
  {
   if(heap[j]> heap[j+1])
   {
    key= heap[j];
    heap[j]= heap[j+1];
    heap[j+1]= key;
    check = 1;
   }
  }
  if(check==0)
   break;
 }
 rear= rear-1;
 heapify(fr);
}

void Insert(int n)
{
 int i,val;
 if(fr==-1)
 {
  fr= 0;
  rear= 0;
  heap[fr]= n;
 }
 else
 {
  rear= rear+1;
  heap[rear]= n;
  i = rear;
  while(heap[(i-1)/2]>n && i>0)
  {
   val = heap[i];
   heap[i]= heap[(i-1)/2];
   heap[(i-1)/2]= val;
   i= (i-1)/2;
  }
 }
}

int main()
{
 int n,k,p,i;
 cout<<"Input:\n";
 cin>>n;
 int A[n];
 for(int i=0;i<n;i++)
 {
  cin>>A[i];
  Insert(A[i]);
 }
 cin>>k;
 int top,num;
 int arr[k];
 for(i=0;i<k;i++)
     cin>>arr[i];
    cout<<"\nOutput:\n";
 for(i=0;i<k;i++){
    p=arr[i];

  if(p==1)
  {
   top= findMin();
   cout<<top<<endl;
   for(int i=fr;i<=rear;i++)
    cout<<heap[i]<<" ";
   cout<<endl;
  }
  else if(p==2)
  {
   top= findMax();
   cout<<top<<endl;
   for(int i=fr;i<=rear;i++)
    cout<<heap[i]<<" ";
   cout<<endl;
  }
  else if(p==3)
  {
   top= findMin();
   cout<<top<<endl;
   deleteMin();
   for(int i=fr;i<=rear;i++)
    cout<<heap[i]<<" ";
   cout<<endl;
  }
  else if(p==4)
  {
   top= findMax();
   cout<<top<<endl;
   delete_max();
   for(int i=fr;i<=rear;i++)
    cout<<heap[i]<<" ";
   cout<<endl;
  }
  else if(p==5)
  {

   cin>>num;
   Insert(num);
   for(int i=fr;i<=rear;i++)
    cout<<heap[i]<<" ";
   cout<<endl;
  }

 }
 }
