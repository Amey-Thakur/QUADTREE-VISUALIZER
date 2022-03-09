#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Node
{
 int data;
 struct Node* next;
};
void push(struct Node** head_ref, int new_data)
{
 struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
 new_node->data=new_data;
 new_node->next=(*head_ref);
 (*head_ref)=new_node;
}
int count(struct Node* head, int searchFor)
{
 struct Node* current=head;
 int count=0;
 while(current!=NULL)
 {
  if(current->data==searchFor)
  count++;
  current=current->next;
 }
 return count;
}
void main()
{
 struct Node* head=NULL;
 clrscr();
 push(&head,1);
 push(&head,3);
 push(&head,1);
 push(&head,2);
 push(&head,1);
 printf("Count of 1 is %d", count(head,1));
 getch();
}
