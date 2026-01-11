#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structure definition */
struct node {
    int usn;
    char name[20];
    char branch[20];
    int sem;
    char phone[15];
    struct node *next;
};

typedef struct node* NODE;

NODE first = NULL;

/* Create a new node */
NODE create_node() {
    NODE temp = (NODE)malloc(sizeof(struct node));

    if (temp == NULL) {
        printf("Memory allocation failed\n");
        exit(0);
    }

    printf("Enter USN, Name, Branch, Semester, Phone:\n");
    scanf("%d %s %s %d %s", &temp->usn, temp->name, temp->branch,&temp->sem,temp->phone);

    temp->next = NULL;
    return temp;
}

/* Insert at front */
void insert_front() { 
    NODE temp = create_node();
    temp->next = first;
    first = temp;
}

/* Insert at rear */
void insert_rear() {
    NODE temp = create_node();
    NODE cur;

    if (first == NULL) {
        first = temp;
        return;
    }

    cur = first;
    while (cur->next != NULL)
        cur = cur->next;

    cur->next = temp;
}

/* Delete from front */
void delete_front() {
    NODE temp;

    if (first == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = first;
    first = first->next;

    printf("Deleted USN: %d\n", temp->usn);
    free(temp);
}

/* Delete from rear */
void delete_rear() {
    NODE cur, prev;

    if (first == NULL) {
        printf("List is empty\n");
        return;
    }

    if (first->next == NULL) {
        printf("Deleted USN: %d\n", first->usn);
        free(first);
        first = NULL;
        return;
    }

    prev = NULL;
    cur = first;
    while (cur->next != NULL) {
        prev = cur;
        cur = cur->next;
    }

    printf("Deleted USN: %d\n", cur->usn);
    free(cur);
    prev->next = NULL;
}

/* Display list */
void display() {
    
    int count = 0;

    if (first == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("\nUSN\tName\tBranch\tSem\tPhone\n");
   NODE cur = first;
    while (cur != NULL) {
        printf("%d\t%s\t%s\t%d\t%s\n",cur->usn, cur->name, cur->branch, cur->sem, cur->phone);
        cur = cur->next;
        count++;
    }
    printf("Total students = %d\n", count);
}

/* Main function */
int main() {
    int ch;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Insert Front\n");
        printf("2. Insert Rear\n");
        printf("3. Delete Front\n");
        printf("4. Delete Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: insert_front(); break;
            case 2: insert_rear(); break;
            case 3: delete_front(); break;
            case 4: delete_rear(); break;
            case 5: display(); break;
            case 6: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
