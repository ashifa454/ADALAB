//Bionimoial Coofiecient 
#include<iostream>
#include <time.h>
using namespace std;
int GetBionomial(int,int);
int main(){
	int n,k;
	cout<<"Enter the value of N"<<endl;
	cin>>n;
	cout<<"Enter the value of k"<<endl;
	cin>>k;
	float time;
	clock_t _start,_end;
     _start=clock();
	cout<<"Bionomila Coffiecient is "<<GetBionomial(n,k)<<endl;
	_end=clock();
	time=(_end-_start)/(double)CLOCKS_PER_SEC;
	cout<<"Time Required for Bionomila Coofiecient "<<time<<endl;
	return 0;
}
int GetBionomial(int n,int k){
	int C[n+1][k+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=k;j++){
			if(j==0||j==i){
				C[i][j]=1;
			}
			else{
				C[i][j]=C[i-1][j]+C[i-1][j-1];
			}
		}
	}
	return C[n][k];
}