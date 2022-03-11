#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
// head node (global)
struct Node *head;

// helper function for creating a new node.
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNode(int data)
{
    struct Node *newNode = createNode(data);
    newNode->next = head;
    head = newNode;
}

void insertNodeAt(int data, int index)
{
    if (index == 1)
    {
        insertNode(data);
        return;
    }
    struct Node *newNode = createNode(data);
    struct Node *temp = head;
    for (int i = 0; i < index - 1; i++)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteNodeAt(int index)
{
    struct Node *temp = head;
    if (index == 1)
    {
        head = temp->next;
        free(temp);
        return;
    }
    for (int i = 0; i < index - 1; i++)
    {
        temp = temp->next;
    }
    struct Node *copy = temp->next;
    temp->next = copy->next;
    free(copy);
}

void reverseList()
{
    struct Node* curr,* next,* prev;
    curr = head;
    prev = NULL;

    while (curr)
    {
        
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

void printList()
{
    struct Node *temp = head;
    while (temp)
    {
        printf(" %i", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    head = NULL;
    for (int i = 0; i < 11; i++)
    {
        insertNode(i);
    }
    printList();
    reverseList();
    printList();

}