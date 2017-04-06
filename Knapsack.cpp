#include<bits/stdc++.h>
using namespace std;
int KNAPSACK(int weight[],int value[],int total,int N)
{
	int Mat[N][total+1];
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<=total;j++)
		{
			if(j==0)
			{
				Mat[i][j]=0;
			}
			else if(i==0&&j>0)
			{
				Mat[i][j]=value[i];
			}
			else if(weight[i]>j)
			{
				Mat[i][j]=Mat[i-1][j];
			}
			else
			{
				Mat[i][j]=max((value[i]+Mat[i-1][j-weight[i]]),Mat[i-1][j]);
			}
		}
	}
	int i=N-1;
	int j=total;
	cout<<"Items to be Selected are "<<endl;
	while(i>0||j>0)
	{
		if(Mat[i][j]==Mat[i-1][j])
		{
			i--;
		}
		else if(Mat[i][j]==Mat[i][j-1])
		{
			j--;
		}
		else
		{
			cout<<"Item with weight "<<weight[i]<<" and with value x"<<value[i]<<endl;
			j=j-weight[i];
			i--;
		}
	}
	cout<<"\nFinal value in the Knapsack is: ";
	cout<<Mat[N-1][total];
}
int main()
{
	int weight[10001],value[10001],no_of_items,total;
	cout<<"Enter number of items: ";
	cin>>no_of_items;
	cout<<"\nEnter weight of items: ";
	for(int i=0;i<no_of_items;i++)
	{
		cin>>weight[i];
	}
	cout<<"\nEnter value for items: ";
	for(int i=0;i<no_of_items;i++)
	{
		cin>>value[i];
	}
	cout<<"\nEnter weight capacity: ";
	cin>>total;
	KNAPSACK(weight,value,total,no_of_items);
	return 0;
}
