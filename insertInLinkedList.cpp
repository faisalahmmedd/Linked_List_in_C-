#include<bits/stdc++.h>
#define ll long long int
using namespace std;

class Node{
   public:
      ll data;
      Node* next;

     Node(ll data)
     {
        this->data = data;
        next=nullptr;
     }
     Node(ll data,Node* next)
     {
        this->data = data;
        this->next = next;
     }

};

Node* arrayToLinkedList(vector<ll>& arr)
{
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(ll i=1; i<arr.size(); i++)
    {
        Node* temp=new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }



    return head;
}

void printLinkedList(Node* head)
{
    Node* temp = head;

    while(temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

Node* insertionAtHead(Node* head,ll value)
{
    return new Node(value,head);
}

Node* insertionAtTail(Node* head,ll value)
{
    if(head==NULL)
    {
        return new Node(value);
    }

    Node* temp = head;

    while(temp->next!=nullptr)
    {
        temp = temp->next;
    }

    Node* newNode = new Node(value);
    temp->next = newNode;
    

    return head;
}

Node* insertionAtKPosition(Node* head,ll position,ll value)
{
    if(head==NULL)
    {
        if(position==1)
        {
            return new Node(value,head);
        }
        else
           return head;
    }
    if(position==1)
    {
        return new Node(value,head);
    }

    ll cnt=0;
    Node* temp = head;

    while(temp != nullptr)
    {
        cnt++;

        if(cnt == position-1)
        {
            Node* newNode = new Node(value,temp->next);
            temp->next = newNode;
        }

        temp = temp->next;
    }


    return head;
}

Node* insertionBeforeValue(Node* head,ll value,ll element)
{
    if(head==nullptr)
    {
        return head;
    }

    if(head->data==value)
    {
        return new Node(value,head);
    }

    Node* temp = head;

    while(temp->next != nullptr)
    {
        if(temp->next->data == value)
        {
            Node* newNode = new Node(element,temp->next);
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }

    return head;
}

int main()
{
   vector<ll> arr={3,5,2,7,9,1};

   Node* head = arrayToLinkedList(arr);

   cout<<"The initial Linked List: ";
   printLinkedList(head);

   head = insertionAtHead(head,25);

   cout<<"The Linked List after insertion in head: ";
   printLinkedList(head);

   head = insertionAtTail(head,50);

   cout<<"The Linked List after insertion in tail: ";
   printLinkedList(head);

   head = insertionAtKPosition(head,7,99);


   cout<<"The Linked List after insertion in K'th position: ";
   printLinkedList(head);
   
   head = insertionBeforeValue(head,2,88);

   cout<<"The Linked List after insertion a element before a value : ";
   printLinkedList(head);


    return 0;
}