/**
 * @file    GCD.C
 * @brief   Calculates the Greatest Common Divisor (GCD) of two numbers.
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
 * This program calculates the Greatest Common Divisor (GCD) of two integers.
 * GCD is the largest positive integer that divides both numbers without
 * remainder.
 *
 * @return  int  Returns 0 on successful execution.
 */

#include <conio.h> /* Console I/O library for clrscr() and getch() (DOS/Turbo C specific) */
#include <stdio.h> /* Standard I/O library for printf and scanf functions */

/**
 * @brief   Calculates the GCD of two numbers.
 * @param   a  First integer.
 * @param   b  Second integer.
 * @return  int  The GCD of a and b.
 */
int gcd(int a, int b);

/**
 * @brief   Main function - Entry point of the program.
 *
 * Prompts the user to enter two numbers and displays their GCD.
 */
int main() {
  int a, b, ans; /* a, b: input numbers; ans: GCD result */

  clrscr(); /* Clears the console screen (Turbo C specific) */

  /* Prompt user to enter first number */
  printf("Enter the value for a:");
  scanf("%d", &a);

  /* Prompt user to enter second number */
  printf("Enter the value for b:");
  scanf("%d", &b);

  /* Calculate GCD */
  ans = gcd(a, b);

  /* Display the GCD */
  printf("GCD is : %d", ans);

  getch(); /* Wait for a key press before closing (Turbo C specific) */

  return 0; /* Return 0 to indicate successful execution */
}

/**
 * @brief   Calculates the GCD of two numbers using iterative method.
 *
 * Iterates through all numbers from 1 to min(a, b) and finds the
 * largest number that divides both a and b evenly.
 *
 * @param   a  First integer.
 * @param   b  Second integer.
 * @return  int  The GCD of a and b.
 */
int gcd(int a, int b) {
  int i, result;

  /* Check all numbers from 1 to minimum of a and b */
  for (i = 1; i <= a && i <= b; i++) {
    /* If i divides both a and b, it's a common divisor */
    if (a % i == 0 && b % i == 0) {
      result = i; /* Update result with the common divisor */
    }
  }

  return result;
}
