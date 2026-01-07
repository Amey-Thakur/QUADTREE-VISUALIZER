/**
 * @file    movenode.C
 * @brief   Moves the front node from one linked list to another.
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
 * This program demonstrates the MoveNode operation which takes the
 * front node from the source list and moves it to the destination list.
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
  printf("NULL\n");
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
 * @brief   Moves the front node from source to destination list.
 */
void MoveNode(struct Node **destRef, struct Node **sourceRef) {
  struct Node *newNode = *sourceRef;

  if (*sourceRef == NULL)
    return;

  *sourceRef = (*sourceRef)->next; /* Advance source */
  newNode->next = *destRef;        /* Link to destination */
  *destRef = newNode;              /* Update destination head */
}

/**
 * @brief   Main function - Entry point of the program.
 */
int main() {
  int i, n;
  struct Node *a = NULL;
  struct Node *b = NULL;
  int keys[] = {1, 2, 3};

  n = sizeof(keys) / sizeof(keys[0]);

  clrscr(); /* Clears the console screen (Turbo C specific) */

  /* Build list a: 1 -> 2 -> 3 */
  for (i = n - 1; i >= 0; i--)
    push(&a, keys[i]);

  /* Build list b: 2 -> 4 -> 6 */
  for (i = 0; i < n; i++)
    push(&b, 2 * keys[i]);

  /* Move front node from b to a */
  MoveNode(&a, &b);

  printf("First List:");
  printList(a);
  printf("Second List:");
  printList(b);

  getch(); /* Wait for a key press before closing (Turbo C specific) */

  return 0; /* Return 0 to indicate successful execution */
}