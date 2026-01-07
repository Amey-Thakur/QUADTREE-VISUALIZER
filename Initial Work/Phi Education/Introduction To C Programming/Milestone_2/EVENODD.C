/**
 * @file    EVENODD.C
 * @brief   Checks if a given number is even or odd using bitwise operation.
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
 * This program determines whether a given integer is even or odd using
 * a bitwise AND operation. If the least significant bit is 0, the number
 * is even; otherwise, it is odd.
 *
 * @return  int  Returns 0 on successful execution.
 */

#include <conio.h> /* Console I/O library for clrscr() and getch() (DOS/Turbo C specific) */
#include <stdio.h> /* Standard I/O library for printf and scanf functions */

/**
 * @brief   Checks if a number is even using bitwise AND.
 *
 * Uses the bitwise AND operation with 1 to check the least significant bit.
 * If LSB is 0, the number is even; if LSB is 1, the number is odd.
 *
 * @param   num  The number to check.
 * @return  int  Returns 1 if even, 0 if odd.
 */
int isEven(int num) {
  /* Bitwise AND with 1: returns 0 if even, 1 if odd */
  /* NOT operator inverts to return 1 for even, 0 for odd */
  return !(num & 1);
}

/**
 * @brief   Main function - Entry point of the program.
 *
 * Prompts the user to enter a number and displays whether it is even or odd.
 */
int main() {
  int num; /* Input number to check */

  clrscr(); /* Clears the console screen (Turbo C specific) */

  /* Prompt user to enter a number */
  printf("Enter any number:");
  scanf("%d", &num);

  /* Check if the number is even or odd */
  if (isEven(num)) {
    printf("The number is even");
  } else {
    printf("The number is odd");
  }

  getch(); /* Wait for a key press before closing (Turbo C specific) */

  return 0; /* Return 0 to indicate successful execution */
}