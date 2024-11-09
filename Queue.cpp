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

Node*enqueue(int data,Node*top)
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

//delete at end

Node*dequeue(Node*top)
{
    if(top==NULL)
    {
        cout<<"Empty"<<endl;
    }
    else
    {
        Node*temp=top;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=NULL;
    }
    return top;
}

//display function

Node*display(Node*top)
{
    Node*temp=top;
    while(temp!=NULL)
    {
        cout<<temp->key<<endl;
        temp=temp->next;
    }
    cout<<endl;
    return top;
}

//Main function

int main()
{
    Node*top=NULL;
    top=enqueue(10,top);
    top=enqueue(20,top);
    top=enqueue(30,top);
    top=enqueue(40,top);
    top=enqueue(50,top);
    top=display(top);
    top=dequeue(top);
    top=dequeue(top);
    top=display(top);
}
