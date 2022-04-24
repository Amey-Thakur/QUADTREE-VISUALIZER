//write a program for int str_find_char(char *str, char *ch) - returns the position where ch is in str and if not present returns -1

#include<stdio.h>
#include<conio.h>
#include<string.h>
int str_find_char(char *str, char *ch);
void main()
{
 char str[30],ch;
 int f;
 clrscr();
 printf("Enter the string for which u want to perform search operation:\t");
 scanf("%s", &str);
 printf("Enter the character u want to search:\t");
 scanf("%c", &ch);
 f=str_find_char(str,ch);
 if(f==-1)
 {
  printf("\n %c is not present in the string \n",ch);
 }
 else
 {
  printf("\n %c is present at position %d in %s \n",ch,f,str);
 }
 getch();
}
int str_find_char(char* str, char* ch)
{
 int i;
 for(i=0;str[i]!='\0';i++)
 {
  if(ch==str[i])
  {
   return i;
  }
 }
 return -1;
}