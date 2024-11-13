#include <bits/stdc++.h>
using namespace std;

class BinaryNode 
{
    public:
        int key;
        int height;
        BinaryNode *left, *right;
};

// To create new Node

BinaryNode* newNode1(int data) 
{
    BinaryNode* temp = new BinaryNode();
    temp->key = data;
    temp->left = NULL;
    temp->right = NULL;
    temp->height = 1;
    return temp;
}

// Display Function

BinaryNode* display(BinaryNode* root) 
{
    if (root == NULL) 
    {
        cout << "Tree empty";
    }
    queue<BinaryNode*> q;
    q.push(root);
    BinaryNode* front = NULL;
    while (!q.empty()) 
    {
        front = q.front();
        q.pop();
        cout << front->key << "->";
        if (front->left != NULL)
        {
            q.push(front->left);
        }
        if (front->right != NULL) 
        {
            q.push(front->right);
        }
    }
    cout <<"NULL"<<endl;
    return root;
}

// To get the Height of the tree

int getHeight(BinaryNode* node)
{
    if (node == NULL)
    {
        return 0;
    }
    return node->height;
}

// Right Rotate

BinaryNode* rotateRight(BinaryNode* disbalancedNode) 
{
    BinaryNode* newRoot = disbalancedNode->left;
    disbalancedNode->left = disbalancedNode->left->right;
    newRoot->right = disbalancedNode;
    disbalancedNode->height = 1 + max(getHeight(disbalancedNode->left), getHeight(disbalancedNode->right));
    newRoot->height = 1 + max(getHeight(newRoot->left), getHeight(newRoot->right));
    return newRoot;
}

// Left Rotate

BinaryNode* rotateLeft(BinaryNode* disbalancedNode)
{
    BinaryNode* newRoot = disbalancedNode->right;
    disbalancedNode->right = disbalancedNode->right->left;
    newRoot->left = disbalancedNode;
    disbalancedNode->height = 1 + max(getHeight(disbalancedNode->right), getHeight(disbalancedNode->left));
    newRoot->height = 1 + max(getHeight(newRoot->right), getHeight(newRoot->left));
    return newRoot;
}

// To check the Balance Factor

int getBalance(BinaryNode* node)
{
    if (node == NULL)
    {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

// Insertion

BinaryNode* insert(BinaryNode* node, int nodeValue) 
{
    if (node == NULL) 
    {
        BinaryNode* newNode = newNode1(nodeValue);
        return newNode;
    } 
    else if (nodeValue < node->key) 
    {
        node->left = insert(node->left, nodeValue);
    }
    else 
    {
        node->right = insert(node->right, nodeValue);
    }

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int balance = getBalance(node);

    if (balance > 1 && nodeValue < node->left->key)
    {
        return rotateRight(node);
    }
    if (balance > 1 && nodeValue > node->left->key) 
    {
        return rotateLeft(node);
    }
    if (balance < -1 && nodeValue > node->right->key) 
    {
        return rotateLeft(node);
    }

    if (balance < -1 && nodeValue < node->right->key) 
    {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    return node;
}

// To find the Minimum to delete the node

BinaryNode* minimum(BinaryNode* root) 
{
    if (root->left == NULL)
    {
        return root;
    } 
    else 
    {
        return minimum(root->left);
    }
}

// Deletion

BinaryNode* deleteNode(BinaryNode* root, int data) 
{
    if (root == NULL) 
    {
        cout << "Value not found in AVL";
        return NULL;
    }

    if (data < root->key) 
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->key) 
    {
        root->right = deleteNode(root->right, data);
    } 
    else
    {
        if (root->left != NULL && root->right != NULL)
        {
            BinaryNode* temp = root;
            BinaryNode* minNodeForRight = minimum(temp->right);
            root->key = minNodeForRight->key;
            root->right = deleteNode(root->right, minNodeForRight->key);
        } 
        else if (root->left != NULL)
        {
            root = root->left;
        } 
        else if (root->right != NULL) 
        {
            root = root->right;
        } 
        else 
        {
            root = NULL;
        }
    }

    if (root == NULL) return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0) 
    {
        return rotateRight(root);
    }

    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0) 
    {
        return rotateLeft(root);
    }

    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

// Main Function

int main() {
    BinaryNode* root = NULL;
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 15);
    root = insert(root, 20);
    root = insert(root, 25);
    root = insert(root, 30);
    root = insert(root, 35);
    root = display(root);
    root = deleteNode(root, 20);
    root = display(root);
    return 0;
}
