#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_STRINGS 10
#define STRING_LENGTH 50
void sort();
void add();
void remove1();
void search();
void print();
void addinfile();
void loadfromfile();
char a[MAX_STRINGS][STRING_LENGTH]={"geeta","meeta","sita","nita","meena"};
line[MAX_STRINGS][STRING_LENGTH];
void main()
{
 int choose;
 clrscr();
 printf("\nEnter the Action U Want to Perform in an Array\n1. Add \n2. Search \n3. Remove \n4. Sort \n5. Print \n6. Add Array in File \n7.Load the Array from the File\n8.Exit \n");
 scanf("%d",&choose);
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
  case 6:addinfile();
	 break;
  case 7:loadfromfile();
	 break;
  case 8:exit(0);
 }
 getch();
}
void add()
{
 char name[20];
 int z;
 printf("enter the String: ");
 scanf("%s",&name);
 for(z=0;z<MAX_STRINGS;z++)
 {
  if(strcmp(a[z],name)==0)
  {
   printf("\n Array Already exist\n");
   main();
  }
 }
 for(z=0;z<MAX_STRINGS;z++)
 {
  if(strcmp(a[z], "")==0)
  {
   strcpy(a[z],name);
   printf("\nElement added successfully\n");
   main();
  }
 }
 printf("\n Array is Full\n");
 getch();
 main();
}
void search()
{
 int j,x=0;
 char search[50];
 printf("enter no. to search : ");
 scanf("%s",&search);
 for(j=0;j<MAX_STRINGS;j++)
 {
  if(strcmp(a[j],search)==0)
  {
   printf("\nPostion of search string is an array  %s is %d \n",search,j);
   x=x+1;
   main();
  }
 }
 if(x==0)
 {
  printf("String Searched not founded\n\n ");
 }
 getch();
}
void remove1()
{
 int j,x=0;
 char search[50];
 printf("enter string u want to delete : ");
 scanf("%s",&search);
 for(j=0;j<MAX_STRINGS;j++)
 {
  if(strcmp(a[j],search)==0)
  {
   strcpy(a[j],"");
   x=x+1;
   printf("String %s is deleted from an array of string ",search);
   main();
  }
 }
 if(x==0)
 {
  printf("String Searched  not founded\n\n ");
  main();
 }
 getch();
}
void sort()
{
 int i,j,count =sizeof(a)/sizeof(a[0]);
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
 printf("\nArray is Sorted \n");
 getch();
 main();
}
void print()
{
 int z;
 printf("The list of Array is as Below :\n");
 for(z=0;z<=MAX_STRINGS;z++)
 {
  printf("%s\t",a[z]);
 }
 getch();
 main();
}
void addinfile()
{
 int z;
 FILE *fpointer;
 fpointer = fopen("View.txt","w");
 for(z=0;z<=MAX_STRINGS;z++)
 {
  char *s;
  s=a[z];
  fprintf(fpointer,s);
  fprintf(fpointer,"\n");
 }
 fclose(fpointer);
 printf("The list of Array is Now been added in the file.\n");
 getch();
 main();
}
void loadfromfile()
{
 int i=0,z;
 FILE *fpointer;
 fpointer = fopen("View.txt","r");
 while(fgets(line[i],MAX_STRINGS,fpointer))
 {
  line[i][strlen(line[i]) - 1]='\0';
  i++;
 }
 printf("The list of Array is as Below :\n");
 for(z=0;z<=MAX_STRINGS;z++)
 {
  printf("%s",line[z]);
 }
 getch();
 main();
}


