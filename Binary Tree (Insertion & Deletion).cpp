#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int key;
    Node*left,*right;
};
Node* newnode(int data)
{
    Node* n=new Node();
    n->key=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}   
Node* insert_node(int data,Node* root)
{
    Node* nn = newnode(data);
    if(root == NULL)
    {
        root=nn;
    }
    else
    {
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            Node *present=q.front();
            q.pop();
            if(present->left==NULL)
            {
                present->left = nn;
                break;
            }
            else if(present->right==NULL)
            {
                present->right = nn;
                break;
            }
            else
            {
                q.push(present->left);
                q.push(present->right);
            }
        }
    }
    return root;
}

int find_lastelement(Node* root)
{
    Node* temp = NULL;
    if(root == NULL)
    {
        cout << "No element" << " ";
    }
    else
    {
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            temp = q.front();
            q.pop();
            if(temp->left != NULL)
            {
                q.push(temp->left);
            }
            if(temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
    return temp->key;
}

Node* delete_last(Node* root)
{
    if(root == NULL)
    {
        cout << "No element" << " ";
    }
    else
    {
        queue<Node*> q;
        q.push(root);
        Node* present = q.front();
        Node* prev = NULL;
        while(!q.empty())
        {
            if(present->left == NULL)
            {
                prev->right = NULL;
            }
            if(present->right == NULL)
            {
                present->left = NULL;
            }
            if(present->left != NULL)
            {
                q.push(present->left);
            }
            if(present->right != NULL)
            {
                q.push(present->right);
            }
            prev = present;
            q.pop();
            present = q.front();
        }
    }
    return root;
}

Node* delete_element(int data,Node* root)
{
    if(root == NULL)
    {
        cout << "No elements" << " ";
    }
    else
    {
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            Node* present = q.front();
            q.pop();
            if(present->key == data)
            {
                present->key = find_lastelement(root);
                root = delete_last(root);
            }
            if(present->left != NULL)
            {
                q.push(present->left);
            }
            if(present->right != NULL)
            {
                q.push(present->right);
            }
        }
    }
    return root;
}



Node* display(Node* root)
{
    if(root == NULL)
    {
        cout<<"No Elements"<<endl;
    }
    else
    {
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            Node *present=q.front();
            cout << present->key <<"->";
            q.pop();
            if(present->left!=NULL)
            {
                q.push(present->left);
            }
            if(present->right!=NULL)
            {
                q.push(present->right);
            }
        }
    }
    cout<<"NULL";
    cout<<endl;
    return root;
}

int main(){
    Node* root = NULL;
    root=insert_node(30,root);
    root=insert_node(20,root);
    root=insert_node(10,root);
    root=insert_node(5,root);
    root=insert_node(15,root);
    root=insert_node(8,root);
    root=insert_node(2,root);
    root=display(root);
    root=delete_element(3,root);
    root=display(root);
    cout<<a;
}
