/**
 * @file    reverselinklist.C
 * @brief   Implements a singly linked list and reverses it.
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
 * Developed as part of the Phi Education Training (Milestone 13) and
 * BE Major-Project @ Terna Engineering College, University of Mumbai.
 *
 * This program demonstrates linked list creation and reversal
 * using iterative approach.
 *
 * @return  int  Returns 0 on successful execution.
 */

#include <conio.h> /* Console I/O library for clrscr() and getch() (DOS/Turbo C specific) */
#include <stdio.h>  /* Standard I/O library for printf */
#include <stdlib.h> /* Standard library for malloc() and NULL */

/**
 * @struct Node
 * @brief  Structure for a linked list node.
 */
struct Node {
  int data;
  struct Node *next;
};

/**
 * @brief   Reverses the linked list iteratively.
 * @param   head_ref  Pointer to the head pointer of the linked list.
 */
static void reverse(struct Node **head_ref) {
  struct Node *prev = NULL;
  struct Node *current = *head_ref;
  struct Node *next = NULL;

  while (current != NULL) {
    /* Store next node */
    next = current->next;
    /* Reverse current node's pointer */
    current->next = prev;
    /* Move pointers one position ahead */
    prev = current;
    current = next;
  }
  /* Update head to the new front (prev) */
  *head_ref = prev;
}

/**
 * @brief   Adds a new node at the beginning of the list.
 * @param   head_ref  Pointer to the head pointer of the linked list.
 * @param   new_data  The data to be stored in the new node.
 */
void push(struct Node **head_ref, int new_data) {
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}

/**
 * @brief   Prints the linked list from head to tail.
 * @param   head  Pointer to the head node of the list.
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
 *
 * Creates a linked list, prints it, reverses it, and prints it again.
 */
int main() {
  struct Node *head = NULL;

  /* Create linked list: 85->15->4->20 */
  push(&head, 20);
  push(&head, 4);
  push(&head, 15);
  push(&head, 85);

  clrscr(); /* Clears the console screen (Turbo C specific) */

  printf("Given linked list \n");
  printList(head);

  reverse(&head);

  printf("\nReversed Linked list \n");
  printList(head);

  getch(); /* Wait for a key press (Turbo C specific) */

  return 0; /* Return 0 to indicate successful execution */
}
