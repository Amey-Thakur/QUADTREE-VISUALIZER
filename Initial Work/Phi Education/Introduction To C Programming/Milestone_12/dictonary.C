#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRINGS 100
#define STRING_LENGTH 100
void add();
void remove1();
void search();
void print();
void loadindictonary();
void savedictonaryinfile();
char a[MAX_STRINGS][STRING_LENGTH] = {'\0'};
char line[MAX_STRINGS][STRING_LENGTH]={'\0'};
void main()
{
 int choose;
 printf("\nEnter the Action U Want to Perform in an Dictonary \n1. Add Word \n2. Search Word \n3. Remove Word  \n4. Print All Dictonary Items \n5.Loading dictonary from file\n6.save dictonary in file format.\n7. Exit \n The Enter number is :\t");
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
  case 5:loadindictonary();
	 break;
  case 6:savedictonaryinfile();
	 break;
  case 7:exit(0);
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
 printf("enter its  meaning. : ");
 scanf("\n");
 gets(meaning);
 for(z=0;z<MAX_STRINGS;z++)
 {
  if(strcmp(a[z],word)==0)
  {
   printf("\nWord is Present in Dictonary Do Search It. \n");
   printf("\n----------------***----------------***----------------***----------------\n");
   main();
  }
  if(strcmp(a[z],"")==0)
  {
   strcpy(a[z],word);
   strcpy(line[z],meaning);
   printf("\nWord is Added in Dictonary.\n");
   printf("\n----------------***----------------***----------------***----------------\n");
   main();
  }
 }
 for(z=0;z<MAX_STRINGS;z++)
 {
  if(strcmp(a[z],word)==0)
  {
   printf("\nWord is Present in Dictonary Do Search It. \n");
   printf("\n----------------***----------------***----------------***----------------\n");
   main();
  }
  if(strcmp(a[z],"")==0)
  {
   strcpy(a[z],word);
   strcpy(line[z],meaning);
   printf("\nWord is Added in Dictonary.\n");
   printf("\n----------------***----------------***----------------***----------------\n");
   main();
  }
 }
 main();
}
void search()
{
 int j,x=0;
 char search[50];
 printf("enter word u want to search in Dictonary: \t");
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
  printf("\nWord Searched not founded\n\n ");
  printf("\n----------------***----------------***----------------***----------------\n");
 }
}
void remove1()
{
 int j,x=0;
 char ww[50];
 printf("enter no to word : ");
 scanf("%s",&ww);
 for(j=0;j<MAX_STRINGS;j++)
 {
  if(strcmp(a[j],ww)==0)
  {
   printf("\n %s is Removed From the dictonary \n ",a[j]);
   strcpy(a[j], "");
   strcpy(line[j], "");
   x=x+1;
   printf("\n--------------***-------------***----------------***---------------\n");
   main();
  }
 }
 if(x==0)
 {
  printf("\nWord Searched to remove is not founded\n ");
  printf("\n----------------***----------------***----------------***----------------\n");
 }
}
void print()
{
 int z=0;
 printf("\n*****************The list of Dictonary is as Below *****************\n");
 printf("\n");
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
void loadindictonary()
{
 FILE *fpointer;
 int z = 0;
 char s[100];
 fpointer = fopen("Dictonary.txt","r");
 while(!feof(fpointer))
 {
  char *word;
  word =strtok(fgets(s,5000,fpointer),":");
  while (word != NULL )
  {
   int x = 0;
   printf ("\n");
   if(x == 0)
   {
    strcpy(a[z],word);
    word = strtok (NULL, ":");
    x = x+1;
    printf ("\n");
   }
   if(x == 1)
   {
    strcpy(line[z],word);
    word = strtok (NULL, ":");
    x = x+1;
   }
   ++z;
  }
 }
 fclose(fpointer);
 print();
}
void savedictonaryinfile()
{
 FILE *fpointer;
 char *s,*w;
 int z=0;
 fpointer = fopen("Dictonary.txt","w");
 for(z=0;z<MAX_STRINGS;z++)
 {
  if(strcmp(a[z],"")==0)
  {
   break;
  }
  else
  {
   s=a[z];
   w=line[z];
   strcat(s," : ");
   strcat(s,w);
   fprintf(fpointer,s);
  }
 }
 fclose(fpointer);
 printf("--------***---- Dictonary Now have been saved in the file.--------***--------\n");
 main();
}
