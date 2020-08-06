#include<iostream>
using namespace std;
int main()
{
    string s1,s2;
    cout<<"Enter string 1: ";
    cin>>s1;
    cout<<"Enter string 2: ";
    cin>>s2;
    int l1=s1.size(),l2=s2.size();
    int lcs[l1+1][l2+1];						
    for(int i=0;i<=l1;i++)
    {
        for(int j=0;j<=l2;j++)
        {
            if(i==0||j==0)						
            {
                lcs[i][j]=0;
            }
            else if(s1[i-1]==s2[j-1])
            {
                lcs[i][j]=lcs[i-1][j-1]+1;			
            }							
            else
            {
                lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);			
            }

        }

    }
    int k=lcs[l1][l2];
    //k is the length of longest common subsequence
    char commonseq[lcs[l1][l2]+1];			
    //character array storing longest common subsequence
    int i=l1,j=l2;
    while(i>0&&j>0)
    {
        if(s1[i-1]==s2[j-1])						
        {
            commonseq[--k]=s1[--i];
            j--;
        }
        else if(lcs[i-1][j]>lcs[i][j-1])				
            i--;
        else
            j--;
    }
    for(i=0;i<lcs[l1][l2];i++)
        cout<<commonseq[i];
    return 0;
}
