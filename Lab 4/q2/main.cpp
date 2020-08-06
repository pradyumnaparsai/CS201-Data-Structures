 #include<iostream>
 #include<string.h>
 #include<stack>
 #include<ctype.h>

 using namespace std;

 int precedence(char c)
 {
     if(c=='/')
     return 4;
     if(c=='*')
     return 3;
     if(c=='+')
     return 2;
     if(c=='-')
     return 1;

     return 0;
 }

 int operate(int d1,int d2,char c)
 {
     if(c=='+')
     return d1+d2;
     if(c=='*')
     return d1*d2;
     if(c=='/')
     return d1/d2;
     if(c=='-')
     return d1-d2;
 }

 int result(string s)
 {
     int l=s.size();
     stack <int> val;
     stack <char> op;
     for(int i=0;i<l;i++)
     {
        if(s[i]=='('||s[i]=='['||s[i]=='{')
            op.push(s[i]);
        else if(isdigit(s[i]))
        {int d=0;
            while(isdigit(s[i])&&i<l)
            {
                d=d*10+(s[i]-'0');
                if(isdigit(s[i+1]))
                i++;
                else
                break;
            }
            val.push(d);
        }
        else if(s[i]==')')
        {int d1,d2;
         char c;
            while(!op.empty()&&(op.top()!='('))
            {
                d1=val.top();
                val.pop();
                d2=val.top();
                val.pop();
                c=op.top();
                op.pop();
                val.push(operate(d2,d1,c));
            }
            if(!op.empty())
            op.pop();
        }
        else if(s[i]=='}')
        {int d1,d2;
         char c;
            while(!op.empty()&&(op.top()!='{'))
            {
                d1=val.top();
                val.pop();
                d2=val.top();
                val.pop();
                c=op.top();
                op.pop();
                val.push(operate(d1,d2,c));
            }
            if(!op.empty())
            op.pop();
        }
        else if(s[i]==']')
        {int d1,d2;
         char c;
            while(!op.empty()&&(op.top()!='['))
            {
                d1=val.top();
                val.pop();
                d2=val.top();
                val.pop();
                c=op.top();
                op.pop();
                val.push(operate(d1,d2,c));
            }
            if(!op.empty())
            op.pop();

        }
        else
        {
            while(!op.empty()&&precedence(op.top())>precedence(s[i]))
            {int d1,d2;
             char c;
                d1=val.top();
                val.pop();
                d2=val.top();
                val.pop();
                c=op.top();
                op.pop();
                val.push(operate(d1,d2,c));
            }op.push(s[i]);
        }

     }
     while(!op.empty())
     {
         int d1,d2;
             char c;
                d1=val.top();
                val.pop();
                d2=val.top();
                val.pop();
                c=op.top();
                op.pop();
                val.push(operate(d1,d2,c));
     }
     return val.top();
 }
 int main()
 {
    string str1;
    cout<<"Enter the expression: ";
    cin>>str1;
    cout<<"\nResult is: "<<result(str1);


 return 0;
 }
