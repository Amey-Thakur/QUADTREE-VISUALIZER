#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Node
{
 int data;
 struct Node *next;
};
void push(struct Node ** head_ref, int new_data)
{
 struct Node* new_node=(struct Node*) malloc(sizeof(struct Node));
 new_node->data = new_data;
 new_node->next = (*head_ref);
 (*head_ref) = new_node;
}
void printList(struct Node *head)
{
 struct Node *temp = head;
 while (temp != NULL)
 {
  printf("%d ", temp->data);
  temp = temp->next;
 }
 printf("\n");
}
void ShuffleMerge(struct Node *a, struct Node **b)
{
 struct Node *a_curr = a, *b_curr = *b;
 struct Node *a_next, *b_next;
 while (a_curr != NULL && b_curr != NULL)
 {
  a_next = a_curr->next;
  b_next = b_curr->next;
  b_curr->next = a_next;
  a_curr->next = b_curr;
  a_curr = a_next;
  b_curr = b_next;
 }
 *b = b_curr;
}
void main()
{
 struct Node *a = NULL, *b = NULL;
 clrscr();
 push(&a, 3);
 push(&a, 2);
 push(&a, 1);
 printf("First Linked List:\n");
 printList(a);
 push(&b, 8);
 push(&b, 7);
 push(&b, 6);
 push(&b, 5);
 push(&b, 4);
 printf("Second Linked List:\n");
 printList(b);
 ShuffleMerge(&a, &b);
 printf("Modified First Linked List:\n");
 printList(a);
 printf("Modified Second Linked List:\n");
 printList(b);
 getch();
}
