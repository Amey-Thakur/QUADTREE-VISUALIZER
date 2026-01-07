/**
 * @file    Area of circle.C
 * @brief   Calculates the area of a circle given the radius.
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
 * Developed as part of the Phi Education Internship (Milestone 1) and
 * BE Major-Project @ Terna Engineering College, University of Mumbai.
 *
 * This program prompts the user for the radius of a circle and calculates
 * its area using the formula: Area = π * r². The value of π is approximated
 * as 3.14 for simplicity.
 */

#include<stdio.h>   /* Standard I/O library for printf and scanf functions */
#include<conio.h>   /* Console I/O library for clrscr() and getch() (DOS/Turbo C specific) */

/**
 * @brief   Main function - Entry point of the program.
 *
 * Clears the console screen, prompts the user to enter the radius of a circle,
 * calculates the area using the formula Area = π * r², and displays the result.
 */
void main()
{
    float area, r;  /* area: stores the calculated area; r: stores the radius input */

    clrscr();  /* Clears the console screen (Turbo C specific) */

    /* Prompt user to enter the radius of the circle */
    printf("Enter radius of circle \n");

    /* Read the radius value from user input */
    scanf("%f", &r);

    /* Calculate area using the formula: Area = π * r² (π ≈ 3.14) */
    area = 3.14 * r * r;

    /* Display the calculated area */
    printf("Area of circle = %f", area);

    getch();  /* Wait for a key press before closing (Turbo C specific) */
}