#include <iostream>
#include <stdio.h>

using namespace std;

typedef struct NODE {
    int data;
    struct NODE* next;
} NODE;

void InsertLinkedList (NODE **head, int data, int position)
{
    NODE* new_node = new NODE;
    new_node->data = data;

    if(*head == NULL || position==0)
    {
        *head = new_node;
    }
    else
    {
        NODE* temp = *head;
        for(int i=0; (temp->next != NULL) && (i<position-1); i++)
        {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next=new_node;
    }
}

void DeleteLinkedList (NODE **head, int position)
{
    if(*head==NULL)
    {
        cout << "Empty\n";
    }
    NODE *delete_node;

    if(position==0)
    {
        delete_node = *head;
        *head = (*head)->next;
        delete(delete_node);
    }

    else
    {
        NODE* temp = *head;
        for(int i=0 ; (temp->next != NULL) && (i < position-1) ; i++)
        {
          temp = temp->next;
        }
        delete_node = temp->next;
        temp->next = delete_node->next;
        delete(delete_node);
    }
    
}

void PrintList(NODE *head)
{
    NODE* temp = head;
    while(temp != NULL)
    {
        cout << temp->data << "->";
        temp=temp->next;
    }
    cout << "NULL\n";
}

NODE *head = NULL;

int main(void)
{
    InsertLinkedList(&head,4,0);
    PrintList(head);
    InsertLinkedList(&head,3,1);
    PrintList(head);
    InsertLinkedList(&head,2,2);
    InsertLinkedList(&head,1,3);
    PrintList(head);
    InsertLinkedList(&head,5,1);
    PrintList(head);

    DeleteLinkedList(&head,2);
    PrintList(head);
    DeleteLinkedList(&head,1);
    PrintList(head);

    return 0;
}