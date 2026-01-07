/**
 * @file    deletelist.C
 * @brief   Deletes an entire linked list and frees all memory.
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
 * This program demonstrates deleting an entire linked list by
 * freeing each node's memory and setting head to NULL.
 *
 * @return  int  Returns 0 on successful execution.
 */

#include <assert.h> /* Assert library for assertions */
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
 * @brief   Deletes the entire linked list.
 *
 * Traverses the list, freeing each node's memory.
 *
 * @param   head_ref  Pointer to head pointer.
 */
void deleteList(struct Node **head_ref) {
  struct Node *current = *head_ref;
  struct Node *next;

  /* Traverse and free each node */
  while (current != NULL) {
    next = current->next; /* Store next before freeing */
    free(current);        /* Free current node */
    current = next;       /* Move to next node */
  }

  *head_ref = NULL; /* Set head to NULL */
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
 * @brief   Main function - Entry point of the program.
 */
int main() {
  struct Node *head = NULL;

  clrscr(); /* Clears the console screen (Turbo C specific) */

  /* Build a linked list */
  push(&head, 1);
  push(&head, 4);
  push(&head, 1);
  push(&head, 12);
  push(&head, 1);

  printf("\n Deleting linked list");
  deleteList(&head);
  printf("\n Linked list deleted");

  getch(); /* Wait for a key press before closing (Turbo C specific) */

  return 0; /* Return 0 to indicate successful execution */
}