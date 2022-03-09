#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Node
{
 int data;
 struct Node* next;
};
void printList(struct Node* head)
{
 struct Node* ptr=head;
 while(ptr)
 {
  printf("%d->", ptr->data);
  ptr=ptr->next;
 }
 printf("null");
}
void push(struct Node** head, int data)
{
 struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
 newNode->data=data;
 newNode->next=*head;
 *head=newNode;
}
int pop(struct Node** headRef)
{
 int result;
 struct Node* head=*headRef;
 if(*headRef==NULL)
 return -1;
 result=head->data;
 (*headRef)=(*headRef)->next;
 free(head);
 return result;
}
void main()
{
 int keys[]={1,2,3,4};
 int n,i;
 struct Node* head=NULL;
 clrscr();
 n=sizeof(keys)/sizeof(keys[0]);
 for(i=n-1;i>=0;i--)
 push(&head,keys[i]);
 i=pop(&head);
 printf("Popped node %d\n",i);
 printList(head);
 getch();
}