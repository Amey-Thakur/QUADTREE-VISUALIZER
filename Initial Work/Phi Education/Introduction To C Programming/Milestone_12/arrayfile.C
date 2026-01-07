/**
 * @file    arrayfile.C
 * @brief   Implements array operations with file persistence (add, search,
 * remove, sort, print).
 *
 * @author  Amey Thakur
 *          GitHub: https://github.com/Amey-Thakur
 * @author  Mega Satish
 *          GitHub: https://github.com/msatmod
 * @author  Hasan Rizvi
 *          GitHub: https://github.com/rizvihasan
 *
 * @project QUADTREE-VISUALIZER
 * @group   Phi-CS-73
 * @batch   2022
 * @repo    https://github.com/Amey-Thakur/QUADTREE-VISUALIZER
 * @date    2021
 * @license MIT
 *
 * Developed as part of the Phi Education Training (Milestone 12) and
 * BE Major-Project @ Terna Engineering College, University of Mumbai.
 *
 * This program provides a menu-driven interface to manage an array of strings,
 * including sorting, searching, and saving/loading the data from a file.
 *
 * @return  int  Returns 0 on successful execution.
 */

#include <conio.h> /* Console I/O library for clrscr() and getch() (DOS/Turbo C specific) */
#include <stdio.h>  /* Standard I/O library for file operations and printing */
#include <stdlib.h> /* Standard library for exit() and others */
#include <string.h> /* String library for strcmp, strcpy, strlen */

#define MAX_STRINGS 10   /* Maximum number of strings in the array */
#define STRING_LENGTH 50 /* Maximum length of each string */

/* Function prototypes */
void sort();         /* Sorts the array alphabetically */
void add();          /* Adds a string to the array */
void remove1();      /* Removes a string from the array */
void search();       /* Searches for a string in the array */
void print();        /* Prints the current array */
void addinfile();    /* Saves the array to "View.txt" */
void loadfromfile(); /* Loads the array from "View.txt" */

/* Global array for strings */
char a[MAX_STRINGS][STRING_LENGTH] = {"geeta", "meeta", "sita", "nita",
                                      "meena"};
char line[MAX_STRINGS][STRING_LENGTH];

/**
 * @brief   Main function - Entry point of the program.
 *
 * Displays menu and handles user's choice for array operations.
 */
int main() {
  int choose;

  clrscr(); /* Clears the console screen (Turbo C specific) */

  /* Display menu */
  printf("\nEnter the Action You Want to Perform in an Array\n"
         "1. Add \n2. Search \n3. Remove \n4. Sort \n5. Print \n"
         "6. Add Array in File \n7. Load the Array from the File\n8. Exit \n");
  scanf("%d", &choose);

  switch (choose) {
  case 1:
    add();
    break;
  case 2:
    search();
    break;
  case 3:
    remove1();
    break;
  case 4:
    sort();
    break;
  case 5:
    print();
    break;
  case 6:
    addinfile();
    break;
  case 7:
    loadfromfile();
    break;
  case 8:
    exit(0);
  }

  getch(); /* Wait for a key press (Turbo C specific) */

  return 0; /* Return 0 to indicate successful execution */
}

/**
 * @brief   Adds a new string to the array.
 */
void add() {
  char name[20];
  int z;
  printf("Enter the String: ");
  scanf("%s", name);

  /* Check for duplicates */
  for (z = 0; z < MAX_STRINGS; z++) {
    if (strcmp(a[z], name) == 0) {
      printf("\n Array Already exist\n");
      main();
    }
  }

  /* Find empty slot */
  for (z = 0; z < MAX_STRINGS; z++) {
    if (strcmp(a[z], "") == 0) {
      strcpy(a[z], name);
      printf("\nElement added successfully\n");
      main();
    }
  }

  printf("\n Array is Full\n");
  getch();
  main();
}

/**
 * @brief   Searches for a string in the array.
 */
void search() {
  int j, x = 0;
  char searchStr[50];
  printf("Enter string to search : ");
  scanf("%s", searchStr);

  for (j = 0; j < MAX_STRINGS; j++) {
    if (strcmp(a[j], searchStr) == 0) {
      printf("\nPosition of search string in array %s is %d \n", searchStr, j);
      x = x + 1;
      main();
    }
  }
  if (x == 0) {
    printf("String searched not found\n\n ");
  }
  getch();
  main();
}

/**
 * @brief   Removes a string from the array.
 */
void remove1() {
  int j, x = 0;
  char searchStr[50];
  printf("Enter string you want to delete : ");
  scanf("%s", searchStr);

  for (j = 0; j < MAX_STRINGS; j++) {
    if (strcmp(a[j], searchStr) == 0) {
      strcpy(a[j], "");
      x = x + 1;
      printf("String %s is deleted from the array of strings", searchStr);
      main();
    }
  }
  if (x == 0) {
    printf("String searched not found\n\n ");
    main();
  }
  getch();
  main();
}

/**
 * @brief   Sorts the array of strings alphabetically using bubble sort.
 */
void sort() {
  int i, j;
  int count = MAX_STRINGS;
  char temp[30];

  for (i = 0; i < count; i++) {
    for (j = i + 1; j < count; j++) {
      if (strcmp(a[i], a[j]) > 0 && strcmp(a[j], "") != 0) {
        strcpy(temp, a[i]);
        strcpy(a[i], a[j]);
        strcpy(a[j], temp);
      }
    }
  }
  printf("\nArray is Sorted \n");
  getch();
  main();
}

/**
 * @brief   Prints the current elements of the array.
 */
void print() {
  int z;
  printf("The list of Array is as Below :\n");
  for (z = 0; z < MAX_STRINGS; z++) {
    if (strcmp(a[z], "") != 0) {
      printf("%s\t", a[z]);
    }
  }
  getch();
  main();
}

/**
 * @brief   Saves the array elements to "View.txt".
 */
void addinfile() {
  int z;
  FILE *fpointer;
  fpointer = fopen("View.txt", "w");
  if (fpointer != NULL) {
    for (z = 0; z < MAX_STRINGS; z++) {
      if (strcmp(a[z], "") != 0) {
        fprintf(fpointer, "%s\n", a[z]);
      }
    }
    fclose(fpointer);
    printf("The list of Array has been saved in the file.\n");
  } else {
    printf("Error opening file for writing.\n");
  }
  getch();
  main();
}

/**
 * @brief   Loads array elements from "View.txt".
 */
void loadfromfile() {
  int i = 0, z;
  FILE *fpointer;
  fpointer = fopen("View.txt", "r");
  if (fpointer != NULL) {
    while (fgets(line[i], STRING_LENGTH, fpointer) && i < MAX_STRINGS) {
      line[i][strlen(line[i]) - 1] = '\0'; /* Remove newline character */
      i++;
    }
    fclose(fpointer);
    printf("The list of Array from file is as Below :\n");
    for (z = 0; z < i; z++) {
      printf("%s\n", line[z]);
    }
  } else {
    printf("Error opening file for reading.\n");
  }
  getch();
  main();
}
