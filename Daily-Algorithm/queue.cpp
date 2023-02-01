#include <iostream>

using namespace std;

typedef struct Node
{
    int data;
    Node *next;
}Node;

typedef struct Queue
{
    Node *front;
    Node *back;
    int count;
}Queue;

void InitQueue(Queue **queue)
{
    (*queue) = (Queue*) malloc(sizeof(Queue));
    (*queue)->front = (*queue)->back = NULL;
    (*queue)->count = 0;
}

Node* CreateNode(int data)
{
    Node* node = (Node*) malloc(sizeof(Node));
    node -> data = data;
    node -> next = NULL;
    return node;
}

void PushQueue(Queue **queue, Node *node)
{
    if((*queue)->count == 0)
    {
        (*queue)->back = (*queue)->front = node;
    }
    else
    {
        (*queue)->back->next = (*queue)-> back;
        (*queue)->back = node;
    }

    (*queue)->count++;
    
}

Node* PopQueue(Queue **queue)
{
    if(!(*queue)) return;

    Node *n = (*queue)->front;
    (*queue) -> front = n->next;
    (*queue)->count --;

    return n;
}

bool IsEmptyQueue (Queue **queue)
{
    if((*queue)->count == 0) return true;
    else return false;
}

void DestroyQueue (Queue **queue)
{
    if(IsEmptyQueue(queue)) return ;
    int cnt = (*queue)->count;
    for(int i=0; i<cnt; i++)
    {
        Node *n = PopQueue(queue);
        free(n);
    }
    (*queue)->front = (*queue)->back = NULL;
    (*queue)->count = 0;
    free(*queue);
}
int main(void)
{
    Queue *queue = NULL;
    InitQueue(&queue);
    PushQueue(&queue, CreateNode(1));
    PushQueue(&queue,CreateNode(2));
    PushQueue(&queue,CreateNode(3));
}