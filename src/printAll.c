#include "../include/headerA3.h"

// menu 2
void printAll (struct employee * headLL) {

    int count = 0;
    int i;

    a3Emp *printList = headLL;

    if (printList == NULL) {
        printf("ERROR: Linked List is empty\n");
        return;
        
    } 

    while (printList != NULL) {
        count++;
        printf("\nEmployee #%d:\n", count);
        printf("\tEmployee ID: %d\n", printList->empId);
        printf("\tFirst Name: %s\n", printList->fname);
        printf("\tLast Name: %s\n", printList->lname);
        printf("\tDependents[%d]: %s", printList->numDependents, printList->dependents[0]);

        for (i = 1; i < printList->numDependents; i++) {
            printf(", %s", printList->dependents[i]);
        }
        printf("\n");

        printList = printList->nextEmployee;
    }

    if (count == 1) {
        printf("\nCurrently there is %d employee.\n\n", count);
    }
    else {
        printf("\nCurrently there are %d employees.\n\n", count);
    }
}