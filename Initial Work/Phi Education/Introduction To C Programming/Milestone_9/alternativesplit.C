/**
 * @file    alternativesplit.C
 * @brief   Splits a linked list into two lists with alternating nodes.
 *
 * @author  Amey Thakur
 *          GitHub: https://github.com/Amey-Thakur
 * @author  Mega Satish
 *          GitHub: https://github.com/msatmod
 * @author  Hasan Rizvi
 *          GitHub: https://github.com/rizvihasan
 *
 * @project QUADTREE-VISUALIZER
 * @group   Phi-CS-73
 * @batch   2022
 * @repo    https://github.com/Amey-Thakur/QUADTREE-VISUALIZER
 * @date    2021
 * @license MIT
 *
 * Developed as part of the Phi Education Training (Milestone 9) and
 * BE Major-Project @ Terna Engineering College, University of Mumbai.
 *
 * This program demonstrates the AlternatingSplit operation on linked lists.
 * Given a list {0,1,2,3,4,5}, it creates two sublists:
 * List 'a' = {0,2,4} and List 'b' = {1,3,5}
 *
 * @return  int  Returns 0 on successful execution.
 */

#include <assert.h> /* Assert library for assertions */
#include <conio.h> /* Console I/O library for clrscr() and getch() (DOS/Turbo C specific) */
#include <stdio.h>  /* Standard I/O library for printf functions */
#include <stdlib.h> /* Standard library for malloc() */

/**
 * @brief   Node structure for linked list.
 */
struct Node {
  int data;          /* Data stored in node */
  struct Node *next; /* Pointer to next node */
};

/* Function prototypes */
void MoveNode(struct Node **destRef, struct Node **sourceRef);
void AlternatingSplit(struct Node *source, struct Node **aRef,
                      struct Node **bRef);
void push(struct Node **head_ref, int new_data);
void printList(struct Node *node);

/**
 * @brief   Splits a linked list into two by alternating nodes.
 *
 * @param   source  The source linked list.
 * @param   aRef    Pointer to first result list.
 * @param   bRef    Pointer to second result list.
 */
void AlternatingSplit(struct Node *source, struct Node **aRef,
                      struct Node **bRef) {
  struct Node *a = NULL;
  struct Node *b = NULL;
  struct Node *current = source;

  /* Alternate between moving nodes to list a and list b */
  while (current != NULL) {
    MoveNode(&a, &current); /* Move to list a */
    if (current != NULL) {
      MoveNode(&b, &current); /* Move to list b */
    }
  }

  *aRef = a;
  *bRef = b;
}

/**
 * @brief   Moves the front node from source to destination list.
 *
 * @param   destRef    Pointer to destination list head.
 * @param   sourceRef  Pointer to source list head.
 */
void MoveNode(struct Node **destRef, struct Node **sourceRef) {
  struct Node *newNode = *sourceRef;
  assert(newNode != NULL);

  *sourceRef = newNode->next; /* Advance source pointer */
  newNode->next = *destRef;   /* Link to destination */
  *destRef = newNode;         /* Update destination head */
}

/**
 * @brief   Pushes a new node to the front of the list.
 *
 * @param   head_ref  Pointer to head pointer.
 * @param   new_data  Data for the new node.
 */
void push(struct Node **head_ref, int new_data) {
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}

/**
 * @brief   Prints all nodes in the linked list.
 *
 * @param   node  Head of the list to print.
 */
void printList(struct Node *node) {
  while (node != NULL) {
    printf("%d ", node->data);
    node = node->next;
  }
}

/**
 * @brief   Main function - Entry point of the program.
 */
int main() {
  struct Node *head = NULL;
  struct Node *a = NULL;
  struct Node *b = NULL;

  clrscr(); /* Clears the console screen (Turbo C specific) */

  /* Build list: 0 -> 1 -> 2 -> 3 -> 4 -> 5 */
  push(&head, 5);
  push(&head, 4);
  push(&head, 3);
  push(&head, 2);
  push(&head, 1);
  push(&head, 0);

  printf("\n Original linked List: ");
  printList(head);

  /* Split into alternating lists */
  AlternatingSplit(head, &a, &b);

  printf("\n Resultant Linked List 'a' ");
  printList(a);

  printf("\n Resultant Linked List 'b' ");
  printList(b);

  getch(); /* Wait for a key press before closing (Turbo C specific) */

  return 0; /* Return 0 to indicate successful execution */
}
