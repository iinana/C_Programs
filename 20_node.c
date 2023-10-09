#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* nextNode;
};

struct Node* CreateNode(int data);
struct Node* InsertNode(struct Node *curr, int data);
void DestroyNode(struct Node *head, struct Node *destroy);
void PrintNodeFrom(struct Node *node);


int main()
{
    struct Node* Node1 = CreateNode(100);
    struct Node* Node2 = InsertNode(Node1, 200);
    struct Node* Node3 = InsertNode(Node2, 300);
    struct Node* Node4 = InsertNode(Node2, 400);

    PrintNodeFrom(Node1);

    DestroyNode(Node1, Node1);
    printf("After Destroy-----------------------\n");
    PrintNodeFrom(Node2);

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