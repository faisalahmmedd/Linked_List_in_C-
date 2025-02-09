#include<bits/stdc++.h>
#define ll long long 
using namespace std;

class Node{
   public:
      ll data;
      Node* next;
      Node* prev;

      Node(ll data1,Node* next1,Node* prev1)
      {
        data = data1;
        next = next1;
        prev = prev1;
      }

      Node(ll data1)
      {
         data = data1;
         next = nullptr;
         prev = nullptr;
      }
};

Node* arrayToDoublyLinkedList(vector<ll>&arr)
{
    Node* head = new Node(arr[0]);
    Node* back = head;

    for(ll i=1; i<arr.size(); i++)
    {
        Node* temp = new Node(arr[i]);
        back->next = temp;
        temp->prev=back;
        back = temp;
    }

    return head;
}

void printDoublyLinkedList(Node* head)
{
    Node* temp = head;

    while(temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    cout<<endl;
}

Node* insertionBeforeHead(Node* head,ll value)
{
    Node* newHead = new Node(value,head,nullptr);
    head->prev = newHead;
    
    return newHead;
}

Node* insertionAfterHead(Node* head,ll value)
{
    if(head->next==nullptr)
    {
        Node* newNode = new Node(value);
        head->next = newNode;
        newNode->prev = head;
        return head;
    }

    Node* newNode = new Node(value);
    Node* temp = head->next;

    head->next = newNode;
    newNode->prev = head;

    newNode->next=temp;
    temp->prev=newNode;

    return head;
}

Node* insertionBeforeTail(Node* head,ll value)
{
    if(head->next==nullptr)
    {
        return insertionBeforeHead(head,value);
    }

    Node* tail = head;

    while(tail->next != nullptr)
    {
        tail = tail->next;
    }

    Node* back = tail->prev;

    Node* newNode = new Node(value,tail,back);
    back->next = newNode;
    tail->prev = newNode;

    return head;
}

Node* insertionAfterTail(Node* head,ll value)
{
    if(head->next == nullptr)
    {
        return insertionAfterHead(head,value);
    }

    Node* tail = head;

    while(tail->next != nullptr)
    {
        tail = tail->next;
    }

    Node* newNode = new Node(value,nullptr,tail);

    tail->next = newNode;

    return head;
}

Node* insertionBeforeKthElement(Node* head,ll k,ll value)
{
    if(k==1)
    {
        return insertionBeforeHead(head,value);
    }

    ll cnt=0;
    Node* curr = head;

    while(curr->next != nullptr)
    {
        cnt++;
        if(cnt==k)
        {
            break;
        }
        curr = curr->next;
    }

    Node* back = curr->prev;

    Node* newNode = new Node(value,curr,back);

    back->next = newNode;
    curr->prev = newNode;

    return head;


}

Node* insertionAfterkthNode(Node* head,ll k,ll value)
{
    if(k==1)
    {
        return insertionAfterHead(head,value);
    }

    Node* curr = head;
    ll cnt=0;

    while(curr->next != nullptr)
    {
        cnt++;
        if(cnt==k)
        {
            break;
        }
        curr = curr->next;
    }

    if(curr->next == nullptr)
    {
        return insertionAfterTail(head,value);
    }

    Node* front = curr->next;

    Node* newNode = new Node(value,front,curr);
    front->prev = newNode;
    curr->next = newNode;

    return head;
}

Node* insertionBeforeElement(Node* head,ll element,ll value)
{
    if(head->data == element)
    {
        return insertionBeforeHead(head,value);
    }

    Node* temp = head;

    while(temp!=nullptr)
    {
        if(temp->data == element)
        {
            break;
        }
        temp = temp->next;
    }
    if(temp==nullptr)
    {
        cout<<"The element is not found";
        return head;
    }

    Node* back = temp->prev;

    Node* newNode = new Node(value,temp,back);
    back->next = newNode;
    temp->prev = newNode;

    return head;
}

Node* insertionAfterElement(Node* head,ll element,ll value)
{
    if(head->data == element)
    {
        return insertionAfterHead(head,value);
    }

    Node* temp = head;

    while(temp!=nullptr)
    {
        if(temp->data == element )
        {
            break;
        }

        temp = temp->next;

    }
    if(temp==nullptr)
    {
        cout<<"The element is not found "<<endl;
        return head;
    }

    Node* front = temp->next;

    Node* newNode = new Node(value,front,temp);

    temp->next = newNode;
    front->prev = newNode;

    return head;
}

int main()
{

   vector<ll> arr={2,4,6,8,10,12,1,3,5};

   Node* head = arrayToDoublyLinkedList(arr);

   cout<<"The initial Doubly Linked List is: ";
   
   printDoublyLinkedList(head);
   


   head = insertionBeforeHead(head,9);

   cout<<"The Doubly Linked List after inserting before head: ";
   printDoublyLinkedList(head);

   
   head = insertionAfterHead(head,22);

   cout<<"The Doubly Linked List after inserting  after head: ";
   printDoublyLinkedList(head);

   head = insertionBeforeTail(head,33);

   cout<<"The Doubly Linked List after inserting before tail : ";
   printDoublyLinkedList(head);

   head = insertionAfterTail(head,44);

   cout<<"The Doubly Linked List after inserting after tail : ";
   printDoublyLinkedList(head);

   head = insertionBeforeKthElement(head,4,55);

   cout<<"The Doubly Linked List after inserting before the kth Node: ";
   printDoublyLinkedList(head);

   head = insertionAfterkthNode(head,5,66);

   cout<<"The Doubly Linked List after inserting after the kth Node: ";
   printDoublyLinkedList(head);

   head = insertionBeforeElement(head,1,77);

   cout<<"The Doubly Linked List after insertion before the node 1 : ";
   printDoublyLinkedList(head);

   head = insertionAfterElement(head,6,99);

   cout<<"The Doubly Linked List after insertion after the element 6 : ";
   printDoublyLinkedList(head);


    return 0;
}