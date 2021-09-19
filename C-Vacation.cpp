#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
#define endl "\n"
using namespace std;
void solve()
{
	ll n;
	cin>>n;
	ll a[n+1],b[n+1],c[n+1],dp[n][3];
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
	}
	dp[0][0]=dp[0][1]=dp[0][2]=0;
	dp[1][0]=a[1];dp[1][1]=b[1];dp[1][2]=c[1];
	for(ll i=2;i<=n;i++)
	{
		dp[i][0]=max(dp[i-1][1],dp[i-1][2])+a[i];
		dp[i][1]=max(dp[i-1][0],dp[i-1][2])+b[i];
		dp[i][2]=max(dp[i-1][0],dp[i-1][1])+c[i];
	}
	ll ans=max(dp[n][0],max(dp[n][1],dp[n][2]));
	cout<<ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
	return 0;
}