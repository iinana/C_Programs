#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *prevNode;
    struct Node *nextNode;
    bool head;
    bool tail;
};

struct Node *CreateNode(int data);
struct Node *InsertNode(struct Node *prev, int data);
void DestroyNode(struct Node *destroy);
void PrintNodeFrom(struct Node *node);
int CountNode(struct Node *head);
bool HasNode(struct Node *head, int data);

int main()
{
    struct Node* Node1 = CreateNode(100);
    struct Node* Node2 = InsertNode(Node1, 200);
    struct Node* Node3 = InsertNode(Node2, 300);
    struct Node* Node4 = InsertNode(Node2, 400);

    PrintNodeFrom(Node1);
    printf("Number of Node : %d\n", CountNode(Node1));
    printf("any node has 100? : %s\n", (HasNode(Node1, 100) == true) ? "YES" : "NO");

    DestroyNode(Node1);
    printf("After Destroy-----------------------\n");
    PrintNodeFrom(Node2);
    printf("Number of Node : %d\n", CountNode(Node2));
    printf("any node has 100? : %s\n", (HasNode(Node2, 100) == true) ? "YES" : "NO");

    return 0;
}

struct Node *CreateNode(int data)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));

    new->data = data;
    new->prevNode = new;
    new->nextNode = new;
    new->head = true;
    new->tail = true;

    return new;
}

struct Node *InsertNode(struct Node *prev, int data)
{
    struct Node *new = CreateNode(data);

    if (prev)
    {
        struct Node *next = prev->nextNode;

        next->prevNode = new;
        new->nextNode = next;
        
        prev->nextNode = new;
        new->prevNode = prev;

        new->head = false;
    }

    if (new->nextNode->head == true) prev->tail = false;
    else new->tail = false;
    return new;
}

void DestroyNode(struct Node *destroy)
{
    struct Node *prev = destroy->prevNode;
    struct Node *next = destroy->nextNode;

    prev->nextNode = next;
    next->prevNode = prev;

    if (destroy->head == true) next->head = true;
    if (destroy->tail == true) prev->head = true;

    free(destroy);
}

void PrintNodeFrom(struct Node *node)
{
    do
    {
        printf("Data of Node : %d\n", node->data);
        node = node->nextNode;
    } while (node->head == false);
}

int CountNode(struct Node *head)
{
    int count = 0;
    do
    {
        count++;
        head = head->nextNode;
    } while (head->head == false);
    
    return count;
}

bool HasNode(struct Node *head, int data)
{
    do
    {
        if (head->data == data) return true;
        head = head->nextNode;
    } while (head->head == false);

    return false;
}