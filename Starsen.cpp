//Startsen Algorithm
#include<iostream>
#include <time.h>
using namespace std;
int main(){
	int a[2][2]={{2,3},{5,5}};
	int b[2][2]={{5,5},{6,2}};
	int p[7];
	int c[2][2];
	clock_t _start,_end;
	float time=0;
	_start=clock();

	p[0]=(a[0][0]+a[1][1])*(b[0][0]+b[1][1]);
	p[1]=(a[1][0]+a[1][1])*b[0][0];
	p[2]=a[0][0]*(b[0][1]-b[1][1]);
	p[3]=a[1][1]*(b[1][0]-b[0][0]);
	p[4]=(a[0][0]+a[0][1])*b[1][1];
	p[5]=(a[1][0]-a[0][0])*(b[0][0]+b[0][1]);
	p[6]=(a[0][1]-a[1][1])*(b[1][0]+b[1][1]);
	c[0][0]=p[0]+p[3]-p[4]+p[6];
	cout<<c[0][0]<<" ";
	c[0][1]=p[2]+p[4];
	cout<<c[0][1]<<" ";
	cout<<endl;
	c[1][0]=p[1]+p[3];
	cout<<c[1][0]<<" ";
	c[1][1]=p[0]-p[1]+p[2]+p[5];
	cout<<c[1][1]<<" "<<endl;
	_end=clock();
	time=(_end-_start)/(double)CLOCKS_PER_SEC;
	cout<<"Time Required for Matrix Multiplication "<<time<<endl;
	
	return 0;
}