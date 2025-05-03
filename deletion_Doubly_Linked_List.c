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

node* deleteAtHead(node* head)
{
    if(head==NULL)
    {
        return NULL;
    }

    node* temp=head;

    head = head->next;

    free(temp);

    return head;
}

node* deleteAtTail(node* head)
{
    if(head==NULL)
    {
        return NULL;
    }
    if(head->next==NULL)
    {
        free(head);
        return NULL;
    }

    node* temp = head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }



    temp = temp->prev;

    temp->next=NULL;

    free(temp);

    return head;
}
node* deleteAtPosition(int position,node *head)
{
    if(position==1)
    {
        return deleteAtHead(head);
    }
    if(head==NULL)
    {
        return head;
    }

    int len=1;

    node* temp = head;

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
        printf("Out of bound\n");
        return head;
    }

    if(temp->next==NULL)
    {
        temp = temp->prev;
        temp->next = NULL;

        return head;
    }

    node* front=temp->next;

    node* back = temp->prev;



    back->next=front;
    front->prev=back;



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


    head = deleteAtHead(head);

    printf("\nLinked list after deleting head : \n");
    forwardTraverse(head);



    head = deleteAtTail(head);

    printf("\nLinked list after deleting tail: \n");
    forwardTraverse(head);

    int position;
    printf("Enter the postion of the node you want to delete:");
    scanf("%d",&position);

    head = deleteAtPosition(position,head);

    printf("\nLinked list after deleting %d'th node.\n",position);
    forwardTraverse(head);


    free(head);

    head=NULL;

    return 0;
}
