#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct _NODE Node;

struct _NODE {
    int data;
    Node* nextNode;
};

Node* createNode();

Node* createList(int noElements);

Node* insert(Node* head, Node* elemToInsert);

void insertAtIdx(Node* head, int value, int idx);

void deleteNode();

void deleteNodeInterior();

int size(Node* node);

void freeList(Node* head);

#endif