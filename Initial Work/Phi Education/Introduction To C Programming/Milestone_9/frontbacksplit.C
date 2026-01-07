/**
 * @file    frontbacksplit.C
 * @brief   Splits a linked list into front and back halves.
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
 * This program splits a linked list into two halves: front and back.
 * If the list has odd length, the extra element goes in the front list.
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
 * @brief   Calculates the length of the linked list.
 */
int Length(struct Node *head) {
  int count = 0;
  struct Node *current = head;
  while (current != NULL) {
    count++;
    current = current->next;
  }
  return count;
}

/**
 * @brief   Splits a list into front and back halves.
 *
 * @param   source    The source linked list.
 * @param   frontRef  Pointer to front half result.
 * @param   backRef   Pointer to back half result.
 */
void FrontBackSplit(struct Node *source, struct Node **frontRef,
                    struct Node **backRef) {
  int len = Length(source);
  struct Node *current = source;
  int hopCount, i;

  /* Handle short lists */
  if (len < 2) {
    *frontRef = source;
    *backRef = NULL;
    return;
  }

  /* Find the midpoint */
  hopCount = (len - 1) / 2;
  for (i = 0; i < hopCount; i++)
    current = current->next;

  /* Split the list */
  *frontRef = source;
  *backRef = current->next;
  current->next = NULL; /* Terminate front list */
}

/**
 * @brief   Main function - Entry point of the program.
 */
int main() {
  int i;
  struct Node *a = NULL, *b = NULL;
  int keys[] = {6, 3, 4, 8, 2, 9};
  int n = sizeof(keys) / sizeof(keys[0]);
  struct Node *head = NULL;

  clrscr(); /* Clears the console screen (Turbo C specific) */

  /* Build the linked list */
  for (i = n - 1; i >= 0; i--)
    push(&head, keys[i]);

  /* Split into front and back */
  FrontBackSplit(head, &a, &b);

  printf("Front List:");
  printList(a);
  printf("\nBack List:");
  printList(b);

  getch(); /* Wait for a key press before closing (Turbo C specific) */

  return 0; /* Return 0 to indicate successful execution */
}