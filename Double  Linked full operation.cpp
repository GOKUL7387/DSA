#include <bits/stdc++.h>
using namespace std;

//class

class Node
{
    public:
    Node*prev;
    int key;
    Node*next;
};

//creating newnode

Node*newnode(int data)
{
    Node*n=new Node();
    n->prev=NULL;
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
        head->prev=nn;
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
        nn->prev=temp;
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
    else if(pos==1)
    {
        head=insert_begin(data,head);
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
            temp->next->prev=nn;
            nn->prev=temp;
            temp->next=nn;
        }
        else if((count+1)==pos)
        {
            head=insert_end(data,head);
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
        Node*temp=head;
        head=head->next;
        head->prev=NULL;
        temp->next=NULL;
    }
    return head;
}

//delete at end

Node*delete_end(Node*head)
{
    Node* temp = head;
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
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        Node*temp1=temp->next;
        temp1->prev=NULL;
        temp->next=NULL;
    }
    return head;
}

//delete at middle

Node* Delete(Node*head,int pos)
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
        Node* temp = head;
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
            if(temp->next->next == NULL)
            {
                head = delete_end(head);
            }
            else
            {
                Node* temp1 = temp->next;
                temp->next = temp1->next;
                temp1->next->prev = temp1->prev;
                temp1->next = NULL;
                temp1->prev = NULL;
            }
        }
        else
        {
            cout<<"Cannot delete,Limit Exceed"<<endl;
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
        return head;
    }
    else
    {
        Node*temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        head=temp;
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

//to diplay reverse linked list

Node*display_reverse(Node*head)
{
    Node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->key<<"->";
        temp=temp->prev;
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
    head=Delete(head,3);
    head=insert_mid(25,head,3);
    head=display(head);
    head=reverse(head);
    head=display_reverse(head);
}
