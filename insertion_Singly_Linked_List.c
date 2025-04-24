#include<stdio.h>
#include<stdlib.h>

typedef struct Node node;

struct Node{

     int number;
     node* next;

};

node* insertionAtHead(node* head,int element)
{
    if(head==NULL)
    {
       node* newNode = (node*) malloc(sizeof(node));

       newNode->number=element;
       newNode->next=NULL;
       head=newNode;


       free(newNode);
       return head;
    }

    node* newNode=(node*) malloc(sizeof(node));


    newNode->number=element;
    newNode->next=head;



    head=newNode;

    free(newNode);

    return head;

}

node* insertAtTail(node* head,int element)
{
    if(head==NULL)
    {
        return insertionAtHead(head,element);
    }

    node* temp=head;

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    node* newNode=(node*) malloc(sizeof(node));

    newNode->number=element;
    newNode->next=NULL;

    temp->next=newNode;

    free(temp);
    free(newNode);

    return head;

}

node* insertBeforeValue(node* head,int value,int element)
{

    if(head==NULL)
    {
        printf("%d not found in Linked List\n",value);
        return head;
    }

    if(head->number==value)
    {
        return insertionAtHead(head,element);
    }

    node* temp=head;
    node* prev=temp;


    while(temp!=NULL)
    {
        if(temp->number==value)
        {
            node* newNode=(node*) malloc(sizeof(node));

            newNode->number=element;
            newNode->next=temp;


            prev->next=newNode;

            return head;

        }
        else
        {
            prev=temp;
            temp=temp->next;
        }
    }
    printf("%d not found in Linked List\n",value);



}


void printLinkedList(node* head)
{
    node* temp=head;

    if(temp==NULL)
    {
        printf("Empty Linked List\n");
        return;
    }
    printf("Linked List: ");

    if(temp->next==NULL)
    {
        printf("%d\n",temp->number);
        return;
    }


    while(temp!=NULL)
    {
        printf("%d-->",temp->number);

        if(temp->next->next==NULL)
        {
            printf("%d\n",temp->next->number);
            return;
        }

        temp=temp->next;

    }

    free(temp);

}


int main()
{
    node* head=NULL;
    node* temp=NULL;

    printf("Enter the values of Linked List (Enter -1 to stop): \n");

    int x;

    while(1)
    {
        scanf("%d",&x);

        if(x==-1)
        {
            break;
        }

        node* newNode=(node*) malloc(sizeof(node));

        newNode->number=x;
        newNode->next=NULL;

        if(head==NULL)
        {
            head=newNode;
            temp=newNode;
        }
        else
        {
            temp->next=newNode;
            temp=newNode;
        }
    }

    printLinkedList(head);

    int element;
    printf("Enter the element you want to insert at head: ");
    scanf("%d",&element);
    head=insertionAtHead(head,element);


    printLinkedList(head);

    int element1;
    printf("Enter the element you want to insert at tail: ");
    scanf("%d",&element1);

    head=insertAtTail(head,element1);

    printLinkedList(head);


    int val,element2;

    printf("Enter the value before you want to insert: ");
    scanf("%d",&val);

    printf("Enter the element you want to insert before %d:",val);
    scanf("%d",&element2);

    head=insertBeforeValue(head,val,element2);


    printLinkedList(head);

    free(temp);
    free(head);

    return 0;
}
