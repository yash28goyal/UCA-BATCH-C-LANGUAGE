#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;
Node* head = NULL;
int Size = 0;

bool isEmpty() {
    return Size == 0;
}

int size() {
    return Size;
}

void push(int data) {
    Node* node = (Node *) malloc(sizeof(Node));
    node->data = data;
    node->next = head;
    head = node;
    Size++; 
}

int get(int idx) {
    if(idx < 0 || idx >= Size) return INT_MIN;

    Node* temp = head;
    for(int i = 0; i < idx; i++) temp = temp->next;

    return temp->data; 
}

int removeAt(int idx) {
    if(idx < 0 || idx >= Size) return INT_MIN;

    Node* temp = head;
    Node* prev = NULL;

    for(int i = 0; i < idx; i++) {
        prev = temp;
        temp = temp->next;
    }

    int data = temp->data;
    if(prev == NULL) head = temp->next;
    else prev->next = temp->next;

    free(temp);
    Size--;
    return data;
}

void testLL() {
    push(10);
    push(20);
    push(30);

    assert(isEmpty() == false);
    assert(size() == 3);
    assert(get(0) == 30);
    assert(get(1) == 20);
    assert(get(2) == 10);
    assert(removeAt(1) == 20);
    assert(size() == 2);
    assert(get(0) == 30);
    assert(get(1) == 10);
    assert(removeAt(0) == 30);
    assert(size() == 1);
    assert(get(0) == 10);
    assert(removeAt(0) == 10);
    assert(size() == 0);
    assert(isEmpty());
}

int main() {
    testLL();
    printf("LinkList Created!");
    return 0;
}