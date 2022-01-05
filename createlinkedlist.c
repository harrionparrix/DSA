#include <stdio.h>
#include <stdlib.h>
 

struct node
{
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
 

int main()
{

  struct node* head = NULL;
  struct node* first = NULL;
  struct node* second=NULL;
  head=(struct node*)malloc(sizeof(struct node));
  first=(struct node*)malloc(sizeof(struct node));
  second=(struct node*)malloc(sizeof(struct node));
  head->data=12;
  head->next=first;
  first->data=3;
  first->next=second;
  second->data=4;
  second->next=NULL;
  printlist(head);
  return 0;
}