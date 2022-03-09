#include<stdio.h>
#include<conio.h>
void main()
{
 float area,r;
 clrscr();
 printf("Enter radius of circle \n");
 scanf("%f",&r);
 area=3.14*r*r;
 printf("Area of circle = %f",area);
 getch();
}