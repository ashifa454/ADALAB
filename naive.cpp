#include<iostream>
#include<string.h>
#include<time.h>
using namespace std;
int getLength(char *str);
bool isMatch(char *str,char *str2);
int main(){
	char *text,*patter;
	bool flag=false;
	text="000010001010001";
	patter="0001";
	float time;
	clock_t _start,_end;
     _start=clock();
	int N=strlen(text);
	int M=strlen(patter);
	int matchCount=0;
	for(int i=0;i<N-M+1;i++){
		matchCount=0;
		for(int j=0;j<M;j++){
			if(patter[j]==text[i+j]){
				matchCount++;
			}
		}	
		if(matchCount==M){
		cout<<"Found Pattern on Shift "<<i<<endl;
		}
	}
	_end=clock();
	time=(_end-_start)/(double)CLOCKS_PER_SEC;
	cout<<"Time Required for Naive "<<time<<endl;
	return 0;
}