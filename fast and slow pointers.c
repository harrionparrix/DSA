



//ERROR IN WHILE LOOP



#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};


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


int middle(struct node* head){
    struct node *fastp=head;
    struct node *slowp=head;
    while(fastp!=NULL && fastp->next!=NULL){
        slowp=slowp->next;
        fastp=fastp->next->next;
    }
    
    return(slowp->data);
}


int main(){
    int n;
    struct node *head=NULL;
    printf("Number of values:  ");
    scanf("%d",&n);
    head=insert(n);
    int p=middle(head);
    printf("\n%d",p);
    return 0;
}