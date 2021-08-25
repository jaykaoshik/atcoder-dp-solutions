#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int h[n];
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>h[i];
	}
	a[0]=0;
	a[1]=abs(h[0]-h[1]);
	for(int i=2;i<n;i++)
	{
        	int x=abs(h[i]-h[i-1]);
        	int y=abs(h[i]-h[i-2]);
        	a[i]=min(a[i-1]+x,a[i-2]+y);
	}
    	cout<<a[n-1];
    	return 0;
}
