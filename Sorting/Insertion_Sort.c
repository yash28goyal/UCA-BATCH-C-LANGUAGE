#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <malloc.h>

void insertion_sort(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        int key = arr[i];
        int j = i-1;

        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

long long time_calculate(int n) {
    int *arr = (int *) malloc(n * sizeof(int));
    srand(time(NULL));

    for(int i = 0; i < n; i++) arr[i] = rand();

    struct timeval before;
    gettimeofday(&before, NULL);
    long long before_millis = before.tv_sec*1000LL + before.tv_usec/1000;
    
    insertion_sort(arr, n);

    struct timeval after;
    gettimeofday(&after, NULL);
    long long after_millis = after.tv_sec*1000LL + after.tv_usec/1000;

    return after_millis - before_millis;
}

void test_sample_input() {
    int arr[] = {3, 1, 5, 9, 2};
    int ans[] = {1, 2, 3, 5, 9};

    insertion_sort(arr, 5);
    for(int i = 0; i < 5; i++) assert(arr[i] == ans[i]);
}

int main() {
    test_sample_input();

    long long l1 = time_calculate(3200);
    long long l2 = time_calculate(6400);

    printf("%1f", l2*1.0 / l1);
    return 0;
}