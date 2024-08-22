#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void selection_sort(int arr[], int n) {
    for(int i = 0; i < n; i++){
        int mini = i;
        for(int j = i+1; j < n; j++){
            if(arr[mini] > arr[j]) mini = j;
        }
        swap(arr, i, mini);
    }
}

long long time_calculate(int n) {
    int *arr = (int *) malloc(n * sizeof(int));
    srand(time(NULL));

    for(int i = 0; i < n; i++) arr[i] = rand();

    struct timeval before;
    gettimeofday(&before, NULL);
    long long before_millis = before.tv_sec*1000LL + before.tv_usec/1000;

    selection_sort(arr, n);

    struct timeval after;
    gettimeofday(&after, NULL);
    long long after_millis = after.tv_sec*1000LL + after.tv_usec/1000;

    return after_millis - before_millis;
}

void test_sample_input() {
    int arr[] = {3, 1, 5, 4, 2};
    int ans[] = {1, 2, 3, 4, 5};

    selection_sort(arr, 5);
    for(int i = 0; i < 5; i++) assert(arr[i] == ans[i]); 
}

int main() {

    test_sample_input();

    long long t1 = time_calculate(3200);
    long long t2 = time_calculate(6400);

    printf("%1f", t2 * 1.0 / t1);
    return 0;
}