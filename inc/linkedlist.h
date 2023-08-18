#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct _NODE {
    int data;
    Node* nextNode;
} Node;

Node linkedList();

void insertNode(Node* head, Node* elemToInsert);

void insertNodeInterior(Node* head, Node* elemToInsert, int position);

void deleteNode();

void deleteNodeInterior();

int size(Node* node);

#endif