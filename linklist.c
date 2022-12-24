#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

struct Node *createNode()
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

void insertAtEnd(struct Node **ptr, int key)
{
    struct Node *newNode = createNode();

    newNode->data = key;
    newNode->link = NULL;
    struct Node *temp;

    if (*ptr == NULL)
    {
        *ptr = newNode;
    }
    else
    {

        temp = *ptr;

        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = newNode;
    }
}

void insertAtBeginning(struct Node **ptr, int key)
{
    struct Node *newNode = createNode();

    newNode->data = key;
    newNode->link = NULL;

    if (*ptr == NULL)
    {
        *ptr = newNode;
    }
    else
    {

        newNode->link = *ptr;
        *ptr = newNode;
    }
}

int deleteFirstNode(struct Node **ptr)
{
    if (ptr == NULL)
    {
        printf("Empty");
    }
    else
    {
        int key;
        struct Node *temp;
        temp = *ptr;
        *ptr = temp->link;
        key = temp->data;
        free(temp);
        return key;
    }
}

int deleteLastNode(struct Node **ptr)
{
    int key;
    struct Node *temp;
    temp = *ptr;

    if (*ptr == NULL)
    {
        printf("Empty");
    }
    else if (temp->link == NULL)
    {
        key = temp->data;
        free(temp);
    }
    else
    {

        while (temp->link->link != NULL)
        {
            temp = temp->link;
        }
        key = temp->data;
        free(temp->link);
        temp->link = NULL;
    }
    return key;
}

void insertAtPos(struct Node **ptr, int key, int pos, int len)
{
    if (pos < 1 || pos > len)
    {
        printf("Postion Not Valid");
    }
    else
    {
        struct Node *newNode = createNode();

        newNode->data = key;
        newNode->link = NULL;
        struct Node *temp;

        if (*ptr == NULL)
        {
            *ptr = newNode;
        }
        else if (pos == 1)
        {
            newNode->link = *ptr;
            *ptr = newNode;
        }
        else
        {

            temp = *ptr;
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

int deleteAtPos(struct Node **ptr, int pos, int len) // error
{
    if (pos < 1 || pos > len)
    {
        printf("Postion Not Valid");
    }
    else
    {
        int key;
        struct Node *temp;

        if (ptr == NULL)
        {
            printf("Empty");
        }
        else if (pos == 1)
        {
            temp = *ptr;
            *ptr = temp->link;
            key = temp->data;
            free(temp);
        }
        else
        {

            temp = *ptr;
            int indx = 1;
            while (indx != pos - 1)
            {
                temp = temp->link;
                indx++;
            }
            key = temp->link->data;
            temp->link = temp->link->link;
            free(temp);
        }
        return key;
    }
}

int search(struct Node *ptr, int searchKey)
{
    if (ptr == NULL)
    {
        printf("Searching is failed \n");
    }
    else
    {
        struct Node *temp;
        temp = ptr;
        int indx = 0;
        while (temp != NULL)
        {
            indx++;
            if (searchKey == temp->data)
            {
                return indx;
            }
            temp = temp->link;
        }

        return -1;
    }
}

void reverse(struct Node **ptr)
{
    struct Node *rev, *ptr1, *ptr2;
    rev = *ptr;
    ptr1 = rev->link;
    ptr2 = ptr1->link;
    ptr1->link = rev;
    rev->link = NULL;
    while (ptr2 != NULL)
    {
        rev = ptr1;
        ptr1 = ptr2;
        ptr2 = ptr1->link;
        ptr1->link = rev;
    }
    *ptr = ptr1;
}

void update(struct Node **ptr, int ele, int key)
{
    if (ptr == NULL)
    {
        printf("Searching is failed \n");
    }
    else
    {
        int tempkey;
        struct Node *temp;
        temp = *ptr;

        while (temp != NULL)
        {

            if (key == temp->data)
            {
                tempkey = temp->data;
                temp->data = ele;
                return;
            }
            temp = temp->link;
        }
    }
}

void display(struct Node *ptr)
{
    if (ptr == NULL)
    {
        printf("Empty");
    }
    else
    {
        while (ptr != NULL)
        {
            printf("%d->", ptr->data);
            ptr = ptr->link;
        }
    }
}

int length(struct Node *ptr)
{
    int c = 0;
    if (ptr == NULL)
    {
        printf("Empty");
    }
    else
    {

        while (ptr != NULL)
        {
            c++;
            ptr = ptr->link;
        }
        return c;
    }
}

int main()
{
    struct Node *head = NULL;
    while (1)
    {
        int ch;
        printf("\n");
        printf("Enter 1 To insert the Element at End. \n");
        printf("Enter 2 To insert the Element at Beginning. \n");
        printf("Enter 3 To Display. \n");
        printf("Enter 4 To check the length of Linkedlist. \n");
        printf("Enter 5 To delete first node and get the value. \n");
        printf("Enter 6 To delete last node and get the value. \n");
        printf("Enter 7 To insert the Element at any position. \n");
        printf("Enter 8 To delete any node and get the value. \n");
        printf("Enter 9 To Search the Key \n");
        printf("Enter 10 To Reverse the linkedlist \n");
        printf("Enter 11 To Update data in Linkedlist \n");
        printf("Enter 12 To Exit \n");
        printf("\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            int key;
            printf("Enter the Key \n");
            scanf("%d", &key);
            insertAtEnd(&head, key);
            break;
        }
        case 2:
        {
            int key;
            printf("Enter the Key \n");
            scanf("%d", &key);
            insertAtBeginning(&head, key);
            break;
        }
        case 3:
        {
            printf("\nLINKEDLIST:\n");
            display(head);

            printf("\n");
            break;
        }
        case 4:
        {

            int c = length(head);
            printf("Length of linkedlist is %d", c);
            printf("\n");
            break;
        }
        case 5:
        {
            printf("Value at deleted Node is %d \n", deleteFirstNode(&head));
            break;
        }
        case 6:
        {
            printf("Value at deleted Node is %d \n", deleteLastNode(&head));
            break;
        }
        case 7:
        {
            int key, pos;
            printf("Enter the Key and Postion \n");
            scanf("%d %d", &key, &pos);
            int len = length(head);
            insertAtPos(&head, key, pos, len);
            break;
        }
        case 8:
        {
            int pos;
            printf("Enter the Postion \n");
            scanf("%d", &pos);
            int len = length(head);
            printf("Value at deleted Node is %d \n", deleteAtPos(&head, pos, len));
            break;
        }
        case 9:
        {
            int key;
            printf("Enter Element To search \n");
            scanf("%d", &key);
            int indx = search(head, key);
            if (indx > 0)
                printf("%d at %d position\n", key, indx);
            else
                printf("Element is not present in linklisted\n");

            break;
        }
        case 10:
        {
            reverse(&head);
            printf("Linkedlist is Reversed\n");
            break;
        }
        case 11:
        {
            int elm, key;
            printf("Enter the element to update and element with to update \n");
            scanf("%d %d", &key, &elm);
            update(&head, elm, key);
            printf("Element %d is Update with %d\n", key, elm);
            break;
        }
        case 12:
        {
            exit(1);
            break;
        }
        }
    }
    return 0;
}