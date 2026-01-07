/**
 * @file    pop.C
 * @brief   Removes and returns the front node from a linked list.
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
 * This program demonstrates the pop operation which removes and
 * returns the data from the front node of a linked list.
 *
 * @return  int  Returns 0 on successful execution.
 */

#include <conio.h> /* Console I/O library for clrscr() and getch() (DOS/Turbo C specific) */
#include <stdio.h>  /* Standard I/O library for printf functions */
#include <stdlib.h> /* Standard library for malloc() and free() */

/**
 * @brief   Node structure for linked list.
 */
struct Node {
  int data;          /* Data stored in node */
  struct Node *next; /* Pointer to next node */
};

/**
 * @brief   Prints all nodes in the linked list.
 */
void printList(struct Node *head) {
  struct Node *ptr = head;
  while (ptr) {
    printf("%d->", ptr->data);
    ptr = ptr->next;
  }
  printf("null");
}

/**
 * @brief   Pushes a new node to the front of the list.
 */
void push(struct Node **head, int data) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = *head;
  *head = newNode;
}

/**
 * @brief   Pops (removes and returns) the front node's data.
 *
 * @param   headRef  Pointer to head pointer.
 * @return  int      Data from the popped node, or -1 if empty.
 */
int pop(struct Node **headRef) {
  int result;
  struct Node *head = *headRef;

  if (*headRef == NULL)
    return -1;

  result = head->data;
  (*headRef) = (*headRef)->next;
  free(head);

  return result;
}

/**
 * @brief   Main function - Entry point of the program.
 */
int main() {
  int keys[] = {1, 2, 3, 4};
  int n, i;
  struct Node *head = NULL;

  clrscr(); /* Clears the console screen (Turbo C specific) */

  n = sizeof(keys) / sizeof(keys[0]);
  for (i = n - 1; i >= 0; i--)
    push(&head, keys[i]);

  /* Pop the front node */
  i = pop(&head);
  printf("Popped node %d\n", i);
  printList(head);

  getch(); /* Wait for a key press before closing (Turbo C specific) */

  return 0; /* Return 0 to indicate successful execution */
}