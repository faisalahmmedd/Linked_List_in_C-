#include<stdio.h>
#include<stdlib.h>
typedef struct Node node;

struct Node
{

    int data;
    node* next;
    node* prev;


};

node* addNewNode(int val,node* head)
{
    node* newNode=(node*)malloc(sizeof(node));
    newNode->data=val;
    newNode->next=NULL;
    newNode->prev=NULL;

    if(head==NULL)
    {
        head=newNode;
    }
    else
    {
        node* temp=head;

        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->prev=temp;
    }




    return head;

}

void forwardTraverse(node* head)
{
    node* temp=head;
    printf("Forward traversal: ");
    while(temp!=NULL)
    {
        if(temp->next==NULL)
            printf("%d\n",temp->data);
        else
            printf("%d<->",temp->data);
        temp=temp->next;
    }


    free(temp);
    temp=NULL;
}

void backwardTraverse(node* tail)
{

    node* temp=tail;
    printf("Backward Traversal: ");
    while(temp!=NULL)
    {
        if(temp->prev==NULL)
        {
            printf("%d\n",temp->data);
        }
        else
        {
            printf("%d<->",temp->data);
        }

        temp=temp->prev;
    }


    free(temp);

    temp=NULL;


}

node* insertAtHead(int val,node* head)
{
    node* newNode=(node*)malloc(sizeof(node));


    newNode->data=val;
    newNode->prev=NULL;
    newNode->next=NULL;

    newNode->next=head;
    head->prev=newNode;

    head=newNode;

    return head;
}

node* insertAtTail(int val,node* head)
{
    if(head==NULL)
    {
        return insertAtHead(val,head);
    }

    node* newNode=(node*) malloc(sizeof(node));
    newNode->data=val;
    newNode->prev=NULL;
    newNode->next=NULL;

    node* temp=head;

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    temp->next=newNode;

    newNode->prev=temp;

    free(temp);
    free(newNode);
    temp=NULL;
    newNode=NULL;



    return head;



}

node* insertAtPosition(int val,int position,node* head)
{
    if(position==1)
    {
        return insertAtHead(val,head);
    }
    int len=1;

    node* temp=head;

    while(temp!=NULL)
    {
        if(len==position)
        {
            break;
        }
        len++;
        temp=temp->next;
    }

    if(temp==NULL)
    {
        printf("Position is out of bound\n");
        return head;
    }



    node* newNode=(node*) malloc(sizeof(node));

    newNode->data=val;
    newNode->prev=NULL;
    newNode->next=NULL;

    node* temp1=temp->prev;

    temp1->next=newNode;
    newNode->prev=temp1;

    newNode->next=temp;
    temp->prev=newNode;




    return head;

}

int main()
{

    int n;
    scanf("%d",&n);

    node* head=NULL;
    printf("Enter %d values:",n);
    for(int i=0; i<n; i++)
    {
        int x;
        scanf("%d",&x);

        head=addNewNode(x,head);

    }

    forwardTraverse(head);

    node* tail=NULL;

    node* temp=head;

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    tail=temp;


    backwardTraverse(tail);

    printf("Enter the value you want to insert at head: ");

    int val;
    scanf("%d",&val);

    head = insertAtHead(val,head);


    forwardTraverse(head);


    printf("Enter the value you want to insert at tail: ");
    scanf("%d",&val);

    head=insertAtTail(val,head);

    forwardTraverse(head);

    int position;
    printf("Insert the postion you want to add a value: ");
    scanf("%d",&position);

    printf("Insert the value you want to add at %d:",position);
    scanf("%d",&val);

    head=insertAtPosition(val,position,head);

    forwardTraverse(head);


    free(head);

    head=NULL;

    return 0;
}
