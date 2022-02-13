#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Node
{
 int data;
 struct Node* next;
 Node(int data)
 {
  this->data = data;
  next = NULL;
 }
};
struct LinkedList
{
 Node* head;
 LinkedList()
 {
  head = NULL;
 }
 Node* reverse(Node* node)
 {
  if (node == NULL)
  return NULL;
  if (node->next == NULL)
  {
   head = node;
   return node;
  }
  Node* node1 = reverse(node->next);
  node1->next = node;
  node->next = NULL;
  return node;
 }
 void print()
 {
  struct Node* temp = head;
  while (temp != NULL)
  {
   printf(" ", temp->data);
   temp = temp->next;
  }
 }
 void push(int data)
 {
  Node* temp = new Node(data);
  temp->next = head;
  head = temp;
 }
};
void main()
{
 LinkedList ll;
 clrscr();
 ll.push(20);
 ll.push(4);
 ll.push(15);
 ll.push(85);
 printf("Given linked list\n");
 ll.print();
 ll.reverse(ll.head);
 printf("\nReversed Linked list \n");
 ll.print();
 getch();
}
