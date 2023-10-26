#include <stdio.h>
#include <stdlib.h>

struct stack {
    int size;
    int top;
    int *arr;
};

int create(struct stack *s) {
    s = (struct stack*)malloc(sizeof(struct stack));
    if (s == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    printf("Enter Size of Stack: ");
    scanf("%d", &s->size);
    s->arr = (int*)malloc(s->size * sizeof(int));
    
    if (s->arr == NULL) {
        printf("Memory allocation for stack array failed.\n");
        free(s);
        return 1;
    }
    s->top = -1;
}

int isFull(struct stack *s1) {
    if (s1->top == s1->size - 1) {
        return 1;
    }
    return 0;
}

int isEmpty(struct stack *s1) {
    if (s1->top == -1) {
        return 1;
    }
    return 0;
}

int push(struct stack *s, int ele) {
    if (isFull(s)) {
        printf("%d cannot be added, Stack Overflow\n");
    } else {
        s->top++;
        s->arr[s->top] = ele;
    }
    return 0;
}

int pop(struct stack *s) {
    return s->arr[s->top--];
}

int peek(struct stack *s) {
    int p;
    p = s->arr[s->top];
    return p;
}

void display(struct stack *s) {
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

int main() {
    struct stack *s;
    
    if(create(s)){
        return 0;
    }
    
    int choice;
    do {
        printf("\nStack Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
         switch (choice) {
            case 1:
                if (isFull(s)) {
                    printf("Stack is full. Cannot push.\n");
                } else {
                    int element;
                    printf("Enter the element to push: ");
                    scanf("%d", &element);
                    push(s, element);
                }
                break;
            case 2:
                if (isEmpty(s)) {
                    printf("Stack is empty. Cannot pop.\n");
                } else {
                    int data = pop(s);
                    printf("Element popped %d.\n",data);
                }
                break;
            case 3:
                if (isEmpty(s)) {
                    printf("Stack is empty. Peek not possible.\n");
                } else {
                    int top = peek(s);
                    printf("The peek element is %d\n", top);
                }
                break;
            case 4:
                if (isEmpty(s)) {
                    printf("Stack is empty. Nothing to display.\n");
                } else {
                    printf("Stack contents: ");
                    display(s);
                }
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    free(s->arr);
    free(s);

    return 0;
}
