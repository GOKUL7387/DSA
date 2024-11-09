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

Node*insert_begin(int data,Node*head)
{
    Node*nn=newnode(data);
    if(head==NULL)
    {
        head=nn;
    }
    else
    {
        nn->next=head;
        head=nn;
    }
    return head;
}

//inserting at end

Node*insert_end(int data,Node*head)
{
    Node*nn=newnode(data);
    if(head==NULL)
    {
        head=nn;
    }
    else
    {
        Node*temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=nn;
    }
    return head;
}

//inserting at middle

Node*insert_mid(int data,Node*head,int pos)
{
    Node*nn=newnode(data);
    if(head==NULL)
    {
        head=nn;
    }
    else
    {
        int count=1;
        Node*temp=head;
        while(temp->next!=NULL)
        {
            count++;
            if(count==pos)
            {
                break;
            }
            temp=temp->next;
        }
        if(count==pos)
        {
            nn->next=temp->next;
            temp->next=nn;
        }
        else if(pos==1)
        {
            head=insert_begin(data,head);
        }
        else
        {
            cout<<"Invalid Position"<<endl;
        }
    }
    return head;
}

//delete at first

Node*delete_begin(Node*head)
{
    if(head==NULL)
    {
        cout<<"Empty"<<endl;
    }
    else
    {
        head=head->next;
    }
    return head;
}

//delete at end

Node*delete_end(Node*head)
{
    if(head==NULL)
    {
        cout<<"Empty"<<endl;
    }
    else if(head->next==NULL)
    {
        head=delete_begin(head);
    }
    else
    {
        Node*temp=head;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=NULL;
    }
    return head;
}

//delete at middle

Node*delete_mid(Node*head,int pos)
{
    if(head==NULL)
    {
        cout<<"Empty"<<endl;
    }
    else if(pos==1)
    {
        head=delete_begin(head);
    }
    else
    {
        int count=1;
        Node*temp=head;
        while(temp->next!=NULL)
        {
            count++;
            Node*temp1=temp->next;
            if(count==pos)
            {
                temp->next=temp1->next;
                temp1->next=NULL;
                break;
            }
            temp=temp->next;
        }
    }
    return head;
}

//searching an element

Node* search(int data,Node*head)
{
    Node*temp=head;
    int count=0;
    while(temp->next!=NULL)
    {
        if(temp->key==data)
        {
            count++;
            cout<<"Value present"<<endl;
        }
        temp=temp->next;
    }
    if(count==0)
    {
        cout<<"Value not present"<<endl;
    }
    return head;
}

//reversing a linked list

Node*reverse(Node*head)
{
    Node*temp1,temp2,temp3;
    if(head==NULL)
    {
        cout<<"List Empty"<<endl;
    }
    else if(head->next==NULL)
    {
        cout<<"List contain one value"<<endl;
    }
    else
    {
        Node*temp1=NULL;
        Node*temp2=head;
        Node*temp3=head->next;
        while(temp3!=NULL)
        {
            temp2->next=temp1;
            temp1=temp2;
            temp2=temp3;
            temp3=temp2->next;
        }
        temp2->next=temp1;
        head=temp2;
    }
    return head;
}

//display function
//To display the linked list

Node*display(Node*head)
{
    Node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->key<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
    cout<<endl;
    return head;
}

//Main function

int main()
{
    Node*head=NULL;
    head=insert_begin(20,head);
    head=insert_begin(10,head);
    head=insert_end(50,head);
    head=insert_end(30,head);
    head=insert_mid(15,head,2);
    head=delete_begin(head);
    head=delete_end(head);
    head=delete_mid(head,4);
    head=search(10,head);
    head=display(head);
    head=reverse(head);
    head=display(head);
}
