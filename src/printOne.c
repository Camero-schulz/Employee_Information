#include "../include/headerA3.h"

// menu 3
void printOne (struct employee * headLL, int whichOne) {

    int i;
    a3Emp *printList = headLL;

    if (printList == NULL) {
        printf("ERROR: Linked List is empty\n");
        return;
        
    } 

    for (i = 1; i < whichOne; i++) {
        printList = printList->nextEmployee;

        if (printList == NULL) {
            printf("ERROR: Employee #%d does not exist\n", whichOne);
            return;
        }
    }

    printf("\tEmployee ID: %d\n", printList->empId);
    printf("\tFirst Name: %s\n", printList->fname);
    printf("\tLast Name: %s\n", printList->lname);
    printf("\tDependents: %s", printList->dependents[0]);

    for (i = 1; i < printList->numDependents; i++) {
        printf(", %s", printList->dependents[i]);
    }
    printf("\n\n");
}