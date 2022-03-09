//Create a program for nPr-Permutations

#include<stdio.h>
#include<conio.h>
int factrorial(int);
void main()
{
 int n, r;
 float nPr;
 clrscr();
 printf("Enter value of n in nPr\n");
 scanf("%d", &n);
 printf("Enter value of r in nPr\n");
 scanf("%d", &r);
 if(n>=r&&n>=0&&r>=0)
 {
  nPr=(float)factorial(n)/factorial(n-r);
  printf("Value of %dP%d=%f\n", n, r, nPr);
 }
 else
 {
  printf("Invalid Entry\n");
 }
 getch();
}
int factorial(int num)
{
 int i, fact=1;
 for(i=1;i<=num;i++)
 {
  fact=fact*i;
 }
 return(fact);
}