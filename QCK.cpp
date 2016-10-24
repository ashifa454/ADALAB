//QuickSort Algorithm
#include<iostream>
#include <stdlib.h>
using namespace std;
int partition(int [],int,int);
void QuickSort(int [],int left,int right);
int main(){
	int array[100];
	for(int i=0;i<100;i++){
		array[i]=i;
	}
	QuickSort(array,0,99);
	for(int i=0;i<=99;i++){
		cout<<array[i]<<endl;
	}
	return 0;
}
int partition(int arr[],int left,int right){
		int pivot=arr[right];
		int i=(left-1);
		for(int j=left;j<=right-1;j++){
			if(arr[j]<=pivot){
				i++;
				arr[i]=(arr[i]+arr[j])-(arr[j]=arr[i]);
			}
		}
		arr[i+1]=(arr[i+1]+arr[right])-(arr[right]=arr[i+1]);
		return i+1;
}
void QuickSort(int arr[],int left,int right){
	if(left<right){
		int prt=partition(arr,left,right);
		QuickSort(arr,left,prt-1);
		QuickSort(arr,prt+1,right);
	}
}