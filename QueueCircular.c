#include <stdio.h>
#define SIZE 5

struct Queue
{
    int front;
    int rear;
    int queue[SIZE];
};

void create(struct Queue *q)
{
    q->front = q->rear = -1;
}

int isFull(struct Queue *q)
{
    if ((q->front == q->rear + 1) || (q->front == 0 && q->rear == SIZE - 1))
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct Queue *q)
{
    if (q->front == -1)
    {
        return 1;
    }
    return 0;
}

void Enqueue(struct Queue *q, int data)
{
    if (isFull(q))
    {
        printf("!! Queue is full !!");
        return;
    }
    else
    {
        if (q->front == -1)
        {
            q->front = 0;
        }
        q->rear = (q->rear + 1)%SIZE;
        q->queue[q->rear] = data;
    }
}

int Dequeue(struct Queue *q)
{
    if (isEmpty(q))
    {

        return -1;
    }
    else
    {
        int data = q->queue[q->front];
        if (q->rear == q->front)
        {
            q->front = q->rear = -1;
        }
        else
        {
            q->front = (q->front + 1) % SIZE;
        }
        return data;
    }
}

void display(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("!! Queue is Empty !!");
        return;
    }
    else
    {
        for (int i = q->front; i != q->rear; i = (i + 1) % SIZE)
        {
            printf("|%d", q->queue[i]);
        }
        printf("|%d|", q->queue[q->rear]);
    }
}

int main()
{
    struct Queue *q;
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
            Enqueue(q, n);
            break;
        }
        
        case 2:
        {
            int d = Dequeue(q);
            if (d == -1)
            {
                printf("!! Queue is Empty !!");
            }
            else
            {
                printf("Deleted Element is %d ", d);
            }
            break;
        }
       
        case 3:
        {
            printf("Queue is \n");
            display(q);
            printf("\n");
             break;
        }
        case 4:
            exit(1);
            break;

        default:
            break;
        }
    }
    return 0;
}
