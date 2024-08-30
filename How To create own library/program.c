#include <stdio.h>
#include "myCalc.h"

int main() {
    printf("%d", add(1, 2)); // it will generate an error that add is not define 
    // by default jo library ye use karta hai usme add naam ka function define nahi hai toh error aaya
    return 0;
}

