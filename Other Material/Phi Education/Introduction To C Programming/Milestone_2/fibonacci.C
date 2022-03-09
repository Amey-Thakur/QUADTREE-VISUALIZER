//Create a program for void fibonacci(int n)-Prints the first n fibonacci numbers

#include<stdio.h>
#include<conio.h>
void fibonacci(int n)
{
 int a=0, b=1,c,i;
 printf("Fibonacci series till %d is", n);
 printf("\n%d %d", a,b);
 for(i=2;i<n;i++)
 {
  c=a+b;
  printf("%d",c);
  a=b;
  b=c;
 }
}
void main()
{
 int n=10;
 clrscr();
 fibonacci(n);
 getch();
}