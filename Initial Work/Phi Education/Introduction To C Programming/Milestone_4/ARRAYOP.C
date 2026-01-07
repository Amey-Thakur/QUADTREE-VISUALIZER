/**
 * @file    ARRAYOP.C
 * @brief   Implements comprehensive array operations with a menu-driven
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
 * Developed as part of the Phi Education Training (Milestone 4) and
 * BE Major-Project @ Terna Engineering College, University of Mumbai.
 *
 * This program provides a menu-driven interface to perform various
 * array operations including: Add, Search, Remove, Sort, and Print.
 *
 * @return  int  Returns 0 on successful execution.
 */

#include <conio.h> /* Console I/O library for clrscr() and getch() (DOS/Turbo C specific) */
#include <stdio.h> /* Standard I/O library for printf and scanf functions */

/* Global variables */
int choice, i, j, arr[10],
    n; /* choice: menu selection; arr: array storage; n: current size */

/* Function prototypes */
void menu();   /* Displays menu and handles user choice */
void add();    /* Adds an element to the array */
void search(); /* Searches for an element in the array */
void Remove(); /* Removes an element from the array */
void sort();   /* Sorts the array in ascending/descending order */
void print();  /* Prints all elements in the array */

/**
 * @brief   Main function - Entry point of the program.
 *
 * Initializes the array with user input and displays the menu.
 */
int main() {
  clrscr(); /* Clears the console screen (Turbo C specific) */

  /* Get array size from user */
  printf("\nEnter size of array:");
  scanf("%d", &n);

  /* Input array elements */
  printf("\nEnter elements of array:");
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  /* Display the main menu */
  menu();

  getch(); /* Wait for a key press before closing (Turbo C specific) */

  return 0; /* Return 0 to indicate successful execution */
}

/**
 * @brief   Displays the menu and handles user's choice.
 *
 * Provides options for Add, Search, Remove, Sort, Print, and Exit.
 */
void menu() {
  printf("\n Array Implementation\n");
  printf("---------------------------\n");
  printf("\n What do you want to do...?");
  printf("\n\t 1.Add");
  printf("\n\t 2.Search");
  printf("\n\t 3.Remove");
  printf("\n\t 4.Sort");
  printf("\n\t 5.Print");
  printf("\n\t 6.Exit");
  printf("\n Your Choice:");
  scanf("%d", &choice);

  switch (choice) {
  case 1:
    add();
    break;
  case 2:
    search();
    break;
  case 3:
    Remove();
    break;
  case 4:
    sort();
    break;
  case 5:
    print();
    break;
  case 6:
    break;
  default:
    printf("Invalid Option. Please try again");
  }
}

/**
 * @brief   Adds a new element to the array.
 *
 * Checks for duplicates and array capacity before adding.
 */
void add() {
  int no, flag = 0;

  printf("Enter an element to add into the array : ");
  scanf("%d", &no);

  /* Check if element already exists */
  for (i = 0; i < n; i++) {
    if (arr[i] == no) {
      printf("Value is already present");
      flag = 1;
      break;
    }
  }

  /* Add element if not duplicate and array not full */
  if (flag == 0 && n != 10) {
    arr[n++] = no;
    printf("Element added successfully");
  } else {
    if (flag == 0) {
      printf("Array is FULL ");
    }
  }

  getch();
  menu(); /* Return to menu */
}

/**
 * @brief   Searches for an element in the array using linear search.
 */
void search() {
  int toSearch, found;

  printf("\n Enter element to search:");
  scanf("%d", &toSearch);

  found = 0;
  for (i = 0; i < n; i++) {
    if (arr[i] == toSearch) {
      found = 1;
      break;
    }
  }

  if (found == 1) {
    printf("\n%d is found at position %d", toSearch, i + 1);
  } else {
    printf("\n%d is not found in the array", toSearch);
  }

  getch();
  menu(); /* Return to menu */
}

/**
 * @brief   Removes an element from the array.
 *
 * Shifts remaining elements after deletion.
 */
void Remove() {
  int position, delitem, flag = 0;

  printf("Enter element to be deleted\n");
  scanf("%d", &delitem);

  /* Find the element's position */
  for (i = 0; i < n; i++) {
    if (arr[i] == delitem) {
      position = i;
      flag = 1;
    }
  }

  if (flag == 0) {
    printf("Number not found in array\n");
  }

  if (flag == 1 && n != 0) {
    /* Shift elements to fill the gap */
    for (i = 0; i < n; i++) {
      if (i >= position) {
        arr[i] = arr[i + 1];
      }
    }
    n--;
    printf("Element Removed");
  } else {
    printf("Array is Empty.. Cannot delete item");
  }

  getch();
  menu(); /* Return to menu */
}

/**
 * @brief   Sorts the array in ascending or descending order.
 *
 * Uses bubble sort algorithm.
 */
void sort() {
  int no, tmp;

  printf("Enter \n 1 for Ascending Order \n 2 for Descending order\n");
  scanf("%d", &no);

  switch (no) {
  case 1:
    /* Bubble sort - Ascending */
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        if (arr[j] > arr[i]) {
          tmp = arr[i];
          arr[i] = arr[j];
          arr[j] = tmp;
        }
      }
    }
    printf("\n Ascending order:");
    for (i = 0; i < n; i++) {
      printf("%d\t", arr[i]);
    }
    break;

  case 2:
    /* Bubble sort - Descending */
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        if (arr[j] < arr[i]) {
          tmp = arr[i];
          arr[i] = arr[j];
          arr[j] = tmp;
        }
      }
    }
    printf("\n Descending order:");
    for (i = 0; i < n; i++) {
      printf("%d\t", arr[i]);
    }
    break;

  default:
    printf("Invalid input");
  }

  getch();
  menu(); /* Return to menu */
}

/**
 * @brief   Prints all elements currently in the array.
 */
void print() {
  printf("Array contains : \n");
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  getch();
  menu(); /* Return to menu */
}
