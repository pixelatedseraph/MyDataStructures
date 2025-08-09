#include <stdio.h>
#include <stdlib.h>

// define a node struct
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// insert a new node at start
void InsertAtHead(Node **head, int data)
{
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("sorry memory allocation failed ,duh!");
        exit(1);
    }
    newNode->data = data;  // initalize with some data
    newNode->next = *head; // link the node with head node
    *head = newNode;       // update head to new node as head node
}

// print the whole list
void PrintLinkedList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("Null \n");
}

// free all nodes to avoid memory leaks
void FreeList(Node *head)
{
    Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}
// now main func to implement this stuff
int main()
{
    Node *head = NULL;
    InsertAtHead(&head, 5);
    InsertAtHead(&head, 10);
    InsertAtHead(&head, 15);
    InsertAtHead(&head, 20);
    PrintLinkedList(head);
    return 0;
}