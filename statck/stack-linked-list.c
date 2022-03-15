#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void Push(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

void Pop()
{
    struct Node* temp;
    if(top == NULL) return;
    temp = top;
    top = top->next;
    free(temp);
}

int main()
{

}