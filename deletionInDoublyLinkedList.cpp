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
         temp->prev = back;
         back->next = temp;
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
        temp=temp->next;
    }cout<<endl;
}

Node* deleteHeadInDoublyLinkedList(Node* head)
{
    if(head == nullptr || head->next == nullptr)
    {
        return nullptr;
    }


    Node* temp = head;
    head = head->next;

    head->prev = nullptr;
    temp->next = nullptr;
    delete temp;

    return head;

}

Node* deleteTailInDoublyLinkedList(Node* head)
{
    if(head == nullptr || head->next == nullptr)
    {
        return nullptr;
    }

    Node* tail = head;

    while(tail->next != nullptr)
    {
        tail = tail->next;
    }

    Node* backOfTail = tail->prev;
    backOfTail->next = nullptr;
    tail->prev = nullptr;
    delete tail;
    return head;
}

Node* deleteKthNodeDoublyLinkedList(Node* head,ll k)
{
    if(head==nullptr)
    {
        return nullptr;
    }

    ll cnt=0;

    Node* kthNode = head;

    while(kthNode!=nullptr)
    {
        cnt++;
        if(cnt==k)
        {
            break;
        }
        kthNode = kthNode->next;
    }

    Node* front = kthNode->next;
    Node* back = kthNode->prev;

    if(front==nullptr && back==nullptr)
    {
        delete kthNode;
        return nullptr;
    }
    else if(back==nullptr)
    {
        return deleteHeadInDoublyLinkedList(head);
    }
    else if(front==nullptr)
    {
        return deleteTailInDoublyLinkedList(head);
    }

    back->next = front;
    front->prev = back;

    kthNode->next = nullptr;
    kthNode->prev = nullptr;
    delete kthNode;

    return head;
}

Node* deleteElementInDoublyLinkedList(Node* head,ll element)
{
    Node* temp = head;

    while(temp->data != element)
    {
        temp = temp->next;
    }

    Node* back = temp->prev;
    Node* front = temp->next;

    if(back==nullptr && front==nullptr)
    {
         delete temp;
         return nullptr;
    }
    else if(back==nullptr)
    {
         return deleteHeadInDoublyLinkedList(head);
    }
    else if(front == nullptr)
    {
        return deleteTailInDoublyLinkedList(head);
    }

    front->prev = back;
    back->next = front;

    temp->next = nullptr;
    temp->prev = nullptr;
    delete temp;

    return head;
}

int main()
{
   vector<ll> arr={3,5,7,9,1,2,8,6};

   Node* head = arrayToDoublyLinkedList(arr);

   cout<<"The initial Doubly Linked List: ";
   printDoublyLinkedList(head);


   head = deleteHeadInDoublyLinkedList(head);


   cout<<"The Doubly Linked List after deleting the head: ";
   printDoublyLinkedList(head);


   head = deleteTailInDoublyLinkedList(head);

   cout<<"The Doubly Linked List after deleting the tail: ";
   printDoublyLinkedList(head);


   head = deleteKthNodeDoublyLinkedList(head,3);

   cout<<"The Doubly Linked List after deleting the kth Node: ";
   printDoublyLinkedList(head);


   head = deleteElementInDoublyLinkedList(head, 1);

   cout<<"The Doubly Linked List after deleting the 1 element: ";
   printDoublyLinkedList(head);




    return 0;
} 