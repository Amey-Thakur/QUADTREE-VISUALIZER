/**
 * @file    CompoundFV.C
 * @brief   Calculates the future value of an investment using compound
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
 * This program calculates the future value of an investment using the
 * compound interest formula: FV = PV * (1 + rate/100)^nperiods
 * where PV is the present value, rate is the interest rate,
 * and nperiods is the number of compounding periods.
 *
 * @return  int  Returns 0 on successful execution.
 */

#include <conio.h> /* Console I/O library for clrscr() and getch() (DOS/Turbo C specific) */
#include <math.h>  /* Math library for pow() function */
#include <stdio.h> /* Standard I/O library for printf and scanf functions */

/**
 * @brief   Calculates the future value using compound interest formula.
 * @param   rate      Interest rate (as percentage).
 * @param   nperiods  Number of compounding periods.
 * @param   PV        Present value (principal amount).
 * @return  double    The calculated future value.
 */
double FV(double rate, unsigned int nperiods, double PV);

/**
 * @brief   Main function - Entry point of the program.
 *
 * Prompts the user to enter the interest rate, principal value, and
 * number of periods, then calculates and displays the future value.
 */
int main() {
  double rate, PV, futureValue; /* rate: interest rate; PV: present value;
                                   futureValue: result */
  unsigned int nperiods;        /* Number of compounding periods */

  clrscr(); /* Clears the console screen (Turbo C specific) */

  /* Prompt user to enter the interest rate */
  printf("Enter rate for future value:");
  scanf("%lf", &rate);

  /* Prompt user to enter the principal value */
  printf("Enter principle value:");
  scanf("%lf", &PV);

  /* Prompt user to enter the number of periods */
  printf("Enter no of periods:");
  scanf("%d", &nperiods);

  /* Calculate the future value */
  futureValue = FV(rate, nperiods, PV);

  /* Display the calculated future value */
  printf("Future Value is %lf", futureValue);

  getch(); /* Wait for a key press before closing (Turbo C specific) */

  return 0; /* Return 0 to indicate successful execution */
}

/**
 * @brief   Calculates the future value using compound interest formula.
 *
 * Uses the formula: FV = PV * (1 + rate/100)^nperiods
 *
 * @param   rate      Interest rate (as percentage).
 * @param   nperiods  Number of compounding periods.
 * @param   PV        Present value (principal amount).
 * @return  double    The calculated future value.
 */
double FV(double rate, unsigned int nperiods, double PV) {
  /* Apply compound interest formula */
  double fv = PV * (pow((1 + rate / 100), nperiods));
  return fv;
}