/**
 * @file    sortdatatype.C
 * @brief   Demonstrates sorting of different data types using qsort.
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
 * Developed as part of the Phi Education Training (Milestone 8) and
 * BE Major-Project @ Terna Engineering College, University of Mumbai.
 *
 * This program demonstrates sorting arrays of different data types:
 * integers, floats, and strings using qsort with custom comparators.
 *
 * @return  int  Returns 0 on successful execution.
 */

#include <conio.h> /* Console I/O library for clrscr() and getch() (DOS/Turbo C specific) */
#include <math.h>   /* Math library for abs() */
#include <stdio.h>  /* Standard I/O library for printf functions */
#include <stdlib.h> /* Standard library for qsort() */
#include <string.h> /* String library for strcmp() */

/**
 * @brief   Comparator function for sorting integers by absolute value.
 * @param   a  Pointer to first element.
 * @param   b  Pointer to second element.
 * @return  int  Negative if a < b, positive if a > b, 0 if equal.
 */
int compare(const void *a, const void *b) {
  int A = *((int *)a);
  int B = *((int *)b);
  return abs(A) - abs(B);
}

/**
 * @brief   Comparator function for sorting strings alphabetically.
 * @param   a  Pointer to first string pointer.
 * @param   b  Pointer to second string pointer.
 * @return  int  Result of strcmp comparison.
 */
int compare_1(const void *a, const void *b) {
  const char *ia = *(const char **)a;
  const char *ib = *(const char **)b;
  return strcmp(ia, ib);
}

/**
 * @brief   Comparator function for sorting floats.
 * @param   a  Pointer to first element.
 * @param   b  Pointer to second element.
 * @return  int  -1 if a < b, 1 otherwise.
 */
int compare_2(const void *a, const void *b) {
  float A = *((float *)a);
  float B = *((float *)b);
  if (A < B)
    return -1;
  return 1;
}

/**
 * @brief   Main function - Entry point of the program.
 *
 * Demonstrates sorting of integer, float, and string arrays.
 */
int main() {
  int i;
  int A[] = {45, 6, 78, 76, 4, 4232, 1, 5, 43};
  float B[] = {45.5, 6.5, 7.8, 7.6, 4.1, 0.4232, 15, 43};
  char *string[] = {"geeta", "sita", "meena", "mita", "jeena", "jiya"};
  int strings_len;

  clrscr(); /* Clears the console screen (Turbo C specific) */

  /* Sort and display integer array */
  printf("\nInteger Array Before sorting :\t");
  for (i = 0; i < 9; i++)
    printf("%d\t", A[i]);

  qsort(A, 9, sizeof(int), compare);

  printf("\nInteger Array After sorting :\t");
  for (i = 0; i < 9; i++)
    printf("%d\t", A[i]);

  /* Sort and display float array */
  printf("\n\nFloat Array Before sorting :\t");
  for (i = 0; i < 8; i++)
    printf("%.2f\t", B[i]);

  qsort(B, 8, sizeof(float), compare_2);

  printf("\nFloat Array After sorting :\t");
  for (i = 0; i < 8; i++)
    printf("%.2f\t", B[i]);

  /* Sort and display string array */
  printf("\n\nChar Array before sorting\n");
  strings_len = sizeof(string) / sizeof(char *);
  for (i = 0; i < strings_len; i++)
    printf("%s\t", string[i]);

  printf("\nChar Array After sorting\n");
  qsort(string, strings_len, sizeof(char *), compare_1);
  for (i = 0; i < strings_len; i++)
    printf("%s\t ", string[i]);

  getch(); /* Wait for a key press before closing (Turbo C specific) */

  return 0; /* Return 0 to indicate successful execution */
}