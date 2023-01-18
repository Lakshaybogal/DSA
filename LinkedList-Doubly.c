#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *link;
    struct Node *prev;
};

struct Node *head = NULL;
struct Node *tail = NULL;

struct Node *CreateNode()
{

    struct Node *newNode = NULL;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("!! Allocation Failed !!");
    }
    else
    {
        printf("Node Created");
        return newNode;
    }
}

void insertAtBegining(int key)
{
    struct Node *newNode;
    newNode = CreateNode();
    if (newNode == NULL)
    {
        printf("!!Allocation is Failed!!\n");
    }
    else
    {
        newNode->data = key;
        newNode->link = NULL;
        newNode->prev = NULL;
        if (head == NULL)
        {
            head = newNode;
            tail = head;
        }
        else
        {
            head->prev = newNode;
            newNode->link = head;
            head = newNode;
        }
    }
}

void insertAtEnd(int key)
{
    struct Node *newNode;
    newNode = CreateNode();
    if (newNode == 0)
    {
        printf("!!Allocation is Failed!!\n");
    }
    else
    {
        newNode->data = key;
        newNode->link = NULL;
        newNode->prev = NULL;
        if (head == NULL)
        {
            newNode->prev = NULL;
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->prev = tail;
            tail->link = newNode;
            tail = newNode;
        }
    }
}

void insertAtPos(int key, int pos, int len)
{
    struct Node *newNode;
    newNode = CreateNode();
    if (newNode == NULL)
    {
        printf("!!Allocation is Failed!!\n");
    }
    else if (pos < 1 || pos > len)
    {
        printf("Position is Invalid!!\n");
    }
    else
    {
        newNode->data = key;
        newNode->link = NULL;
        newNode->prev = NULL;
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else if (pos == 1)
        {
            newNode->link = head;
            head->prev = newNode;
            head = newNode;
        }
        else
        {
            struct Node *temp;
            temp = head;
            int indx = 1;
            while (indx != pos - 1)
            {
                temp = temp->link;
                indx++;
            }
            newNode->prev = temp;
            newNode->link = temp->link;
            temp->link->prev = newNode;
            temp->link = newNode;
        }
    }
}

int deleteFirstNode()
{
    if (head == NULL)
    {
        return -1;
    }
    else
    {
        int key;
        key = head->data;
        struct Node *temp;
        if (head->link == NULL)
        {

            free(head);
            head = tail = NULL;
        }
        else
        {
            head = head->link;
            temp = head->prev;
            head->prev = NULL;
            free(temp);
        }
        return key;
    }
}

int deleteLastNode()
{
    if (head == NULL)
    {
        printf("Linked List is Empty!!\n");
    }
    else
    {
        int key;
        struct Node *temp;
        if (head->link == NULL)
        {
            key = head->data;
            temp = head;
            head = NULL;
            tail = head;
            free(temp);
        }
        else
        {
            key = tail->data;
            temp = tail;
            tail = temp->prev;
            tail->link = NULL;
            free(temp);
        }
        return key;
    }
}

int deleteAtPos(int pos,int len)
{
     if (head == NULL)
    {
        return -1;
    }
    else if(pos<1 || pos>len)
    {
        printf("Invalid Position\n");
    }
    else
    {
        int key;
        key = head->data;
        struct Node *temp;
        temp = head;
        if (head->link == NULL)
        {
            free(head);
            head = tail = NULL;
        }
        else if(pos==1)
        {
            head = head->link;
            temp = head->prev;
            head->prev = NULL;
            free(temp);
        }
        else{

            int indx=1;
            while(indx!=pos)
            {
                temp = temp->link;
                indx++;
            }
            key = temp->data;
            temp->prev->link=temp->link;
            temp->link->prev = temp->prev;
            free(temp);
        }
        return key;
    }
}
void display()
{
    if (head == NULL)
    {
        printf("Empty!!\n");
    }
    else
    {
        struct Node *temp;
        temp = head;
        while (temp != NULL)
        {
            printf("%d<->", temp->data);
            temp = temp->link;
        }
    }
}

void displyheadtail()
{
    printf("%d,%d", head->data, tail->data);
}
int length()
{
    if (head == NULL)
    {
        return -1;
    }
    else
    {
        int len = 0;
        struct Node *temp;
        temp = head;
        while (temp != NULL)
        {
            len++;
            temp = temp->link;
        }
        return len;
    }
}

int main()
{
    while (1)
    {
        printf("\n");
        printf("Enter 1 to insert at begining in Doubly LinkedList\n");
        printf("Enter 2 to insert at end in Doubly LinkedList\n");
        printf("Enter 3 to insert at any Position in Doubly LinkedList\n");
        printf("Enter 4 to Delete first element in Doubly LinkedList\n");
        printf("Enter 5 to Delete last element in Doubly LinkedList\n");
        printf("Enter 6 to Delete any element in Doubly LinkedList\n");
        printf("Enter 7 to display Doubly LinkedList\n");
        printf("Enter 8 to display Head and Tail\n");
        printf("Enter 9 to get length Doubly LinkedList\n");
        printf("Enter 10 to exit\n");
        int num;
        scanf("%d", &num);
        printf("\n");
        switch (num)
        {
        case 1:
        {
            int key;
            printf("Enter the Number to insert at begining\n");
            scanf("%d", &key);
            insertAtBegining(key);
            printf("\n");
            break;
        }

        case 2:
        {
            int key;
            printf("Enter the Number to insert at End\n");
            scanf("%d", &key);
            insertAtEnd(key);
            printf("\n");
            break;
        }

        case 3:
        {
            int key, pos;
            int len = length();
            printf("Enter the Number and Positon to insert \n");
            scanf("%d %d", &key, &pos);
            insertAtPos(key, pos, len);
            printf("\n");
            break;
        }
        case 4:
        {
            int d;
            d = deleteFirstNode();
            if(d == -1)
            printf("Linked List is Empty!!\n");
            else
            printf("Deleted Element is %d", d);
            printf("\n");
            break;
        }
        case 5:
        {
            int key;
            key = deleteLastNode();
            if(key == -1)
            printf("Linked List is Empty!!\n");
            else
            printf("Deleted Element is %d", key);
            printf("\n");
            break;
        }
        case 6:
        {
            int key,pos,len;
            len = length();
            printf("Enter the Node Position to Delete : ");
            scanf("%d",&pos);
            key = deleteAtPos(pos,len);
            if(key == -1)
            printf("Linked List is Empty!!\n");
            else
            printf("Deleted Element is %d", key);
            printf("\n");
            break;
            break;
        }
        case 7:
        {
            printf("Doubly LinkedList is : ");
            display();
            printf("\n");

            break;
        }
        case 8:
        {
            printf("Head and Tail of LinkList are : ");
            displyheadtail();
            break;
        }
        case 9:
        {
            int len = length();
            if (len == -1)
                printf("!!LinkedList is Empty!!");
            else
                printf("Length of Doubly LinkedList is : %d", len);
            printf("\n");
            break;
        }
        case 10:
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
