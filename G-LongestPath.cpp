#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
#define endl "\n"
using namespace std;
ll dp[100001];
vector<ll>adj[100001];
ll longestpath(ll u)
{
    ll result=0;
    if(dp[u]!=-1)
    {
        return dp[u];
    }
    if(adj[u].size()==0)
    {
        return dp[u]=0;
    }
    for(int v:adj[u])
    {
        result=max(result,longestpath(v));
    }
    return dp[u]=1+result;
}
void solve()
{
    ll n,m;
    ll ans=0;
    cin>>n>>m;
    for(ll i=1;i<=m;i++)
    {
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    memset(dp,-1,sizeof(dp));
    for(ll i=0;i<=n;i++)
    {
        ans=max(ans,longestpath(i));
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