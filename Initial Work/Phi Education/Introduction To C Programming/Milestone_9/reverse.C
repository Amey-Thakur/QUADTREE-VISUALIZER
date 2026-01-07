/**
 * @file    reverse.C
 * @brief   Reverses a linked list iteratively.
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
 * This program reverses a linked list using an iterative approach
 * with three pointers: prev, current, and next.
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
 * @brief   Reverses a linked list iteratively.
 */
static void reverse(struct Node **head_ref) {
  struct Node *prev = NULL;
  struct Node *current = *head_ref;
  struct Node *next = NULL;

  while (current != NULL) {
    next = current->next; /* Store next */
    current->next = prev; /* Reverse link */
    prev = current;       /* Move prev forward */
    current = next;       /* Move current forward */
  }

  *head_ref = prev; /* Update head to new front */
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
void printList(struct Node *head) {
  struct Node *temp = head;
  while (temp != NULL) {
    printf("%d\t", temp->data);
    temp = temp->next;
  }
}

/**
 * @brief   Main function - Entry point of the program.
 */
int main() {
  struct Node *head = NULL;

  /* Build the list */
  push(&head, 20);
  push(&head, 4);
  push(&head, 15);
  push(&head, 85);

  clrscr(); /* Clears the console screen (Turbo C specific) */

  printf("Given linked list \n");
  printList(head);

  /* Reverse the list */
  reverse(&head);

  printf("\nReversed Linked list \n");
  printList(head);

  getch(); /* Wait for a key press before closing (Turbo C specific) */

  return 0; /* Return 0 to indicate successful execution */
}
