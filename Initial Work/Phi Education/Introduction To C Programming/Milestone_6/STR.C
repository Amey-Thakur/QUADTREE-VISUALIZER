/**
 * @file    STR.C
 * @brief   Demonstrates string copy, tokenize, and memory copy operations.
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
 * Developed as part of the Phi Education Training (Milestone 6) and
 * BE Major-Project @ Terna Engineering College, University of Mumbai.
 *
 * This program demonstrates three string operations:
 * 1. String copying using strcpy
 * 2. String tokenization using strtok
 * 3. Memory copying
 *
 * @return  int  Returns 0 on successful execution.
 */

#include <conio.h> /* Console I/O library for clrscr() and getch() (DOS/Turbo C specific) */
#include <stdio.h>  /* Standard I/O library for printf and scanf functions */
#include <string.h> /* String library for strcpy, strtok, strlen */

/**
 * @brief   Copies a string to a local buffer and displays it.
 * @param   str1  The source string to copy.
 * @return  char* Returns 0 (null pointer).
 */
char *str_copy(const char *str1);

/**
 * @brief   Copies memory from source to destination.
 * @param   dest  Destination memory location.
 * @param   src   Source memory location.
 * @param   n     Number of bytes to copy.
 */
void mem_copy(void *dest, const void *src, unsigned int n);

/**
 * @brief   Tokenizes a string using a delimiter.
 * @param   str   The string to tokenize.
 * @param   c     The delimiter character(s).
 * @return  char* Returns 0 (null pointer).
 */
char *str_tokenize(char *str, char *c);

/**
 * @brief   Main function - Entry point of the program.
 *
 * Demonstrates string copy, tokenization, and memory copy operations.
 */
int main() {
  unsigned int x;
  char str[19], str1[50], ch[2], dest[140];

  clrscr(); /* Clears the console screen (Turbo C specific) */

  /* Demonstrate string copy */
  printf("Enter the string:");
  scanf("%s", str);
  str_copy(str);

  /* Demonstrate string tokenization */
  printf("Enter the string:");
  scanf("%s", str1);
  printf("Enter the split token:");
  scanf("%s", ch);
  str_tokenize(str1, ch);

  /* Demonstrate memory copy */
  printf("Enter the string:");
  scanf("%s", ch);
  x = strlen(str);
  mem_copy(dest, str, x + 1);

  getch(); /* Wait for a key press before closing (Turbo C specific) */

  return 0; /* Return 0 to indicate successful execution */
}

/**
 * @brief   Copies a string to a local buffer using strcpy.
 *
 * @param   str   The source string to copy.
 * @return  char* Returns 0 (null pointer).
 */
char *str_copy(const char *str) {
  char dst[14];

  /* Copy string using strcpy */
  strcpy(dst, str);
  printf("The string is copied %s\n", dst);

  return 0;
}

/**
 * @brief   Tokenizes a string using strtok.
 *
 * Splits the string at each occurrence of the delimiter
 * and prints each token.
 *
 * @param   str   The string to tokenize.
 * @param   c     The delimiter character(s).
 * @return  char* Returns 0 (null pointer).
 */
char *str_tokenize(char *str, char *c) {
  char *s;

  printf("The splitted string is as below\n");

  /* Get first token */
  s = strtok(str, c);

  /* Continue getting tokens until end */
  while (s != '\0') {
    printf("%s\n", s);
    s = strtok(NULL, c); /* Get next token */
  }

  return 0;
}

/**
 * @brief   Copies memory from source to destination.
 *
 * Uses strcpy to copy the content from source to destination.
 *
 * @param   dest  Destination memory location.
 * @param   src   Source memory location.
 * @param   n     Number of bytes to copy.
 */
void mem_copy(void *dest, const void *src, unsigned int n) {
  char *nsrc = (char *)src;
  char *ndest = (char *)dest;

  /* Copy source to destination */
  strcpy(ndest, nsrc);
  printf("\nCopied array is %s \n", ndest);
}
