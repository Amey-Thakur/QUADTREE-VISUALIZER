#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<assert.h>
struct Node
{
 int data;
 struct Node* next;
};
void MoveNode(struct Node** destRef, struct Node** sourceRef) ;
void AlternatingSplit(struct Node* source, struct Node** aRef, struct Node** bRef)
{
 struct Node* a = NULL;
 struct Node* b = NULL;
 struct Node* current = source;
 while (current != NULL)
 {
  MoveNode(&a,¤t);
  if(current != NULL)
  {
   MoveNode(&b,¤t);
  }
 }
 *aRef = a;
 *bRef = b;
}
void MoveNode(struct Node** destRef, struct Node** sourceRef)
{
 struct Node* newNode = *sourceRef;
 assert(newNode != NULL);
 *sourceRef = newNode->next;
 newNode->next = *destRef;
 *destRef = newNode;
}
void push(struct node** head_ref, int new_data)
{
 struct Node* new_node=(struct Node*) malloc(sizeof(struct Node));
 new_node->data = new_data;
 new_node->next = (*head_ref);
 (*head_ref) = new_node;
}
void printList(struct Node *node)
{
 while(node!=NULL)
 {
  printf("%d ", node->data);
  node = node->next;
 }
}
void main()
{
 struct Node* head = NULL;
 struct Node* a = NULL;
 struct Node* b = NULL;
 clrscr();
 push(&head, 5);
 push(&head, 4);
 push(&head, 3);
 push(&head, 2);
 push(&head, 1);
 push(&head, 0);
 printf("\n Original linked List: ");
 printList(head);
 AlternatingSplit(head, &a, &b);
 printf("\n Resultant Linked List 'a' ");
 printList(a);
 printf("\n Resultant Linked List 'b' ");
 printList(b);
 getch();
}
