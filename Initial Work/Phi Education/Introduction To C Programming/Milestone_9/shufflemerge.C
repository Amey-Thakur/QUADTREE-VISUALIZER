/**
 * @file    shufflemerge.C
 * @brief   Merges two linked lists by alternating their nodes.
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
 * This program merges two linked lists by taking nodes alternately
 * from each list, interleaving them together.
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
void printList(struct Node *head) {
  struct Node *temp = head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

/**
 * @brief   Merges list b into list a by alternating nodes.
 */
void ShuffleMerge(struct Node *a, struct Node **b) {
  struct Node *a_curr = a, *b_curr = *b;
  struct Node *a_next, *b_next;

  /* Interleave nodes */
  while (a_curr != NULL && b_curr != NULL) {
    a_next = a_curr->next;
    b_next = b_curr->next;

    b_curr->next = a_next; /* Link b node after a node */
    a_curr->next = b_curr; /* Link b node to a chain */

    a_curr = a_next;
    b_curr = b_next;
  }

  *b = b_curr; /* Remaining nodes of b */
}

/**
 * @brief   Main function - Entry point of the program.
 */
int main() {
  struct Node *a = NULL, *b = NULL;

  clrscr(); /* Clears the console screen (Turbo C specific) */

  /* Build list a: 1 -> 2 -> 3 */
  push(&a, 3);
  push(&a, 2);
  push(&a, 1);

  printf("First Linked List:\n");
  printList(a);

  /* Build list b: 4 -> 5 -> 6 -> 7 -> 8 */
  push(&b, 8);
  push(&b, 7);
  push(&b, 6);
  push(&b, 5);
  push(&b, 4);

  printf("Second Linked List:\n");
  printList(b);

  /* Shuffle merge */
  ShuffleMerge(a, &b);

  printf("Modified First Linked List:\n");
  printList(a);

  printf("Modified Second Linked List:\n");
  printList(b);

  getch(); /* Wait for a key press before closing (Turbo C specific) */

  return 0; /* Return 0 to indicate successful execution */
}
