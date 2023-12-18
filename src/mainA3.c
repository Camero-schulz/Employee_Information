#include "../include/headerA3.h"

int main(){

    int userInput;

    a3Emp *head, *ptr, *new_node; 
    head = ptr = new_node = NULL;

    loadEmpData(&head, "proFile.txt");
    
    do {
        printf("\n--------MENU--------\n");
        printf("1. Add a new employee\n");
        printf("2. Print data of all employees\n");
        printf("3. Print data of the nth employee\n");
        printf("4. Search for employee based on empId\n");
        printf("5. Search for employee based on full name\n");
        printf("6. Count the total number of employees\n");
        printf("7. Sort the employees based on their empId\n");
        printf("8. Remove the nth employee in the current LL\n");
        printf("9. Remove all employees in the current LL\n");
        printf("10. Exit\n");

        printf("\nChoose a menu option: ");
        scanf("%d", &userInput);
        scanf("%c", (char *) stdin);    // catches newline error
        printf("\n");

        if (userInput == 1) {

            // Create the node and assign values to it
            recruitEmployee (&new_node);
            
            new_node->nextEmployee = NULL;

            // If linked list is empty
            if (head == NULL) {
                head = new_node;
                ptr = head;
            }

            else {
                // Traverse the list to reach the last element
                ptr = head;
                while (ptr->nextEmployee != NULL) {
                    ptr = ptr->nextEmployee;
                }

                // Link the last element to the newly created node
                ptr->nextEmployee = new_node;
            }

        }

        else if (userInput == 2) {
            printAll(head);

        }

        else if (userInput == 3) {

            int pos;

            printf("Enter a position: ");
            scanf("%d", &pos);
            scanf("%c", (char *) stdin);    // catches newline error

            printOne (head, pos);
        }

        else if (userInput == 4) {

            int inputId;

            printf("Enter an ID: ");
            scanf("%d", &inputId);
            scanf("%c", (char *) stdin);    // catches newline error

            int position = lookOnId (head, inputId);

            if (position != -1) {
                printOne(head, position);
            }
        }

        else if (userInput == 5) {

            char fullName [100];
            printf("Enter the full name of the employee: ");

            fgets(fullName, 100, stdin);
            fullName[strlen(fullName)-1] = '\0';    // Ends string and removes \n

            int position = lookOnFullName (head, fullName);

            if (position != -1) {
                printOne(head, position);
            }
        }

        else if (userInput == 6) {
            int numEmployees = countEmployees (head);
            printf("Total number of employees = %d\n", numEmployees);

        }

        else if (userInput == 7) {
            sortEmployeesId (head);
        }

        else if (userInput == 8) {
            int numEmployees = countEmployees (head);
            int empNum;

            if (numEmployees == 1) {
                printf("Currently there is %d employee\n", numEmployees);
            }
            else {
                printf("Currently there are %d employees\n", numEmployees);
            }
            printf("Which employee do you wish to fire - enter a value between 1 and %d: ", numEmployees);

            scanf("%d", &empNum);
            scanf("%c", (char *) stdin);    // catches newline error

            if (empNum >= 1 && empNum <= numEmployees){
                fireOne (&head, empNum);
            }

            else {
                printf("ERROR: Employee not found\n");
            }

        }

        else if (userInput == 9) {

            char YN;
            printf("Are you sure you want to fire everyone? (y/n): ");
            scanf("%c", &YN);

            if (YN == 'y' || YN == 'Y') {
                if (head == NULL) {
                    printf("ERROR: Linked List is empty\n");
                }
                else {
                    printf("All fired. Linked list is now empty\n");
                }

                fireAll (&head);
            }

        }

        else {
            if (userInput != 10) { 
                printf("Enter a number between 1 - 10\n");
            }
            else {
                fireAll (&head);
            }
        }

    } while (userInput != 10);

    return 0;

}