/**
 * @file    insertsort.C
 * @brief   Sorts a linked list using the insertion sort algorithm.
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
 * This program implements insertion sort for linked lists by removing
 * each node and inserting it in sorted order into a new list.
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
 * @brief   Inserts a node into a sorted list maintaining order.
 */
void SortedInsert(struct Node **head, struct Node *newNode) {
  struct Node dummy;
  struct Node *current = &dummy;
  dummy.next = *head;

  /* Find the correct position */
  while (current->next != NULL && current->next->data < newNode->data)
    current = current->next;

  /* Insert the node */
  newNode->next = current->next;
  current->next = newNode;
  *head = dummy.next;
}

/**
 * @brief   Sorts a linked list using insertion sort.
 */
void InsertSort(struct Node **head) {
  struct Node *result = NULL;
  struct Node *current = *head;
  struct Node *next;

  /* Move each node to sorted result list */
  while (current != NULL) {
    next = current->next;
    SortedInsert(&result, current);
    current = next;
  }

  *head = result;
}

/**
 * @brief   Main function - Entry point of the program.
 */
int main() {
  int keys[] = {6, 3, 4, 8, 2, 9};
  int n, i;
  struct Node *head = NULL;

  clrscr(); /* Clears the console screen (Turbo C specific) */

  n = sizeof(keys) / sizeof(keys[0]);
  for (i = n - 1; i >= 0; i--)
    push(&head, keys[i]);

  /* Sort the list */
  InsertSort(&head);

  /* Print sorted list */
  printList(head);

  getch(); /* Wait for a key press before closing (Turbo C specific) */

  return 0; /* Return 0 to indicate successful execution */
}