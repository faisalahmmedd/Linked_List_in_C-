#include<stdio.h>
#include<stdlib.h>

typedef struct Node node;

struct Node{

     int number;
     node* next;

};

void printLinkedList(node* head)
{
    node* temp=head;

    if(temp==NULL)
    {
        printf("Empty Linked List\n");
        return;
    }

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





    free(temp);
    free(head);

    return 0;
}
