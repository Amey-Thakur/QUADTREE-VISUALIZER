/**
 * @file    primecheck.C
 * @brief   Checks if a given number is a prime number.
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
 * This program determines whether a given positive integer is a prime number.
 * A prime number is a natural number greater than 1 that has no positive
 * divisors other than 1 and itself.
 *
 * @return  int  Returns 0 on successful execution.
 */

#include <conio.h> /* Console I/O library for clrscr() and getch() (DOS/Turbo C specific) */
#include <stdio.h> /* Standard I/O library for printf and scanf functions */

/**
 * @brief   Checks if a number is prime.
 * @param   x  The number to check.
 * @return  int  Returns 1 if prime, 0 if not prime.
 */
int is_prime(unsigned int x);

/**
 * @brief   Main function - Entry point of the program.
 *
 * Prompts the user to enter a number and displays whether it is prime.
 */
int main() {
  unsigned int x; /* Input number to check */
  int ans;        /* Result: 1 if prime, 0 if not */

  clrscr(); /* Clears the console screen (Turbo C specific) */

  /* Prompt user to enter a number */
  printf("Enter the no:");
  scanf("%d", &x);

  /* Handle special cases: 0 and 1 are not prime */
  if (x == 0 || x == 1) {
    printf("Pls try with other nos:");
    getch();
    return 0;
  }

  /* Check if the number is prime */
  ans = is_prime(x);

  /* Display result: 1 = prime, 0 = not prime */
  printf("%d", ans);

  getch(); /* Wait for a key press before closing (Turbo C specific) */

  return 0; /* Return 0 to indicate successful execution */
}

/**
 * @brief   Checks if a number is prime using trial division.
 *
 * Divides x by all integers from 2 to x/2 to check for factors.
 * If any factor is found, the number is not prime.
 *
 * @param   x  The number to check.
 * @return  int  Returns 1 if prime, 0 if not prime.
 */
int is_prime(unsigned int x) {
  int i;

  /* Check for factors from 2 to x/2 */
  for (i = 2; i <= x / 2; i++) {
    /* If x is divisible by i, it's not prime */
    if (x % i == 0) {
      return 0; /* Not prime */
    }
  }

  return 1; /* Prime */
}