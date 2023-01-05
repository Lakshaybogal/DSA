#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

struct Node *Top = NULL;

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

    if (Top == NULL)
    {
        Top = newNode;
    }
    else
    {
        newNode->link = Top;
        Top = newNode;
    }
}

int pop()
{
    if (Top == NULL)
    {
        printf("Stack is Empty");
    }
    else
    {
        int key;
        struct Node *temp;
        temp = Top;
        Top = temp->link;
        key = temp->data;
        free(temp);
        return key;
    }
}

int peek()
{
    if (Top == NULL)
    {
        return -1;
    }
    else
    {
        int key;
        key = Top->data;
        return key;
    }
}

int main()
{
    while (1)
    {
        printf("\n");
        printf("Enter 1 to push in stack\n");
        printf("Enter 2 to pop in stack\n");
        printf("Enter 3 to peek in stack\n");
        printf("Enter 4 to Exit\n");
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
            int element = pop();
            printf("\n%d is pop from the stack.\n", element);
            break;
        }

        case 3:
        {
            if(peek()==-1)
            {
                printf("\nTop of Stack is Empty\n");
            }
            else
            printf("\nTop of Stack is : %d\n",  peek());
            break;
        }

        case 4:
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
