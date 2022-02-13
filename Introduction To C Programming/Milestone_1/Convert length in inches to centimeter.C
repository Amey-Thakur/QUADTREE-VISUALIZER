#include<stdio.h>
#include<conio.h>
void main()
{
 float inch, cm;
 clrscr();
 printf("Enter length in inch: ");
 scanf("%f", &inch);
 cm=inch*2.54;
 printf("Equivalent length in centimeter = %.2f", cm);
 getch();
}