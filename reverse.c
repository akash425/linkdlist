#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* link;
};

struct node *head;

static void create(int totalNodes){
    // head = (struct node*)malloc(sizeof(struct node*));
    int data,count;
    struct node *temp;
    struct node *NewNode;

    head = (struct node*)malloc(sizeof(struct node *));

    if (head == NULL)
    {
        printf("Memory not allocated");
    }
    else{
        printf("Enter Data for Node 1: ");
        scanf("%d", &data);

        head->data = data;
        head->link = NULL;

        temp = head;

        for(count = 2; count <= totalNodes; count++){
            NewNode = (struct node*)malloc(sizeof(struct node *));

            if (NewNode == NULL){
                printf("Memory not allocated");
            }
            else{
                printf("Enter Data for Node %d: ",count);
                scanf("%d",&data);

                NewNode->data = data;
                NewNode->link = NULL;

                temp->link = NewNode;
                temp = temp->link;
            }
        }
    }
}

static void reverse(){
    struct node * prev;
    struct node * curr;
    struct node * next;

    prev=NULL;
    curr=head;
    next=head;

    while(next!=NULL){
        next = next->link;
        curr->link = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
}

static void display(){
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

    create(totalNodes);

    printf("\nList Created!");
    display();

    printf("After reversing the List ");
    reverse();
    display();


    return 0;

}