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
    printf("\n");
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

struct node* oddeven(struct node* head){
    struct node *odd=NULL;
    struct node *even=NULL;
    struct node *p=NULL;
    odd=head;
    even=head->next;
    p=even;
    while(even!=NULL && even->next!=NULL)
    {
        odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;
    }
    odd->next=p;
    
    return head;
}

int main(){
    int n;
    struct node *head=NULL;
    printf("Number of values:  ");
    scanf("%d",&n);
    head=insert(n);
    printlist(head);
    head=oddeven(head);
    printlist(head);
    return 0;
}