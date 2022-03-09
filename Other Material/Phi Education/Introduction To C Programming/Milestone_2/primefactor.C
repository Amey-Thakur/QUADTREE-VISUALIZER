//Create a program for function for finding and printing all prime factors of a number

#include<stdio.h>
#include<conio.h>
void Find_Prime(int Number)
{
 int i, Count=0;
 for(i=2;i<=Number/2;i++)
 {
  if(Number%i==0)
  {
   Count++;
  }
 }
 if(Count==0&&Number!=1)
 {
  printf("\n %d is a prime number", Number);
 }
}
void Find_Factors(int Number)
{
 int i;
 for(i=1;i<=Number;i++)
 {
  if(Number%i==0)
  {
   Find_Prime(i);
  }
 }
}
void main()
{
 int i, j, Number, count;
 clrscr();
 printf("\n Please enter any number to find it's prime factors:");
 scanf("%d", &Number);
 printf("\n Prime factors of a given number are:\n");
 Find_Factors(Number);
 getch();
}
