/**
 * @file    Area of triangle.C
 * @brief   Calculates the area of a triangle given base and height.
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
 * This program prompts the user for the base and height of a triangle
 * and calculates its area using the formula: Area = 0.5 * base * height.
 *
 * @return  int  Returns 0 on successful execution.
 */

#include <conio.h> /* Console I/O library for clrscr() and getch() (DOS/Turbo C specific) */
#include <stdio.h> /* Standard I/O library for printf and scanf functions */

/**
 * @brief   Main function - Entry point of the program.
 *
 * Clears the console screen, prompts the user to enter the base and height
 * of a triangle, calculates the area, and displays the result.
 */
int main() {
  float area, base, height; /* area: calculated area; base: triangle base;
                               height: triangle height */

  clrscr(); /* Clears the console screen (Turbo C specific) */

  /* Prompt user to enter the base of the triangle */
  printf("Enter base \n");

  /* Read the base value from user input */
  scanf("%f", &base);

  /* Prompt user to enter the height of the triangle */
  printf("Enter height \n");

  /* Read the height value from user input */
  scanf("%f", &height);

  /* Calculate area using the formula: Area = 0.5 * base * height */
  area = 0.5 * base * height;

  /* Display the calculated area */
  printf("Area of triangle = %f", area);

  getch(); /* Wait for a key press before closing (Turbo C specific) */

  return 0; /* Return 0 to indicate successful execution */
}