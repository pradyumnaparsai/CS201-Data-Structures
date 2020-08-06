#include <bits/stdc++.h>

using namespace std;

void ParenthesisOrder(int i, int j, int n, int *s, int& index){

    if (i == j)
    {
        cout << "A" << "_" << index;
        index++;
        return;
    }

    cout << "(";
    ParenthesisOrder(i,*((s+i*n)+j),n,s,index);
    ParenthesisOrder(*((s+i*n)+j)+1,j,n,s,index);
    cout << ")";
}


void parenthesis(int arr[], int n){

    int m[n+1][n+1],s[n+1][n+1];
    int i,j,k;
    for(i=0;i<=n;i++){
        m[i][i] = 0;
        s[i][i] = 0;
    }

    int l = 2;
    for(;l<=n;l++){
        for(i=1;i<=n-l+1;i++){
            j = i+l-1;
            m[i][j] = INT_MAX;
            for(k=i;k<=j-1;k++){
                int q = m[i][k] + m[k+1][j] + arr[i-1]*arr[k]*arr[j];
                if(q < m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    cout << "Optimal parenthesis cost is: " << m[1][n] << endl;
    cout << "Optimal parenthesis sequence is: ";
    int index = 1;
    ParenthesisOrder(1,n,n+1,(int*)s,index);
    cout << endl;
}



int main(){

    int n;
    cout << "Enter number of matrices to be multiplied: ";
    cin >> n;

    int p[n+1];

    cout << "Enter the dimensions of the matrices: ";
    for(int i=0;i<n+1;i++){

        cin >> p[i];
    }
    parenthesis(p,n);
    return 0;
}
