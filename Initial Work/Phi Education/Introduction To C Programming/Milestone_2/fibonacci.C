/**
 * @file    fibonacci.C
 * @brief   Prints the first n Fibonacci numbers.
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
 * This program generates and prints the Fibonacci sequence.
 * The Fibonacci sequence is: 0, 1, 1, 2, 3, 5, 8, 13, 21, ...
 * Each number is the sum of the two preceding numbers.
 *
 * @return  int  Returns 0 on successful execution.
 */

#include <conio.h> /* Console I/O library for clrscr() and getch() (DOS/Turbo C specific) */
#include <stdio.h> /* Standard I/O library for printf and scanf functions */

/**
 * @brief   Prints the first n Fibonacci numbers.
 *
 * Uses iterative approach to generate Fibonacci sequence.
 * F(0) = 0, F(1) = 1, F(n) = F(n-1) + F(n-2)
 *
 * @param   n  The count of Fibonacci numbers to print.
 */
void fibonacci(int n) {
  int a = 0, b = 1, c,
      i; /* a, b: previous two numbers; c: current; i: loop counter */

  printf("Fibonacci series till %d is", n);
  printf("\n%d %d", a, b); /* Print first two Fibonacci numbers */

  /* Generate remaining Fibonacci numbers */
  for (i = 2; i < n; i++) {
    c = a + b; /* Calculate next Fibonacci number */
    printf(" %d", c);
    a = b; /* Shift: a becomes b */
    b = c; /* Shift: b becomes c */
  }
}

/**
 * @brief   Main function - Entry point of the program.
 *
 * Calls fibonacci function to print first 10 Fibonacci numbers.
 */
int main() {
  int n = 10; /* Number of Fibonacci numbers to generate */

  clrscr(); /* Clears the console screen (Turbo C specific) */

  /* Generate and print Fibonacci sequence */
  fibonacci(n);

  getch(); /* Wait for a key press before closing (Turbo C specific) */

  return 0; /* Return 0 to indicate successful execution */
}