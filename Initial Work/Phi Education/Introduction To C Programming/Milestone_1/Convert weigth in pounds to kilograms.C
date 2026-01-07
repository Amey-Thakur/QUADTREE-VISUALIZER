/**
 * @file    Convert weigth in pounds to kilograms.C
 * @brief   Converts a weight measurement from pounds to kilograms.
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
 * This program prompts the user for a weight in pounds and converts it
 * to kilograms using the conversion factor: 1 pound = 0.453592 kilograms.
 *
 * @return  int  Returns 0 on successful execution.
 */

#include <conio.h> /* Console I/O library for clrscr() and getch() (DOS/Turbo C specific) */
#include <stdio.h> /* Standard I/O library for printf and scanf functions */

/**
 * @brief   Main function - Entry point of the program.
 *
 * Clears the console screen, prompts the user to enter a weight in pounds,
 * converts it to kilograms, and displays the result.
 */
int main() {
  const float KG = 0.453592; /* Conversion factor: 1 pound = 0.453592 kg */
  float pound;               /* Input weight in pounds */

  clrscr(); /* Clears the console screen (Turbo C specific) */

  /* Prompt user to enter the weight in pounds */
  printf("Enter weight in pounds\n");

  /* Read the weight value from user input */
  scanf("%f", &pound);

  /* Display the converted weight in kilograms */
  printf("Weight in kilograms is %f\n", pound * KG);

  getch(); /* Wait for a key press before closing (Turbo C specific) */

  return 0; /* Return 0 to indicate successful execution */
}