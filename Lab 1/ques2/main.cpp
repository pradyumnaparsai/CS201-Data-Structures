#include <iostream>

using namespace std;

int main()
{
    int n1=1,n2=1,n3,n;
 cout<<"Enter the value of n: ";
    cin>>n;
 if(n==1)
     cout<<n1;
 else{
 cout<<n1<<" "<<n2<<" ";

    for(int i=2; i<n; i++)
            {
                n3=n1+n2;
                cout<<n3<<" ";
                n1=n2;
                n2=n3;
            }
 }
   return 0;
   }
