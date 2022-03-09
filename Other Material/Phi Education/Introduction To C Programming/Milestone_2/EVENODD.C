//Create a program for function to check if a number is odd or even
#include<stdio.h>
#include<conio.h>
int isEven(int num)
{
 return !(num & 1);
}
void main()
{
 int num;
 clrscr();
 printf("Enter any number:");
 scanf("%d", &num);
 if(isEven(num))
 {
  printf("The number is even");
 }
 else
 {
  printf("The number is odd");
 }
 getch();
}