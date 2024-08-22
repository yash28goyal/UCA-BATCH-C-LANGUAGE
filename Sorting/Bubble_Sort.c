#include <stdio.h> //for input output function
#include <malloc.h> //for dynamic memory allocation
#include <assert.h> //for runtime assertion
#include <time.h> //for time-related functions
#include <sys/time.h> //for getting precise time
#include <stdlib.h> //for general utilities

//Bubble Sort Implementation
void bubble_sort(int arr[], int n) {
    // Time Complexity is O(n^2)
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

//Runtime Calculation
long long runtime_calculate(int arr[], int n) { 
    //define a timeval structure that is defined in <sys/time.h> 
    struct timeval before; 
    //calling a gettimeofday function that take two argumnets first structure where the current time is stored and second that is optional which is timezone information
    gettimeofday(&before, NULL); 
    //this is to calculate that the time before sorting the array
    //tv_sec is the time in second Epoch ( january 1, 1970 )
    //tv_usec is the time in microsecond (1 million microseconds = 1 second).
    long long before_millis = before.tv_sec*1000LL + before.tv_usec/1000;  

    //Call bubble_sort function
    bubble_sort(arr, n);

    //Same task to calculate the after time
    struct timeval after;
    gettimeofday(&after, NULL);
    long long after_millis = after.tv_sec*1000LL + after.tv_usec/1000;

    return after_millis - before_millis; // Return the total time taken by the bubble sort funtion to sort the array
}

void test_sample_input() {
    int arr[] = {3, 1, 5, 9, 2};
    int ans[] = {1, 2, 3, 5, 9};

    bubble_sort(arr, 5);
    for(int i = 0; i < 5; i++) assert(arr[i] == ans[i]);
}

int main() {
    test_sample_input();
    //seeds the random number generator with the current time. This ensures that each time the program runs, the sequence of random numbers generated by rand() is different.
    srand(time(NULL));

    int k = 3200;
    int *arr1 = (int *) malloc(sizeof(int)*k);
    for(int i = 0; i < k; i++) arr1[i] = rand();
    long long t1 = runtime_calculate(arr1, k);

    k = 6400;
    int *arr2 = (int *) malloc(sizeof(int)*k);
    for(int i = 0; i < k; i++) arr2[i] = rand();
    long long t2 = runtime_calculate(arr2, k);

    printf("%d ", t2);
    printf("%d ", t1);
    printf("%lf\n", t2*1.0 / t1);
    return 0;
}