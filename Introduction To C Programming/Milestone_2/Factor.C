//Create a program for function for finding and printing all factors of a number

#include<stdio.h>
#include<conio.h>
int findFactors(int n);
void main()
{
 int number;
 clrscr();
 printf("Enter number:");
 scanf("%d", &number);
 findFactors(number);
 getch();
}
int findFactors(int n)
{
 int i;
 for(i=1;i<=n/2;i++)
 {
  if(n%i==0)
  printf("%d\t", i);
 }
}
