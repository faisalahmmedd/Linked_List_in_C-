#include<bits/stdc++.h>
#define ll long long int
using namespace std;


class Node{
   public: 
      ll data;
      Node* next;

    

    Node(ll data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node* arrayToLinkedList(vector<ll>&arr)
{
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(ll i=1; i<arr.size(); i++)
    {
        Node* temp=new Node(arr[i]);
        mover->next = temp;
        mover=temp;
    }
    return head;
}

Node* deleteHead(Node* head)
{
    if(head==nullptr)
       return head;

    Node* temp=head;
    head = head->next;
    delete temp;
    return head;
}

Node* deleteTail(Node* head)
{
    if(head==nullptr || head->next == nullptr)
       return nullptr;
    
    Node* temp=head;

    while(temp->next->next!=nullptr)
    {
        temp=temp->next;
    }
    delete(temp->next);
    temp->next=nullptr;

    return head;
}

Node* deleteKthElement(Node* head,ll k)
{
    if(head==nullptr)
       return head;

    if(k==1)
    {
        Node* temp=head;
        head = head->next;
        delete temp;
        return head;
    }

    ll cnt=0;
    Node* temp=head;
    Node* prev=nullptr;

    while(temp!=nullptr)
    {
        cnt++;

        if(cnt==k)
        {
           prev->next = prev->next->next;
           delete temp;
           break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}

Node* deleteElement(Node* head,ll element)
{
    if(head==nullptr)
    {
        return head;
    }

    if(head->data == element)
    {
        Node* temp=head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* temp = head;
    Node* prev = nullptr;

    while(temp!=nullptr)
    {
        if(temp->data == element)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        } 
        prev = temp;
        temp = temp->next;
    }
    return head;
}

void printLinkedList(Node* head)
{
    Node* temp=head;

    while(temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}



int main()
{
    vector<ll> arr={2,4,6,5,1,10,15};

    Node* head = arrayToLinkedList(arr);

    cout<<"The Linked List: ";
    printLinkedList(head);

    head = deleteHead(head);

    cout<<"Linked List after deleting the head : ";
    printLinkedList(head);

    head = deleteTail(head);

    cout<<"Linked List after deleting the tail : ";
    printLinkedList(head);

    head = deleteKthElement(head,2);

    cout<<"Linked List after deleting the K-th Element: ";
    printLinkedList(head);

    head = deleteElement(head,5);

    cout<<"Linked List after deleteing the element 5 if there any : ";
    printLinkedList(head);

    return 0;
}