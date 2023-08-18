#include <stdio.h>
#include <stdlib.h>

#include "..\inc\linkedlist.h"

Node* createNode() {
    Node* node = (Node*)malloc(sizeof(Node));

    printf("Node data: ");
    scanf("%d", &node->data);

    node->nextNode = 0;

    return node;
}

Node* createList(int noElements) {
    Node* head = createNode(), *elemToInsert;
    int i, value;
    for (i = 1; i < noElements; i++) 
        head = insert(head, createNode());

    return head;
}

Node* insert(Node* head, Node* elemToInsert) {
    elemToInsert->nextNode = head;
    head = elemToInsert;

    return head;
}

void insertAtIdx(Node* head, int value, int idx) {
    int i = 0;
    Node* tmp = head, *elemToInsert = (Node*)malloc(sizeof(Node));
    
    for (tmp; i < idx - 1 && tmp->nextNode != 0; tmp = tmp->nextNode) 
        i++;

    elemToInsert->data = value;
    elemToInsert->nextNode = tmp->nextNode;
    tmp->nextNode = elemToInsert;
}

void freeList(Node* head) {
    free(head);
    head = 0;
}
