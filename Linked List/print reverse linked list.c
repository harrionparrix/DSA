#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};

void printlist_reverse(struct node* head)
{   
    if(head==NULL){
        return;
    }
    printlist_reverse(head->next);
    printf("%d ",head->data);
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
int main(){
    int n;
    struct node *head=NULL;
    printf("Number of values:  ");
    scanf("%d",&n);
    head=insert(n);
    printlist_reverse(head);
    return 0;
}