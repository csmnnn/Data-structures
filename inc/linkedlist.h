/**
 * @file linkedlist.h
 * @author Cosmin-Iulian Manole
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct _NODE Node;

struct _NODE {
    int data;
    Node* nextNode;
};

/**
 * @brief Creates a node for the list
 * @return Pointer to the created node
*/
Node* createNode(void);

/**
 * @brief Creates a list with a given number of elements
 * @param noElements number of elements in the list
 * @return Pointer to the head of the list 
*/
Node* createList(int noElements);

/**
 * @brief Deletes the head of the list
 * @param head Pointer that points to the head of the list
 * @return Void
*/
void delete(Node** head);

/**
 * @brief Deletes an element specified by index
 * @param head pointer to the head of the list
 * @param idx index of the element to be deleted
 * @return Void
*/
void deleteAtIdx(Node* head, int idx);

/**
 * @brief Inserts an element at the head of the list
 * @param head pointer to the head of the list
 * @param elemToInsert pointer to the element to be inserted
 * @return Pointer to the head of the list
*/
Node* insert(Node* head, Node* elemToInsert);

/**
 * @brief Inserts an element with a given value at a specified index
 * @param head pointer to the head of the list
 * @param value value of the element
 * @param idx index at which to insert the element
 * @return Pointer to the head of the list or NULL
*/
Node* insertAtIdx(Node* head, int value, int idx);

/**
 * @brief Returns the size of the list
 * @param head pointer to the head of the list
 * @return Size of the list
*/
int size(Node* head);

/**
 * @brief Deallocates memory for a list
 * @param head pointer to the head of the list
 * @return Void
*/
void freeList(Node* head);

/**
 * @brief Prints the list
 * @param head pointer to the head of the list
 * @return Void
*/
void print(Node* head);

#endif