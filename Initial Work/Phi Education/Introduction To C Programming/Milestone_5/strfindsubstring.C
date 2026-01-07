/**
 * @file    strfindsubstring.C
 * @brief   Finds the position of a substring within a string.
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
 * Developed as part of the Phi Education Training (Milestone 5) and
 * BE Major-Project @ Terna Engineering College, University of Mumbai.
 *
 * This program searches for a substring within a main string and returns
 * its starting position if found, or -1 if not present.
 * Example: "Hello World" with substring "World" returns 6.
 *
 * @return  int  Returns 0 on successful execution.
 */

#include <conio.h> /* Console I/O library for clrscr() and getch() (DOS/Turbo C specific) */
#include <stdio.h>  /* Standard I/O library for printf and scanf functions */
#include <string.h> /* String library */

/**
 * @brief   Calculates the length of a string.
 * @param   str  The string to measure.
 * @return  int  The length of the string.
 */
int str_length(char *str);

/**
 * @brief   Finds a substring within a string.
 * @param   str  The main string to search in.
 * @param   sub  The substring to find.
 * @return  int  Starting position if found, -1 otherwise.
 */
int str_find_substring(char *str, char *sub);

/**
 * @brief   Main function - Entry point of the program.
 *
 * Prompts user for a string and substring, then searches.
 */
int main() {
  char sub[30], str[30]; /* str: main string; sub: substring to find */
  int f;                 /* Result: position or -1 */

  clrscr(); /* Clears the console screen (Turbo C specific) */

  /* Input main string */
  printf("Enter the string:");
  scanf("%s", str);

  /* Input substring to search */
  printf("\nEnter the substring to search:");
  scanf("%s", sub);

  /* Search for the substring */
  f = str_find_substring(str, sub);

  /* Display result */
  if (f == -1) {
    printf("\n %s is not present in the string\n", sub);
  } else {
    printf("\n The substring is present at position %d\n", f + 1);
  }

  getch(); /* Wait for a key press before closing (Turbo C specific) */

  return 0; /* Return 0 to indicate successful execution */
}

/**
 * @brief   Calculates the length of a string.
 *
 * Counts characters until null terminator is reached.
 *
 * @param   str  The string to measure.
 * @return  int  The length of the string.
 */
int str_length(char *str) {
  int len = 0, i = 0;

  while (str[i] != '\0') {
    len++;
    i++;
  }

  return len;
}

/**
 * @brief   Finds a substring within a string using sequential matching.
 *
 * Iterates through the main string and tracks consecutive matches
 * with the substring characters.
 *
 * @param   str  The main string to search in.
 * @param   sub  The substring to find.
 * @return  int  Starting position (0-indexed) if found, -1 otherwise.
 */
int str_find_substring(char *str, char *sub) {
  int i, j, len;

  len = str_length(sub); /* Get substring length */

  /* Search for matching sequence */
  for (i = 0, j = 0; str[i] != '\0' && sub[j] != '\0'; i++) {
    if (str[i] == sub[j]) {
      j++; /* Match found, move to next substring character */
    } else {
      j = 0; /* Mismatch, reset substring index */
    }
  }

  /* Check if entire substring was matched */
  if (j == len) {
    int x = i - j; /* Calculate starting position */
    return x;
  } else {
    return -1; /* Substring not found */
  }
}