#include<stdio.h>
#include<conio.h>
#include<string.h>
char* str_copy(const char *str1);
void mem_copy(void *dest, const void *src, unsigned int n);
char* str_tokenize(char *str, char* c);
void main()
{
 unsigned int x;
 char str[19], str1[50], ch[2], dest[140];
 clrscr();
 printf("Enter the string:");
 scanf("%s", &str);
 str_copy(str);
 printf("Enter the string:");
 scanf("%s", &str1);
 printf("Enter the spilt token:");
 scanf("%s", &ch);
 str_tokenize(str1,ch);
 printf("Enter the string:");
 scanf("%s",&ch);
 x=strlen(str);
 mem_copy(dest, str,x+1);
 getch();
}
char* str_copy(const char *str)
{
 char dst[14];
 strcpy(dst, str);
 printf("The string is copied %s\n", dst);
 return 0;
}
char* str_tokenize(char *str, char* c)
{
 char* s;
 printf("The splitted string is as below\n");
 s=strtok(str,c);
 while(s!='\0')
 {
  printf("%s\n",s);
  s=strtok(NULL,c);
 }
 return 0;
}
void mem_copy(void *dest, const void *src, unsigned int n)
{
 char *nsrc=(char *)src;
 char *ndest=(char *)dest;
 strcpy(ndest,nsrc);
 printf("\nCopied array is %s \n", ndest);
}
