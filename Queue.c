#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

struct queue
{
    int front;
    int rear;
    int arr[SIZE];
} queue;

void create(struct queue *q)
{
    q->front = q->rear = -1;
}

int isFull(struct queue *q)
{
    if (q->rear == SIZE - 1)
    {
        return 1;
    }
    else
        return 0;
}

int isEmpty(struct queue *q)
{
    if (q->front == -1 && q->rear == -1)
    {
        return 1;
    }
    else
        return 0;
}

void insert(struct queue *q, int data)
{
    if (isFull(q))
    {
        printf("!! Queue is Full !!");
    }
    else
    {
        if(q->front==-1)
        {
            q->front = 0;
        }
        q->rear++;
        q->arr[q->rear] = data;
    }
}

void delete(struct queue *q, int d)
{
    if (isEmpty(q))
    {
        printf("!! Queue is Empty !!");
    }
    else
    {
        while (d--)
        {
            q->front++;
        }
    }
}

void displayfront(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("!! Queue is Empty !!");
    }
    else
    {
        printf("First Element of Queue is %d \n", q->arr[q->front]);
    }
}

void displayrear(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("!! Queue is Empty !!");
    }
    else
    {
        printf("Last Element of Queue is %d \n", q->arr[q->rear]);
    }
}

void display(struct queue *q)
{
    for (int i = q->front; i <= q->rear; i++)
    {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int Input()
{
    int num;
    scanf("%d", &num);
    return num;
}

int main()
{
    struct queue *q;

    create(q);
    while (1)
    {
        int ch;
        printf("1.Insert element to queue \n");
        printf("2.Delete element from queue \n");
        printf("3.Display all elements of queue \n");
        printf("4.Quit \n");
        printf("Enter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            int n;
            printf("\nEnter no. of element to Insert: ");
            scanf("%d", &n);
            int ip;
            printf("\nEnter your Input: \n");
            for (int i = 0; i < n; i++)
            {
                ip = Input();
                insert(q, ip);
            }
        }
        break;
        case 2:
        {
            int d;
            printf("Enter number of element to delete: ");
            scanf("%d", &d);
            delete (q, d);
        }
        break;
        case 3:
        {
            displayfront(q);
            displayrear(q);
            printf("Queue is \n");
            display(q);
        }

            break;
        case 4:
            exit(1);
            break;

        default:
            break;
        }
    }


    return 0;
}
