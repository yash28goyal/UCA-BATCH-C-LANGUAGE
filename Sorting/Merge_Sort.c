#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void merge(int* arr,int s,int e){
	int m=s+(e-s)/2;
	int l1=m-s+1;
	int l2=e-m;
	int* arr1=(int*)malloc(l1*sizeof(int));
	int* arr2=(int*)malloc(l2*sizeof(int));
	int k=s;
	for(int i=0;i<l1;i++){
		arr1[i]=arr[k++];
	}
	for(int i=0;i<l2;i++){
		arr2[i]=arr[k++];
	}
	k=s;
	int i=0;
	int j=0;
	while(i<l1 && j<l2){
		if(arr1[i]<arr2[j]){
			arr[k++]=arr1[i];
			i++;
		}
		else{
			arr[k++]=arr2[j];
			j++;
		}
	}
	while(i<l1){
            arr[k++]=arr1[i];
            i++;

	}
	while(j<l2){
		 arr[k++]=arr2[j];
                 j++;

	}
	free(arr1);
	free(arr2);

}
void mergeSort(int* arr,int s,int e){
	if(s>=e){
		return ;
	}
	int m=s+(e-s)/2;
	mergeSort(arr,s,m);
	mergeSort(arr,m+1,e);
	merge(arr,s,e);
}

	


int main(){
	srand(time(0));
	int n;
	n=rand()%10;
	int* arr= (int*)(malloc)(sizeof(int)*n);
	for(int i=0;i<n;i++){
		arr[i]=rand()%20;
	}
	
	mergeSort(arr,0,n-1);
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}

}
