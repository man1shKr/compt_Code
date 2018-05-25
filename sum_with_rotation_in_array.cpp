#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int i,j,n,s;
	cin>>n>>s;
	int a[n];
	int r[n-1];
	int arsum=0;
	r[0]=0;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		arsum=arsum+a[i];
		r[0]=r[0]+i*a[i];
	}
	//cout<<r[0]<<endl;
	if(r[0]==s)
	{
		for(i=0;i<n;i++)
		{
			cout<<i<<"*"<<a[i]<<" + ";
		}
	}
	else
	{
	for( i=1;i<n;i++)
	{
		r[i]=arsum-n*a[n-i]+r[i-1];
		//cout<<r[i]<<endl;
		if(s==r[i])
		{
			cout<<"the sum exists with "<<i<<" rotations "<<endl;
			break;
		}
	}
	}

}
