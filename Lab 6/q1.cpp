#include <bits/stdc++.h>
using namespace std;

void countSort(int array[], int size) {
  int output[1000];
  int count[1000];
  int max = array[0];
  for (int i = 1; i < size; i++) {
    if (array[i] > max)
      max = array[i];
  }
  //max eelement
  for (int i = 0; i <= max; ++i) {
    count[i] = 0;
  }
  //count storing
  for (int i = 0; i < size; i++) {
    count[array[i]]++;
  }
  //cummulative count
  for (int i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }

  for (int i = size - 1; i >= 0; i--) {
    output[count[array[i]] - 1] = array[i];
    count[array[i]]--;
  }

  // sorted elements into orginal array
  for (int i = 0; i < size; i++) {
    array[i] = output[i];
  }
}

int getMax(int array[], int n) {
  int max = array[0];
  for (int i = 1; i < n; i++)
    if (array[i] > max)
      max = array[i];
  return max;
}

void countingSort(int array[], int size, int place) {
  const int max = 10;
  int output[size];
  int count[max];

  for (int i = 0; i < max; ++i)
    count[i] = 0;

  for (int i = 0; i < size; i++)
    count[(array[i] / place) % 10]++;

  for (int i = 1; i < max; i++)
    count[i] += count[i - 1];

  for (int i = size - 1; i >= 0; i--) {
    output[count[(array[i] / place) % 10] - 1] = array[i];
    count[(array[i] / place) % 10]--;
  }

  for (int i = 0; i < size; i++)
    array[i] = output[i];
}

void radixsort(int array[], int size) {
  int max = getMax(array, size);

  for (int place = 1; max / place > 0; place *= 10)
    countingSort(array, size, place);
}

void bucketSort(int arr[], int size) {
  int max, bucket = 10, divider, i, j, k;
  vector<int> B[bucket];

  max = getMax(arr, size);

  divider = ceil(float(max + 1) / bucket);
  for(i = 0; i < size; i++) {
    j = floor( arr[i] / divider );
    B[j].push_back(arr[i]);
  }

  for(i = 0; i < bucket; i++) {
    sort(B[i].begin(), B[i].end());
  }

  k = 0;
  for(i = 0; i < bucket; i++) {
    for(j = 0; j < B[i].size(); j++) {
      arr[k++] = B[i][j];
    }
  }
}

void printArray(int array[], int size) {
  for (int i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}

int main() {
    clock_t start, end,t;
    int x;
    cout<<"Please select an algorithm to perform the sorting: \n";
    cout<<"1. Radix Sort\n";
    cout<<"2. Counting Sort\n";
    cout<<"3. Bucket Sort\n";
    cin>>x;
    int n;
    cout<<"Please enter the number of elements and the elements to be sorted.\n";
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    if(x==1){
        start = clock();
        radixsort(array,n);
        end = clock();
        double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        printArray(array, n);
        cout << "Time taken by program is : " << fixed
        << time_taken << setprecision(5);
        cout << " sec " << endl;

    }
    if(x==2){
        t = clock();
        countSort(array, n);
        t = clock() - t;
        double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        printArray(array, n);
        cout<<time_taken;
    }
    if(x==3){
        t = clock();
        bucketSort(array, n);
        t = clock() - t;
        double time_taken = ((double)t)/CLOCKS_PER_SEC;
        printArray(array, n);
        cout<<time_taken;
    }


}
