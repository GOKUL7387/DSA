#include <bits/stdc++.h>
using namespace std;

//class

class Node
{
    public:
    int key;
    Node*next;
};

//creating newnode

Node*newnode(int data)
{
    Node*n=new Node();
    n->key=data;
    n->next=NULL;
    return n;
}

//inserting at first

Node*push(int data,Node*top)
{
    Node*nn=newnode(data);
    if(top==NULL)
    {
        top=nn;
    }
    else
    {
        nn->next=top;
        top=nn;
    }
    return top;
}

//delete at first

Node*pop(Node*top)
{
    if(top==NULL)
    {
        cout<<"Empty"<<endl;
    }
    else
    {
        top=top->next;
    }
    return top;
}

//display function
//To display the linked list

Node*display(Node*top)
{
    Node*temp=top;
    while(temp!=NULL)
    {
        cout<<temp->key<<" "<<endl;
        temp=temp->next;
    }
    cout<<endl;
    return top;
}

//Main function

int main()
{
    Node*top=NULL;
    top=push(10,top);
    top=push(20,top);
    top=push(30,top);
    top=push(40,top);
    top=push(50,top);
    top=display(top);
    top=pop(top);
    top=pop(top);
    top=display(top);
}
