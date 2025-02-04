#include<bits/stdc++.h>
#define ll long long int
using namespace std;

class node{
    public:
      ll data;
      node* next;

      node(ll data1,node* next1)
      {
        data=data1;
        next=next1;
      }
      node (ll data)
      {
        this->data = data;
        next=nullptr;
      }
};

node* convertArrtoLinkedList(vector<ll>& arr)
{
    node* head =  new node(arr[0]);
    node* mover=head;

    for(ll i=1; i<arr.size(); i++)
    {
        node* temp=new node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void printLinkedList(node* head)
{
    node* temp=head;

    while(temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

ll lengthLinkedList(node* head)
{
    ll cnt=0;
    node* temp=head;

    while(temp!=nullptr)
    {
        cnt++;
        temp = temp->next;
    }

    return cnt;
}


int main()
{
    vector<ll> arr={5,4,3,2,1};


    node* head = convertArrtoLinkedList(arr);

    cout<<"the value of the head: "<<head->data<<endl;
    
    cout<<"The length of the Linked List: "<<lengthLinkedList(head)<<endl;

    cout<<"Traversing the Linked List: ";
    printLinkedList(head);

    

    return 0;
}
