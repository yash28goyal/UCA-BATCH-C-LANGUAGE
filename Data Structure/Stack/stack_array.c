#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include "stack.h"
int *arr=NULL;
int N=0;
int max_size=1;
void resize_array(int new_size){
    int* new_array=(int *)malloc(sizeof(int)*new_size);
    for(int i=0;i<N;i++){
        new_array[i]=arr[i];
    }
    int *temp=arr;
    arr=new_array;
    free(temp);
}
void push(int item){
    if(N==0){ 
        resize_array(max_size);
    }else if(N==max_size){
        max_size*=2;
        resize_array(max_size);
    }
    arr[N++]=item;
}
int pop(){
    if(isEmpty()){
        return INT_MIN;
    }
    int value=arr[--N];
    if(size()>0 && size()==max_size/4){
        max_size/=2;
        resize_array(max_size);
    }
    return value;
}
int size(){
    return N;
}
bool isEmpty(){
    return N==0;
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