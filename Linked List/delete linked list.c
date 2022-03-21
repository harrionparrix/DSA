#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};

void printlist(struct node* n)
{
    if(n==NULL)
    printf("\nList is Empty");
    
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

void del_list(struct node** head)
{
    struct node* prev = *head;
 
    while (*head)
    {
        *head = (*head)->next;
        free(prev);
        prev = *head;
    }
    
}



int main(){
    int n;
    struct node *head=NULL;
    printf("Number of values:  ");
    scanf("%d",&n);
    head=insert(n);
    printlist(head);
    del_list(&head);
    printlist(head);
    return 0;
}