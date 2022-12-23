#include <stdio.h>
#include <stdlib.h>
struct Node
{
  int data;
  struct Node *link;
};

struct Node *
createNode ()
{
  struct Node *newNode;
  newNode = (struct Node *) malloc (sizeof (struct Node));
  if (newNode == NULL)
    {
      printf ("Allocation Failed\n");
    }
  else
    {
      printf ("Node Created\n");
      return newNode;
    }
}

void
insertAtEnd (struct Node **ptr, int key)
{
  struct Node *newNode = createNode ();
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

void
insertAtBeginning (struct Node **ptr, int key)
{
  struct Node *newNode = createNode ();
  newNode->data = key;
  newNode->link = NULL;
  struct Node *temp;

  if (*ptr == NULL)
    {
      *ptr = newNode;
    }
  else
    {


      newNode->link = *ptr;
      *ptr = newNode;
      temp->link = newNode;
    }
}

int
deleteFirstNode (struct Node **ptr)
{
  if (ptr == NULL)
    {
      printf ("Empty");

    }
  else
    {
      int key;
      struct Node *temp;
      temp = *ptr;
      *ptr = temp->link;
      key = temp->data;
      free (temp);
      return key;

    }
}

void
display (struct Node *ptr)
{
  if (ptr == NULL)
    {
      printf ("Empty");
    }
  else
    {
      while (ptr != NULL)
	{
	  printf ("%d->", ptr->data);
	  ptr = ptr->link;
	}

    }
}

void
length (struct Node *ptr)
{
  int c = 0;
  if (ptr == NULL)
    {
      printf ("Empty");
    }
  else
    {

      while (ptr != NULL)
	{
	  c++;
	  ptr = ptr->link;
	}
      printf ("Length of linkedlist is %d", c);

    }
}

int
main ()
{
  struct Node *head = NULL;
  while (1)
    {
      int ch;
      printf ("Enter 1 To insert the value. \n");
      printf ("Enter 2 To insert the value at Beginning. \n");
      printf ("Enter 3 To Display. \n");
      printf ("Enter 4 To check the length of Linkedlist. \n");
      printf ("Enter 5 To delete first node and get the value. \n");
      scanf ("%d", &ch);
      switch (ch)
	{
	case 1:
	  {
	    int key;
	    printf ("Enter the Key \n");
	    scanf ("%d", &key);
	    insertAtEnd (&head, key);
	    break;
	  }
	case 2:
	  {
	    int key;
	    printf ("Enter the Key \n");
	    scanf ("%d", &key);
	    insertAtBeginning (&head, key);
	    break;
	  }
	case 3:
	  {
	    printf ("\nLINKEDLIST:\n");
	    display (head);

	    printf ("\n");
	    break;
	  }
	case 4:
	  {

	    length (head);

	    printf ("\n");
	    break;
	  }
	case 5:
	  {
	    printf ("Value at deleted Node is %d", deleteFirstNode (&head));
	    break;
	  }
	case 12:
	  {
	    exit (1);
	  }
	}
    }
  return 0;
}
