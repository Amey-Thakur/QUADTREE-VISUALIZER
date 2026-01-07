/**
 * @file    removeduplicates.C
 * @brief   Removes duplicate nodes from a sorted linked list.
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
 * This program removes duplicate values from a sorted linked list
 * by comparing adjacent nodes and deleting duplicates.
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
 * @brief   Removes duplicate nodes from a sorted list.
 */
void removeDuplicates(struct Node *head) {
  struct Node *current = head;
  struct Node *next_next;

  if (current == NULL)
    return;

  /* Compare adjacent nodes */
  while (current->next != NULL) {
    if (current->data == current->next->data) {
      /* Delete duplicate node */
      next_next = current->next->next;
      free(current->next);
      current->next = next_next;
    } else {
      current = current->next;
    }
  }
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
  struct Node *head = NULL;

  clrscr(); /* Clears the console screen (Turbo C specific) */

  /* Build sorted list with duplicates: 11 -> 11 -> 11 -> 13 -> 13 -> 20 */
  push(&head, 20);
  push(&head, 13);
  push(&head, 13);
  push(&head, 11);
  push(&head, 11);
  push(&head, 11);

  printf("\n Linked list before duplicate removal \n");
  printList(head);

  /* Remove duplicates */
  removeDuplicates(head);

  printf("\n Linked list after duplicates removal \n");
  printList(head);

  getch(); /* Wait for a key press before closing (Turbo C specific) */

  return 0; /* Return 0 to indicate successful execution */
}