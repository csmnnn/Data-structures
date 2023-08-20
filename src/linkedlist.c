/**
 * @file linkedlist.c
 * @author Cosmin-Iulian Manole
*/

#include <stdio.h>
#include <stdlib.h>

#include "..\inc\linkedlist.h"

Node* createNode() {
    Node* node = (Node*)malloc(sizeof(Node));
    if (!node) {
        puts("Error");
        exit(EXIT_FAILURE);
    }

    printf("Node data: ");
    scanf("%d", &node->data);

    node->nextNode = 0;

    return node;
}

Node* createList(int noElements) {
    if (noElements < 1)
        return NULL;
    
    Node* head = createNode();
    int i;
    for (i = 1; i < noElements; i++) 
        head = insert(head, createNode());

    return head;
}

Node* insert(Node* head, Node* elemToInsert) {
    elemToInsert->nextNode = head;
    head = elemToInsert;

    return head;
}

Node* insertAtIdx(Node* head, int value, int idx) {
    if (idx > size(head) || idx < 0) 
        return NULL;

    int i = 0;
    Node* tmp = head, *elemToInsert = (Node*)malloc(sizeof(Node));
    
    for (tmp; i < idx - 1 && tmp->nextNode != 0; tmp = tmp->nextNode) 
        i++;

    elemToInsert->data = value;
    elemToInsert->nextNode = tmp->nextNode;
    tmp->nextNode = elemToInsert;

    return head;
}

int size(Node* head) {
    Node* tmp = head;
    int size = 0;
    while (tmp != 0) {
        size++;
        tmp = tmp->nextNode;
    }

    return size;
}

void delete(Node** head) {
    Node* oldHead = *head;
    *head = (*head)->nextNode;
    free(oldHead);
    oldHead = 0;
}

void deleteAtIdx(Node* head, int idx) {
    if (idx > size(head) || idx < 0)
        return;
    
    if (size(head) == 1)
        delete(&head);
    else {
        int i = 0;
        Node* tmp = head, *nodeToDelete;
        for (tmp; tmp != 0 && i < idx - 1; tmp = tmp->nextNode) 
            i++;

        nodeToDelete = tmp->nextNode;
        tmp->nextNode = nodeToDelete->nextNode;
        free(nodeToDelete);
        nodeToDelete = 0;
    }
}

void freeList(Node* head) {
    do {
        delete(&head);
    }
    while (head->nextNode != 0);
    free(head);
    head = 0;
}

void print(Node* head) {
    Node* tmp = head;
    printf("[");
    while (tmp != 0) {
        if (!tmp->nextNode) {
            printf("%d]\n", tmp->data);
            break;
        }
        else {
            printf("%d, ", tmp->data);
            tmp = tmp->nextNode;
        }
    }
}
