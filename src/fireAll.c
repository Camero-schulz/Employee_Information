#include "../include/headerA3.h"

// menu 9
void fireAll (a3Emp ** headLL) {

    int i;

    a3Emp * temp = *headLL;

    if (temp == NULL) {
        return;
    }

    while (temp != NULL) {

        // free the node dependents
        for (i = 0; i < temp->numDependents; i++) {
            free(temp->dependents[i]);
        }
        free(temp->dependents); 

        *headLL = temp->nextEmployee;
        free(temp);
        temp = *headLL;
    }
}
