/*Create a program for double PV(double rate, unsigned int nperiods, double FV)-Calculates and returns the present value of
  an investment based on the compound interest formula FV=PV*(1+rate)^nperiods*/
#include<stdio.h>
#include<conio.h>
#include<math.h>
double PV(double, unsigned int, double);
void main()
{
 double rate, FV, principleValue;
 unsigned int nperiods;
 clrscr();
 printf("Enter rate:");
 scanf("%f", &rate);
 printf("Enter future value:");
 scanf("%f", &FV);
 printf("Enter no of periods:");
 scanf("%d", &nperiods);
 principleValue=PV(rate, nperiods, FV);
 printf("Future value is %f", principleValue);
 getch();
}
double PV(double rate, unsigned int nperiods, double FV)
{
 double pv=FV/(pow((1+rate/100), nperiods));
 return pv;
}
