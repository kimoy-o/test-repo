#include <stdio.h>
#include <stdlib.h>

// Definition of a binary tree node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the BST
struct Node *insert(struct Node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }

    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }

    return root;
}

// Function to print the BST in a tree-like manner
void printTree(struct Node *root, int depth)
{
    if (root == NULL)
    {
        return;
    }

    // Print the right subtree
    printTree(root->right, depth + 1);

    // Print the current node
    for (int i = 0; i < depth; i++)
    {
        printf("    ");
    }
    printf("%d\n", root->data);

    // Print the left subtree
    printTree(root->left, depth + 1);
}

int main()
{
    struct Node *root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Binary Search Tree (Tree-like view):\n");
    printTree(root, 0);

    return 0;
}
