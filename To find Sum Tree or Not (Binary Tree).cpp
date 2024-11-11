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
bool sum_tree(Node* root)
{
    if(root == NULL)
    {
        cout<<"No elements"<<endl;
    }
    else
    {
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            Node* present = q.front();
            q.pop();
            if(present->left != NULL && present->right != NULL)
            {
                Node* left_element = present->left;
                Node* right_element = present->right;
                int sum = left_element->key + right_element->key;
                if(sum != present->key)
                {
                    return false;
                }
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
    return true;
}
int main()
{
    Node* root = NULL;
    root=insert_node(30,root);
    root=insert_node(20,root);
    root=insert_node(10,root);
    root=insert_node(5,root);
    root=insert_node(15,root);
    root=insert_node(8,root);
    root=insert_node(2,root);
    root=display(root);
    bool a=sum_tree(root);
    cout<<a;
}
