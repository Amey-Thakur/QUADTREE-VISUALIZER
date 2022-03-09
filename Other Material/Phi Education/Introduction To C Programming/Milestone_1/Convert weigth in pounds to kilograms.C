#include<stdio.h>
#include<conio.h>
void main()
{
 const float KG=0.453592;
 float pound;
 clrscr();
 printf("Enter weight in pounds\n");
 scanf("%f", &pound);
 printf("Weight in kilograms is %f\n", pound*KG);
 getch();
}