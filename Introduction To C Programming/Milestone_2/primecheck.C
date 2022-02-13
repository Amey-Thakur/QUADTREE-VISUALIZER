//Create a program for int is_prime(unsigned int x)-Returns 1 if x is a prime number and returns 0 if it is not

#include<stdio.h>
#include<conio.h>
int is_prime(unsigned int);
void main()
{
 unsigned int x;
 int ans;
 clrscr();
 printf("Enter the no:");
 scanf("%d", &x);
 if(x==0||x==1)
 {
  printf("Pls try with other nos:");
  return;
 }
 ans = is_prime(x);
 printf("%d", ans);
 getch();
}
int is_prime(unsigned int x)
{
 int i;
 for(i=2;i<=x/2;i++)
 {
  if(x%i==0)
  {
   return 0;
  }
  else
  {
   return 1;
  }
 }
}