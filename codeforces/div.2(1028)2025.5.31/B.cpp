#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;
int expow(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> p(n), q(n), ans(n);
    vector<array<int, 2>> prep(n), preq(n);
    for (auto &x : p)
        cin >> x;
    for (auto &x : q)
        cin >> x;
    prep[0] = {p[0], 0};
    preq[0] = {q[0], 0};
    for (int i = 1; i < n; i++)
    {
        if (p[i] > prep[i - 1][0])
        {
            prep[i][0] = p[i];
            prep[i][1] = i;
        }
        else
            prep[i] = prep[i - 1];
        if (q[i] > preq[i - 1][0])
        {
            preq[i][0] = q[i];
            preq[i][1] = i;
        }
        else
            preq[i] = preq[i - 1];
    }
    for (int i = 0; i < n; i++)
    {
        if (prep[i][0] > preq[i][0])
        {
            ans[i] = (expow(2, prep[i][0]) + expow(2, q[i - prep[i][1]])) % mod;
        }
        else if (prep[i][0] < preq[i][0])
            ans[i] = (expow(2, preq[i][0]) + expow(2, p[i - preq[i][1]])) % mod;
        else{
            int x = q[i - prep[i][1]], y = p[i - preq[i][1]];
            if(x>y){
                ans[i] = (expow(2, prep[i][0]) + expow(2, q[i - prep[i][1]])) % mod;
            }
            else
                ans[i] = (expow(2, preq[i][0]) + expow(2, p[i - preq[i][1]])) % mod;
        }
    }
    for (auto ele : ans)
        cout << ele << ' ';
    cout << '\n';
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