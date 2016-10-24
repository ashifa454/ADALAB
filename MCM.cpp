//MCM Dynamic Alogorithm
#include<iostream>
#include<time.h>
int MCM(int[],int);
using namespace std;
int main(){
	int n,p[10];
	float time;
	clock_t _start,_end;
	cout<<"How many Values do you want to Enter"<<endl;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>p[i];
	
	_start=clock();
	cout<<"Number of Multiply Required for this chain is "<<MCM(p,n)<<endl;
	_end=clock();
	time=(_end-_start)/(double)CLOCKS_PER_SEC;
	cout<<"Time Required for MCM "<<time<<endl;
	return 0;
}
int MCM(int p[],int n){
	int C[10][10],MIN=100000,j,temp;
	for(int i=0;i<n;i++)
		C[i][i]=0;
	for(int k=2;k<n;k++){
		for(int i=1;i<(n-k+1);i++){
			j=i+k-1;
			C[i][j]=MIN;
			for(int l=i;l<j;l++){
				temp=C[i][l]+C[l+1][j]+(p[i-1]*p[l]*p[j]);
				if(temp<C[i][j]){
					C[i][j]=temp;
				}
			}
		}
	}
	return C[1][n-1];
}