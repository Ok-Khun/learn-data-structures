#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 101

int A[MAX_SIZE];
int top = -1;

void Push(int data)
{
    if (top == MAX_SIZE - 1)
    {
        printf("Error: stack overflow \n");
        return;
    }
    top += 1;
    A[top] = data;
}

void Pop()
{
    if (top == -1)
    {
        printf("Error: No element to pop \n");
        return;
    }
    top -= 1;
}

int Top()
{
    return A[top];
}

int main()
{
    for(int i = 1; i < 10; i++){
        Push(i);
    }
    Pop(); // 9
    Pop(); // 8
    printf("%i \n", Top()); // 7
    Push(100);
    printf("%i \n", Top()); // 100

}   

// last in first out

// operations
// push
// pop
// top
// isEmpty

// scenario
// function calls/ recursion
// undo operations like ctrl + z
// balanced parentheses {()}

// can be implemented with arrays or linkedlist
// if implemented with array there will be an overflow.
// if overflow, we'll need to copy the existing array and create a new array doubling the size.
