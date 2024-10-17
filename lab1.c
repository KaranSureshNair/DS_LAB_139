#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

void push(int *top, int stack[], int item);
int pop(int *top, int stack[]);
void display(int *top, int stack[]);

int main() {
    int stack[SIZE];
    int choice;
    int item;
    int deleted_item;
    int top = -1;

    while (1) {
        printf("Enter 1 for insert, 2 for deleting, 3 for displaying: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item to insert: ");
                scanf("%d", &item);
                push(&top, stack, item);
                break;
            case 2:
                deleted_item = pop(&top, stack);
                if (deleted_item != -1) 
                    printf("Deleted item = %d\n", deleted_item);

                break;
            case 3:
                display(&top, stack);
                break;
            default:
                printf("Invalid choice. Exiting...\n");
                exit(0);
        }
    }

    return 0;
}

void push(int *top, int stack[], int item) {
    if (*top == (SIZE - 1)) {
        printf("Stack is overflow\n");
        return; 
    }
    stack[++(*top)] = item;
}

int pop(int *top, int stack[]) {
    if (*top == -1) {
        printf("Stack is underflow\n");
        return -1; 
    }
    return stack[(*top)--];
}

void display(int *top, int stack[]) {
    if (*top == -1) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = *top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

