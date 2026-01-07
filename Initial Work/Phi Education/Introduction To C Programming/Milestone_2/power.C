/**
 * @file    power.C
 * @brief   Calculates the power of a number (x^n).
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
 * This program calculates x raised to the power n (x^n) using
 * an iterative multiplication approach.
 *
 * @return  int  Returns 0 on successful execution.
 */

#include <conio.h> /* Console I/O library for clrscr() and getch() (DOS/Turbo C specific) */
#include <stdio.h> /* Standard I/O library for printf and scanf functions */

/**
 * @brief   Calculates x raised to the power n.
 * @param   x  The base value (double).
 * @param   n  The exponent value (integer).
 * @return  double  The result of x^n.
 */
double power(double x, int n);

/**
 * @brief   Main function - Entry point of the program.
 *
 * Prompts the user to enter base and exponent values,
 * calculates the power, and displays the result.
 */
int main() {
  double x;   /* Base value */
  int n;      /* Exponent value */
  double ans; /* Result of x^n */

  clrscr(); /* Clears the console screen (Turbo C specific) */

  /* Prompt user to enter the base value */
  printf("Enter the base value i.e. X:");
  scanf("%lf", &x);

  /* Prompt user to enter the exponent value */
  printf("Enter the exponent value i.e. N:");
  scanf("%d", &n);

  /* Calculate power */
  ans = power(x, n);

  /* Display the result */
  printf("Power of X^N is %lf", ans);

  getch(); /* Wait for a key press before closing (Turbo C specific) */

  return 0; /* Return 0 to indicate successful execution */
}

/**
 * @brief   Calculates x raised to the power n using iteration.
 *
 * Multiplies x by itself n times to compute x^n.
 *
 * @param   x  The base value (double).
 * @param   n  The exponent value (integer).
 * @return  double  The result of x^n.
 */
double power(double x, int n) {
  double result = 1.0; /* Initialize result to 1 */
  int i;

  /* Multiply x by itself n times */
  for (i = 1; i <= n; i++) {
    result *= x;
  }

  return result;
}