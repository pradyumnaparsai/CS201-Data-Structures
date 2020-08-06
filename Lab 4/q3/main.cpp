#include <iostream>
using namespace std;

void CocktailSort(int a[], int n)
{
    int swapped = 1;
    int start = 0;
    int end = n - 1;

    while (swapped==1) {
        swapped = 0;
        for (int i = start; i < end; ++i) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = 1;
            }
        }
        if (swapped==0)
            break;

        swapped =0;
        --end;

        for (int i = end - 1; i >= start; --i) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = 1;
            }
        }
        ++start;
    }
}
void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout<< a[i]<<" ";
}

int main()
{
    int n;
    cout<<"Enter the number of values: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the values to be sorted: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    CocktailSort(arr, n);
    cout<<"Sorted array :\n";
    printArray(arr, n);
    return 0;
}
