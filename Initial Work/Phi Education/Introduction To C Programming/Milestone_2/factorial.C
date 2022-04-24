//Create a program for unsigned int fact(unsigned int n)-Calculates and returns the factorial of n

#include<stdio.h>
#include<conio.h>
unsigned int factorial(unsigned int n)
{
 if(n==0)
   return 1;
 return n*factorial(n-1);
}
void main()
{
 int num;
 clrscr();
 printf("Enter the number:");
 scanf("%d", &num);
 printf("Factorial of %d is %d", num, factorial(num));
 getch();
}