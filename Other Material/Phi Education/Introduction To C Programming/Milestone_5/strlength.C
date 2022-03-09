//write a program for int str_length(char *str) - returns the length of the string or -1 on error

#include<stdio.h>
#include<conio.h>
#include<string.h>
int str_length(char* str);
void main()
{
 char str[30];
 int len;
 clrscr();
 printf("Enter the string u want to find length off:\t");
 scanf("%s", &str);
 len=str_length(str);
 printf("\n Length of string is =%d\n", len);
 getch();
}
int str_length(char* str)
{
 int len=0,i=0;
 while(str[i]!='\0')
 {
  len++;
  i++;
 }
 return len;
}