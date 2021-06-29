#include<stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *head;

static void createList(int totalNodes){
    struct node *newNode;
    struct node *temp;
    int nodeData;
    int nodeCounter;

    head = (struct node*)malloc(sizeof(struct node *));
    if(head==NULL){
        printf("Memory not availible");
    }
    else
    {
        printf("Input Data for node 1: ");
        scanf("%d",&nodeData);

        head->data = nodeData;
        head->link = NULL;

        temp = head;

        for(nodeCounter=2;nodeCounter<=totalNodes;nodeCounter++){
            newNode = (struct node*)malloc(sizeof(struct node *));
            if(head==NULL){
                printf("Memory not availible");
                break;
            }
            else{
                printf("Input Data for node %d: ", nodeCounter);
                scanf("%d",&nodeData);
            }

            newNode->data = nodeData;
            newNode->link = NULL;

            temp->link = newNode;
            temp = temp->link;       
        }
    }   
}

static void displayList(){
    struct node *temp;
    temp = head;

    if(temp==NULL){
        printf("Empety List");
    }
    else{
        while (temp!=NULL)
        {
            printf(" -> %d",temp->data);
            temp = temp->link;
        }   
        printf("\n");
    }
}

int main(){
    int totalNodes;
    printf("Entar No. of nodes:");
    scanf("%d",&totalNodes);
    printf("\n");

    createList(totalNodes);

    printf("\nList Created!");
    displayList();

    return 0;
}