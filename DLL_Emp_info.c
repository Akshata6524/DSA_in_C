#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structure definition */
struct node {
    int ssn;
    char name[20], dept[10], desg[20];
    float sal;
    long int phno;
    struct node *prev;
    struct node *next;
};

/* typedef for pointer */
typedef struct node* NODE;

/* Global pointers */
NODE first = NULL, last = NULL;

/* Create Node */
NODE create() {
    NODE temp = (NODE)malloc(sizeof(struct node));

    if (temp == NULL) {
        printf("Memory allocation failed\n");
        exit(0);
    }

    printf("\nEnter SSN, Name, Dept, Designation, Salary, Phone No:\n");
    scanf("%d %s %s %s %f %ld",&temp->ssn,temp->name,temp->dept,temp->desg,&temp->sal,&temp->phno);

    temp->prev = NULL;
    temp->next = NULL;
    

    return temp;
}

/* Insert at Front */
void insert_front() {
    NODE temp = create();

    if (first == NULL) {
        first = last = temp;
    } else {
        temp->next = first;
        first->prev = temp;
        first = temp;
    }
}

/* Insert at Rear */
void insert_rear() {
    NODE temp = create();

    if (first == NULL) {
        first = last = temp;
    } else {
        last->next = temp;
        temp->prev = last;
        last = temp;
    }
}

/* Delete from Front */
void delete_front() {
    NODE cur;

    if (first == NULL) {
        printf("\nList is Empty\n");
        return;
    }

    cur = first;
    printf("\nDeleted Employee: %d %s\n", cur->ssn, cur->name);

    if (first == last) {
        first = last = NULL;
    } else {
        first = first->next;
        first->prev = NULL;
    }

    free(cur);
    
}

/* Delete from Rear */
void delete_rear() {
    NODE cur;

    if (first == NULL) {
        printf("\nList is Empty\n");
        return;
    }

    cur = last;
    printf("\nDeleted Employee: %d %s\n", cur->ssn, cur->name);

    if (first == last) {
        first = last = NULL;
    } else {
        last = last->prev;
        last->next = NULL;
    }

    free(cur);

}

/* Display */
void display() {
    NODE cur = first;
    int count = 0;
    
    if (cur == NULL) {
        printf("\nList is Empty\n");
        return;
    }

    printf("\nSSN\tName\tDept\tDesg\tSalary\tPhone\n");
    while (cur != NULL) {
        printf("%d\t%s\t%s\t%s\t%f\t%ld\n",cur->ssn,cur->name,cur->dept,cur->desg,cur->sal,cur->phno);
        cur = cur->next;
        count++;
    }

    printf("Total Employees = %d\n", count);
}

/* Main Menu */
int main() {
    int choice;

    while (1) {
        printf("\n---- DLL MENU ----\n");
        printf("1. Insert Front\n");
        printf("2. Insert Rear\n");
        printf("3. Delete Front\n");
        printf("4. Delete Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert_front(); break;
            case 2: insert_rear(); break;
            case 3: delete_front(); break;
            case 4: delete_rear(); break;
            case 5: display(); break;
            case 6: exit(0);
            default: printf("Invalid Choice\n");
        }
    }
}
