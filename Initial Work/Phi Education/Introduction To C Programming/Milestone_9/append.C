/**
 * @file    append.C
 * @brief   Appends two sorted linked lists into one merged sorted list.
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
 * This program demonstrates merging two sorted linked lists into a single
 * sorted linked list using the Append (merge) operation.
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
struct Node *Append(struct Node *a, struct Node *b);
void push(struct Node **head_ref, int new_data);
void printList(struct Node *node);

/**
 * @brief   Merges two sorted lists into one sorted list.
 *
 * @param   a  First sorted linked list.
 * @param   b  Second sorted linked list.
 * @return  struct Node*  Head of the merged sorted list.
 */
struct Node *Append(struct Node *a, struct Node *b) {
  struct Node dummy;
  struct Node *tail = &dummy;
  dummy.next = NULL;

  while (1) {
    /* If one list is exhausted, append the other */
    if (a == NULL) {
      tail->next = b;
      break;
    } else if (b == NULL) {
      tail->next = a;
      break;
    }

    /* Move smaller node to result list */
    if (a->data <= b->data)
      MoveNode(&(tail->next), &a);
    else
      MoveNode(&(tail->next), &b);

    tail = tail->next;
  }

  return dummy.next;
}

/**
 * @brief   Moves the front node from source to destination.
 */
void MoveNode(struct Node **destRef, struct Node **sourceRef) {
  struct Node *newNode = *sourceRef;
  assert(newNode != NULL);

  *sourceRef = newNode->next;
  newNode->next = *destRef;
  *destRef = newNode;
}

/**
 * @brief   Pushes a new node to the front of the list.
 */
void push(struct Node **head_ref, int new_data) {
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}

/**
 * @brief   Prints all nodes in the linked list.
 */
void printList(struct Node *node) {
  while (node != NULL) {
    printf("%d\t", node->data);
    node = node->next;
  }
}

/**
 * @brief   Main function - Entry point of the program.
 */
int main() {
  struct Node *res = NULL;
  struct Node *a = NULL;
  struct Node *b = NULL;

  clrscr(); /* Clears the console screen (Turbo C specific) */

  /* Build list a: 5 -> 10 -> 15 */
  push(&a, 15);
  push(&a, 10);
  push(&a, 5);

  /* Build list b: 2 -> 3 -> 20 */
  push(&b, 20);
  push(&b, 3);
  push(&b, 2);

  /* Merge the two lists */
  res = Append(a, b);

  printf("Appended Linked List is \n");
  printList(res);

  getch(); /* Wait for a key press before closing (Turbo C specific) */

  return 0; /* Return 0 to indicate successful execution */
}
