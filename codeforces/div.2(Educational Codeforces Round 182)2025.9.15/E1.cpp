#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

const int mod = 998244353;
int exp(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> h(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    vector<int> l, r, cntl(n + 1), cntr(n + 1);
    vector<vector<int>> lpos(l.size()), rpos(r.size());
    for (int i = 1; i <= n; i++)
    {
        if (i == 1 || h[i] > *l.rbegin())
            l.pb(h[i]), lpos[l.size() - 1].pb(i);
    }
    for (int i = n; i >= 1; i--)
    {
        if (i == n || h[i] > *r.rbegin())
            r.pb(h[i]), rpos[r.size() - 1].pb(i);
    }

    for (int i = 0; i < l.size(); i++)
    {
        for (int j = 0; j < lpos[i].size()-1; j++)
        {
            for (int k = lpos[i][j]; k < lpos[i][j+1]; k++)
            {
                if (i != 0 && h[k] <= l[i - 1])
                    cntl[k] = cntl[k - 1] + 1;
                else
                    cntl[k] = cntl[k - 1];
            }
        }
    }
    for (int i = r.size()-1; i >=0; i--)
    {
        for (int j = rpos[i].size()-1; j >=0; j--)
        {
            for (int k = lpos[i][j]; k < lpos[i][j]; k++)
            {
                if (i != 0 && h[k] <= l[i - 1])
                    cntl[k] = cntl[k - 1] + 1;
                else
                    cntl[k] = cntl[k - 1];
            }
        }
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}