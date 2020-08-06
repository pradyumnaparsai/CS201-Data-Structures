#include <iostream>

using namespace std;
 int factorial(int a)
    {
        if (a==1)
        {
            return 1;
        }
        else
        return a*factorial(a-1);
    }


int main()
{   int a;
    cout <<"Enter the number(>=1) whose factorial is to be calculated: ";
    cin >>a;
    cout <<"The factorial of "<<a<<" is: "<< factorial(a);
    return 0;
}
