#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
#define endl "\n"
using namespace std;
ll dp[1001][1001];
char a[1001][1001];
void solve()
{
    ll n,m;
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    dp[n][m]=1;
    for(ll i=n;i>=1;i--)
    {
        for(ll j=m;j>=1;j--)
        {
            if(i==n&&j==m)
            {
                continue;
            }
            if(a[i][j]=='#')
            {
                dp[i][j]=0;
            }
            else
            {
                if(i==n&&j!=m)
                {
                    dp[i][j]=dp[i][j+1]%MOD;
                }
                else if(i!=n&&j==m)
                {
                    dp[i][j]=dp[i+1][j]%MOD;
                }
                else
                {
                    dp[i][j]=(dp[i][j+1]+dp[i+1][j])%MOD;
                }
            }
        }
    }
    cout<<dp[1][1];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}