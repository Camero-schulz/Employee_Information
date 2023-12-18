#include "../include/headerA3.h"

void bubbleSort(int arr[], int n) {
    int i, j;
    int temp;

    for (i = 0; i < n - 1; i++) {       // loop through each element in the array

        for (j = 0; j < n - i - 1; j++) {   // compare adjacent elements and swap if necessary

            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// menu 7
void sortEmployeesId (struct employee * headLL) {

    int i, j;
    int totalEmp;

    a3Emp *og_node = headLL;
    a3Emp *temp_node, *head, *ptr;
    temp_node = head = ptr = NULL;

    if (og_node == NULL) {
        printf("ERROR: Linked List is empty\n");
        return;
    }

    totalEmp = countEmployees(og_node);
    int arrEmpId [totalEmp];

    
    // Finds all empIds
    for (i = 0; i < totalEmp; i++) {
        arrEmpId[i] = og_node->empId;
        og_node = og_node->nextEmployee;
    }

    // Sorts Ids in ascending order
    bubbleSort(arrEmpId, totalEmp);



    /* EXAMPLE: If lowest id is found in the third node */

    /* Loops until new list is sorted */ 

    for (i = 0; i < totalEmp; i++) {
        og_node = headLL;                      // og_node is set to node1


        /* loops until sorted number equals empId - found in 3rd node */

        while (arrEmpId[i] != og_node->empId && og_node != NULL) {
            og_node = og_node->nextEmployee;
        }

        temp_node = malloc(sizeof(a3Emp));      // allocate memory for the node


        /* Copies 3rd og_node to 1st temp_node */

        strcpy(temp_node->fname, og_node->fname);
        strcpy(temp_node->lname, og_node->lname);
        temp_node->empId = og_node->empId;
        temp_node->numDependents = og_node->numDependents;
    
        char ** temp_dependents = malloc(sizeof(char*) * temp_node->numDependents);
        temp_node->dependents = temp_dependents;
        for (j = 0; j < temp_node->numDependents; j++) {
            temp_node->dependents[j] = malloc(sizeof(char) * (strlen(og_node->dependents[j]) + 1));
            strcpy(temp_node->dependents[j], og_node->dependents[j]);
        } 


        /* Copies node to new list */

        // If linked list is empty
        if (head == NULL) {
            head = temp_node;
            ptr = head;
        }

        else {
            // Traverse the list to reach the last element
            ptr = head;
            while (ptr->nextEmployee != NULL) {
                ptr = ptr->nextEmployee;
            }

            // Link the last element to the newly created node
            ptr->nextEmployee = temp_node;
        }

        temp_node->nextEmployee = NULL; // terminate the new linked list
    } 

    printf("After sorting on empId, the employees are as follows: \n");

    printAll(head); // Prints sorted list
    fireAll(&head); // removes list
}
    