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


Node* arrayToDoublyLinkedList(vector<ll>& arr)
{
    Node* head = new Node(arr[0]);

    Node* mover = head;
    ll x=arr.size();
    for(ll i=1; i<x; i++)
    {
        Node* temp = new Node(arr[i],nullptr,mover);
        mover->next = temp;
        mover = temp;
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

Node* reverseDoublyLinkedList(Node* head)
{

    if(head == nullptr || head->next == nullptr)
    {
        return head;
    }


    Node* back = nullptr;
    Node* curr = head;

    while(curr != nullptr)
    {
       back = curr->prev;

       curr->prev = curr->next;
       curr->next=back;

       curr = curr->prev;
    }

    return back->prev;
}

int main()
{
   vector<ll> arr={2,4,6,8,10,12,14,1,3,5};
   

   Node* head = arrayToDoublyLinkedList(arr);

   cout<<"The initial Doubly Linked List is: ";
   printDoublyLinkedList(head);

   
   head = reverseDoublyLinkedList(head);


   cout<<"The Doubly Linked List after reversing : ";
   printDoublyLinkedList(head);








    return 0;
}