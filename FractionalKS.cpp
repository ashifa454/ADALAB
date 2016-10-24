//Fractional Knapsack
#include<iostream>
#include <time.h>
using namespace std;
void sort(float [],int [],int [],int ,int);
int partition(float [],int [],int [],int,int);
int main(){
	int value[]={12,10,20,15};
	int weight[]={2,1,3,2};
	float totalWeight=5;
	float Fraction[4];
	float time;
	clock_t _start,_end;
     _start=clock();
	for(int i=0;i<4;i++){
		Fraction[i]=(float)value[i]/weight[i];
	}
	sort(Fraction,value,weight,0,3);
	int i=0;
	float totalvalue=0;
	while(totalWeight>0){
		if(weight[i]<=totalWeight){
			cout<<"The item with value "<<value[i]<<" and weight "<<weight[i]<<" has been selected"<<endl;
			totalWeight-=weight[i];
			totalvalue=totalvalue+value[i];
			i++;
		}else{
			cout<<"The item with value "<<value[i]<<" and weight "<<weight[i]<<" with Fraction "<<Fraction[i]<<" has been selected"<<endl;
			totalvalue=totalvalue+((totalWeight/weight[i])*value[i]);
			totalWeight-=Fraction[i];
		}
	}
	cout<<"Hence Total Value is "<<totalvalue<<endl;
	_end=clock();
	time=(_end-_start)/(double)CLOCKS_PER_SEC;
	cout<<"Time Required for Fractional Knapsack "<<time<<endl;
	return 0;
}

void sort(float arr[],int value[],int weight[],int left,int right){
	if(left<=right){
		int par=partition(arr,value,weight,left,right);
		sort(arr,value,weight,left,par-1);
		sort(arr,value,weight,par+1,right);
	}
}
int partition(float arr[],int value[],int weight[],int left,int right){
	int pivot=arr[right];
	int i=left-1;
	for(int j=left;j<=right-1;j++){
		if(arr[j]>pivot){
			i++;
			arr[i]=arr[i]+arr[j]-(arr[j]=arr[i]);
			value[i]=value[i]+value[j]-(value[j]=value[i]);
			weight[i]=weight[i]+weight[j]-(weight[j]=weight[i]);
		}
	}
	arr[i+1]=arr[i+1]+arr[right]-(arr[right]=arr[i+1]);
	value[i+1]=value[i+1]+value[right]-(value[right]=value[i+1]);
	weight[i+1]=weight[i+1]+weight[right]-(weight[right]=weight[i+1]);
	return i+1;
}