#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node *insertElement(struct Node *head, int data, int position)
{
    struct Node *newNode = createNode(data);

    if (position == 0)
    {
        if (head == NULL)
        {
            newNode->next = newNode; // Point to itself for the first node
            return newNode;
        }
        else
        {
            // Insert at the beginning
            newNode->next = head->next;
            head->next = newNode;
            return head;
        }
    }
    else
    {
        struct Node *current = head;
        for (int i = 0; i < position - 1; i++)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        return head;
    }
}

struct Node *deleteElement(struct Node *head, int position)
{
    if (head == NULL)
    {
        printf("List is empty. Cannot delete.\n");
        return head;
    }

    if (position == 0)
    {
        if (head->next == head)
        {
            // Only one element in the list
            free(head);
            return NULL;
        }
        else
        {
            // Delete the first element
            struct Node *temp = head->next;
            head->data = temp->data;
            head->next = temp->next;
            free(temp);
            return head;
        }
    }
    else
    {
        struct Node *current = head;
        for (int i = 0; i < position - 1; i++)
        {
            current = current->next;
        }
        struct Node *temp = current->next;
        current->next = temp->next;
        free(temp);
        return head;
    }
}

void displayCircularLinkedList(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *current = head;
    do
    {
        printf("%d-> ", current->data);
        current = current->next;
    } while (current->next != head);
    printf("%d ", current->data);
    printf("\n");
}

int main()
{
    struct Node *head = NULL;
    int n, data, choice, position;

    printf("Enter the number of elements to add initially: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        head = insertElement(head, data, i); // Insert at the end initially
    }

    do
    {
        printf("Circular Linked List Operations\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Display the elements\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data to insert: ");
            scanf("%d", &data);
            printf("Enter the position to insert: ");
            scanf("%d", &position);
            head = insertElement(head, data, position);
            break;
        case 2:
            printf("Enter the position to delete: ");
            scanf("%d", &position);
            head = deleteElement(head, position);
            break;
        case 3:
            displayCircularLinkedList(head);
            break;
        case 4:
            exit(1);
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    // Free memory before exiting
    while (head != NULL)
    {
        struct Node *temp = head->next;
        if (temp == head)
        {
            free(head);
            break;
        }
        free(head);
        head = temp;
    }

    return 0;
}