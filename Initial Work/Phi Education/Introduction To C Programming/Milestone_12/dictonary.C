/**
 * @file    dictonary.C
 * @brief   Implements a dictionary with file persistence (add, search, remove,
 * print, load, save).
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
 * This program implements a dictionary data structure with file persistence,
 * allowing users to add, search, remove, and save/load entries from
 * "Dictonary.txt".
 *
 * @return  int  Returns 0 on successful execution.
 */

#include <conio.h> /* Console I/O library for clrscr() and getch() (DOS/Turbo C specific) */
#include <stdio.h>  /* Standard I/O library for file operations and printing */
#include <stdlib.h> /* Standard library for exit() */
#include <string.h> /* String library for strcmp, strcpy, strtok, strcat */

#define MAX_STRINGS 100   /* Maximum number of dictionary entries */
#define STRING_LENGTH 100 /* Maximum length of each string */

/* Function prototypes */
void add();                 /* Adds a word and its meaning */
void remove1();             /* Removes a word from dictionary */
void search();              /* Searches for a word */
void print();               /* Prints all dictionary entries */
void loadindictonary();     /* Loads dictionary from "Dictonary.txt" */
void savedictonaryinfile(); /* Saves dictionary to "Dictonary.txt" */

/* Global arrays for words and meanings */
char a[MAX_STRINGS][STRING_LENGTH] = {'\0'};
char line[MAX_STRINGS][STRING_LENGTH] = {'\0'};

/**
 * @brief   Main function - Entry point of the program.
 *
 * Displays menu and handles user's choice for dictionary operations.
 */
int main() {
  int choose;

  clrscr(); /* Clears the console screen (Turbo C specific) */

  /* Display menu */
  printf(
      "\nEnter the Action You Want to Perform in a Dictionary \n"
      "1. Add Word \n2. Search Word \n3. Remove Word  \n"
      "4. Print All Dictionary Items \n5. Loading dictionary from file\n"
      "6. Save dictionary in file format.\n7. Exit \n The Enter number is :\t");
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
    loadindictonary();
    break;
  case 6:
    savedictonaryinfile();
    break;
  case 7:
    exit(0);
  }

  getch(); /* Wait for a key press (Turbo C specific) */

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
      printf("\n----------------***----------------***----------------***------"
             "----"
             "------\n");
      main();
    }
    if (strcmp(a[z], "") == 0) {
      strcpy(a[z], word);
      strcpy(line[z], meaning);
      printf("\nWord is added to Dictionary.\n");
      printf("\n----------------***----------------***----------------***------"
             "----"
             "------\n");
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
    printf(
        "\n----------------***----------------***----------------***----------"
        "------\n");
  }
}

/**
 * @brief   Removes a word from the dictionary.
 */
void remove1() {
  int j;
  char wordToRemove[50];
  int x = 0;

  printf("Enter word to remove: ");
  scanf("%s", wordToRemove);

  for (j = 0; j < MAX_STRINGS; j++) {
    if (strcmp(a[j], wordToRemove) == 0) {
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
    printf(
        "\n----------------***----------------***----------------***----------"
        "------\n");
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

/**
 * @brief   Loads context from "Dictonary.txt" using string tokenization.
 */
void loadindictonary() {
  FILE *fpointer;
  int z = 0;
  char s[1024]; /* Increased size for safety */

  fpointer = fopen("Dictonary.txt", "r");
  if (fpointer != NULL) {
    while (fgets(s, sizeof(s), fpointer) != NULL && z < MAX_STRINGS) {
      char *word;
      word = strtok(s, ":");
      if (word != NULL) {
        strcpy(a[z], word);
        word = strtok(NULL, ":");
        if (word != NULL) {
          /* Remove leading space and trailing newline */
          if (word[0] == ' ')
            word++;
          if (word[strlen(word) - 1] == '\n')
            word[strlen(word) - 1] = '\0';
          strcpy(line[z], word);
        }
        z++;
      }
    }
    fclose(fpointer);
    printf("\nDictionary loaded successfully.\n");
  } else {
    printf("\nError opening Dictonary.txt for reading.\n");
  }
  print();
}

/**
 * @brief   Saves the dictionary entries to "Dictonary.txt".
 */
void savedictonaryinfile() {
  FILE *fpointer;
  int z = 0;

  fpointer = fopen("Dictonary.txt", "w");
  if (fpointer != NULL) {
    for (z = 0; z < MAX_STRINGS; z++) {
      if (strcmp(a[z], "") != 0) {
        fprintf(fpointer, "%s : %s\n", a[z], line[z]);
      }
    }
    fclose(fpointer);
    printf("--------***---- Dictionary has been saved to the "
           "file.--------***--------"
           "\n");
  } else {
    printf("\nError opening Dictonary.txt for writing.\n");
  }
  main();
}
