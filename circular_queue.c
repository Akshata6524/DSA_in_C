#include <stdio.h>
#include <stdlib.h>

#define QSIZE 4

int q[QSIZE];
int front = 0, rear = -1, count = 0;

/* Insert operation */
void insert(int item) {
    if (count == QSIZE) {
        printf("Queue Overflow\n");
        return;
    }

    rear = (rear + 1) % QSIZE;
    q[rear] = item;
    count++;

    printf("Inserted: %d\n", item);
}

/* Delete operation */
void del() {
    if (count == 0) {
        printf("Queue Underflow\n");
        return;
    }

    printf("Deleted item: %d\n", q[front]);
    front = (front + 1) % QSIZE;
    count--;
}

/* Display operation */
void display() {
    int i, idx;

    if (count == 0) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue contents: ");
    idx = front;
    for (i = 0; i < count; i++) {
        printf("%d ", q[idx]);
        idx = (idx + 1) % QSIZE;
    }
    printf("\n");
}

/* Main function */
int main() {
    int choice, item;

    while(1){
        printf("\n--- Circular Queue Operations ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item to insert: ");
                scanf("%d", &item);
                insert(item);
                break;

            case 2:
                del();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    } 

    return 0;
}
