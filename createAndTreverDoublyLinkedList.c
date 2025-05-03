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

void display(node* head)
{
    node* temp=head;

    while(temp!=NULL)
    {
        if(temp->next==NULL)
            printf("%d ",temp->data);
        else
            printf("%d->",temp->data);
        temp=temp->next;
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

    display(head);




    return 0;
}
