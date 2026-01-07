/**
 * @file    arraysearch.C
 * @brief   Searches for a specific element in an integer array.
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
 * This program allows the user to input a set of integers into an array,
 * then searches for a specific element using linear search algorithm.
 *
 * @return  int  Returns 0 on successful execution.
 */

#include <conio.h> /* Console I/O library for clrscr() and getch() (DOS/Turbo C specific) */
#include <stdio.h> /* Standard I/O library for printf and scanf functions */

#define MAX_SIZE 100 /* Maximum size of the array */

/**
 * @brief   Main function - Entry point of the program.
 *
 * Creates an array, accepts user input for elements,
 * searches for a specific element, and displays the result.
 */
int main() {
  int arr[MAX_SIZE]; /* Array to store integers */
  int size, i, toSearch,
      found; /* size: array size; toSearch: element to find; found: flag */

  clrscr(); /* Clears the console screen (Turbo C specific) */

  /* Prompt user to enter array size */
  printf("Enter size of array:");
  scanf("%d", &size);

  /* Input array elements */
  printf("Enter elements in array:");
  for (i = 0; i < size; i++) {
    scanf("%d", &arr[i]);
  }

  /* Prompt user to enter element to search */
  printf("\nEnter element to search:");
  scanf("%d", &toSearch);

  /* Linear search: iterate through array to find element */
  found = 0; /* Initialize found flag to false */
  for (i = 0; i < size; i++) {
    if (arr[i] == toSearch) {
      found = 1; /* Element found */
      break;     /* Exit loop */
    }
  }

  /* Display search result */
  if (found == 1) {
    printf("\n%d is found at position %d", toSearch, i + 1);
  } else {
    printf("\n%d is not found in the array", toSearch);
  }

  getch(); /* Wait for a key press before closing (Turbo C specific) */

  return 0; /* Return 0 to indicate successful execution */
}