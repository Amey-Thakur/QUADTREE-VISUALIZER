/**
 * @file    strfindchar.C
 * @brief   Finds the position of a character within a string.
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
 * This program searches for a specific character within a string
 * and returns its position if found, or -1 if not present.
 *
 * @return  int  Returns 0 on successful execution.
 */

#include <conio.h> /* Console I/O library for clrscr() and getch() (DOS/Turbo C specific) */
#include <stdio.h>  /* Standard I/O library for printf and scanf functions */
#include <string.h> /* String library */

/**
 * @brief   Finds a character in a string.
 * @param   str  The string to search in.
 * @param   ch   The character to search for.
 * @return  int  Position of character if found, -1 otherwise.
 */
int str_find_char(char *str, char ch);

/**
 * @brief   Main function - Entry point of the program.
 *
 * Prompts user for a string and character, then searches.
 */
int main() {
  char str[30], ch; /* str: input string; ch: character to find */
  int f;            /* Result: position or -1 */

  clrscr(); /* Clears the console screen (Turbo C specific) */

  /* Input string to search */
  printf("Enter the string for which you want to perform search operation:\t");
  scanf("%s", str);

  /* Clear input buffer and get character to search */
  getchar(); /* Consume newline */
  printf("Enter the character you want to search:\t");
  scanf("%c", &ch);

  /* Search for the character */
  f = str_find_char(str, ch);

  /* Display result */
  if (f == -1) {
    printf("\n %c is not present in the string \n", ch);
  } else {
    printf("\n %c is present at position %d in %s \n", ch, f, str);
  }

  getch(); /* Wait for a key press before closing (Turbo C specific) */

  return 0; /* Return 0 to indicate successful execution */
}

/**
 * @brief   Searches for a character within a string.
 *
 * Iterates through the string character by character
 * until the target character is found or end is reached.
 *
 * @param   str  The string to search in.
 * @param   ch   The character to search for.
 * @return  int  Position (0-indexed) if found, -1 otherwise.
 */
int str_find_char(char *str, char ch) {
  int i;

  /* Iterate through the string */
  for (i = 0; str[i] != '\0'; i++) {
    if (ch == str[i]) {
      return i; /* Character found at position i */
    }
  }

  return -1; /* Character not found */
}