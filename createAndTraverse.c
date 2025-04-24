#include <stdio.h>
#include<stdlib.h>
typedef struct Node node;
struct Node{

    int val;
    node *next;

};



int main(void) {

    node* head=NULL;
    node* tmp=NULL;

    int value;
    printf("Enter values of the Linked List (enter -1 to end): \n");
    while(1)
    {
        scanf("%d",&value);

        if(value==-1)
        {
            break;
        }

        node* newNode=(node*) malloc(sizeof(node));

        newNode->val=value;
        newNode->next=NULL;

        if(head==NULL)
        {
            head=newNode;
            tmp=newNode;
        }
        else
        {
            tmp->next=newNode;
            tmp=newNode;
        }
    }

    node* temp=head;

    while(temp!=NULL)
    {
        printf("%d->",temp->val);
        temp = temp->next;
    }
    printf("NULL\n");

   return 0;
}

