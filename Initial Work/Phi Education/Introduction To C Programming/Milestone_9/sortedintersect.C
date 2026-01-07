/**
 * @file    sortedintersect.C
 * @brief   Finds the intersection of two sorted linked lists.
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
 * This program finds common elements in two sorted linked lists
 * and creates a new list containing the intersection.
 *
 * @return  int  Returns 0 on successful execution.
 */

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

/* Function prototype */
void push(struct Node **head_ref, int new_data);

/**
 * @brief   Creates a new list from the intersection of two sorted lists.
 */
struct Node *sortedIntersect(struct Node *a, struct Node *b) {
  struct Node dummy;
  struct Node *tail = &dummy;
  dummy.next = NULL;

  /* Traverse both lists */
  while (a != NULL && b != NULL) {
    if (a->data == b->data) {
      /* Common element found */
      push((&tail->next), a->data);
      tail = tail->next;
      a = a->next;
      b = b->next;
    } else if (a->data < b->data) {
      a = a->next; /* Advance a */
    } else {
      b = b->next; /* Advance b */
    }
  }

  return dummy.next;
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
    printf("%d ", node->data);
    node = node->next;
  }
}

/**
 * @brief   Main function - Entry point of the program.
 */
int main() {
  struct Node *a = NULL;
  struct Node *b = NULL;
  struct Node *intersect = NULL;

  clrscr(); /* Clears the console screen (Turbo C specific) */

  /* Build list a: 1 -> 2 -> 3 -> 4 -> 5 -> 6 */
  push(&a, 6);
  push(&a, 5);
  push(&a, 4);
  push(&a, 3);
  push(&a, 2);
  push(&a, 1);

  /* Build list b: 2 -> 4 -> 6 -> 8 */
  push(&b, 8);
  push(&b, 6);
  push(&b, 4);
  push(&b, 2);

  /* Find intersection */
  intersect = sortedIntersect(a, b);

  printf("\n Linked list containing common items of a & b \n ");
  printList(intersect);

  getch(); /* Wait for a key press before closing (Turbo C specific) */

  return 0; /* Return 0 to indicate successful execution */
}
