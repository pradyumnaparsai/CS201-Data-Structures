#include <iostream>
using namespace std;

void subset(string str, int index = 0, string temp = "")
{
    int n = str.length();
    if (index == n) {
        cout <<"\""<<temp<<"\""<<",";
        return;
    }
    subset(str, index + 1, temp + str[index]);
    subset(str, index + 1, temp);
}

int main()
{
    string str;
    cout<<"Enter the string: ";
    cin>>str;
    subset(str);
    return 0;
}
