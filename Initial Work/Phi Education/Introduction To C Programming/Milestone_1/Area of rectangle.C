#include<stdio.h>
#include<conio.h>
void main()
{
 int area, h, w;
 clrscr();
 printf("Enter height of rectangle \n");
 scanf("%d", &h);
 printf("Enter width of rectangle \n");
 scanf("%d", &w);
 area=h*w;
 printf("Area of rectangle = %d", area);
 getch();
}