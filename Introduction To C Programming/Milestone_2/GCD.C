//Create a program for int gcd(int a, int b)-Calculates and returns the Greatest Common Divisor of a and b

#include<stdio.h>
#include<conio.h>
int gcd(int,int);
void main()
{
 int a, b, ans;
 clrscr();
 printf("Enter the value for a:");
 scanf("%d", &a);
 printf("Enter the value for b:");
 scanf("%d", &b);
 ans=gcd(a,b);
 printf("GCD is : %d", ans);
 getch();
}
int gcd(int a, int b)
{
 int i, result;
 for(i=1;i<=a && i<=b;i++)
 {
  if(a%i==0 && b%i==0)
  {
   result=i;
  }
 }
 return result;
}
