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
  printf("%d->",ptr->data);
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
int Length(struct Node* head)
{
 int count=0;
 struct Node* current=head;
 while(current!=NULL)
 {
  count++;
  current=current->next;
 }
 return count;
}
void FrontBackSplit(struct Node* source,struct Node** frontRef,struct Node** backRef)
{
 int len=Length(source);
 struct Node* current=source;
 int hopCount,i;
 if(len<2)
 {
  *frontRef=source;
  *backRef=NULL;
  return;
 }
 hopCount=(len-1)/2;
 for(i=0;i<hopCount;i++)
 current=current->next;
 *frontRef=source;
 *backRef=current->next;
 current->next=NULL;
}
void main()
{
 int i;
 struct Node *a=NULL, *b=NULL;
 int keys[]={6,3,4,8,2,9};
 int n=sizeof(keys)/sizeof(keys[0]);
 struct Node* head=NULL;
 clrscr();
 for(i=n-1;i>=0;i--)
 push(&head,keys[i]);
 FrontBackSplit(head, &a, &b);
 printf("Front List:");
 printList(a);
 printf("\nBack List:");
 printList(b);
 getch();
}