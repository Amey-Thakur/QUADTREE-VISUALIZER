/**
 * @file    14.c
 * @brief   Implements merging of two sorted linked lists.
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
 * Developed as part of the Phi Education Training (Milestone 14) and
 * BE Major-Project @ Terna Engineering College, University of Mumbai.
 *
 * This program demonstrates how to merge two sorted linked lists into
 * a single sorted linked list by moving nodes from source to destination.
 *
 * @return  int  Returns 0 on successful execution.
 */

#include <assert.h> /* Standard library for debugging assertions */
#include <stdio.h>  /* Standard I/O library for printing and input */
#include <stdlib.h> /* Standard library for malloc() and NULL */

/**
 * @struct Node
 * @brief  Structure for a linked list node.
 */
struct Node {
  int d;
  struct Node *next;
};

/* Function prototypes */
void movenode(struct Node **desR, struct Node **souR);
struct Node *sortedmerge(struct Node *a, struct Node *b);
void push(struct Node **head_r, int n_d);
void displaylist(struct Node *node);

/**
 * @brief   Merges two sorted linked lists into one sorted list.
 * @param   a  Pointer to the head of the first sorted list.
 * @param   b  Pointer to the head of the second sorted list.
 * @return  struct Node*  Pointer to the head of the merged sorted list.
 */
struct Node *sortedmerge(struct Node *a, struct Node *b) {
  struct Node dummy;
  struct Node *tail = &dummy;
  dummy.next = NULL;

  while (1) {
    if (a == NULL) {
      tail->next = b;
      break;
    } else if (b == NULL) {
      tail->next = a;
      break;
    }

    /* Move the smaller node to the resulting list */
    if (a->d <= b->d) {
      movenode(&(tail->next), &a);
    } else {
      movenode(&(tail->next), &b);
    }
    tail = tail->next;
  }
  return (dummy.next);
}

/**
 * @brief   Moves the front node of the source list to the front of destination.
 * @param   desR  Pointer to the head pointer of the destination list.
 * @param   souR  Pointer to the head pointer of the source list.
 */
void movenode(struct Node **desR, struct Node **souR) {
  struct Node *nNode = *souR;
  assert(nNode != NULL);

  *souR = nNode->next; /* Advances the source-list pointer */
  nNode->next = *desR; /* Link the old dest-list off the new node */
  *desR = nNode;       /* Move dest-list to point to the new node */
}

/**
 * @brief   Adds a new node at the beginning of the list.
 * @param   head_r  Pointer to the head pointer of the linked list.
 * @param   n_d     The data to be stored in the new node.
 */
void push(struct Node **head_r, int n_d) {
  struct Node *n_node = (struct Node *)malloc(sizeof(struct Node));
  n_node->d = n_d;
  n_node->next = (*head_r);
  (*head_r) = n_node;
}

/**
 * @brief   Prints the linked list data.
 * @param   node  Pointer to the head of the list.
 */
void displaylist(struct Node *node) {
  while (node != NULL) {
    printf("%d ", node->d);
    node = node->next;
  }
  printf("\n");
}

/**
 * @brief   Main function - Entry point of the program.
 */
int main() {
  struct Node *res = NULL;
  struct Node *a = NULL;
  struct Node *b = NULL;

  /* List a: 5 10 15 */
  push(&a, 15);
  push(&a, 10);
  push(&a, 5);

  /* List b: 3 20 20 */
  push(&b, 20);
  push(&b, 20);
  push(&b, 3);

  res = sortedmerge(a, b);

  printf("Merged Linked List: ");
  displaylist(res);

  return 0;
}