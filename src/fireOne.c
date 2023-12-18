#include "../include/headerA3.h"

// menu 8
void fireOne (a3Emp ** headLL, int whichOne) {

    int i, j;

    a3Emp * og_node = *headLL;  // original node
    a3Emp * temp_node = NULL;   // previous node

    // gets total num of employees
    int totalEmp = countEmployees(og_node);

    if (og_node == NULL) {
        printf("ERROR: Linked List is empty\n");
        return;
    }


    // If the first employee gets chosen
    if (whichOne == 1) {

        // free the first node dependents
        for (j = 0; j < og_node->numDependents; j++) {
            free(og_node->dependents[j]);
        }
        free(og_node->dependents);


        // if there is only 1 employee
        // sets head to NULL
        if (totalEmp == 1) {
            *headLL = NULL; 
        }

        // head now begins at the second node 
        else {
            *headLL = og_node->nextEmployee;     
        }

        printf("Employee [Id: %d] fired\n", og_node->empId);
        if (totalEmp-1 > 1 || totalEmp-1 == 0) {
            printf("There are now %d employees\n", totalEmp-1);
        }
        else {
            printf("There is now %d employee\n", totalEmp-1);
        }

        free(og_node);
        return;
    }


    // if any other employee gets chosen for whichOne
    // loops until whichOne equals placement of original node (og_node) in LL
    for (i = 1; i <= totalEmp; i++) {

        if (i == whichOne) {

            // free the node dependents
            for (j = 0; j < og_node->numDependents; j++) {
                free(og_node->dependents[j]);
            }
            free(og_node->dependents); 

            /* Let's say that whichOne = 3:
            i =     1   2   3   4   5
            og =    1 - 2 - 3x  4 - 5   
                              /
            temp =      1 - 2   3   4   5

            temp_node = og_node                                 // 1 - 2 : temp
            temp_node->nextEmployee = og_node->nextEmployee     // 2 - 4 : cross LLs
            */

            temp_node->nextEmployee = og_node->nextEmployee;
            //temp_node = temp_node->nextEmployee;

            printf("Employee [Id: %d] fired\n", og_node->empId);
            if (totalEmp-1 > 1) {
                printf("There are now %d employees\n", totalEmp-1);
            }
            else {
                printf("There is now %d employee\n", totalEmp-1);
            }

            free(og_node);

            return;

        }

        // temp_node is always one node before og_node 
        temp_node = og_node;
        og_node = og_node->nextEmployee;

    }
}