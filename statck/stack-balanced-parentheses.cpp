#include <iostream>
#include <stack>
using namespace std;

char OpenOf(char c)
{
    if (c == ')')
    {
        return '(';
    }
    else if (c == ']')
    {
        return '[';
    }
    else if (c == '}')
    {
        return '{';
    }
    else
    {
        return '\0';
    }
}

bool isOpen(char c)
{
    return c == '(' || c == '[' || c == '{';
}

bool isClose(char c)
{
    return c == ')' || c == ']' || c == '}';
}

int main()
{
    stack<char> S;
    string example = "[()]{}{[()()]()}";  // you can change this to check if the 
    int stackLength = 0;
    for (int i = 0; i < example.length(); i++)
    {
        if (isOpen(example[i]))
        {
            S.push(example[i]);
            stackLength += 1;
        }
        else if (isClose(example[i]))
        {
            if(S.top() == OpenOf(example[i]))
            {
                S.pop();
                stackLength -= 1;
            } else {
                break;
            }
        }
    }
    cout << stackLength << endl; // 0 = balanced | not balanced.
}