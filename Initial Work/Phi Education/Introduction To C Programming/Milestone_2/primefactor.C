/**
 * @file    primefactor.C
 * @brief   Finds and prints all prime factors of a given number.
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
 * This program finds and displays all prime factors of a given number.
 * A prime factor is a factor that is also a prime number.
 *
 * @return  int  Returns 0 on successful execution.
 */

#include <conio.h> /* Console I/O library for clrscr() and getch() (DOS/Turbo C specific) */
#include <stdio.h> /* Standard I/O library for printf and scanf functions */

/**
 * @brief   Checks if a number is prime and prints it if so.
 *
 * A number is prime if it has no divisors other than 1 and itself.
 *
 * @param   Number  The number to check.
 */
void Find_Prime(int Number) {
  int i, Count = 0;

  /* Count divisors from 2 to Number/2 */
  for (i = 2; i <= Number / 2; i++) {
    if (Number % i == 0) {
      Count++;
    }
  }

  /* If no divisors found (except 1 and itself), it's prime */
  if (Count == 0 && Number != 1) {
    printf("\n %d is a prime number", Number);
  }
}

/**
 * @brief   Finds all factors of a number and checks each for primality.
 *
 * Iterates through all numbers from 1 to Number and checks
 * if each factor is a prime number.
 *
 * @param   Number  The number to find prime factors for.
 */
void Find_Factors(int Number) {
  int i;

  /* Check all numbers from 1 to Number for factors */
  for (i = 1; i <= Number; i++) {
    if (Number % i == 0) {
      Find_Prime(i); /* Check if this factor is prime */
    }
  }
}

/**
 * @brief   Main function - Entry point of the program.
 *
 * Prompts the user to enter a number and displays its prime factors.
 */
int main() {
  int Number; /* Input number to find prime factors for */

  clrscr(); /* Clears the console screen (Turbo C specific) */

  /* Prompt user to enter a number */
  printf("\n Please enter any number to find it's prime factors:");
  scanf("%d", &Number);

  /* Display prime factors */
  printf("\n Prime factors of a given number are:\n");
  Find_Factors(Number);

  getch(); /* Wait for a key press before closing (Turbo C specific) */

  return 0; /* Return 0 to indicate successful execution */
}
