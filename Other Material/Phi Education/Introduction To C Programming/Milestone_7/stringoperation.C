#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_STRINGS 10
#define STRING_LENGTH 50
void sort();
void add();
void remove1();
void search();
void print();
char a[MAX_STRINGS][STRING_LENGTH]={"geeta","sita","mita","meena","nita"};
void main()
{
 int choose;
 clrscr();
 printf("\n Enter the action u want to perform in an array \n 1.Add \n 2.Search \n 3.Remove \n 4.Sort \n 5.Print \n 6.Exit \n");
 scanf("%d", &choose);
 switch(choose)
 {
  case 1:add();
	 break;
  case 2:search();
	 break;
  case 3:remove1();
	 break;
  case 4:sort();
	 break;
  case 5:print();
	 break;
  case 6:exit(0);
 }
 getch();
}
void add()
{
 int j,z;
 char name[20];
 printf("enter the string:");
 scanf("%s", &name);
 for(z=0;z<MAX_STRINGS;z++)
 {
  if(strcmp(a[z],name)==0)
  {
   printf("\n Already exits in array \n");
   getch();
   main();
  }
 }
 for(z=0;z<MAX_STRINGS;z++)
 {
  if(strcmp(a[z],"")==0)
  {
   strcpy(a[z],name);
   printf("\nElement added successfully\n");
   getch();
   main();
  }
 }
 printf("\n Array is full \n");
 getch();
 main();
}
void search()
{
 int j,x;
 char search[50];
 printf("Enter string to search:");
 scanf("%s", &search);
 x=0;
 for(j=0;j<MAX_STRINGS;j++)
 {
  if(strcmp(a[j],search)==0)
  {
   printf("\n Position of search string is an array %s is %d \n", search,j);
   x=x+1;
   getch();
   main();
  }
 }
 if(x==0)
 {
  printf("String searched not founded \n");
 }
 getch();
}
void remove1()
{
 int j,x;
 char search[50];
 printf("Enter string u want to delete:");
 scanf("%s", &search);
 x=0;
 for(j=0;j<MAX_STRINGS;j++)
 {
  if(strcmp(a[j],search)==0)
  {
   strcpy(a[j],"");
   x=x+1;
   printf("String %s is deleted from an array of string", search);
   getch();
   main();
  }
 }
 if(x==0)
 {
  printf("String searched not founded \n");
  getch();
  main();
 }
}
void sort()
{
 int i,j,count=sizeof(a)/sizeof(a[0]);
 char temp[30];
 for(i=0;i<=count;i++)
 for(j=i+1;j<=count;j++)
 {
  if(strcmp(a[i],a[j])>0)
  {
   strcpy(temp,a[i]);
   strcpy(a[i],a[j]);
   strcpy(a[j],temp);
  }
 }
 printf("\n Array is sorted \n");
 getch();
 main();
}
void print()
{
 int z;
 printf("The list of array is as below:\n");
 for(z=0;z<MAX_STRINGS;z++)
 {
  printf("%s\t", a[z]);
 }
 getch();
 main();
}