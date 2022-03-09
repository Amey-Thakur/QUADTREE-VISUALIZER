#include<stdio.h>
#include<conio.h>
int choice,i,j,arr[10],n;
void menu();
void add();
void search();
void Remove();
void sort();
void print();
void main()
{
 clrscr();
 printf("\nEnter size of array:");
 scanf("%d", &n);
 printf("\nEnter elements of array:");
 for(i=0;i<n;i++)
 {
  scanf("%d", &arr[i]);
 }
 menu();
 getch();
}
void menu()
{
 printf("\n Array Implementation\n");
 printf("---------------------------\n");
 printf("\n What do you want to do...?");
 printf("\n\t 1.Add");
 printf("\n\t 2.Search");
 printf("\n\t 3.Remove");
 printf("\n\t 4.Sort");
 printf("\n\t 5.Print");
 printf("\n\t 6.Exit");
 printf("\n Your Choice:");
 scanf("%d", &choice);
 switch(choice)
 {
  case 1:add();
	 break;
  case 2:search();
	 break;
  case 3:Remove();
	 break;
  case 4:sort();
	 break;
  case 5:print();
	 break;
  case 6:break;
  default:printf("Invalid Option. Please try again");
 }
}
void add()
{
 int no,flag=0;
 printf("Enter an element to add into the array : ");
 scanf("%d",&no);
 for(i=0;i<n;i++)
 {
  if(arr[i]==no)
  {
   printf("Value is already present");
   flag=1;
   break;
  }
 }
 if(flag==0 && n!=10)
 {
  arr[n++]=no;
  printf("Element added successfully");
 }
 else
 {
  if(flag==0)
  {
   printf("Array is FULL ");
  }
 }
 getch();
 menu();
}

void search()
{
 int toSearch,found;
 printf("\n Enter elemnet to search:");
 scanf("%d", &toSearch);
 found=0;
 for(i=0;i<n;i++)
 {
  if(arr[i]==toSearch)
  {
   found=1;
   break;
  }
 }
 if(found==1)
 {
  printf("\n%d is found at position %d", toSearch, i+1);
 }
 else
 {
  printf("\n%d is not found in the array", toSearch);
 }
 getch();
 menu();
}

void Remove()
{
 int position,delitem,flag=0;
 printf("Enter element to be deleted\n");
 scanf("%d",&delitem);
 for(i=0;i<n;i++)
 {
  if(arr[i]==delitem)
  {
   position=i;
   flag=1;
  }
 }
 if(flag==0)
 {
  printf("Number not found in array\n");
 }
 if(flag==1 && n!=0)
 {
  for(i=0;i<n;i++)
  {
   if(i>=position)
   {
    arr[i]=arr[i+1];
   }
  }
  n--;
  printf("Element Removed");
 }
 else
 {
	printf("Array is Empty.. Cannot delete item");
 }
 getch();
 menu();
}

void sort()
{
 int no,tmp;
 printf("Enter \n 1 for Ascending Order \n 2 for Descending order\n");
 scanf("%d", &no);
 switch(no)
 {
  case 1:for(i=0;i<n;i++)
	 {
	  for(j=0;j<n;j++)
	  {
	   if(arr[j]>arr[i])
	   {
	    tmp=arr[i];
	    arr[i]=arr[j];
	    arr[j]=tmp;
	   }
	  }
	 }
	 printf("\n Ascending order:");
	 for(i=0;i<n;i++)
	 {
	  printf("%d\t", arr[i]);
	 }
	 break;
  case 2:for(i=0;i<n;i++)
	 {
	  for(j=0;j<n;j++)
	  {
	   if(arr[j]<arr[i])
	   {
	    tmp=arr[i];
	    arr[i]=arr[j];
	    arr[j]=tmp;
	   }
	  }
	 }
	 printf("\n Descending order:");
	 for(i=0;i<n;i++)
	 {
	  printf("%d\t", arr[i]);
	 }
	 break;
  default:printf("Invalid input");
 }
 getch();
 menu();
}

void print()
{
 printf("Array contains : \n");
 for(i=0;i<n;i++)
 {
  printf("%d ", arr[i]);
 }
 getch();
 menu();
}
