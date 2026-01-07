/**
 * @file    recursivereverse.C
 * @brief   Reverses a linked list using recursion.
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
 * This program demonstrates reversing a linked list using a
 * recursive approach. Uses C++ style classes for linked list.
 *
 * @return  int  Returns 0 on successful execution.
 */

#include <conio.h> /* Console I/O library for clrscr() and getch() (DOS/Turbo C specific) */
#include <stdio.h>  /* Standard I/O library for printf functions */
#include <stdlib.h> /* Standard library for malloc() */

/**
 * @brief   Node structure for linked list (using C++ constructor).
 */
struct Node {
  int data;
  struct Node *next;

  Node(int data) {
    this->data = data;
    next = NULL;
  }
};

/**
 * @brief   LinkedList class with recursive reverse method.
 */
struct LinkedList {
  Node *head;

  LinkedList() { head = NULL; }

  /**
   * @brief   Recursively reverses the linked list.
   */
  Node *reverse(Node *node) {
    if (node == NULL)
      return NULL;

    if (node->next == NULL) {
      head = node;
      return node;
    }

    Node *node1 = reverse(node->next);
    node1->next = node;
    node->next = NULL;

    return node;
  }

  /**
   * @brief   Prints all nodes in the list.
   */
  void print() {
    struct Node *temp = head;
    while (temp != NULL) {
      printf("%d ", temp->data);
      temp = temp->next;
    }
  }

  /**
   * @brief   Pushes a new node to the front.
   */
  void push(int data) {
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
  }
};

/**
 * @brief   Main function - Entry point of the program.
 */
int main() {
  LinkedList ll;

  clrscr(); /* Clears the console screen (Turbo C specific) */

  /* Build the list */
  ll.push(20);
  ll.push(4);
  ll.push(15);
  ll.push(85);

  printf("Given linked list\n");
  ll.print();

  /* Reverse the list */
  ll.reverse(ll.head);

  printf("\nReversed Linked list \n");
  ll.print();

  getch(); /* Wait for a key press before closing (Turbo C specific) */

  return 0; /* Return 0 to indicate successful execution */
}
