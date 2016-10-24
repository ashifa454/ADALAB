//Rabin Karp
#include<iostream>
#include<string.h>
#include<math.h>
#include<time.h>
#define d 256
using namespace std;	
void RabinSearch(char *,char *,int);
int main(){
	char *text="000010001010001";
	char *pattern="0001";
	int q=11;
	float time;
	clock_t _start,_end;
     _start=clock();
	RabinSearch(text,pattern,q);
	_end=clock();
	time=(_end-_start)/(double)CLOCKS_PER_SEC;
	cout<<"Time Required for Rabin Carp "<<time<<endl;
	return 0;
}
void RabinSearch(char *text,char *pattern,int q){
	int N=strlen(text);
	int M=strlen(pattern);
	int h=1;
	int i,j;
	int p=0,t=0;
	h=pow(d,M-1);
	h=h%q;
	for(int i=0;i<M;i++){
		p=(d*p+pattern[i])%q;
		t=(d*t+text[i])%q;
	}
	for(i=0;i<=N-M;i++){
		if(p==t){
			for(j=0;j<M;j++){
				if(pattern[j]!=text[i+j])
					break;
			}
			if(j==M){
				cout<<"Got the String on shift  "<<i+1<<endl;
			}
		}
		if(i<N-M){
			t=(d*(t-text[i]*h)+text[i+M])%q;
			if(t<0){
				t=t+q;
			}
		}
	}
}