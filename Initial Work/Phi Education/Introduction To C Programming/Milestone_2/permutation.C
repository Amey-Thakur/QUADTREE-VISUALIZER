/**
 * @file    permutation.C
 * @brief   Calculates the permutation (nPr) of two numbers.
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
 * This program calculates the permutation (nPr) using the formula:
 * nPr = n! / (n-r)!
 * where n! denotes the factorial of n.
 *
 * @return  int  Returns 0 on successful execution.
 */

#include <conio.h> /* Console I/O library for clrscr() and getch() (DOS/Turbo C specific) */
#include <stdio.h> /* Standard I/O library for printf and scanf functions */

/**
 * @brief   Calculates the factorial of a given number.
 * @param   num  The number to calculate factorial for.
 * @return  int  The factorial of the input number.
 */
int factorial(int num);

/**
 * @brief   Main function - Entry point of the program.
 *
 * Prompts the user to enter values for n and r, validates the input,
 * calculates the permutation (nPr), and displays the result.
 */
int main() {
  int n, r;  /* n: total items; r: items to arrange */
  float nPr; /* Result of the permutation calculation */

  clrscr(); /* Clears the console screen (Turbo C specific) */

  /* Prompt user to enter the value of n */
  printf("Enter value of n in nPr\n");
  scanf("%d", &n);

  /* Prompt user to enter the value of r */
  printf("Enter value of r in nPr\n");
  scanf("%d", &r);

  /* Validate input: n >= r and both n, r >= 0 */
  if (n >= r && n >= 0 && r >= 0) {
    /* Calculate nPr = n! / (n-r)! */
    nPr = (float)factorial(n) / factorial(n - r);
    printf("Value of %dP%d=%f\n", n, r, nPr);
  } else {
    printf("Invalid Entry\n");
  }

  getch(); /* Wait for a key press before closing (Turbo C specific) */

  return 0; /* Return 0 to indicate successful execution */
}

/**
 * @brief   Calculates the factorial of a given number.
 *
 * Uses an iterative approach to compute n! = 1 * 2 * 3 * ... * n.
 *
 * @param   num  The number to calculate factorial for.
 * @return  int  The factorial of the input number.
 */
int factorial(int num) {
  int i, fact = 1;

  /* Multiply all integers from 1 to num */
  for (i = 1; i <= num; i++) {
    fact = fact * i;
  }

  return fact;
}