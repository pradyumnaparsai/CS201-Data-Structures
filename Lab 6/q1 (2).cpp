#include<bits/stdc++.h>
using namespace std;

void bucketsort(float *a,int n)
{
    vector<float> b[n];
    for (int i=0; i<n; i++)
    {
       b[int(n*a[i])].push_back(a[i]);
    }
    for (int i=0; i<n; i++)
       sort(b[i].begin(), b[i].end());
    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
          a[index++] = b[i][j];
}
//creating n buckets, pushing (array values)*n to respective bucket
//sorting individual bucket
//merging all the buckets  together

void countsort(int *a,int n,int max)
{
    int count[max+1]={0},b[n+1];

    for(int i=0;i<n;i++)
    {
        count[a[i]]++;
    }

    for(int i=1;i<=max;i++)
    {
        count[i]+=count[i-1];
    }
    for(int i=0;i<n;i++)
    {
        b[count[a[i]]-1]=a[i];
        count[a[i]]--;
    }
    for(int i=0;i<n;i++)
        cout<<b[i]<<" ";
}
//count array to store the range of number according to their occurrence
//updating the count array
//storing values in the new array in sorted manner

void radixsort(int *a,int n,int j)
{
    int count[10]={0},b[n+1];

    for(int i=0;i<n;i++)
    {
        count[(a[i]/j)%10]++;
    }

    for(int i=1;i<10;i++)
    {
        count[i]+=count[i-1];
    }

    for(int i=n-1;i>=0;i--)
    {
        b[count[(a[i]/j)%10]-1]=a[i];
        count[(a[i]/j)%10]--;
    }
    for(int i=0;i<n;i++)
        a[i]=b[i];
}
//j is the digit's place by which elements are being stored like unit's place ten's place
//sorting takes place according to j, i.e if j is one's then sorting according to the last digit takes place

int main()
{
    int x;
    cout<<"Please select an algorithm to perform sorting:\n1) Radix Sort\n2) Counting sort\n3) Bucket sort\n";
    cin>>x;

	if(x==1)
    {
        int a[1000],n,max=0,i,j=1;
        cout<<"Enter number of elements and elements to be sorted: ";
        cin>>n;
        for( i=0;i<n;i++)
        {
            cin>>a[i];
            if(max<a[i])
                max=a[i];
        }
        int temp=max;
        clock_t start, end;
        start=clock();
        cout<<"Sorted array: ";
        for(;temp!=0;)
        {
            temp/=10;
            radixsort(a,n,j);
            j*=10;
        }
        for(int i=0;i<n;i++)
            cout<<a[i]<<" ";
        end=clock();
        double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout << "\nTime taken by program is : " << fixed<< time_taken << setprecision(10);
        cout << " sec " << endl;
    }

    if(x==2)
    {
        int a[1000],n,max=0;
        cout<<"Enter number of elements and elements to be sorted: ";
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(max<a[i])
            max=a[i];
        }

        clock_t start, end;
        start=clock();
        cout<<"Sorted array: ";
        countsort(a,n,max);
        end=clock();
        double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout << "\nTime taken by program is : " << fixed<< time_taken << setprecision(5);
        cout << " sec " << endl;
        ;
    }
    
	if(x==3)
    {
        float a[1000];
        int n,i;
        cout<<"Enter number of elements and elements to be sorted: ";
        cin>>n;
        for( i=0;i<n;i++)
        {
            cin>>a[i];
        }
        clock_t start, end;
        start=clock();
        cout<<"Sorted array: ";
        bucketsort(a,n);
        for(int i=0;i<n;i++)
            cout<<a[i]<<" ";
        end=clock();
        double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout << "\nTime taken by program is : " << fixed<< time_taken << setprecision(5);
        cout << " sec " << endl;
    }

    return 0;

}
