/**
 * @file    strlength.C
 * @brief   Calculates and returns the length of a string.
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
 * This program calculates the length of a string by counting
 * characters until the null terminator is reached.
 *
 * @return  int  Returns 0 on successful execution.
 */

#include <conio.h> /* Console I/O library for clrscr() and getch() (DOS/Turbo C specific) */
#include <stdio.h>  /* Standard I/O library for printf and scanf functions */
#include <string.h> /* String library */

/**
 * @brief   Calculates the length of a string.
 * @param   str  The string to measure.
 * @return  int  The length of the string, or -1 on error.
 */
int str_length(char *str);

/**
 * @brief   Main function - Entry point of the program.
 *
 * Prompts user for a string and displays its length.
 */
int main() {
  char str[30]; /* Input string */
  int len;      /* String length */

  clrscr(); /* Clears the console screen (Turbo C specific) */

  /* Input string */
  printf("Enter the string you want to find length of:\t");
  scanf("%s", str);

  /* Calculate length */
  len = str_length(str);

  /* Display result */
  printf("\n Length of string is = %d\n", len);

  getch(); /* Wait for a key press before closing (Turbo C specific) */

  return 0; /* Return 0 to indicate successful execution */
}

/**
 * @brief   Calculates the length of a string.
 *
 * Iterates through the string character by character,
 * counting until the null terminator is reached.
 *
 * @param   str  The string to measure.
 * @return  int  The length of the string.
 */
int str_length(char *str) {
  int len = 0, i = 0;

  /* Count characters until null terminator */
  while (str[i] != '\0') {
    len++;
    i++;
  }

  return len;
}