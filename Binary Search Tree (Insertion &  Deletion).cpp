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
        root = nn;
    }
    else
    {
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            Node* temp = q.front();
            q.pop();
            if(temp->key > nn->key)
            {
                if(temp->left == NULL)
                {
                    temp->left = nn;
                    break;
                }
                else if(temp->left != NULL)
                {
                    q.push(temp->left);
                }
            }
            if(temp->key < nn->key)
            {
                if(temp->right == NULL)
                {
                    temp->right = nn;
                    break;
                }
                else if(temp->right != NULL)
                {
                    q.push(temp->right);
                }
            }
        }
    }
    return root;
}

Node* min(Node* root)
{
    if(root->left==NULL)
    {
        return root;
    }
    else
    {
        return min(root->left);
    }
}

Node* deletenode(Node* root,int data)
{
    if(root==NULL)
    {
        cout<<"value not found";
        return NULL;
    }
    if(data < root->key)
    {
        root->left=deletenode(root->left,data);
    }
    else if(data > root->key)
    {
        root->right=deletenode(root->right,data);
    }
    else
    {
        if(root->left!=NULL && root->right!=NULL)
        {
            Node*temp=root;   
            Node*minNodeForRight=min(temp->right);
            root->key=minNodeForRight->key;
            root->right=deletenode(root->right,minNodeForRight->key);
        }
        else if(root->left!=NULL)
        {
            root=root->left;
        }
        else if(root->right!=NULL)
        {
            root=root->right;
        }
        else
        {
            root=NULL;
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
    root=insert_node(60,root);
    root=insert_node(56,root);
    root=insert_node(35,root);
    root=insert_node(48,root); 
    root=insert_node(7,root);
    root=insert_node(61,root);
    root=insert_node(82,root);
    root=insert_node(96,root);
    root=insert_node(66,root);
    root=insert_node(10,root);
    root=display(root);
    root=deletenode(root,48);
    root=display(root);
}
