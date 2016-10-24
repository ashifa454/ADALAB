//Program to Implement LCS
#include<iostream>
#include<string.h>
#include <time.h>
using namespace std;
int main(){
	char temp[100],temp2[100];
	float time;
	clock_t _start,_end;
	cout<<"Enter the text"<<endl;
	cin>>temp;
	char *text=temp;
	cout<<"Enter the pattern"<<endl;
	cin>>temp2;
	_start=clock();
	char *pattern=temp2;
	int TL=strlen(text);
	int PL=strlen(pattern);
	int Mat[TL+1][PL+1];
	int Arrow[TL+1][PL+1];
	for(int i=0;i<=TL;i++){
		for(int j=0;j<=PL;j++){
			if(i==0||j==0)
			{	
				Mat[i][j]=0;
				Arrow[i][j]=0;
			}
			else if(text[i-1]==pattern[j-1]){
				Mat[i][j]=Mat[i-1][j-1]+1;
				Arrow[i][j]=7;
				//7 For Dioganal
			}
			else if(Mat[i-1][j]>=Mat[i][j-1]){
				Mat[i][j]=Mat[i-1][j];
				Arrow[i][j]=5;
				//5 For UP 
			}
			else{
				Mat[i][j]=Mat[i][j-1];
				Arrow[i][j]=6;
				//6 For Bottom
			}

		}
	}
	int LCSCOUNT=0;
	int i=TL,j=PL;
	while(true){
		if(Arrow[i][j]==7){
			i--;
			j--;
			LCSCOUNT++;
		}
		else if(Arrow[i][j]==5){
			i--;
		}
		else if(Arrow[i][j]==6){
			j--;
		}
		else{
			break;
		}
	}
	cout<<"Length of Longest Common Subsequence is "<<LCSCOUNT<<endl;
	_end=clock();
	time=(_end-_start)/(double)CLOCKS_PER_SEC;
	cout<<"Time Required for LCS "<<time<<endl;
	return 0;
}