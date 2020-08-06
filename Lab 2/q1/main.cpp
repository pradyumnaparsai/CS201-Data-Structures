#include <iostream>
#include <string>

using namespace std;

string sortstring(string s, int a)
{
    char temp;
    int i,j;
     for (i = 0; i < a-1; i++) {
      for (j = i+1; j < a; j++) {
         if (s[i] > s[j]) {
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
         }
      }
   } return s;
}
int main()
{
    string s1,s2;
    cout<<"Enter the two strings in lowercase separated by space: ";
    cin>>s1; cin>>s2;
    if(s1.length()==s2.length())
    {
        int l=s1.length();
       s1=sortstring(s1,l);
       s2=sortstring(s2,l);
       for (int i = 0; i < l; i++)
       {if (s1[i] != s2[i])
       {cout<<"NO";
            break;}

    }
    cout<<"YES";}
    else
    {
        cout<<"NO";
    }
    return 0;
}
