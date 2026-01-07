/**
 * @file    getNth.C
 * @brief   Gets the Nth element from a linked list by index.
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
 * This program retrieves the element at a given index position
 * in a linked list (0-indexed).
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
 * @brief   Gets the element at the given index.
 *
 * @param   head   Head of the linked list.
 * @param   index  Index of element to retrieve (0-indexed).
 * @return  int    Data at the given index.
 */
int GetNth(struct Node *head, int index) {
  struct Node *current = head;
  int count = 0;

  /* Traverse to the Nth node */
  while (current != NULL) {
    if (count == index)
      return current->data;
    count++;
    current = current->next;
  }

  /* Index out of bounds */
  assert(0);
  return -1;
}

/**
 * @brief   Main function - Entry point of the program.
 */
int main() {
  struct Node *head = NULL;

  clrscr(); /* Clears the console screen (Turbo C specific) */

  /* Build linked list */
  push(&head, 1);
  push(&head, 4);
  push(&head, 1);
  push(&head, 12);
  push(&head, 1);

  /* Get element at index 3 */
  printf("Element at index 3 is %d", GetNth(head, 3));

  getch(); /* Wait for a key press before closing (Turbo C specific) */

  return 0; /* Return 0 to indicate successful execution */
}