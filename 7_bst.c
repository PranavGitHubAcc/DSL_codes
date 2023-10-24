#include <stdio.h>
#include <stdlib.h>

struct BTnode
{
    int data;
    struct BTnode *left;
    struct BTnode *right;
};

struct BTnode *createNode()
{
    struct BTnode *newNode = malloc(sizeof(struct BTnode));
    printf("Enter data: ");
    scanf("%d", &newNode->data);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(struct BTnode **root, struct BTnode *node)
{
    if (*root == NULL)
    {
        *root = node;
    }
    else
    {
        if (node->data < (*root)->data)
        {
            insert(&((*root)->left), node);
        }
        else if (node->data > (*root)->data)
        {
            insert(&((*root)->right), node);
        }
    }
}

void inorder(struct BTnode *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void preorder(struct BTnode *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct BTnode *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

struct BTnode *search(struct BTnode *root, int key)
{
    if (root == NULL || root->data == key)
        return root;

    if (root->data < key)
        return search(root->right, key);

    return search(root->left, key);
}

struct BTnode *findMinValueNode(struct BTnode *node)
{
    struct BTnode *current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

struct BTnode *deleteNode(struct BTnode *root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            struct BTnode *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct BTnode *temp = root->left;
            free(root);
            return temp;
        }

        struct BTnode *temp = findMinValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

int main()
{
    int num;
    struct BTnode *root = NULL, *node;

    printf("Enter the number of nodes you want: ");
    scanf("%d", &num);
    printf("Enter the nodes data:\n");

    while (num != 0)
    {
        node = createNode();
        insert(&root, node);
        num--;
    }

    printf("\nInorder traversal: ");
    inorder(root);
    printf("\n");

    int searchKey;
    printf("Enter the value to search for: ");
    scanf("%d", &searchKey);

    struct BTnode *searchResult = search(root, searchKey);
    if (searchResult)
    {
        printf("Value %d found in the tree.\n", searchKey);
    }
    else
    {
        printf("Value %d not found in the tree.\n", searchKey);
    }

    int deleteKey;
    printf("Enter the value to delete: ");
    scanf("%d", &deleteKey);

    root = deleteNode(root, deleteKey);

    printf("Inorder traversal after deleting %d: ", deleteKey);
    inorder(root);
    printf("\n");

    return 0;
}
