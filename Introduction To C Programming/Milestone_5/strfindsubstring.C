//write a program for int str_find_substring(char *str1, char *str2) - returns the position where str2 is in str1 and if not present returns -1. E.g. if str1 is "Hello World" and str2 is "World" then the function should return 6 and if str2 is "eat" then it should return -1

#include<stdio.h>
#include<conio.h>
#include<string.h>
int str_length(char* str);
int str_find_substring(char* str, char* sub);
void main()
{
 char sub[30],str[30];
 int f;
 clrscr();
 printf("Enter the string:");
 scanf("%s", &str);
 printf("\nEnter the substring want to search:");
 scanf("%s", &sub);
 f=str_find_substring(str,sub);
 if(f==-1)
 {
  printf("\n %s is not present in the string\n", sub);
 }
 else
 {
  printf("\n the substring is presnt at position %d\n", f+1);
 }
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
int str_find_substring(char* str, char* sub)
{
 int i,j,len;
 len=str_length(sub);
 for(i=0,j=0;str[i]!='\0'&&sub[j]!='\0';i++)
 {
  if(str[i]==sub[j])
  {
   j++;
  }
  else
  {
   j=0;
  }
 }
 if(j==len)
 {
  int x=i-j;
  return x;
 }
 else
 {
  return -1;
 }
}