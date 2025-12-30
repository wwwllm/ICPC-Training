#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> st(N + 1), prime;
void f()
{
    for (int i = 2; i <= N; i++)
    {
        if (!st[i])
            prime.push_back(i);
        for (int j = 0; j < prime.size() && prime[j] <= N / i; j++)
        {
            st[prime[j] * i] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    vector<int> ans(n + 1), st(n + 1);
    ans[1] = 1;
    for (int i = prime.size() - 1; i >= 0; i--)
    {
        int p = prime[i];
        if (p > n)
            continue;
        vector<int> tmp;
        int x = p;
        while (n >= x)
        {
            if (!st[x])
            {
                st[x] = 1;
                tmp.push_back(x);
            }
            x += p;
        }
        for (int i = 0; i < tmp.size(); i++)
        {
            ans[tmp[i]] = tmp[(i + 1) % tmp.size()];
        }
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " \n"[i == n];
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    f();
    while (t--)
        solve();
    return 0;
}