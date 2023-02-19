#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *CreateNode()
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Node Created\n");
    return newNode;
}

struct Node *insert(struct Node *root, int key)
{

    if (root == NULL)
    {
        root = CreateNode();
        root->data = key;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else
    {
        if (key < root->data)
        {
            root->left = insert(root->left, key);
        }
        else if (key > root->data)
        {
            root->right = insert(root->right, key);
        }
        return root;
    }
}

struct Node *delete(struct Node *root, int key)
{
    if (root == NULL)
    {
        printf("Tree is Empty");
        return NULL;
    }
    else if (key < root->data)
    {
        root->left = delete (root->left, key);
    }
    else if (key > root->data)
    {
        root->right = delete (root->right, key);
    }
    else
    {
        struct Node *temp;
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if (root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            temp = root->right;
            while (temp->left != NULL)
            {
                temp = temp->left;
            }
            root->data = temp->data;
            root->right = delete (root->right, temp->data);
        }
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
void postorder(struct Node *root)
{

    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
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

int height(struct Node *root)
{
    if (root == NULL)
        return 0;

    else
    {
        int left = height(root->left) + 1;
        int right = height(root->right) + 1;
        if (left >= right)
            return left;
        else
            return right;
    }
}
void levelorder(struct Node* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        atLevel(root, i);
}
 

void atLevel(struct Node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1) {
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
            int key;
            printf("Enter Number To Insert\n");
            scanf("%d", &key);
            root = insert(root, key);
            printf("\n");
            break;
        }
        case 2:
        {
            int key;
            printf("Enter Number To Delete\n");
            scanf("%d", &key);
            root = delete (root, key);
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
