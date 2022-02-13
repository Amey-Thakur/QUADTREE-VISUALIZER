//write a program for int str_copy(char *str1, char *str2) - copies string 2 into string 1, returns 0 on success or -1 on error
#include<stdio.h>
#include<conio.h>
#include<string.h>
int str_copy(char* str1, char* str2);
void main()
{
 char str1[30], str2[30];
 int x;
 clrscr();
 printf("\n Enter the string u want to copy:");
 scanf("%s", &str1);
 x=str_copy(str1,str2);
 if(x==0)
 {
  printf("\n String is successfully copied\n");
 }
 if(x==-1)
 {
  printf("\n String is not copied\n");
 }
 getch();
}
int str_copy(char* str1, char* str2)
{
 int i=0;
 while(str1[i]!='\0')
 {
  str2[i]=str1[i];
  i++;
 }
 if(str2[0]!='\0')
 {
  return 0;
 }
 else
 {
  return -1;
 }
}