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

// now lets write a function which inserts at tail ,meaning insertion at end
void InsertAtEnd(Node **head, int data)
{
    // allocate a new node
    Node *NewNode = malloc(sizeof(Node));
    if (NewNode == NULL)
    {
        printf("sorry memory allocation failed ,duh!");
    }
    NewNode->data = data; // initalize the node data
    NewNode->next = NULL;
    if (*head == NULL) // check if there are no nodes and if there happens to be none then you are supposed to point head to NewNode
    {
        *head = NewNode; // NewNode becomes head if no other node is present
        return;
    }
    Node *temp = *head; // making a temp node to iterate over the Nodes and check the node which has NULL in its "next" field
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = NewNode;
}

// lets write a function that deletes a node by value

void Delete(Node **head, int val)
{
    Node *temp = *head;
    Node *prev = NULL;
    while (temp != NULL && temp->data != val)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    if (prev == NULL)
    {
        *head = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }
    free(temp);
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
    InsertAtEnd(&head, 10);
    InsertAtEnd(&head, 15);
    InsertAtEnd(&head, 20);
    Delete(&head, 15);
    // InsertAtEnd(&head, 15);
    // InsertAtEnd(&head, 20);
    PrintLinkedList(head);
    FreeList(head);
    return 0;
}
