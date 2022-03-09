#include <stdio.h>
#include<conio.h>
#include <math.h>
#include<stdlib.h>
int compare(const void* a,const void* b)
{
 int A = *((int*)a);
 int B = *((int*)b);
 return abs(A)-abs(B);
}
int compare_1(const void* a,const void* b)
{
 const char *ia = *( const char**)a;
 const  char *ib = *(const char**)b;
 return strcmp(ia,ib);
}
int compare_2(const void* a,const void* b)
{
 float A = *((float*)a);
 float B = *((float*)b);
 if(A < B)
 return -1;
 return 1;
}
void main()
{
 int i;
 int A[] ={45,6,78,76,4,4232,1,5,43};
 float B[] ={45.5,6.5,7.8,7.6,4.1,0.4232,15,43};
 char *string[] = { "geeta", "sita", "meena", "mita", "jeena", "jiya" };
 int strings_len;
 clrscr();
 printf("\nInteger Array Before sorting :\t");
 for(i=0; i<9; i++)
 printf("%d\t",A[i]);
 qsort(A,9,sizeof(int),compare);
 printf("\nInteger Array After sorting :\t");
 for(i=0; i<9; i++)
 printf("%d\t",A[i]);
 printf("\n\nFloat Array Before sorting :\t");
 for(i=0; i<8; i++)
 printf("%.2f\t",B[i]);
 qsort(B,8,sizeof(float),compare_2);
 printf("\nFloat Array After sorting :\t");
 for(i=0; i<8; i++)
 printf("%.2f\t",B[i]);
 printf("\n\nChar Array before sorting\n");
 strings_len = sizeof(string)/sizeof(char *);
 for(i=0; i<strings_len; i++)
 printf("%s\t", string[i]);
 printf("\nChar Array After sorting\n");
 qsort(string,strings_len,sizeof(char *),compare_1);
 for(i=0; i<strings_len; i++)
 printf("%s\t ", string[i]);
 getch();
}