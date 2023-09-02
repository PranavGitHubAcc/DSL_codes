#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

void create(int number, struct node **head)
{
    if (number <= 0)
    {
        printf("Invalid.\n");
        return;
    }

    while (number--)
    {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter the value of new Node:  ");
        scanf("%d", &(newNode->data));
        newNode->prev = NULL;
        newNode->next = NULL;

        if (*head == NULL)
        {
            *head = newNode;
        }
        else
        {
            struct node *temp = *head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }
}

void add_start(struct node **head)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the value of the new node: ");
    scanf("%d", &(newNode->data));
    newNode->prev = NULL;

    if (*head == NULL)
    {
        newNode->next = NULL;
        *head = newNode;
    }
    else
    {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

void add_end(struct node **head)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the value of the new node: ");
    scanf("%d", &(newNode->data));
    newNode->next = NULL;

    if (*head == NULL)
    {
        newNode->prev = NULL;
        *head = newNode;
    }
    else
    {
        struct node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void add_random(struct node **head)
{
    if (*head == NULL)
    {
        printf("Empty list.\n");
        return;
    }

    printf("\nEnter the position at which you want to add the new node: ");
    int pos;
    scanf("%d", &pos);

    if (pos <= 0)
    {
        printf("Invalid position.\n");
        return;
    }

    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    printf("Enter the value of the new node: ");
    scanf("%d", &(newNode->data));
    newNode->prev = NULL;
    newNode->next = NULL;

    if (pos == 1)
    {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
        return;
    }

    struct node *temp = *head;
    int i;
    for (i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid position.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL)
    {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

void delete_start(struct node **head)
{
    if (*head == NULL)
    {
        printf("Empty List.\n");
        return;
    }

    struct node *temp = *head;
    *head = (*head)->next;
    if (*head != NULL)
    {
        (*head)->prev = NULL;
    }
    free(temp);
}

void delete_last(struct node **head)
{
    if (*head == NULL)
    {
        printf("Empty list.\n");
        return;
    }

    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }

    struct node *temp = *head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void reverse(struct node **head)
{
    if (*head == NULL)
    {
        printf("Empty list.\n");
        return;
    }

    struct node *current = *head;
    struct node *temp = NULL;
    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL)
    {
        *head = temp->prev;
    }
}

void concatenate(struct node **head, struct node **head2)
{
    if (*head == NULL)
    {
        *head = *head2;
        return;
    }

    if (*head2 != NULL)
    {
        struct node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = *head2;
        (*head2)->prev = temp;
    }
}

void display(struct node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int len, size;
    printf("Enter the size of the linked list: ");
    scanf("%d", &len);

    struct node *head = NULL;
    create(len, &head);

    int choice;
    while (1)
    {
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Add at the beginning\n");
        printf("2. Add at the end\n");
        printf("3. Add at a specific position\n");
        printf("4. Delete from the beginning\n");
        printf("5. Delete from the end\n");
        printf("6. Reverse the linked list\n");
        printf("7. Concatenate with another linked list\n");
        printf("8. Display\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            add_start(&head);
            break;
        case 2:
            add_end(&head);
            break;
        case 3:
            add_random(&head);
            break;
        case 4:
            delete_start(&head);
            break;
        case 5:
            delete_last(&head);
            break;
        case 6:
            reverse(&head);
            break;
        case 7:
            printf("Enter the size of the new linked list: ");
            scanf("%d", &size);

            struct node *head2 = NULL;
            create(size, &head2);
            concatenate(&head, &head2);
            break;
        case 8:
            display(head);
            break;
        case 9:
            exit(0);
        default:
            printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
