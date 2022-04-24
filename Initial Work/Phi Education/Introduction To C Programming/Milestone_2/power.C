//Create a program for double pow(double x, int n)-Calculates and returns x^n

#include<stdio.h>
#include<conio.h>
double pow(double, int);
void main()
{
 double x;
 int n;
 double ans;
 clrscr();
 printf("Enter the base value i.e. X:");
 scanf("%1f", &x);
 printf("Enter the exponent value i.e. N:");
 scanf("%d", &n);
 ans=pow(x,n);
 printf("Power of X^N is %1f", ans);
 getch();
}
double pow(double x, int n)
{
 double result=1.0;
 int i;
 for(i=1;i<=n;i++)
 {
  result*=x;
 }
 return result;
}