#include <iostream>

using namespace std;

int main()
{   char a, qual;
    int yr;
    cout<< "Enter the gender of the individual: ";
    cin>>a;
    cout<<"Enter the year of service:";
    cin>>yr;
    cout<<"Enter the qualification (pg or g): ";
    cin>>qual;

        if(a=='m')
    {
      if(yr<10)
      {
          if(qual=='p')
            cout<<"Salary of the individual is:10000";
          if(qual=='g')
            cout<<"Salary of the individual is:7000";
      }
      else
      {
          if(qual=='p')
            cout<<"Salary of the individual is:15000";
          if(qual=='g')
            cout<<"Salary of the individual is:10000";
      }


    }
        if(a=='f')
        if(yr<10)
      {
          if(qual=='p')
            cout<<"Salary of the individual is:10000";
          if(qual=='g')
            cout<<"Salary of the individual is:6000";
      }
      else
      {
          if(qual=='p')
            cout<<"Salary of the individual is:12000";
          if(qual=='g')
            cout<<"Salary of the individual is:9000";
      }

    }


