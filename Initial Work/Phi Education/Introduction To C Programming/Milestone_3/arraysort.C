/**
 * @file    arraysort.C
 * @brief   Sorts an integer array in ascending or descending order.
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
 * Developed as part of the Phi Education Training (Milestone 3) and
 * BE Major-Project @ Terna Engineering College, University of Mumbai.
 *
 * This program allows the user to input a set of integers and sort them
 * in ascending or descending order based on user's choice using bubble sort.
 *
 * @return  int  Returns 0 on successful execution.
 */

#include <conio.h> /* Console I/O library for clrscr() and getch() (DOS/Turbo C specific) */
#include <stdio.h> /* Standard I/O library for printf and scanf functions */

/**
 * @brief   Main function - Entry point of the program.
 *
 * Accepts array input, prompts for sort order, sorts using bubble sort,
 * and displays the sorted array.
 */
int main() {
  int a[100], n, i, j, no,
      tmp; /* a: array; n: size; no: user choice; tmp: swap temp */

  clrscr(); /* Clears the console screen (Turbo C specific) */

  /* Prompt user to enter array size */
  printf("Array size:");
  scanf("%d", &n);

  /* Input array elements */
  printf("Elements:");
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  /* Prompt user for sort order */
  printf("Enter\n 1 for Ascending order\n 2 for Descending order\n");
  scanf("%d", &no);

  switch (no) {
  case 1:
    /* Bubble sort - Ascending order */
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        if (a[j] > a[i]) {
          /* Swap elements */
          tmp = a[i];
          a[i] = a[j];
          a[j] = tmp;
        }
      }
    }
    /* Display sorted array */
    printf("\n Ascending order:");
    for (i = 0; i < n; i++) {
      printf("%d\t", a[i]);
    }
    break;

  case 2:
    /* Bubble sort - Descending order */
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        if (a[j] < a[i]) {
          /* Swap elements */
          tmp = a[i];
          a[i] = a[j];
          a[j] = tmp;
        }
      }
    }
    /* Display sorted array */
    printf("\n Descending order:");
    for (i = 0; i < n; i++) {
      printf("%d\t", a[i]);
    }
    break;

  default:
    printf("Invalid Input");
  }

  getch(); /* Wait for a key press before closing (Turbo C specific) */

  return 0; /* Return 0 to indicate successful execution */
}
