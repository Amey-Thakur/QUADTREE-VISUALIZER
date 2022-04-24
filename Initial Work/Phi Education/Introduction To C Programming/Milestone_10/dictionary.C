#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRINGS 100
#define STRING_LENGTH 100
void add();
void remove1();
void search();
void print();
char a[MAX_STRINGS][STRING_LENGTH]={"hydromancy","trochiline","yusho","screed","heterography"};
char line[MAX_STRINGS][STRING_LENGTH]={"divination using water","of like or pertaining to hummingbirds","skin-staining disease caused by contaminated rice oil","informal piece of writing","incorrect or unorthodox spelling"};

void main()
{
 int choose;
 clrscr();
 printf("\nEnter the Action U Want to Perform in an Dictonary \n1. Add Word \n2. Search Word \n3. Remove Word  \n4. Print All Dictonary Items \n5.Exit \n The Enter number is :\t");
 scanf("%d",&choose);
 switch(choose)
 {
  case 1:add();
	 break;
  case 2:search();
	 break;
  case 3:remove1();
	 break;
  case 4:print();
	 break;
  case 5:exit(0);
 }
 getch();
}
void add()
{
 char word[100];
 char meaning[100];
 int z;
 printf("enter the word: ");
 scanf("\n");
 gets(word);
 printf("enter its meaning: ");
 scanf("\n");
 gets(meaning);
 for(z=0;z<MAX_STRINGS;z++)
 {
  if(strcmp(a[z],word)==0)
  {
   printf("\nWord is Present in Dictonary Do Search It \n");
   main();
  }
  if(strcmp(a[z],"")==0)
  {
   strcpy(a[z],word);
   strcpy(line[z],meaning);
   printf("\nWord is Added in Dictonary.\n");
   main();
  }
 }
 for(z=0;z<MAX_STRINGS;z++)
 {
  if(strcmp(a[z],word)==0)
  {
   printf("\nWord is Present in Dictonary Do Search It. \n");
   main();
  }
  if(strcmp(a[z],"")==0)
  {
   strcpy(a[z],word);
   strcpy(line[z],meaning);
   printf("\nWord is Added in Dictonary.\n");
   main();
  }
 }
 main();
}
void search()
{
 int j;
 char search[50];
 int x=0;
 printf("enter word u want  to search  in Dictonary: \t");
 scanf("%s",&search);
 for(j=0;j<MAX_STRINGS;j++)
 {
  if(strcmp(&a[j],search)==0)
  {
   printf("\nWord : %s",a[j]);
   printf("\nMeaning : %s\n",line[j]);
   x=x+1;
   printf("\n--------------***-------------***----------------***---------------\n");
   main();
  }
 }
 if(x==0)
 {
  printf("\nWord Searched  not founded\n\n ");
 }
}
void remove1()
{
 int j;
 char ww[50];
 int x=0;
 printf("enter no. to word : ");
 scanf("%s",&ww);
 for(j=0;j<MAX_STRINGS;j++)
 {
  if(strcmp(a[j],ww)==0)
  {
   printf("\n %s  is Removed From the dictonary \n ",a[j]);
   strcpy(a[j], "");
   strcpy(line[j], "");
   x=x+1;
   printf("\n--------------***-------------***----------------***---------------\n");
   main();
  }
 }
 if(x==0)
 {
  printf("\nWord Searched  to remove is not founded\n ");
 }
}
void print()
{
 int z=0;
 printf("\n*****************The list of Dictonary is as Below *****************\n");
 for(z=0;z<MAX_STRINGS;z++)
 {
  if(strcmp(a[z],"")!=0)
  {
   printf("%s : %s\n",a[z],line[z]);
  }
 }
 printf("\n--------------***-------------***----------------***---------------\n");
 main();
}
