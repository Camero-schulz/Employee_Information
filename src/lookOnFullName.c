#include "../include/headerA3.h"

// menu 5
int lookOnFullName (struct employee * headLL, char whichName [100]) {

    int i; 
    int j = 0;
    int count = 1;

    a3Emp *printList = headLL;

    char fname[MAX_LENGTH];
    char lname[MAX_LENGTH];

    if (printList == NULL) {
        printf("ERROR: Linked List is empty\n");
        return -1;
    }


    // gets fname
    for (i = 0; i < strlen(whichName) - 1; i++) {

        if (whichName[i] == ' ') {
            fname[i] = '\0';    // ends string
            j = i+1;            // j used for lname 
            break;
        }
        fname[i] = whichName[i];
    }

    // Returns -1 if no space is found 
    if (j == 0) {
        printf("Please enter the first and last name of the employee\n");
        return -1;
    }


    // gets lname
    int size = 0;

    for (i = j; i < strlen(whichName); i++) {
        lname[size] = whichName[i];
        size++;
    }
    lname[size] = '\0';    // ends string


    /*
    printf("%s|\n", fname); 
    printf("%s|\n", lname);
    printf("%s\n", printList->fname);
    int x = strcmp(printList->fname, fname);
    printf("%d\n", x); */


    // loops until first name = fname and last name = lname
    while (strcmp(printList->fname, fname) != 0 || strcmp(printList->lname, lname) != 0) {
        printList = printList->nextEmployee;

        // returns -1 if employee name is not found
        if (printList == NULL) {
            printf("ERROR: Employee name not found\n");
            return -1;
        }
        count++;
    }

    printf("Employee is found at position %d\n\n", count);
    return count;


}