#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
 FILE *fpointer;
 char s[250];
 char s1[250];
 clrscr();
 fpointer=fopen("View.txt","r");
 while(!feof(fpointer))
 {
  fgets(s,250,fpointer);
  puts(s);
 }
 fclose(fpointer);
 fpointer=fopen("View1.txt","r");
 while(!feof(fpointer))
 {
  char *word;
  word=strtok(fgets(s1,250,fpointer),":");
  while(word!=NULL)
  {
   int x=0;
   printf("\n");
   if(x==0)
   {
    printf("Word : %s",word);
    word=strtok(NULL, ":");
    x=x+1;
    printf("\n");
   }
   if(x==1)
   {
    printf("Meaning : %s",word);
    word=strtok (NULL, ":");
    x=x+1;
   }
  }
 }
 fclose(fpointer);
 getch();
}

