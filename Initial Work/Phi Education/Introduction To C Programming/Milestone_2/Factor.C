/**
 * @file    Factor.C
 * @brief   Finds and prints all factors of a given number.
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
 * Developed as part of the Phi Education Training (Milestone 2) and
 * BE Major-Project @ Terna Engineering College, University of Mumbai.
 *
 * This program finds and displays all factors of a given integer.
 * A factor is a number that divides evenly into another number.
 *
 * @return  int  Returns 0 on successful execution.
 */

#include <conio.h> /* Console I/O library for clrscr() and getch() (DOS/Turbo C specific) */
#include <stdio.h> /* Standard I/O library for printf and scanf functions */

/**
 * @brief   Finds and prints all factors of a number.
 *
 * Iterates from 1 to n/2 and prints all numbers that divide n evenly.
 *
 * @param   n  The number to find factors for.
 * @return  int  Returns 0 (implicit).
 */
int findFactors(int n);

/**
 * @brief   Main function - Entry point of the program.
 *
 * Prompts the user to enter a number and displays all its factors.
 */
int main() {
  int number; /* Input number to find factors for */

  clrscr(); /* Clears the console screen (Turbo C specific) */

  /* Prompt user to enter a number */
  printf("Enter number:");
  scanf("%d", &number);

  /* Find and display all factors */
  findFactors(number);

  getch(); /* Wait for a key press before closing (Turbo C specific) */

  return 0; /* Return 0 to indicate successful execution */
}

/**
 * @brief   Finds and prints all factors of a number.
 *
 * A factor of n is any integer i where n % i == 0.
 * Only checks up to n/2 since no factor greater than n/2 can exist (except n
 * itself).
 *
 * @param   n  The number to find factors for.
 * @return  int  Returns 0.
 */
int findFactors(int n) {
  int i;

  /* Iterate from 1 to n/2 to find all factors */
  for (i = 1; i <= n / 2; i++) {
    /* Check if i is a factor of n */
    if (n % i == 0) {
      printf("%d\t", i);
    }
  }

  return 0;
}
