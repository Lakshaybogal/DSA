#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

struct Node *head = NULL;
struct Node *tail = NULL;

struct Node *CreateNode()
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Node Created\n");
    return newNode;
}

void insertAtEnd(int key)
{
    struct Node *newNode = CreateNode();
    newNode->data = key;

    if (head == NULL)
    {
        head = newNode;
        newNode->link = head;
        tail = head;
    }
    else
    {
        tail->link = newNode;
        newNode->link = head;
        tail = newNode;
    }
}

void insertAtBeginning(int key)
{
    struct Node *newNode = CreateNode();
    newNode->data = key;

    if (head == NULL)
    {
        head = newNode;
        newNode->link = head;
        tail = head;
    }
    else
    {
        newNode->link = head;
        head = newNode;
        tail->link = head;
    }
}

int deleteFirstNode()
{
    if (head == NULL)
    {
        printf("Empty");
    }

    else
    {
        int key;

        if (head == tail)
        {
            key = head->data;
            head = NULL;
            tail = NULL;
        }
        else
        {
            struct Node *temp;
            temp = head;
            key = head->data;
            head = head->link;
            tail->link = head;
            free(temp);
        }
        return key;
    }
}

int deleteLastNode()
{

    if (head == NULL)
    {
        printf("Empty");
    }
    else
    {
        int key;

        if (head->link == head)
        {
            key = head->data;
            head = NULL;
        }
        else
        {
            struct Node *temp;
            temp = tail;
            key = temp->data;
            free(temp);
            temp->link = head;
        }
        return key;
    }
}

void insertAtPos(int key, int pos, int len)
{
    if (pos < 1 || pos > len)
    {
        printf("Postion Not Valid");
    }
    else
    {
        struct Node *newNode = CreateNode();
        newNode->data = key;
        if (head == NULL)
        {
            head = newNode;
            newNode->link = head;
            tail = head;
        }
        else if (head == head->link)
        {
            head = newNode;
            newNode->link = head;
            tail = head;
        }
        else
        {
            if (pos == 1)
            {

                newNode->link = head;
                head = newNode;
                tail->link = head;
            }
            else if (pos == len)
            {
                tail->link = newNode;
                newNode->link = head;
                tail = newNode;
            }
            else
            {
                struct Node* temp;
                temp = head;
                int indx = 1;
                while (indx != pos - 1)
                {
                    temp = temp->link;
                    indx++;
                }
                newNode->link = temp->link;
                temp->link = newNode;
            }
        }
    }
}

int deleteAtPos(int pos, int len)
{
    if (pos < 1 || pos > len)
    {
        printf("Postion Not Valid");
    }
    else if (head == NULL)
    {
        printf("Empty");
    }
    else
    {
        int key;
        struct Node *temp;
        temp = head;
        if (head == head->link)
        {
            key = head->data;
            head = NULL;
        }
        else if (pos == 1)
        {
            key = head->data;
            head = head->link;
            tail->link = head;
            free(temp);
        }
        else if (pos == len)
        {
            struct Node *temp;
            temp = tail;
            key = temp->data;
            free(temp);
            temp->link = head;
        }
        else
        {
            int indx = 1;
            while (indx != pos - 1)
            {
                temp = temp->link;
                indx++;
            }
            struct Node *temp1;
            temp1 = temp->link;
            key = temp->link->data;
            temp->link = temp->link->link;
            free(temp1);
        }
        return key;
    }
}

int length()
{

    if (head == NULL)
    {
        printf("Empty");
    }
    else
    {
        int len = 0;
        struct Node *temp = head;
        do
        {
            len++;
            temp = temp->link;
        } while (head != temp);
        return len;
    }
}
void display()
{
    if (head == NULL)
    {
        printf("Empty");
    }
    else
    {
        struct Node *temp;
        temp = head;
        do
        {
            printf("%d->", temp->data);
            temp = temp->link;
        } while (temp != head);
    }
}

int main()
{

    while (1)
    {
        int ch;
        printf("\n");
        printf("Enter 1 To insert the Element at End. \n");
        printf("Enter 2 To insert the Element at Beginning. \n");
        printf("Enter 3 To delete first node and get the value. \n");
        printf("Enter 4 To delete last node and get the value. \n");
        printf("Enter 5 To insert the Element at any position. \n");
        printf("Enter 6 To delete any node and get the value. \n");
        printf("Enter 7 To Display. \n");
        printf("Enter 8 To check the length of Linkedlist. \n");
        printf("Enter 9 To Exit \n");
        printf("\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            int key;
            printf("Enter the Key \n");
            scanf("%d", &key);
            insertAtEnd(key);
            break;
        }
        case 2:
        {
            int key;
            printf("Enter the Key \n");
            scanf("%d", &key);
            insertAtBeginning(key);
            break;
        }
        case 3:
        {
            printf("Value at deleted Node is %d \n", deleteFirstNode());
            break;
        }
        case 4:
        {
            printf("Value at deleted Node is %d \n", deleteLastNode());
            break;
        }
        case 5:
        {

            int key, pos;
            printf("Enter the Key and Postion \n");
            scanf("%d %d", &key, &pos);
            int len = length();
            insertAtPos(key, pos, len);
            break;
        }
        case 6:
        {
            int pos;
            printf("Enter the Postion \n");
            scanf("%d", &pos);
            int len = length();
            printf("Value at deleted Node is %d \n", deleteAtPos(pos, len));
            break;
        }
        case 7:
        {
            printf("\nLINKEDLIST:\n");
            display();
            printf("\n");
            break;
        }
        case 8:
        {
            int len = length();
            printf("Length of linkedlist is %d", len);
            printf("\n");
            break;
        }
        case 9:
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
