#include<bits/stdc++.h>
using namespace std;
struct data
{
	float profit;
	float weight;
	float pr;	//profit per unit weight
};

int partition(struct data s[],int low,int high)
{
	float pivot=s[high].pr;
	int i=low-1;
	for(int j=low;j<high;j++)
	{
		if(s[j].pr<=pivot)
		{
			i++;
			data t= s[i];
			s[i]= s[j];
			s[j]=t;
		}
	}
	data t= s[i+1];
	s[i+1]= s[high];
	s[high]=t;
	return(i+1);
}
void quicksort(struct data s[],int low,int high)
{
	
	if(low<high)
	{
		int pi=partition(s,low,high);
		quicksort(s,low,pi-1);
		quicksort(s,pi+1,high);
	}
}
void knapsack(struct data s[],int n,float t)
{
	float x[n+1];
	for(int j=1;j<=n;j++)x[j]=0;
	float prof=0;
	int i;
	for( i=n;i>0;i--)
	{
		if(t>=s[i].weight)
		{
			x[i]=1;
			t=t-(s[i].weight);
			prof=prof+(s[i].profit);
		}
		else
		break;
	}
	if(t!=0){
	float f=t/(s[i].weight);
	x[i]=f;
	prof=f*(s[i].profit)+prof;}
	for(int i=1;i<=n;i++)
	{
		if(x[i]!=0)
		cout<<x[i]<<" is used by "<<s[i].weight<<endl;
	}
	cout<<prof;
}
int main()
{
	cout<<"enter no of items";
	float t;
	int n;
	cin>>n;
	cout<<"enter total weight of knapsack";
	cin>>t;
	
    struct data s[n];
		    
    for(int i=1;i<=n;i++)
    {
		cout<<"enter data for "<<i<<" element";
    	cin>>s[i].profit>>s[i].weight;
    	s[i].pr=s[i].profit/s[i].weight;
    }
    
    quicksort(s,1,n);
    
    for(int i=1;i<=n;i++)
    {
		cout<<" data for "<<i<<" element";
    	cout<<s[i].profit<<" "<<s[i].weight<<" "<<s[i].pr<<endl;
    }
    knapsack(s,n,t);
    return 0;
}
