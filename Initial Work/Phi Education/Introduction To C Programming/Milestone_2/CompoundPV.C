/**
 * @file    CompoundPV.C
 * @brief   Calculates the present value of an investment using compound
 * interest.
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
 * This program calculates the present value of an investment using the
 * compound interest formula: PV = FV / (1 + rate/100)^nperiods
 * where FV is the future value, rate is the interest rate,
 * and nperiods is the number of compounding periods.
 *
 * @return  int  Returns 0 on successful execution.
 */

#include <conio.h> /* Console I/O library for clrscr() and getch() (DOS/Turbo C specific) */
#include <math.h>  /* Math library for pow() function */
#include <stdio.h> /* Standard I/O library for printf and scanf functions */

/**
 * @brief   Calculates the present value using compound interest formula.
 * @param   rate      Interest rate (as percentage).
 * @param   nperiods  Number of compounding periods.
 * @param   FV        Future value.
 * @return  double    The calculated present value.
 */
double PV(double rate, unsigned int nperiods, double FV);

/**
 * @brief   Main function - Entry point of the program.
 *
 * Prompts the user to enter the interest rate, future value, and
 * number of periods, then calculates and displays the present value.
 */
int main() {
  double rate, FV, principleValue; /* rate: interest rate; FV: future value;
                                      principleValue: result */
  unsigned int nperiods;           /* Number of compounding periods */

  clrscr(); /* Clears the console screen (Turbo C specific) */

  /* Prompt user to enter the interest rate */
  printf("Enter rate:");
  scanf("%lf", &rate);

  /* Prompt user to enter the future value */
  printf("Enter future value:");
  scanf("%lf", &FV);

  /* Prompt user to enter the number of periods */
  printf("Enter no of periods:");
  scanf("%d", &nperiods);

  /* Calculate the present value */
  principleValue = PV(rate, nperiods, FV);

  /* Display the calculated present value */
  printf("Present value is %lf", principleValue);

  getch(); /* Wait for a key press before closing (Turbo C specific) */

  return 0; /* Return 0 to indicate successful execution */
}

/**
 * @brief   Calculates the present value using compound interest formula.
 *
 * Uses the formula: PV = FV / (1 + rate/100)^nperiods
 *
 * @param   rate      Interest rate (as percentage).
 * @param   nperiods  Number of compounding periods.
 * @param   FV        Future value.
 * @return  double    The calculated present value.
 */
double PV(double rate, unsigned int nperiods, double FV) {
  /* Apply inverse compound interest formula */
  double pv = FV / (pow((1 + rate / 100), nperiods));
  return pv;
}
