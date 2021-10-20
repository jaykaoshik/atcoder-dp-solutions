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
	ll dp[n+1][w+1]={0};
	vector<pair<ll,ll>>a(n+1);
	for(ll i=1;i<n+1;i++)
	{
		cin>>a[i].first;
		cin>>a[i].second;
	}
	for(ll i=1;i<=w;i++)
	{
		dp[1][i]=0;
	}
	dp[1][a[1].first]=a[1].second;
	for(ll i=2;i<=n;i++)
	{
		for(ll j=1;j<=w;j++)
		{
			dp[i][j]=dp[i-1][j];
			if(a[i].first>j)
			{
				continue;
			}
			dp[i][j]=max(dp[i][j],dp[i-1][j-a[i].first]+a[i].second);
		}
	}
	for(ll i=1;i<=w;i++)
	{
		ans=max(ans,dp[n][i]);
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