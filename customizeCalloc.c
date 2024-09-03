// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

void* customizeCalloc(int num) {
    void* ptr = malloc(num);
    for (int i = 0; i < num; i++) {
        char * curr = (char*)(ptr)+i;
        curr = 0;
    }
    return ptr;
}

int main() {
    int num = 5;
    void* memory = customizeCalloc(num);
    for (int i = 0; i < num; i++) {
        char * curr = (char*)(memory)+i;
        printf("%d", curr);
        printf("\n");
    }
    return 0;
}