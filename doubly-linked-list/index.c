#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

// global variable
struct Node *head;

// create new node
struct Node *CreateNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// insert at head
void InsertAtHead(int data)
{
    struct Node *newNode = CreateNode(data);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }
}

// insert at tail
void InsertAtTail(int data)
{
    struct Node *newNode = CreateNode(data);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    else
    {
        // go all the way to the end
        struct Node *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        // last node.
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// print
void Print()
{
    struct Node *temp = head;
    while (temp)
    {
        printf(" %i", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// reverse print
void PrintReverse()
{
    struct Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    while (temp)
    {
        printf(" %i", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main()
{
    head = NULL;
    for (int i = 0; i < 10; i++)
    {
        InsertAtHead(i);
    }
    // PrintReverse();
    InsertAtTail(100);
    Print();
}