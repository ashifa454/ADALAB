//ActivitySelection Using Greedy
#include<iostream>
#include <time.h>
void sort(int [],int [],int,int);
int partition(int [],int [],int,int);
using namespace std;
int main(){
	int A[10];
	int s[]={1,3,4,5,3,7,8,10,8,13,2};
	int f[]={4,5,6,7,8,9,12,11,13,15,14};
	float time;
	clock_t _start,_end;
     _start=clock();
	sort(f,s,0,10);
	int j=0,k=1;
	A[0]=s[0];
	for(int i=0;i<11;i++){
		if(s[i]>=f[j]){
			A[k]=i+1;
			j=i;
			k++;
		}
	}
	_end=clock();
	time=(_end-_start)/(double)CLOCKS_PER_SEC;
	cout<<"Select Activities Are :"<<endl;
	for(int i=0;i<k;i++)
		cout<<A[i]<<endl;
	cout<<"Time Required for ActivitySelection "<<time<<endl;
}
void sort(int arr[],int start[],int left,int right){
	if(left<=right){
		int par=partition(arr,start,left,right);
		sort(arr,start,left,par-1);
		sort(arr,start,par+1,right);
	}
}
int partition(int arr[],int start[],int left,int right){
	int pivot=arr[right];
	int i=left-1;
	for(int j=left;j<=right-1;j++){
		if(arr[j]<=pivot){
			i++;
			arr[i]=arr[i]+arr[j]-(arr[j]=arr[i]);
			start[i]=start[i]+start[j]-(start[j]=start[i]);
		}
	}
	arr[i+1]=arr[i+1]+arr[right]-(arr[right]=arr[i+1]);
	start[i+1]=start[i+1]+start[right]-(start[right]=start[i+1]);
	return i+1;
}