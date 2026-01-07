/**
 * @file    strcompare.C
 * @brief   Compares two strings and returns their relative order.
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
 * Developed as part of the Phi Education Training (Milestone 5) and
 * BE Major-Project @ Terna Engineering College, University of Mumbai.
 *
 * This program compares two strings by calculating the sum of ASCII values.
 * Returns -1 if str1 < str2, 1 if str1 > str2, and 0 if equal.
 *
 * @return  int  Returns 0 on successful execution.
 */

#include <conio.h> /* Console I/O library for clrscr() and getch() (DOS/Turbo C specific) */
#include <stdio.h>  /* Standard I/O library for printf and scanf functions */
#include <string.h> /* String library */

/**
 * @brief   Compares two strings based on ASCII value sum.
 * @param   str1  First string to compare.
 * @param   str2  Second string to compare.
 * @return  int   -1 if str1 < str2, 1 if str1 > str2, 0 if equal.
 */
int str_compare(char *str1, char *str2);

/**
 * @brief   Main function - Entry point of the program.
 *
 * Prompts user for two strings and displays comparison result.
 */
int main() {
  char str1[30], str2[30]; /* Input strings */
  int g;                   /* Comparison result */

  clrscr(); /* Clears the console screen (Turbo C specific) */

  /* Input first string */
  printf("\n Comparing two strings \n Enter the first string:");
  scanf("%s", str1);

  /* Input second string */
  printf("\n Enter the second string:");
  scanf("%s", str2);

  /* Compare the strings */
  g = str_compare(str1, str2);

  /* Display result based on comparison */
  if (g == -1) {
    printf("\n %s is less than %s \n", str1, str2);
  } else if (g == 1) {
    printf("\n %s is less than %s \n", str2, str1);
  } else {
    printf("\n %s and %s are equal \n", str1, str2);
  }

  getch(); /* Wait for a key press before closing (Turbo C specific) */

  return 0; /* Return 0 to indicate successful execution */
}

/**
 * @brief   Compares two strings by calculating ASCII value sums.
 *
 * Sums all ASCII values of each character in both strings
 * and compares the totals.
 *
 * @param   str1  First string to compare.
 * @param   str2  Second string to compare.
 * @return  int   -1 if str1 < str2, 1 if str1 > str2, 0 if equal.
 */
int str_compare(char *str1, char *str2) {
  int i, ascii1 = 0, ascii2 = 0;

  /* Calculate ASCII sum for first string */
  for (i = 0; str1[i] != '\0'; i++)
    ascii1 = ascii1 + str1[i];

  /* Calculate ASCII sum for second string */
  for (i = 0; str2[i] != '\0'; i++)
    ascii2 = ascii2 + str2[i];

  /* Compare and return result */
  if (ascii1 < ascii2) {
    return -1;
  } else if (ascii1 > ascii2) {
    return 1;
  } else {
    return 0;
  }
}