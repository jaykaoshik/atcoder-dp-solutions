#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
#define endl "\n"
using namespace std;
void solve()
{
	ll n,w;
	ll ans=0;
	cin>>n>>w;
	ll dp[n+1][1000*n+1];
	vector<pair<ll,ll>>a(n+1);
	for(ll i=1;i<n+1;i++)
	{
		cin>>a[i].first;
		cin>>a[i].second;
	}
	for(ll i=0;i<=1000*n;i++)
	{
		dp[1][i]=MOD;
	}
	dp[1][0]=0;
	dp[1][a[1].second]=a[1].first;
	for(ll i=2;i<=n;i++)
	{
		for(ll j=1;j<=1000*n;j++)
		{
			dp[i][j]=dp[i-1][j];
			if(a[i].second>j)
			{
				continue;
			}
			dp[i][j]=min(dp[i][j],dp[i-1][j-a[i].second]+a[i].first);
		}
	}
	for(ll i=1;i<=1000*n;i++)
	{
		if(dp[n][i]<=w)
		{
			ans=max(ans,i);
		}
	}
	cout<<ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
	return 0;
}