#include <bits/stdc++.h>
using namespace std;

int result(string s)
{
    stack<int>stack;
    for(int i=0;i<s.size();i++)
    {
        int num=s[i]-'0';
        if(num>=0 && num<=9)
        {
            stack.push(num);
        }
        else if(s[i]=='+' || s[i]=='-' || s[i]=='*'  || s[i]=='%' || s[i]=='/')
        {
            if(s[i]=='+')
            {
                int num1=stack.top();
                stack.pop();
                int num2=stack.top();
                stack.pop();
                num1 = num1+num2;
                stack.push(num1);
            }
            else if(s[i]=='-')
            {
                int num1=stack.top();
                stack.pop();
                int num2=stack.top();
                stack.pop();
                num1 = num1-num2;
                stack.push(num1);
            }
            else if(s[i]=='*')
            {
                int num1=stack.top();
                stack.pop();
                int num2=stack.top();
                stack.pop();
                num1 = num1*num2;
                stack.push(num1);
            }
            else if(s[i]=='%')
            {
                int num1=stack.top();
                stack.pop();
                int num2=stack.top();
                stack.pop();
                num1 = num1%num2;
                stack.push(num1);
            }
            else if(s[i]=='/')
            {
                int num1=stack.top();
                stack.pop();
                int num2=stack.top();
                stack.pop();
                num1 = num1/num2;
                stack.push(num1);
            }
        }
    }
    int x=stack.top();
    return x;
}

int main()
{
    string s;
    getline(cin,s);
    cout<<result(s);
    return 0;
}
