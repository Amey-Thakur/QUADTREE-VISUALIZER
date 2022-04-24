//write a program for int str_compare(char *str1, char *str2) - if str1 is less than str2 the function should return -1 if str1 is greater than str2 it should return 1 and if both are equal then return 0

#include<stdio.h>
#include<conio.h>
#include<string.h>
int str_compare(char* str1, char* str2);
void main()
{
 char str1[30], str2[30];
 int g;
 clrscr();
 printf("\n Comparing two strings \n Enter the first string:");
 scanf("%s", &str1);
 printf("\n Enter the second string:");
 scanf("%s", &str2);
 g=str_compare(str1, str2);
 if(g==-1)
 {
  printf("\n %s is less then %s \n", str1, str2);
 }
 else if(g==1)
 {
  printf("\n %s is less than %s \n", str2, str1);
 }
 else
 {
  printf("\n %s and %s is equal \n", str1, str2);
 }
 getch();
}
int str_compare(char* str1, char* str2)
{
 int i,ascii1=0,ascii2=0;
 for(i=0;str1[i]!='\0';i++)
 ascii1=ascii1+str1[i];
 for(i=0;str2[i]!='\0';i++)
 ascii2=ascii2+str2[i];
 if(ascii1<ascii2)
 {
  return -1;
 }
 else if(ascii1>ascii2)
 {
  return 1;
 }
 else
 {
  return 0;
 }
}