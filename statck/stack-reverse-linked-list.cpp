// #include <stdio.h>
// #include <stdlib.h>
#include <iostream>
#include <stack>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;

// create node.
struct Node *createNode(int data)
{
    struct Node *newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// insert node
void insertNode(int data)
{
    struct Node *newNode = createNode(data);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    else
    {
        newNode->next = head;
        head = newNode;
        return;
    }
}
// print nodes
void printNodes()
{
    struct Node *temp = head;
    while (temp)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

void reverseNodes()
{
    stack<struct Node*> S;
    struct Node *temp = head;
    while (temp)
    {
        S.push(temp);
        temp = temp->next;
    }

    temp = S.top();
    head = temp;
    S.pop();

    while (!S.empty())
    {
        temp->next = S.top();
        S.pop();
        temp = temp->next;
    }
    temp->next = NULL;
}

int main()
{
    head = NULL;
    for (int i = 0; i < 11; i++)
    {
        insertNode(i);
    }
    cout << "List:" << endl;
    printNodes();
    cout << "Reversed List:" << endl;
    reverseNodes();
    printNodes();
}