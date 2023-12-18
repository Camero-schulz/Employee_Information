#include "../include/headerA3.h"

// menu 4
int lookOnId (struct employee * headLL, int whichEmpId) {

    int count = 1;
    a3Emp *printList = headLL;

    if (printList == NULL) {
        printf("ERROR: Linked List is empty\n");
        return -1;
    }

    while (printList->empId != whichEmpId) {
        printList = printList->nextEmployee;

        if (printList == NULL) {
            printf("ERROR: Employee ID not found\n");
            return -1;
        }
        count++;
    }

    printf("Employee is found - position %d\n\n", count);
    return count;
}