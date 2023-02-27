
#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	int height;
};

int height(struct Node *root)
{
	if (root == NULL)
		return 0;
	return root->height;
}

int max(int a, int b)
{
	return (a > b) ? a : b;
}

struct Node *newNode(int data)
{
	struct Node *root = (struct Node *)
		malloc(sizeof(struct Node));
	root->data = data;
	root->left = NULL;
	root->right = NULL;
	root->height = 1;
	return (root);
}

struct Node *rightRotate(struct Node *root)
{
	struct Node *newRoot = root->left;
	struct Node *T2 = newRoot->right;

	newRoot->right = root;
	root->left = T2;

	root->height = max(height(root->left),
					   height(root->right)) +
				   1;
	newRoot->height = max(height(newRoot->left),
						  height(newRoot->right)) +
					  1;

	return newRoot;
}

struct Node *leftRotate(struct Node *newRoot)
{
	struct Node *root = newRoot->right;
	struct Node *T2 = root->left;

	root->left = newRoot;
	newRoot->right = T2;

	newRoot->height = max(height(newRoot->left),
						  height(newRoot->right)) +
					  1;
	root->height = max(height(root->left),
					   height(root->right)) +
				   1;

	return root;
}

int getBalance(struct Node *root)
{
	if (root == NULL)
		return 0;
	return height(root->left) - height(root->right);
}

struct Node *insert(struct Node *root, int data)
{

	if (root == NULL)
		return (newNode(data));

	if (data < root->data)
		root->left = insert(root->left, data);
	else if (data > root->data)
		root->right = insert(root->right, data);
	else
		return root;

	root->height = 1 + max(height(root->left),
						   height(root->right));

	int balance = getBalance(root);

	if (balance > 1 && data < root->left->data)
		return rightRotate(root);

	if (balance < -1 && data > root->right->data)
		return leftRotate(root);

	if (balance > 1 && data > root->left->data)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	if (balance < -1 && data < root->right->data)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}

struct Node *delete(struct Node *root, int data)
{

	if (root == NULL)
		return root;

	if (data < root->data)
		root->left = delete (root->left, data);

	else if (data > root->data)
		root->right = delete (root->right, data);

	else
	{

		if ((root->left == NULL) || (root->right == NULL))
		{
			struct Node *temp = root->left ? root->left : root->right;

			if (temp == NULL)
			{
				temp = root;
				root = NULL;
			}
			else
				*root = *temp;
			free(temp);
		}
		else
		{

			struct Node *temp ;

			temp = root->right;
            while (temp->left != NULL)
            {
                temp = temp->left;
            }
            root->data = temp->data;
            root->right = delete (root->right, temp->data);
			
		}
	}

	if (root == NULL)
		return root;

	root->height = 1 + max(height(root->left),
						   height(root->right));

	int balance = getBalance(root);

	if (balance > 1 && getBalance(root->left) >= 0)
		return rightRotate(root);

	if (balance > 1 && getBalance(root->left) < 0)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	if (balance < -1 && getBalance(root->right) <= 0)
		return leftRotate(root);

	if (balance < -1 && getBalance(root->right) > 0)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}

void preorder(struct Node *root)
{
	if (root != NULL)
	{
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(struct Node *root)
{

	if (root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ", root->data);
	}
}

void inorder(struct Node *root)
{

	if (root != NULL)
	{
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

int countNode(struct Node *root)
{
	if (root == NULL)
		return 0;
	else
		return countNode(root->left) + countNode(root->right) + 1;
}

int countNonLeafNode(struct Node *root)
{
	if (root == NULL)
		return 0;
	else if (root->left == NULL && root->right == NULL)
	{
		return 0;
	}
	else
		return countNonLeafNode(root->left) + countNonLeafNode(root->right) + 1;
}
int countLeafNode(struct Node *root)
{
	if (root == NULL)
		return 0;
	else if (root->left == NULL && root->right == NULL)
	{
		return +1;
	}
	else
		return countLeafNode(root->left) + countLeafNode(root->right);
}

void levelorder(struct Node *root)
{
	int h = height(root);
	int i;
	for (i = 1; i <= h; i++)
		atLevel(root, i);
}

void atLevel(struct Node *root, int level)
{
	if (root == NULL)
		return;
	if (level == 1)
		printf("%d ", root->data);
	else if (level > 1)
	{
		atLevel(root->left, level - 1);
		atLevel(root->right, level - 1);
	}
}

int main()
{
	struct Node *root = NULL;
	while (1)
	{
		int ch;
		printf("\n");
		printf("1.Insertion in tree\n");
		printf("2.Delection in tree\n");
		printf("3.Inorder Display\n");
		printf("4.Preorder Display\n");
		printf("5.Postorder Display\n");
		printf("6.Levelorder Display\n");
		printf("7.Count Nodes\n");
		printf("8.Count Non leaf Nodes\n");
		printf("9.Count leaf Nodes\n");
		printf("10.Height of the tree\n");
		printf("0.Exit\n");
		scanf("%d", &ch);
		printf("\n");
		switch (ch)
		{
		case 1:
		{
			int data;
			printf("Enter Number To Insert\n");
			scanf("%d", &data);
			root = insert(root, data);
			printf("\n");
			break;
		}
		case 2:
		{
			int data;
			printf("Enter Number To Delete\n");
			scanf("%d", &data);
			root = delete (root, data);
			printf("\n");
			break;
		}
		case 3:
		{
			printf("Inorder Tree\n");
			inorder(root);
			printf("\n");
			break;
		}
		case 4:
		{
			printf("Preorder Tree\n");
			preorder(root);
			printf("\n");
			break;
		}
		case 5:
		{
			printf("Postorder Tree\n");
			postorder(root);
			printf("\n");
			break;
		}
		case 6:
		{
			printf("Levelorder Tree\n");
			levelorder(root);
			printf("\n");
			break;
		}
		case 7:
		{
			printf("Number Of Nodes are %d", countNode(root));

			printf("\n");
			break;
		}
		case 8:
		{
			printf("Number Of Non leaf Nodes are %d", countNonLeafNode(root));

			printf("\n");
			break;
		}
		case 9:
		{
			printf("Number Of leaf Nodes are %d", countLeafNode(root));

			printf("\n");
			break;
		}
		case 10:
		{
			printf("Height of the tree is %d", height(root));
			printf("\n");
			break;
		}
		case 0:
		{
			return 0;
		}
		}
	}

	return 0;
}
