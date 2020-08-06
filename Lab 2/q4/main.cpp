#include <iostream>
using namespace std;

int main()
{
    int r,c,count, num, first, last, middle;
    cout<<"Enter the size of the matrix(rows,columns) followed by elements of the matrix and lastly element to be searched: "<<endl;
    cin>>r>>c;
    int arr[r][c];

    for(int a=0;a<r;a++)
        {
        for(int b=0;b<c;b++)
            {
        cin>>arr[a][b];
                }
        }
    cin>>num;
    int arr1[r*c];
    int q=0;
    while(q<r*c)
    {
        for(int a=0;a<r;a++)
        {
        for(int b=0;b<c;b++)
            {
         arr1[q]=arr[a][b];
         q++;
            }}
    }

    count=r*c;
	first = 0;
	last = count-1;
	middle = (first+last)/2;
	while (first <= last)
	{
	   if(arr1[middle] < num)
	   {
		first = middle + 1;

	   }
	   else if(arr1[middle] == num)
	   {
		cout<<"FOUND";
                break;
           }
           else {
                last = middle - 1;
           }
           middle = (first + last)/2;
        }
        if(first > last)
	{
	   cout<<num<<"NOT FOUND";
	}
	return 0;
}

