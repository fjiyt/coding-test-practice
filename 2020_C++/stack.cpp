#include <iostream>

using namespace std;

typedef struct Node
{
    int data;
    Node* prev;
}Node;

typedef struct Stack
{
    Node* top;
}Stack;

void InitStack(Stack** s)
{
    (*s) = (Stack*) malloc(sizeof(Stack));
    (*s)->top = NULL;
}
 
Node* CreateNode (int data)
{
    Node* n = (Node*) malloc(sizeof(Node));
    n->data = data;
    n->prev = NULL;
    return n;
}

void PushNode(Stack** stack, Node * node)
{
    if(!stack) return;

    node->prev=(*stack)->top;
    (*stack)->top = node;
}

Node* PopNode(Stack** stack)
{
    if(!(*stack) && !((*stack)->top)) return NULL;

    Node* n = (*stack)->top;
    (*stack)->top = n->prev;
    return n;
}

Node* TopNode(Stack** stack)
{
    if(!(*stack) && !((*stack) -> top)) return NULL;
    return ((*stack)->top);
}

void DestroyStack (Stack** stack)
{
    if(!(*stack)) return;
    
    Node* n = PopNode(&(*stack));
    while(n != NULL)
    {
        cout << "Destroy Node : " << n->data << "\n";
        free(n);
        n= PopNode(&(*stack));
    }

    (*stack) = NULL;
    free((*stack));

    return ;
}

int main(void)
{
    Stack * stack = NULL;
    InitStack(&stack);
    PushNode(&stack, CreateNode(1));
    PushNode(&stack,CreateNode(2));
    PushNode(&stack,CreateNode(3));
    PushNode(&stack,CreateNode(4));
    PushNode(&stack,CreateNode(5));
    PushNode(&stack,CreateNode(100));

    for(int i=0; i<5; i++)
    {
        Node* n =PopNode(&stack);
        cout << n->data << endl;
        free(n);
    }
    DestroyStack(&stack);

    cout << "end\n";
    return 0;
}