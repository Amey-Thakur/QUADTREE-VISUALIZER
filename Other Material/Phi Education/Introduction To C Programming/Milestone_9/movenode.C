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
 printf("NULL\n");
}
void push(struct Node** head, int data)
{
 struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
 newNode->data=data;
 newNode->next=*head;
 *head=newNode;
}
void MoveNode(struct Node** destRef, struct Node** sourceRef)
{
 struct Node* newNode=*sourceRef;
 if(*sourceRef==NULL)
 return;
 *sourceRef=(*sourceRef)->next;
 newNode->next=*destRef;
 *destRef=newNode;
}
void main()
{
 int i,n;
 struct node* a=NULL;
 struct node* b=NULL;
 int keys[]={1,2,3};
 n=sizeof(keys)/sizeof(keys[0]);
 clrscr();
 for(i=n-1;i>=0;i--)
 push(&a,keys[i]);
 for(i=0;i<n;i++)
 push(&b,2*keys[i]);
 MoveNode(&a, &b);
 printf("First List:");
 printList(a);
 printf("Second List:");
 printList(b);
 getch();
}