#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include "stack.h"
struct Node{
    int data;
    struct Node* next;
};
typedef struct Node Node;
Node* head=NULL;
int N=0;

void push(int item){
    Node* oldHead=head;
    head=(Node* )malloc(sizeof(Node)*1);
    head->data=item;
    head->next=oldHead;
    N++;
}
int pop(){
    if(head==NULL){
        return INT_MIN;
    }else{
        Node* oldhead=head;
        int value=oldhead->data;
        head=head->next;
        oldhead->next=NULL;
        free(oldhead);
        N--;
        return value;
    }
}
int size(){
    return N;
}
bool isEmpty(){
    if(head==NULL){
        return true;
    }else{
        return false;
    }
}
int teststack(){
    push(3);
    push(10);
    push(19);
    assert(isEmpty()==false);
    assert(size()==3);
    assert(pop()==19);
    assert(size()==2);
    assert(pop()==10);
    assert(size()==1);
    assert(pop()==3);
    assert(size()==0);
    assert(isEmpty()==true);
    return 0;
}
int main(){
    teststack();
    return 0;
}