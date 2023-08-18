#include <stdio.h>

#include "linkedList.h"

Node linkedList() {
    Node node;
    node.data = 0;
    node.nextNode = 0;

    return node;
}

void insertNode(Node* head, Node* elemToInsert) {
    head->nextNode = elemToInsert;
    elemToInsert->nextNode = head;
}
