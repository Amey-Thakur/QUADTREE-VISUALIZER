/**
 * @file    dictionary.C
 * @brief   Implements a simple dictionary with add, search, remove, and print
 * operations.
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
 * Developed as part of the Phi Education Training (Milestone 10) and
 * BE Major-Project @ Terna Engineering College, University of Mumbai.
 *
 * This program implements a simple dictionary data structure with
 * menu-driven operations to add, search, remove, and print word-meaning pairs.
 *
 * @return  int  Returns 0 on successful execution.
 */

#include <conio.h> /* Console I/O library for clrscr() and getch() (DOS/Turbo C specific) */
#include <stdio.h>  /* Standard I/O library for printf and scanf functions */
#include <stdlib.h> /* Standard library for exit() */
#include <string.h> /* String library for strcmp, strcpy */

#define MAX_STRINGS 100   /* Maximum number of dictionary entries */
#define STRING_LENGTH 100 /* Maximum length of each string */

/* Function prototypes */
void add();     /* Adds a word and its meaning */
void remove1(); /* Removes a word from dictionary */
void search();  /* Searches for a word */
void print();   /* Prints all dictionary entries */

/* Global arrays for words and meanings */
char a[MAX_STRINGS][STRING_LENGTH] = {"hydromancy", "trochiline", "yusho",
                                      "screed", "heterography"};
char line[MAX_STRINGS][STRING_LENGTH] = {
    "divination using water", "of like or pertaining to hummingbirds",
    "skin-staining disease caused by contaminated rice oil",
    "informal piece of writing", "incorrect or unorthodox spelling"};

/**
 * @brief   Main function - Entry point of the program.
 *
 * Displays menu and handles user's choice for dictionary operations.
 */
int main() {
  int choose;

  clrscr(); /* Clears the console screen (Turbo C specific) */

  /* Display menu */
  printf("\nEnter the Action You Want to Perform in Dictionary \n1. Add Word "
         "\n2. Search Word \n3. Remove Word  \n4. Print All Dictionary Items "
         "\n5.Exit \n The Enter number is :\t");
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
    print();
    break;
  case 5:
    exit(0);
  }

  getch(); /* Wait for a key press before closing (Turbo C specific) */

  return 0; /* Return 0 to indicate successful execution */
}

/**
 * @brief   Adds a new word and its meaning to the dictionary.
 */
void add() {
  char word[100];
  char meaning[100];
  int z;

  printf("Enter the word: ");
  scanf("\n");
  gets(word);
  printf("Enter its meaning: ");
  scanf("\n");
  gets(meaning);

  /* Check if word exists or find empty slot */
  for (z = 0; z < MAX_STRINGS; z++) {
    if (strcmp(a[z], word) == 0) {
      printf("\nWord is present in Dictionary. Do search it.\n");
      main();
    }
    if (strcmp(a[z], "") == 0) {
      strcpy(a[z], word);
      strcpy(line[z], meaning);
      printf("\nWord is added to Dictionary.\n");
      main();
    }
  }

  main();
}

/**
 * @brief   Searches for a word in the dictionary.
 */
void search() {
  int j;
  char searchWord[50];
  int x = 0;

  printf("Enter word you want to search in Dictionary: \t");
  scanf("%s", searchWord);

  for (j = 0; j < MAX_STRINGS; j++) {
    if (strcmp(a[j], searchWord) == 0) {
      printf("\nWord : %s", a[j]);
      printf("\nMeaning : %s\n", line[j]);
      x = x + 1;
      printf("\n--------------***-------------***----------------***-----------"
             "----\n");
      main();
    }
  }

  if (x == 0) {
    printf("\nWord searched not found.\n\n ");
  }
}

/**
 * @brief   Removes a word from the dictionary.
 */
void remove1() {
  int j;
  char ww[50];
  int x = 0;

  printf("Enter word to remove: ");
  scanf("%s", ww);

  for (j = 0; j < MAX_STRINGS; j++) {
    if (strcmp(a[j], ww) == 0) {
      printf("\n %s is removed from the dictionary.\n ", a[j]);
      strcpy(a[j], "");
      strcpy(line[j], "");
      x = x + 1;
      printf("\n--------------***-------------***----------------***-----------"
             "----\n");
      main();
    }
  }

  if (x == 0) {
    printf("\nWord to remove not found.\n ");
  }
}

/**
 * @brief   Prints all words and meanings in the dictionary.
 */
void print() {
  int z = 0;

  printf("\n*****************The list of Dictionary is as "
         "below*****************\n");
  for (z = 0; z < MAX_STRINGS; z++) {
    if (strcmp(a[z], "") != 0) {
      printf("%s : %s\n", a[z], line[z]);
    }
  }
  printf("\n--------------***-------------***----------------***---------------"
         "\n");
  main();
}
