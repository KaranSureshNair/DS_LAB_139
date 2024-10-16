#include <stdio.h>
#define SIZE 5

void insert(int* rear, int item, int queue[]);
void delete(int* front, int* rear, int queue[]);
void display(int front, int rear, int queue[]);

int main() {
    int front, rear, queue[SIZE], choice, item;
    front = -1;
    rear = -1;

    while (1) { // Loop indefinitely until explicitly broken
        printf("\n1) Insert an element");
        printf("\n2) Delete an element");
        printf("\n3) Display the queue");
        printf("\nEnter your choice here: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Insert
                if (rear < SIZE - 1) {
                    printf("Enter your item here: ");
                    scanf("%d", &item);
                    insert(&rear, item, queue);
                    if (front == -1) { // Update front if queue was empty
                        front = 0;
                    }
                } else {
                    printf("Queue is full\n");
                }
                break;

            case 2: // Delete
                delete(&front, &rear, queue);
                break;

            case 3: // Display
                display(front, rear, queue);
                break;

            default:
                printf("\nInvalid input\n");
                break;
        }
    }
}

void insert(int* rear, int item, int queue[]) {
    *rear += 1; // Increment rear
    queue[*rear] = item; // Insert the item
}

void delete(int* front, int* rear, int queue[]) {
    if (*front > *rear) {
        printf("Queue is empty\n");
    } else {
        printf("Deleted item: %d\n", queue[*front]);
        *front += 1; // Increment front
        if (*front > *rear) { // Reset if the queue becomes empty
            *front = *rear = -1;
        }
    }
}

void display(int front, int rear, int queue[]) {
    if (front > rear) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements:\n");
        for (int i = front; i <= rear; i++) {
            printf("%d\n", queue[i]);
        }
    }
}
