#include "../include/headerA3.h"

// menu 1
void recruitEmployee (struct employee ** headLL) {

    int i;

    char fname[MAX_LENGTH];
    char lname[MAX_LENGTH];

    char ** dependents = malloc(sizeof(char*));
    char aDependent[MAX_LENGTH];

    char YN;
    int count = 0;

    a3Emp * new_node;
    new_node = malloc(sizeof(a3Emp));


    /* FIRST AND LAST NAMES */
    printf("\nEnter the first name of the employee: ");
    fgets(fname, MAX_LENGTH, stdin);
    fname[strlen(fname)-1] = '\0';    // Ends string and removes \n

    printf("Enter the last name of the employee: ");
    fgets(lname, MAX_LENGTH, stdin);
    lname[strlen(lname)-1] = '\0';    // Ends string and removes \n

    strcpy(new_node->fname, fname);
    strcpy(new_node->lname, lname);


    /* DEPENDENTS */
    // Loops for # of dependents
    do {

        // count is used for indexing, memory allocation and determining the number of dependents
        count++; 

        printf("\nEnter name of dependent #%d: ", count); // count = 1

        // Gets a depenedent
        fgets(aDependent, MAX_LENGTH, stdin);
        aDependent[strlen(aDependent) - 1] = '\0';

        // saves aDependent to dependents[n]
        dependents[count-1] = malloc(strlen(aDependent) + 1);   // count = 0
        strcpy(dependents[count-1], aDependent);


        // Asks if any other dependents exists
        do{

            printf("Do you have any more dependents? (y/n): ");
            //fgets(YN, 1, stdin);
            scanf("%c", &YN);
            scanf("%c", (char *) stdin);    // catches newline error

            if (YN != 'y' && YN != 'Y' && YN != 'n' && YN != 'N') {
                printf("Please ONLY enter: 'y'/'n'\n");
            }

        } while (YN != 'y' && YN != 'Y' && YN != 'n' && YN != 'N');


        // reallocates more memory if another dependent exists
        if (YN == 'y' || YN == 'Y') {
            dependents = realloc(dependents, sizeof(char *) * (count + 1)); // count = 2
        }

    } while (YN != 'n' && YN != 'N');

    // Saves dependents to node
    new_node->numDependents = count;
    new_node->dependents = dependents;


    // prints # of dependents
    if (count == 1) {
        printf("\nYou have %d dependent.\n", count);
    }
    else {
        printf("\nYou have %d dependents.\n", count);
    }


    /* EMPID */
    // EMPID = (sum of ascii values of characters in the first name) + (length of the employee’s last name)

    int empId = 0;
    int lower = 1;
    int upper = 999;
    int num;
    int check;          // checks if all empIds are different
    a3Emp * temp_node;  // to check if empIds already exists

    // Sum of ascii values of first name
    for (i = 0; i < strlen(fname); i++) {
        empId = empId + (int)fname[i];
    }

    // Length of the employee's last name
    empId = empId + strlen(lname);

    // loops until no 2 ids are equal
    do {
        check = 1;
        temp_node = *headLL;

        while (temp_node != NULL) {

            if (temp_node->empId == empId) {
                srand(time(0));
                num = (rand() % (upper - lower + 1)) + lower;
                empId = empId + num;

                check = 0;
            }

            temp_node = temp_node->nextEmployee;
        }

    } while (check != 1);

    new_node->empId = empId;


    printf("\nYour computer-generated empId is %d\n\n", empId);

    *headLL = new_node; // saves new_node to ptr

}