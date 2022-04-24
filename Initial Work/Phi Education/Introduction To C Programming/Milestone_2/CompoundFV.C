/*Create a program for double FV(double rate, unsigned int nperiods, double PV)-Calculates and returns the future value
  of an investment based on the compound interest formula FV=PV*(1+rate)^nperiods*/
#include<stdio.h>
#include<conio.h>
#include<math.h>
double FV(double,unsigned int,double);
void main()
{
 double rate, PV, futureValue;
 unsigned int nperiods;
 clrscr();
 printf("Enter rate for future value:");
 scanf("%1f", &rate);
 printf("Enter principle value:");
 scanf("%1f", &PV);
 printf("Enter no of periods:");
 scanf("%d", &nperiods);
 futureValue=FV(rate, nperiods, PV);
 printf("Future Value is %1f", futureValue);
 getch();
}
double FV(double rate, unsigned int nperiods, double PV)
{
 int fv=PV*(pow((1+rate/100), nperiods));
 return fv;
}