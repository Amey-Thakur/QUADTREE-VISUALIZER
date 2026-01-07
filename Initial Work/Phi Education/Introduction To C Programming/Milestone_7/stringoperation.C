/**
 * @file    stringoperation.C
 * @brief   Implements comprehensive string array operations with a menu-driven
 * interface.
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
 * Developed as part of the Phi Education Training (Milestone 7) and
 * BE Major-Project @ Terna Engineering College, University of Mumbai.
 *
 * This program provides a menu-driven interface to perform various
 * string array operations including: Add, Search, Remove, Sort, and Print.
 *
 * @return  int  Returns 0 on successful execution.
 */

#include <conio.h> /* Console I/O library for clrscr() and getch() (DOS/Turbo C specific) */
#include <stdio.h>  /* Standard I/O library for printf and scanf functions */
#include <stdlib.h> /* Standard library for exit() */
#include <string.h> /* String library for strcmp, strcpy */

#define MAX_STRINGS 10   /* Maximum number of strings in array */
#define STRING_LENGTH 50 /* Maximum length of each string */

/* Function prototypes */
void sort();    /* Sorts the string array alphabetically */
void add();     /* Adds a new string to the array */
void remove1(); /* Removes a string from the array */
void search();  /* Searches for a string in the array */
void print();   /* Prints all strings in the array */

/* Global string array with initial values */
char a[MAX_STRINGS][STRING_LENGTH] = {"geeta", "sita", "mita", "meena", "nita"};

/**
 * @brief   Main function - Entry point of the program.
 *
 * Displays menu and handles user's choice for string operations.
 */
int main() {
  int choose;

  clrscr(); /* Clears the console screen (Turbo C specific) */

  /* Display menu */
  printf("\n Enter the action you want to perform in an array \n 1.Add \n "
         "2.Search \n 3.Remove \n 4.Sort \n 5.Print \n 6.Exit \n");
  scanf("%d", &choose);

  /* Handle user choice */
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
    exit(0);
  }

  getch(); /* Wait for a key press before closing (Turbo C specific) */

  return 0; /* Return 0 to indicate successful execution */
}

/**
 * @brief   Adds a new string to the array.
 *
 * Checks for duplicates and available space before adding.
 */
void add() {
  int j, z;
  char name[20];

  printf("Enter the string:");
  scanf("%s", name);

  /* Check if string already exists */
  for (z = 0; z < MAX_STRINGS; z++) {
    if (strcmp(a[z], name) == 0) {
      printf("\n Already exists in array \n");
      getch();
      main();
    }
  }

  /* Find empty slot and add string */
  for (z = 0; z < MAX_STRINGS; z++) {
    if (strcmp(a[z], "") == 0) {
      strcpy(a[z], name);
      printf("\nElement added successfully\n");
      getch();
      main();
    }
  }

  printf("\n Array is full \n");
  getch();
  main();
}

/**
 * @brief   Searches for a string in the array.
 *
 * Uses strcmp to find matching string and displays its position.
 */
void search() {
  int j, x;
  char searchStr[50];

  printf("Enter string to search:");
  scanf("%s", searchStr);

  x = 0;
  for (j = 0; j < MAX_STRINGS; j++) {
    if (strcmp(a[j], searchStr) == 0) {
      printf("\n Position of search string %s is %d \n", searchStr, j);
      x = x + 1;
      getch();
      main();
    }
  }

  if (x == 0) {
    printf("String searched not found \n");
  }
  getch();
}

/**
 * @brief   Removes a string from the array.
 *
 * Finds the string and replaces it with empty string.
 */
void remove1() {
  int j, x;
  char searchStr[50];

  printf("Enter string you want to delete:");
  scanf("%s", searchStr);

  x = 0;
  for (j = 0; j < MAX_STRINGS; j++) {
    if (strcmp(a[j], searchStr) == 0) {
      strcpy(a[j], ""); /* Replace with empty string */
      x = x + 1;
      printf("String %s is deleted from the array", searchStr);
      getch();
      main();
    }
  }

  if (x == 0) {
    printf("String searched not found \n");
    getch();
    main();
  }
}

/**
 * @brief   Sorts the string array alphabetically.
 *
 * Uses bubble sort algorithm with strcmp for comparison.
 */
void sort() {
  int i, j, count = sizeof(a) / sizeof(a[0]);
  char temp[30];

  /* Bubble sort for strings */
  for (i = 0; i <= count; i++) {
    for (j = i + 1; j <= count; j++) {
      if (strcmp(a[i], a[j]) > 0) {
        /* Swap strings */
        strcpy(temp, a[i]);
        strcpy(a[i], a[j]);
        strcpy(a[j], temp);
      }
    }
  }

  printf("\n Array is sorted \n");
  getch();
  main();
}

/**
 * @brief   Prints all strings currently in the array.
 */
void print() {
  int z;

  printf("The list of array is as below:\n");
  for (z = 0; z < MAX_STRINGS; z++) {
    printf("%s\t", a[z]);
  }

  getch();
  main();
}