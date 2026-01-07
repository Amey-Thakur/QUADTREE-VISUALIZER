/**
 * @file    strcopy.C
 * @brief   Copies one string into another.
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
 * This program copies the contents of one string into another.
 * Returns 0 on success or -1 on error.
 *
 * @return  int  Returns 0 on successful execution.
 */

#include <conio.h> /* Console I/O library for clrscr() and getch() (DOS/Turbo C specific) */
#include <stdio.h>  /* Standard I/O library for printf and scanf functions */
#include <string.h> /* String library */

/**
 * @brief   Copies str1 into str2.
 * @param   str1  Source string to copy from.
 * @param   str2  Destination string to copy to.
 * @return  int   0 on success, -1 on error.
 */
int str_copy(char *str1, char *str2);

/**
 * @brief   Main function - Entry point of the program.
 *
 * Prompts user for a string and copies it to another string.
 */
int main() {
  char str1[30], str2[30]; /* str1: source; str2: destination */
  int x;                   /* Copy result */

  clrscr(); /* Clears the console screen (Turbo C specific) */

  /* Input string to copy */
  printf("\n Enter the string you want to copy:");
  scanf("%s", str1);

  /* Perform the copy operation */
  x = str_copy(str1, str2);

  /* Display result */
  if (x == 0) {
    printf("\n String is successfully copied\n");
  }
  if (x == -1) {
    printf("\n String is not copied\n");
  }

  getch(); /* Wait for a key press before closing (Turbo C specific) */

  return 0; /* Return 0 to indicate successful execution */
}

/**
 * @brief   Copies str1 into str2 character by character.
 *
 * Iterates through str1 and copies each character to str2
 * until the null terminator is reached.
 *
 * @param   str1  Source string to copy from.
 * @param   str2  Destination string to copy to.
 * @return  int   0 on success, -1 on error.
 */
int str_copy(char *str1, char *str2) {
  int i = 0;

  /* Copy each character from str1 to str2 */
  while (str1[i] != '\0') {
    str2[i] = str1[i];
    i++;
  }
  str2[i] = '\0'; /* Add null terminator */

  /* Verify copy was successful */
  if (str2[0] != '\0') {
    return 0; /* Success */
  } else {
    return -1; /* Error */
  }
}