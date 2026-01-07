/**
 * @file    Convert temperature in farenheit to celcius.C
 * @brief   Converts a temperature from Fahrenheit to Celsius.
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
 * This program prompts the user for a temperature in Fahrenheit and converts
 * it to Celsius using the formula: Celsius = (Fahrenheit - 32) * 5/9.
 *
 * @return  int  Returns 0 on successful execution.
 */

#include <conio.h> /* Console I/O library for clrscr() and getch() (DOS/Turbo C specific) */
#include <stdio.h> /* Standard I/O library for printf and scanf functions */

/**
 * @brief   Main function - Entry point of the program.
 *
 * Clears the console screen, prompts the user to enter a temperature in
 * Fahrenheit, converts it to Celsius, and displays the result.
 */
int main() {
  float celsius, fahrenheit; /* celsius: converted temperature; fahrenheit:
                                input temperature */

  clrscr(); /* Clears the console screen (Turbo C specific) */

  /* Prompt user to enter the temperature in Fahrenheit */
  printf("Enter temperature in fahrenheit");

  /* Read the temperature value from user input */
  scanf("%f", &fahrenheit);

  /* Convert Fahrenheit to Celsius: C = (F - 32) * 5/9 */
  celsius = (fahrenheit - 32) * 5 / 9;

  /* Display the converted temperature with 2 decimal places */
  printf("%.2f Fahrenheit = %.2f Celsius", fahrenheit, celsius);

  getch(); /* Wait for a key press before closing (Turbo C specific) */

  return 0; /* Return 0 to indicate successful execution */
}