#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node* nextNode;
};

struct Node* CreateNode(int data);
struct Node* InsertNode(struct Node *curr, int data);
void DestroyNode(struct Node *head, struct Node *destroy);
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

    DestroyNode(Node1, Node1);
    printf("After Destroy-----------------------\n");
    PrintNodeFrom(Node2);
    printf("Number of Node : %d\n", CountNode(Node2));
    printf("any node has 100? : %s\n", (HasNode(Node2, 100) == true) ? "YES" : "NO");

    return 0;
}


struct Node* CreateNode(int data)
{
    struct Node* newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->nextNode = NULL;

    return newnode;
}

struct Node* InsertNode(struct Node *pre, int data)
{
    struct Node* after = pre->nextNode;
    struct Node* new = CreateNode(data);
    new->nextNode = after;
    pre->nextNode = new; 
    return new;
}

void DestroyNode(struct Node *head, struct Node *destroy)
{
    if (destroy == head)
    {
        free(destroy);
        return;
    }

    struct Node *curr = head;
    while (curr->nextNode)
    {
        if (curr->nextNode == destroy) break;
        curr = curr->nextNode;
    }
    curr->nextNode = destroy->nextNode;
    free(destroy);
}

void PrintNodeFrom(struct Node *node)
{
    while(node)
    {
        printf("Data of Node : %d\n", node->data);
        node = node->nextNode;
    }
}

int CountNode(struct Node *head)
{
    int count = 0;
    while(head)
    {
        count++;
        head = head->nextNode;
    }
    return count;
}

bool HasNode(struct Node *head, int data)
{
    while (head)
    {
        if (head->data == data) return true;
        head = head->nextNode;
    }
    return false;
}