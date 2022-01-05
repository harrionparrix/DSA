#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};

void printlist(struct node* n)
{
    while (n != NULL) {
        printf(" %d ", n->data);
        n = n->next;
    }
}

struct node* insert(int n){
    struct node *head=NULL;
    struct node *p= NULL;
    struct node *temp= NULL;
    for(int i=0;i<n;i++)
    {
    
        struct node *temp=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data:  ");
        scanf("%d",&(temp->data));
        temp->next=NULL;
        
        if(head==NULL){

            head=temp;
        }
        else{
            p=head;
            while(p->next!=NULL)
                p=p->next;
        p->next=temp;
    }
}
return head;
}
struct node* insertatbeg(struct node* head,int n1){

    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=n1;
    temp->next=NULL;
    
    temp->next=head;
    head=temp;
    
    
return head;
}
    
int main(){
    int n,n1;
    struct node *head=NULL;
    printf("Number of values:  ");
    scanf("%d",&n);
    head=insert(n);
    printlist(head);
    printf("\nEnter value to be inserted: ");
    scanf("%d",&n1);
    printf("\nAfter insertion at beginning: ");
    head=insertatbeg(head,n1);
    printlist(head);
    return 0;
}