#include <bits/stdc++.h>
using namespace std;

bool isbalanced(string exp)
{
    if(exp.length()&1)    //Find the length of the string is odd or even
    {
        return false;
    }
    stack<char> stack;
    int i;
    for(i=0;i<exp.size();i++)
    {
        char ch=exp[i];
        if(ch=='(' || ch=='{' || ch=='[')
        {
            stack.push(ch);
        }
        if(ch==')' || ch=='}' || ch==']')
        {
            if(stack.empty())
            {
                return false;
            }
            char top=stack.top();
            stack.pop();
            if((top=='(' && ch!=')') || (top=='{' && ch!='}') || (top=='[' && ch!=']'))
            {
                return false;
            }
        }
    }
    return stack.empty();
}

int main()
{
    string exp="{()}[{}]";
    if(isbalanced(exp))
    {
        cout<<"The expression is balanced";
    }
    else
    {
        cout<<"The expression is not balanced";
    }
    return 0;
}
