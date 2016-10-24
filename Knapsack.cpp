//0-1 KNAPSACK
#include<iostream>
#include<time.h>
using namespace std;
int maximum(int ,int);
void KNAPSACK(int [],int [],int total,int);
int main(){
	int weight[]={1,3,4,5};
	int value[]={1,4,5,7};
	float time;
	clock_t _start,_end;
     _start=clock();
	KNAPSACK(weight,value,7,4);
	_end=clock();
	time=(_end-_start)/(double)CLOCKS_PER_SEC;
	cout<<"Time Required for KNAPSACK "<<time<<endl;
	return 0;
}
void KNAPSACK(int weight[],int value[],int total,int N){
	int Mat[N][total+1];
	for(int i=0;i<N;i++){
		for(int j=0;j<=total;j++){
			if(j==0){
				Mat[i][j]=0;
			}
			else if(i==0&&j>0){
				Mat[i][j]=value[i];
			}
			else if(weight[i]>j){
				Mat[i][j]=Mat[i-1][j];
			}
			else{
				Mat[i][j]=maximum((value[i]+Mat[i-1][j-weight[i]]),Mat[i-1][j]);
			}
		}
	}
	int i=N-1;
	int j=total;
	cout<<"Items to be Selected are "<<endl;
	while(i>0||j>0){
		if(Mat[i][j]==Mat[i-1][j]){
			i--;
		}
		else if(Mat[i][j]==Mat[i][j-1]){
			j--;
		}
		else{
			cout<<"Item with weight "<<weight[i]<<" and with value x"<<value[i]<<endl;
			j=j-weight[i];
			i--;
		}
	}
}
int maximum(int a,int b){
	//cout<<a<<" "<<b<<" "<<((a>b)?a:b)<<endl;
	return((a>=b)?a:b);
}