#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>
using namespace std;

// reverse a string using stack

void Reverse(char C[], int n)
{
    stack<char> S;
    for (int i = 0; i < n; i++)
    {
        S.push(C[i]);
    }
    for(int i = 0; i < n; i++)
    {
        C[i] = S.top();
        S.pop();
    }
}

int main()
{
    char C[100];
    printf("Please enter a string: ");
    gets(C);
    Reverse(C, strlen(C));
    printf("Output = %s \n", C);
}