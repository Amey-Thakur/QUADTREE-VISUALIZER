/**
 * @file    Area of rectangle.C
 * @brief   Calculates the area of a rectangle given height and width.
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
 * This program prompts the user for the height and width of a rectangle
 * and calculates its area using the formula: Area = height * width.
 *
 * @return  int  Returns 0 on successful execution.
 */

#include <conio.h> /* Console I/O library for clrscr() and getch() (DOS/Turbo C specific) */
#include <stdio.h> /* Standard I/O library for printf and scanf functions */

/**
 * @brief   Main function - Entry point of the program.
 *
 * Clears the console screen, prompts the user to enter the height and width
 * of a rectangle, calculates the area, and displays the result.
 */
int main() {
  int area, h, w; /* area: calculated area; h: height; w: width */

  clrscr(); /* Clears the console screen (Turbo C specific) */

  /* Prompt user to enter the height of the rectangle */
  printf("Enter height of rectangle \n");

  /* Read the height value from user input */
  scanf("%d", &h);

  /* Prompt user to enter the width of the rectangle */
  printf("Enter width of rectangle \n");

  /* Read the width value from user input */
  scanf("%d", &w);

  /* Calculate area using the formula: Area = height * width */
  area = h * w;

  /* Display the calculated area */
  printf("Area of rectangle = %d", area);

  getch(); /* Wait for a key press before closing (Turbo C specific) */

  return 0; /* Return 0 to indicate successful execution */
}