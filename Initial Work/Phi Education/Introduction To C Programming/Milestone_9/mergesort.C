/**
 * @file    mergesort.C
 * @brief   Sorts a linked list using the merge sort algorithm.
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
 * This program implements merge sort for linked lists using
 * divide-and-conquer approach with FrontBackSplit and SortedMerge.
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

/* Function prototypes */
struct Node *SortedMerge(struct Node *a, struct Node *b);
void FrontBackSplit(struct Node *source, struct Node **frontRef,
                    struct Node **backRef);

/**
 * @brief   Sorts a linked list using merge sort (recursive).
 */
void MergeSort(struct Node **headRef) {
  struct Node *head = *headRef;
  struct Node *a;
  struct Node *b;

  /* Base case: 0 or 1 elements */
  if ((head == NULL) || (head->next == NULL)) {
    return;
  }

  /* Split list into halves */
  FrontBackSplit(head, &a, &b);

  /* Recursively sort both halves */
  MergeSort(&a);
  MergeSort(&b);

  /* Merge the sorted halves */
  *headRef = SortedMerge(a, b);
}

/**
 * @brief   Merges two sorted lists into one sorted list.
 */
struct Node *SortedMerge(struct Node *a, struct Node *b) {
  struct Node *result = NULL;

  /* Base cases */
  if (a == NULL)
    return b;
  else if (b == NULL)
    return a;

  /* Pick the smaller value and recurse */
  if (a->data <= b->data) {
    result = a;
    result->next = SortedMerge(a->next, b);
  } else {
    result = b;
    result->next = SortedMerge(a, b->next);
  }

  return result;
}

/**
 * @brief   Splits a list into front and back halves using slow/fast pointers.
 */
void FrontBackSplit(struct Node *source, struct Node **frontRef,
                    struct Node **backRef) {
  struct Node *fast;
  struct Node *slow;

  slow = source;
  fast = source->next;

  /* Fast pointer moves 2x, slow moves 1x */
  while (fast != NULL) {
    fast = fast->next;
    if (fast != NULL) {
      slow = slow->next;
      fast = fast->next;
    }
  }

  /* Split at the midpoint */
  *frontRef = source;
  *backRef = slow->next;
  slow->next = NULL;
}

/**
 * @brief   Prints all nodes in the linked list.
 */
void printList(struct Node *node) {
  while (node != NULL) {
    printf("%d ", node->data);
    node = node->next;
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
 * @brief   Main function - Entry point of the program.
 */
int main() {
  struct Node *a = NULL;

  clrscr(); /* Clears the console screen (Turbo C specific) */

  /* Build unsorted list */
  push(&a, 15);
  push(&a, 10);
  push(&a, 5);
  push(&a, 20);
  push(&a, 3);
  push(&a, 2);

  /* Sort the list */
  MergeSort(&a);

  printf("Sorted Linked List is: \n");
  printList(a);

  getch(); /* Wait for a key press before closing (Turbo C specific) */

  return 0; /* Return 0 to indicate successful execution */
}
