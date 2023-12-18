#include "../include/headerA3.h"

// menu 6
int countEmployees (a3Emp * headLL) {

    int count = 0;
    a3Emp *printList = headLL;

    while (printList!= NULL) {

        printList = printList->nextEmployee;
        count++;
    }

    return count;

}