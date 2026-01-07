/**
 * @file    LCM.C
 * @brief   Calculates the Least Common Multiple (LCM) of three numbers.
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
 * This program calculates the Least Common Multiple (LCM) of three integers.
 * LCM is the smallest positive integer that is divisible by all given numbers.
 *
 * @return  int  Returns 0 on successful execution.
 */

#include <conio.h> /* Console I/O library for clrscr() and getch() (DOS/Turbo C specific) */
#include <stdio.h> /* Standard I/O library for printf and scanf functions */

/**
 * @brief   Calculates the LCM of two numbers.
 * @param   a  First integer.
 * @param   b  Second integer.
 * @return  int  The LCM of a and b.
 */
int lcm(int a, int b);

/**
 * @brief   Main function - Entry point of the program.
 *
 * Prompts the user to enter three numbers and displays their LCM.
 */
int main() {
  int a, b, c, l,
      k; /* a, b, c: input numbers; l, k: intermediate LCM results */

  clrscr(); /* Clears the console screen (Turbo C specific) */

  /* Prompt user to enter three positive integers */
  printf("Enter any three positive integers:");
  scanf("%d%d%d", &a, &b, &c);

  /* Calculate LCM of first two numbers */
  if (a > b)
    l = lcm(a, b);
  else
    l = lcm(b, a);

  /* Calculate LCM of the result with third number */
  if (l > c)
    k = lcm(l, c);
  else
    k = lcm(c, l);

  /* Display the final LCM */
  printf("LCM of three integers is %d", k);

  getch(); /* Wait for a key press before closing (Turbo C specific) */

  return 0; /* Return 0 to indicate successful execution */
}

/**
 * @brief   Calculates the LCM of two numbers using iterative method.
 *
 * Starts from the larger number and increments until finding a number
 * that is divisible by both a and b.
 *
 * @param   a  First integer (should be >= b for efficiency).
 * @param   b  Second integer.
 * @return  int  The LCM of a and b.
 */
int lcm(int a, int b) {
  int temp = a; /* Start from the larger number */

  /* Find the smallest number divisible by both a and b */
  while (1) {
    if (temp % b == 0 && temp % a == 0)
      break;
    temp++;
  }

  return temp;
}