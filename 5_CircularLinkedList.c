#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void create(int number, struct node **head)
{
    if (number <= 0)
    {
        printf("Invalid.\n");
        return;
    }

    struct node *newNode, *temp;
    while (number--)
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter the value of new Node: ");
        scanf("%d", &(newNode->data));
        newNode->next = NULL;

        if (*head == NULL)
        {
            *head = newNode;
            (*head)->next = *head; 
        }
        else
        {
            temp = *head;
            while (temp->next != *head)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = *head;
        }
    }
}

void insert_start(struct node **head)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the value of the new node: ");
    scanf("%d", &(newNode->data));

    if (*head == NULL)
    {
        *head = newNode;
        (*head)->next = *head;
    }
    else
    {
        struct node *temp = *head;
        while (temp->next != *head)
        {
            temp = temp->next;
        }
        newNode->next = *head;
        temp->next = newNode;
        *head = newNode;
    }
}

void insert_end(struct node **head)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the value of the new node: ");
    scanf("%d", &(newNode->data));

    if (*head == NULL)
    {
        *head = newNode;
        (*head)->next = *head;
    }
    else
    {
        struct node *temp = *head;
        while (temp->next != *head)
        {
            temp = temp->next;
        }
        newNode->next = *head;
        temp->next = newNode;
    }
}

void insert_random(struct node **head)
{
    if (*head == NULL)
    {
        printf("Empty list.\n");
        return;
    }

    printf("\nEnter the position at which you want to insert the new node: ");
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
    newNode->next = NULL;

    if (pos == 1)
    {
        struct node *temp = *head;
        while (temp->next != *head)
        {
            temp = temp->next;
        }
        newNode->next = *head;
        temp->next = newNode;
        *head = newNode;
        return;
    }

    struct node *temp = *head;
    int i;
    for (i = 1; i < pos - 1; i++)
    {
        if (temp->next == *head)
        {
            printf("Invalid position.\n");
            free(newNode);
            return;
        }
        temp = temp->next;
    }

    newNode->next = temp->next;
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
    while (temp->next != *head)
    {
        temp = temp->next;
    }
    struct node *first = *head;
    temp->next = first->next;
    *head = first->next;
    free(first);
}

void delete_last(struct node **head)
{
    if (*head == NULL)
    {
        printf("Empty list.\n");
        return;
    }

    struct node *temp = *head;
    while (temp->next->next != *head)
    {
        temp = temp->next;
    }
    struct node *last = temp->next;
    temp->next = *head;
    free(last);
}

void delete_random(struct node **head)
{
    if (*head == NULL)
    {
        printf("Empty list.\n");
        return;
    }

    printf("Enter the position to delete: ");
    int pos;
    scanf("%d", &pos);

    if (pos <= 0)
    {
        printf("Invalid position.\n");
        return;
    }

    struct node *temp = *head;
    if (pos == 1)
    {
        while (temp->next != *head)
        {
            temp = temp->next;
        }
        struct node *nodeToDelete = *head;
        if (temp == *head)
        {
            *head = NULL;
        }
        else
        {
            *head = (*head)->next;
            temp->next = *head;
        }
        free(nodeToDelete);
    }
    else
    {
        int i;
        for (i = 1; i < pos - 1; i++)
        {
            if (temp->next == *head)
            {
                printf("Invalid position.\n");
                return;
            }
            temp = temp->next;
        }

        struct node *nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        free(nodeToDelete);
    }
}

void reverse(struct node **head)
{
    if (*head == NULL)
    {
        printf("Empty list.\n");
        return;
    }

    struct node *prev = NULL;
    struct node *current = *head;
    struct node *nextNode;

    do
    {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    } while (current != *head);

    *head = prev;
}

void concatenate(struct node **head1, struct node **head2)
{
    if (*head1 == NULL)
    {
        *head1 = *head2;
    }
    else if (*head2 != NULL)
    {
        struct node *temp1 = *head1;
        while (temp1->next != *head1)
        {
            temp1 = temp1->next;
        }
        struct node *temp2 = *head2;
        while (temp2->next != *head2)
        {
            temp2 = temp2->next;
        }
        temp1->next = *head2;
        temp2->next = *head1;
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
    do
    {
        printf("[%d]->", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("[head]\n");
}

int main()
{
    int len, size;
    printf("Enter the size of the circular linked list: ");
    scanf("%d", &len);

    struct node *head = NULL;
    create(len, &head);

    int choice;
    while (1)
    {
        printf("\n*********Circular Linked List Menu*********\n");
        printf("===============================================\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert at any random location\n");
        printf("4. Delete from the beginning\n");
        printf("5. Delete from the end\n");
        printf("6. Delete at specific location\n");
        printf("7. Reverse linked list\n");
        printf("8. Concatenate linked lists\n");
        printf("9. Display\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert_start(&head);
            break;
        case 2:
            insert_end(&head);
            break;
        case 3:
            insert_random(&head);
            break;
        case 4:
            delete_start(&head);
            break;
        case 5:
            delete_last(&head);
            break;
        case 6:
            delete_random(&head);
            break;
        case 7:
            reverse(&head);
            break;
        case 8:
            printf("Enter the size of the new circular linked list: ");
            scanf("%d", &size);

            struct node *head2 = NULL;
            create(size, &head2);
            concatenate(&head, &head2);
            break;
        case 9:
            display(head);
            break;
        case 10:
            exit(0);
        default:
            printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
