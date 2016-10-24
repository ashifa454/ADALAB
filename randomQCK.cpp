//QuickSort Algorithm
#include<iostream>
#include <stdlib.h>
#include <time.h>
#include<unistd.h>
using namespace std;
int randpartition(int [],int,int);
void randQuickSort(int [],int,int);
int main(){
	clock_t _start,_end;
	float time;
	int array[100000];
	for(int i=0;i<100000;i++){
		array[i]=rand()%100000;
	}
	_start=clock();
	randQuickSort(array,0,99999);
	_end=clock();
	cout<<"Time Required for Average Case for 100000"<<endl;
	time=(_end-_start)/(double)CLOCKS_PER_SEC;
	cout<<time<<endl;
	//Worst Case
	for(int i=0;i<100000;i++){
		array[i]=100000-i;
	}
	_start=clock();
	randQuickSort(array,0,99999);
	_end=clock();
	cout<<"Time Required for worst Case for 100000"<<endl;
	time=(_end-_start)/(double)CLOCKS_PER_SEC;
	cout<<time<<endl;
	return 0;
}
int randpartition(int arr[],int left,int right){
		int Pindex=left+(rand()%(right-left+1));
		int pivot=arr[Pindex];
		arr[right]=(arr[right]+arr[Pindex])-(arr[Pindex]=arr[right]);
		int i=(left-1);
		for(int j=left;j<=right-1;j++){
			if(arr[j]<=pivot){
				i++;
				arr[i]=(arr[i]+arr[j])-(arr[j]=arr[i]);
			}
		}
		arr[i+1]=(arr[i+1]+arr[Pindex])-(arr[Pindex]=arr[i+1]);
		return i+1;
}
void randQuickSort(int arr[],int left,int right){
	if(left<right){
		int prt=randpartition(arr,left,right);
		randQuickSort(arr,left,prt-1);
		randQuickSort(arr,prt+1,right);
	}
}