#include <bits/stdc++.h>
using namespace std;

void exchange(string s)
{
    stack<string> stack;
    string ans = "";
    int count = 0;
    for(char c:s)
    {
        if(c!=' ')
        {
            ans = ans + c;
            count = 1;
        }
        else if(c==' ' && count!=0)
        {
            stack.push(ans);
            ans = "";
            count = 0;
        }
    }
    stack.push(ans);
    while(!stack.empty())
    {
        cout << stack.top() << " ";
        stack.pop();
    }
}

int main() 
{
	string s;
	getline(cin,s);
	exchange(s);
	return 0;
}
