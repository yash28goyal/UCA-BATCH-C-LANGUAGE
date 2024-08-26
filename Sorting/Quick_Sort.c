
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
int pivot(int arr[] ,int s,int e){
    int p=arr[s];
    int c=0;
    for (int i=s+1;i<=e;i++){
        if (arr[i]<=p){
            c++;
        }
    }
    int k=s+c;
    int n=arr[k];
    arr[k]=arr[s];
    arr[s]=n;
    int i=s;
    int j=e;
    while (i<k && j>k){
        while (arr[i]<=p){
            i++;
        }
        while (arr[j]>p){
            j--;
        }
        if (i<k && j>k){
            int m=arr[j];
            arr[j]=arr[i];
            arr[i]=m;
            i++;
            j--;
        } 
    }
    return k;
}
void quicksort(int arr[],int s,int e){
    if(s>=e){
        return ;
    }
    int p=pivot(arr,s,e);
    quicksort(arr,s,p-1);
    quicksort(arr,p+1,e);
    
}
int main() {
    srand(time(0));
    int n;
    n=rand()%40;
    int* arr=(int*)malloc(sizeof(int)*n);
    for ( int i=0;i<n;i++){
       arr[i]=rand()%200;
    } 
    printf("Before Sort\n");
    for (int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    quicksort (arr,0,n-1);
    printf("\nAfter Sort\n");
    for (int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }

    return 0;
}
