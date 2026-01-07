/**
 * @file    FILEREAD.C
 * @brief   Demonstrates file reading and string tokenization in C.
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
 * Developed as part of the Phi Education Training (Milestone 11) and
 * BE Major-Project @ Terna Engineering College, University of Mumbai.
 *
 * This program reads content from "View.txt" and "View1.txt",
 * performing string tokenization to extract word-meaning pairs.
 *
 * @return  int  Returns 0 on successful execution.
 */

#include <conio.h> /* Console I/O library for clrscr() and getch() (DOS/Turbo C specific) */
#include <stdio.h>  /* Standard I/O library for file operations and printing */
#include <stdlib.h> /* Standard library */
#include <string.h> /* String library for strtok */

/**
 * @brief   Main function - Entry point of the program.
 *
 * Reads files "View.txt" and "View1.txt" and processes their content.
 */
int main() {
  FILE *fpointer;
  char s[250];
  char s1[250];

  clrscr(); /* Clears the console screen (Turbo C specific) */

  /* Read and print content from View.txt */
  fpointer = fopen("View.txt", "r");
  if (fpointer != NULL) {
    while (!feof(fpointer)) {
      if (fgets(s, 250, fpointer) != NULL) {
        puts(s);
      }
    }
    fclose(fpointer);
  }

  /* Read and tokenize content from View1.txt */
  fpointer = fopen("View1.txt", "r");
  if (fpointer != NULL) {
    while (!feof(fpointer)) {
      char *word;
      if (fgets(s1, 250, fpointer) != NULL) {
        word = strtok(s1, ":");
        while (word != NULL) {
          int x = 0;
          printf("\n");
          if (x == 0) {
            printf("Word : %s", word);
            word = strtok(NULL, ":");
            x = x + 1;
            printf("\n");
          }
          if (x == 1 && word != NULL) {
            printf("Meaning : %s", word);
            word = strtok(NULL, ":");
            x = x + 1;
          }
        }
      }
    }
    fclose(fpointer);
  }

  getch(); /* Wait for a key press before closing (Turbo C specific) */

  return 0; /* Return 0 to indicate successful execution */
}
