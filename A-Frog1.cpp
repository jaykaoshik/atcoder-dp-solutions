#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
#define endl "\n"
using namespace std;
void solve()
{
	ll n;
	cin>>n;
	ll h[n],dp[n];
	for(ll i=0;i<n;i++)
	{
		cin>>h[i];
	}
	dp[0]=0;
	dp[1]=abs(h[0]-h[1]);
	for(ll i=2;i<n;i++)
	{
        ll x=abs(h[i]-h[i-1]);
        ll y=abs(h[i]-h[i-2]);
        dp[i]=min(dp[i-1]+x,dp[i-2]+y);
	}
    	cout<<dp[n-1];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
	return 0;
}
