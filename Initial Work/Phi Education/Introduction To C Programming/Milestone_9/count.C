/**
 * @file    count.C
 * @brief   Counts occurrences of a value in a linked list.
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
 * This program counts how many times a specific value appears in a linked list.
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
 * @brief   Counts occurrences of a value in the list.
 *
 * @param   head       Head of the linked list.
 * @param   searchFor  Value to search for.
 * @return  int        Count of occurrences.
 */
int count(struct Node *head, int searchFor) {
  struct Node *current = head;
  int count = 0;

  /* Traverse list and count matches */
  while (current != NULL) {
    if (current->data == searchFor)
      count++;
    current = current->next;
  }

  return count;
}

/**
 * @brief   Main function - Entry point of the program.
 */
int main() {
  struct Node *head = NULL;

  clrscr(); /* Clears the console screen (Turbo C specific) */

  /* Build list: 1 -> 2 -> 1 -> 3 -> 1 */
  push(&head, 1);
  push(&head, 3);
  push(&head, 1);
  push(&head, 2);
  push(&head, 1);

  /* Count occurrences of 1 */
  printf("Count of 1 is %d", count(head, 1));

  getch(); /* Wait for a key press before closing (Turbo C specific) */

  return 0; /* Return 0 to indicate successful execution */
}
