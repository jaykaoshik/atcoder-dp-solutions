#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
#define endl "\n"
using namespace std;
ll dp[3001][3001];
ll lenLCS(string&s,string&t,ll i,ll j)
{
    if(i>=(ll)s.size()||j>=(ll)t.size())
    {
        return 0LL;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    if(s[i]==t[j])
    {
        return dp[i][j]=1+lenLCS(s,t,i+1,j+1);
    }
    return dp[i][j]=max(lenLCS(s,t,i,j+1),lenLCS(s,t,i+1,j));
}
void solve()
{
    ll i=0,j=0;
    string s,t,LCS;
    cin>>s>>t;
    memset(dp,-1,sizeof(dp));
    ll maxlen=lenLCS(s,t,0LL,0LL);
    while(maxlen>0LL)
    {
        if(s[i]==t[j])
        {
            LCS.push_back(s[i]);
            i++;j++;maxlen--;
        }
        else
        {
            if(dp[i+1][j]>dp[i][j+1])
            {
                i++;
            }
            else
            {
                j++;
            }
        }
    }
    cout<<LCS;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}