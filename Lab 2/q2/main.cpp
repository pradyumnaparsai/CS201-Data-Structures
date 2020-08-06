#include <iostream>
using namespace std;

void cofactor(int mat[N][N], int temp[N][N], int p, int q, int n)
{
    int i = 0, j = 0;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (row != p && col != q)
            {
                temp[i][j++] = mat[row][col];

                if (j == n - 1)
                {   j = 0;
                    i++;
                }
            }}}
}
int determinant(int mat[N][N], int n)
{
    int D = 0;
    if (n == 1)
    return mat[0][0];

    int temp[N][N];
    int sign = 1;

    for (int f = 0; f < n; f++)
    {
        cofactor(mat, temp, 0, f, n);
        D += sign * mat[0][f] * determinant(temp, n - 1);
        sign = -sign;
    }
    return D;
}

int main()
{
    int N;
    cout<<"Enter the size of the matrix: ";
    cin>>N;
    int arr[N][N];
    for(int i=0;i<N;i++)
        {
    for(j=0;j<N;j++)
    {
        cin>>arr[i][j];
    }}
    cout<<"Determinant of the matrix is : %d"<<determinant(arr, N);

    return 0;
}
