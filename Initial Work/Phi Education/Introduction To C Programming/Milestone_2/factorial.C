/**
 * @file    factorial.C
 * @brief   Calculates the factorial of a number using recursion.
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
 * This program calculates the factorial of a number using recursive function.
 * Factorial of n is defined as: n! = n * (n-1) * (n-2) * ... * 1
 * By definition, 0! = 1.
 *
 * @return  int  Returns 0 on successful execution.
 */

#include <conio.h> /* Console I/O library for clrscr() and getch() (DOS/Turbo C specific) */
#include <stdio.h> /* Standard I/O library for printf and scanf functions */

/**
 * @brief   Calculates the factorial of a number using recursion.
 *
 * Uses the recursive definition: n! = n * (n-1)!
 * Base case: 0! = 1
 *
 * @param   n  The number to calculate factorial for.
 * @return  unsigned int  The factorial of n.
 */
unsigned int factorial(unsigned int n) {
  /* Base case: factorial of 0 is 1 */
  if (n == 0)
    return 1;

  /* Recursive case: n! = n * (n-1)! */
  return n * factorial(n - 1);
}

/**
 * @brief   Main function - Entry point of the program.
 *
 * Prompts the user to enter a number and displays its factorial.
 */
int main() {
  int num; /* Input number to calculate factorial for */

  clrscr(); /* Clears the console screen (Turbo C specific) */

  /* Prompt user to enter a number */
  printf("Enter the number:");
  scanf("%d", &num);

  /* Calculate and display the factorial */
  printf("Factorial of %d is %d", num, factorial(num));

  getch(); /* Wait for a key press before closing (Turbo C specific) */

  return 0; /* Return 0 to indicate successful execution */
}