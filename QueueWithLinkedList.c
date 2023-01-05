#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

struct Node *front = NULL;
struct Node *rear = NULL;

struct Node *CreateNode()
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Allocation Failed\n");
    }
    else
    {
        printf("Node Created\n");
        return newNode;
    }
}

void push(int key)
{
    struct Node *newNode = CreateNode();

    newNode->data = key;
    newNode->link = NULL;

    if (rear == NULL)
    {
        rear = newNode;
        front = rear;
    }
    else
    {
        newNode->link = front;
        rear->link = newNode;
        rear = newNode;
    }
}

int pop()
{
    if (front == NULL)
    {
        return -1;
    }
    else
    {
        int key;
        struct Node *temp;
        temp = front;
        front = temp->link;
        key = temp->data;
        free(temp);
        return key;
    }
}

int peek()
{
    if (front == NULL)
    {
        return -1;
    }
    else
    {
        int key;
        key = front->data;
        return key;
    }
}

void display()
{
    if (front == NULL)
    {
        printf("Empty");
    }
    else
    {
        struct Node *temp;
        temp = front;
        do
        {
            printf("%d->", temp->data);
            temp = temp->link;
        } while (temp != front);
    }
}

int main()
{
    while (1)
    {
        printf("\n");
        printf("Enter 1 to push in queue\n");
        printf("Enter 2 to pop in queue\n");
        printf("Enter 3 to peek in queue\n");
        printf("Enter 4 to display whole queue\n");
        printf("Enter 5 to Exit\n");

        int ch;
        scanf("%d", &ch);
        printf("\n");
        switch (ch)
        {
        case 1:
        {
            int element;
            printf("\nEnter the Element to Push : ");
            scanf("%d", &element);
            push(element);
            break;
        }

        case 2:
        {
            int key = pop();
            if (key == -1)
            {
                printf("\nQueue is Empty\n");
            }
            else
                printf("\n%d is pop from the queue.\n", key);
            break;
        }

        case 3:
        {
            int key = peek();
            if (key == -1)
            {
                printf("\n Queue is Empty\n");
            }
            else
                printf("\nFornt of queue is : %d\n", key);
            break;
        }

        case 4:
        {
            printf("\nQueue is : ");
            display();
          
        }
        case 5:
        {
            exit(1);
            break;
        }

        default:
            break;
        }
    }

    return 0;
}
