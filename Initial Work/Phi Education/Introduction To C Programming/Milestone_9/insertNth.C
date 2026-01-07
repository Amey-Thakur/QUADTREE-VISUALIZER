/**
 * @file    insertNth.C
 * @brief   Inserts a new node at the Nth position in a linked list.
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
 * This program inserts a new node at a specified position (1-indexed)
 * in a linked list.
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

int size = 0; /* Global size tracker */

/**
 * @brief   Creates and returns a new node with given data.
 */
struct Node *getNode(int data) {
  struct Node *newNode;
  newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

/**
 * @brief   Inserts a node at the specified index (1-indexed).
 */
void insertNth(struct Node **headref, int index, int data) {
  if (index < 1 || index > size + 1) {
    printf("Invalid Position \n");
  } else {
    while (index--) {
      if (index == 0) {
        struct Node *temp = getNode(data);
        temp->next = *headref;
        *headref = temp;
      } else {
        headref = &(*headref)->next;
      }
    }
    size++;
  }
}

/**
 * @brief   Prints all nodes in the linked list.
 */
void printList(struct Node *head) {
  while (head != NULL) {
    printf("%d\t", head->data);
    head = head->next;
  }
  printf("\n");
}

/**
 * @brief   Main function - Entry point of the program.
 */
int main() {
  struct Node *head = NULL;
  int data = 12, index = 3;

  clrscr(); /* Clears the console screen (Turbo C specific) */

  /* Build initial list: 3 -> 5 -> 8 -> 10 */
  head = getNode(3);
  head->next = getNode(5);
  head->next->next = getNode(8);
  head->next->next->next = getNode(10);
  size = 4;

  printf("Linked list before insertion:");
  printList(head);

  /* Insert 12 at position 3 */
  insertNth(&head, index, data);
  printf("Linked list after insertion of 12 at position 3:");
  printList(head);

  /* Insert 1 at position 1 */
  data = 1;
  index = 1;
  insertNth(&head, index, data);
  printf("Linked list after insertion of 1 at position 1:");
  printList(head);

  /* Insert 15 at position 7 */
  data = 15;
  index = 7;
  insertNth(&head, index, data);
  printf("Linked list after insertion of 15 at position 7:");
  printList(head);

  getch(); /* Wait for a key press before closing (Turbo C specific) */

  return 0; /* Return 0 to indicate successful execution */
}
