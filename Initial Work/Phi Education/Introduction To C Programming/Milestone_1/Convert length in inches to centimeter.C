/**
 * @file    Convert length in inches to centimeter.C
 * @brief   Converts a length measurement from inches to centimeters.
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
 * Developed as part of the Phi Education Training (Milestone 1) and
 * BE Major-Project @ Terna Engineering College, University of Mumbai.
 *
 * This program prompts the user for a length in inches and converts it
 * to centimeters using the conversion factor: 1 inch = 2.54 centimeters.
 *
 * @return  int  Returns 0 on successful execution.
 */

#include <conio.h> /* Console I/O library for clrscr() and getch() (DOS/Turbo C specific) */
#include <stdio.h> /* Standard I/O library for printf and scanf functions */

/**
 * @brief   Main function - Entry point of the program.
 *
 * Clears the console screen, prompts the user to enter a length in inches,
 * converts it to centimeters, and displays the result.
 */
int main() {
  float inch, cm; /* inch: input length in inches; cm: converted length in
                     centimeters */

  clrscr(); /* Clears the console screen (Turbo C specific) */

  /* Prompt user to enter the length in inches */
  printf("Enter length in inch: ");

  /* Read the length value from user input */
  scanf("%f", &inch);

  /* Convert inches to centimeters: 1 inch = 2.54 cm */
  cm = inch * 2.54;

  /* Display the converted length with 2 decimal places */
  printf("Equivalent length in centimeter = %.2f", cm);

  getch(); /* Wait for a key press before closing (Turbo C specific) */

  return 0; /* Return 0 to indicate successful execution */
}