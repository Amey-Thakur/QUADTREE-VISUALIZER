#include<stdio.h>
#include<conio.h>
void main()
{
 float celsius, fahrenheit;
 clrscr();
 printf("Enter temperature in fahrenheit");
 scanf("%f", &fahrenheit);
 celsius=(fahrenheit-32)*5/9;
 printf("%.2f Fahrenheit = %.2f Celsius", fahrenheit, celsius);
 getch();
}