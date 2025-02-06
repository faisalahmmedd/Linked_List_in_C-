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
        Node* temp = new Node(arr[i],nullptr,back);
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

int main()
{
    vector<ll> arr={3,5,2,8,9,23};


    Node* head = arrayToDoublyLinkedList(arr);


    printDoublyLinkedList(head);




    return 0;
}