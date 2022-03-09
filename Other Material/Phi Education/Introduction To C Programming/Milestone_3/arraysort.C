//Create a program to input a set of integers and sort them in ascending or descending order depending on users choice

#include<stdio.h>
#include<conio.h>
void main()
{
 int a[100],n,i,j,no,tmp;
 clrscr();
 printf("Array size:");
 scanf("%d", &n);
 printf("Elements:");
 for(i=0;i<n;i++)
 {
  scanf("%d", &a[i]);
 }
 printf("Enter\n 1 for Ascending order\n 2 for Descending order\n");
 scanf("%d", &no);
 switch(no)
 {
  case 1:for(i=0;i<n;i++)
	 {
	  for(j=0;j<n;j++)
	  {
	   if(a[j]>a[i])
	   {
	    tmp=a[i];
	    a[i]=a[j];
	    a[j]=tmp;
	   }
	  }
	 }
	 printf("\n Ascending order:");
	 for(i=0;i<n;i++)
	 {
	  printf("%d\t", a[i]);
	 }
	 break;
  case 2:for(i=0;i<n;i++)
	 {
	  for(j=0;j<n;j++)
	  {
	   if(a[j]<a[i])
	   {
	    tmp=a[i];
	    a[i]=a[j];
	    a[j]=tmp;
	   }
	  }
	 }
	 printf("\n Descending order:");
	 for(i=0;i<n;i++)
	 {
	  printf("%d\t", a[i]);
	 }
	 break;
  default:printf("Invalid Input");
 }
 getch();
}

