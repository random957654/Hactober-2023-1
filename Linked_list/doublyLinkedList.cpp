// doublylinkedlist implementation of array

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct LinkedList
{
    Node *head;
    int size;
} LinkedList;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

LinkedList *createLinkedList()
{
    LinkedList *newLinkedList = (LinkedList *)malloc(sizeof(LinkedList));
    newLinkedList->head = NULL;
    newLinkedList->size = 0;
    return newLinkedList;
}

// insert at the end
void insertAtTheEnd(LinkedList *list, int data)
{
    Node *newNode = createNode(data);
    Node *current = list->head;
    if (list->head == NULL)
    {
        list->head = newNode;
        return;
    }
    else if (list->head->next == NULL)
    {
        newNode->prev = list->head;
        list->head->next = newNode;
        return;
    }
    while (current->next != NULL)
    {
        current = current->next;
    }
    newNode->prev = current;
    current->next = newNode;
    list->size++;
}

// insert at the beginning
void insertAtTheBeginning(LinkedList *list, int data)
{
    Node *newNode = createNode(data);
    if (list->head == NULL)
    {
        list->head = newNode;
        return;
    }
    newNode->next = list->head;
    list->head->prev = newNode;
    list->head = newNode;
    list->size++;
}

// insert at the given index
void insertAtTheGivenIndex(LinkedList *list, int data, int index)
{
    Node *newNode = createNode(data);
    Node *current = list->head;
    if (index == 0)
    {
        insertAtTheBeginning(list, data);
        return;
    }
    // else if (index == list->size+1)
    // {
    //     insertAtTheEnd(list, data);
    //     return;
    // }
    else if (index > list->size)
    {
        printf("Index out of bound\n");
        return;
    }
    for (int i = 0; i < index - 1; i++)
    {
        current = current->next;
    }
    newNode->next = current->next;
    newNode->prev = current;
    current->next->prev = newNode;
    current->next = newNode;
    list->size++;
}

// delete at the beginning
void deleteAtTheBeginning(LinkedList *list)
{
    if (list->head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    Node *temp = list->head;
    list->head = list->head->next;
    list->head->prev = NULL;
    free(temp);
    list->size--;
}

// delete at the end
void deleteAtTheEnd(LinkedList *list)
{
    if (list->head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    Node *current = list->head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->prev->next = NULL;
    free(current);
    list->size--;
}

// delete at the given index
void deleteAtTheGivenIndex(LinkedList *list, int index)
{
    if (list->head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    else if (index == 0)
    {
        deleteAtTheBeginning(list);
        return;
    }
    else if (index == list->size)
    {
        deleteAtTheEnd(list);
        return;
    }
    else if (index > list->size)
    {
        printf("Index out of bound\n");
        return;
    }
    Node *current = list->head;
    for (int i = 0; i < index; i++)
    {
        current = current->next; // index 1
    }
    // Node *temp = current->next;//index 1
    current->prev->next = current->next; // index 0->next=index 2
    current->next->prev = current->prev; // index 2->prev=index 0
    free(current);                       // index 1
    list->size--;
}

// print the list
void printList(LinkedList *list)
{
    Node *current = list->head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    LinkedList *list = createLinkedList();
    int choice, data, index;
    printf("Doubly Linked List:\n");
    do
    {
        printf("1. Insert at the end\n");
        printf("2. Insert at the beginning\n");
        printf("3. Insert at the given index\n");
        printf("4. Delete at the beginning\n");
        printf("5. Delete at the end\n");
        printf("6. Delete at the given index\n");
        printf("7. Print the list\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            insertAtTheEnd(list, data);
            break;

        case 2:
            printf("Enter data: ");
            scanf("%d", &data);
            insertAtTheBeginning(list, data);
            break;

        case 3:
            printf("Enter data: ");
            scanf("%d", &data);
            printf("Enter index: ");
            scanf("%d", &index);
            insertAtTheGivenIndex(list, data, index);
            break;

        case 4:
            deleteAtTheBeginning(list);
            break;

        case 5:
            deleteAtTheEnd(list);
            break;

        case 6:
            printf("Enter index: ");
            scanf("%d", &index);
            deleteAtTheGivenIndex(list, index);
            break;

        case 7:
            printf("List: ");
            printList(list);
            break;

        case 8:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice\n");
        }
        printList(list);
        printf("\n");

    } while (choice != 8);

    return 0;
}