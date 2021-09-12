#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
#define endl "\n"
using namespace std;
void solve()
{
	ll n,k;
	cin>>n>>k;
	ll h[n+1],dp[n+1];
	for(ll i=1;i<=n;i++)
	{
	    cin>>h[i];
	}
	dp[1]=0;
	for(ll i=2;i<=n;i++)
	{
		dp[i]=INT_MAX;
		for(ll j=i-1;(j>=(i-k))&&(j>=1);j--)
		{
			dp[i]=min(dp[i],abs(h[i]-h[j])+dp[j]);
		}
	}
    	cout<<dp[n];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
	return 0;
}
