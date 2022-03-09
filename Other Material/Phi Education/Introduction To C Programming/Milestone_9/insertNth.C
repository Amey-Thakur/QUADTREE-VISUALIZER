#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Node
{
 int data;
 struct Node* next;
};
int size=0;
struct Node* getNode(int data)
{
 struct Node* newNode;
 newNode=(struct Node*)malloc(sizeof(struct Node));
 newNode->data=data;
 newNode->next=NULL;
 return newNode;
}
void insertNth(struct Node** headref, int index, int data)
{
 if(index<1||index>size+1)
 printf("Invalid Position \n");
 else
 {
  while(index--)
  {
   if(index==0)
   {
    struct Node* temp=getNode(data);
    temp->next=*headref;
    *headref=temp;
   }
   else
   headref=&(*headref)->next;
  }
  size++;
 }
}

void printList(struct Node* head)
{
 while(head!=NULL)
 {
  printf("%d\t", head->data);
  head=head->next;
 }
 printf("\n");
}
void main()
{
 struct Node* head=NULL;
 int data=12,index=3;
 clrscr();
 head=getNode(3);
 head->next=getNode(5);
 head->next->next=getNode(8);
 head->next->next->next=getNode(10);
 size=4;
 printf("Linked list before insertion:");
 printList(head);
// int data=12,index=3;
 insertNth(&head, index, data);
 printf("Linked list after insertion of 12 at position 3:");
 printList(head);
 data=1, index=1;
 insertNth(&head, index, data);
 printf("Linked list after insertion of 1 at position 1:");
 printList(head);
 data=15, index=7;
 insertNth(&head, index, data);
 printf("Linked list after insertion of 15 at position 7:");
 printList(head);
 getch();
}

