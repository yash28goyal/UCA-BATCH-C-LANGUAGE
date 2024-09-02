// Our task is to print all the possible ways to reach n-1,m-1 from 0,0

#include <stdio.h>

void printAllWay(int n,int m, int i, int j) {
    if(i == n-1 && j == m-1) {
        printf("(%d,%d)\n",i ,j);
        return;
    }

    if(i > n-1 || j > m-1) {
        return;
    }

    printf("(%d,%d)-->", i, j);
    printAllWay(n, m, i+1, j);
    printAllWay(n, m, i, j+1);
}

int main() {
    int n, m;
    printf("Enter the numbers : ");
    scanf("%d %d", &n, &m);
    printAllWay(n, m, 0, 0);
    return 0;
}