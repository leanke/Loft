#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

// Insert a new node at the head
Node* insertHead(Node* head, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = val;
    newNode->next = head;
    return newNode;
}

// Delete the first node found with the given value
Node* deleteNode(Node* head, int val) {
    Node* temp = head;
    Node* prev = NULL;

    if (temp && temp->value == val) {
        head = temp->next;
        free(temp);
        return head;
    }

    while (temp && temp->value != val) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) return head;

    prev->next = temp->next;
    free(temp);
    return head;
}
