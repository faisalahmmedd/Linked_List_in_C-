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


    free(head);

    head=NULL;

    return 0;
}
