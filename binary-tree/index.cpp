#include <iostream>
#include <queue>
using namespace std;

// node
struct Node
{
    int data;
    Node *left;  // left pointer
    Node *right; // right pointer
};

// function for creating a new node
Node *createNode(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// function for inserting a new node
Node *insert(Node *root, int data)
{
    // if the root is empty
    if (root == NULL)
    {
        root = createNode(data);
        return root;
    }
    else if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

bool find(Node *root, int data)
{
    if (root == NULL)
    {
        return false;
    }
    else if (data == root->data)
    {
        return true;
    }
    else if (data < root->data)
    {
        return find(root->left, data);
    }
    else
    {
        return find(root->right, data);
    }
}

Node *findMin(Node *root)
{
    if (root == NULL)
        return root;
    Node *temp = root;
    while (temp)
    {
        temp = temp->left;
    }

    return temp;
}

Node *findMax(Node *root)
{
    if (root == NULL)
        return root;
    Node *temp = root;
    while (temp)
    {
        temp = temp->right;
    }

    return temp;
}

int findHeight(Node *root)
{
    if (root == NULL)
        return -1;
    int left = findHeight(root->left);
    int right = findHeight(root->right);
    return max(left, right) + 1;
}
// breadth-first
void levelOrder(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> Q;
    Q.push(root);
    while (!Q.empty())
    {
        Node *current = Q.front();
        cout << current->data << " ";
        if (current->left != NULL)
            Q.push(current->left);
        if (current->right != NULL)
            Q.push(current->right);
        Q.pop();
    }
}
// depth-first
void preOrder(Node *root)
{
    if (root == NULL)
        return;
    // root left right
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node *root)
{
    // left root right
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(Node *root)
{
    if (root == NULL)
        return;
    // root left right
    postOrder(root->right);
    postOrder(root->left);
    cout << root->data << " ";
}

Node *deleteNode(Node *root, int data)
{
    if (root == NULL)
        return root;
    // find the node in the tree
    else if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    else
    {
        // if not child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        //  if only one child
        else if (root->left == NULL)
        {
            Node *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root;
            root = root->left;
            delete temp;
        }
        else
        {
            Node *temp = findMin(root->right);
        }
    }
    return root;
}

int main()
{
    Node *root = NULL;
    root = insert(root, 7);
    root = insert(root, 4);
    root = insert(root, 9);
    root = insert(root, 1);
    root = insert(root, 6);
    // root = insert(root, 17);
    // root = insert(root, 25);
    // root = insert(root, 1);
    cout << "In order : ";
    inOrder(root);
    cout << endl;
    cout << "Deleting a node :" << endl;
    deleteNode(root,6);
    cout << "In order : ";
    inOrder(root);

}