#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum ^= a[i];
    }
    for (int i = 0; i < n; i++)
        cin >> b[i];
    vector msk(32, 0);
    vector pos(32, 0);
    vector<int> p(32);
    auto insert = [&](int x, int idx)
    {
        int mask = 0;
        for (int i = 30; i >= 0; i--)
        {
            if ((x >> i) & 1)
            {
                if (!p[i])
                {
                    p[i] = x;
                    pos[i] = idx;
                    msk[i] = mask;
                    return;
                }
                x ^= p[i];
                mask ^=  (1LL << i);
            }
        }
    };
    for (int i = 0; i < n; i++)
    {
        insert(a[i] ^ b[i], i);
    }
    bool ok = 1;
    int mask = 0;
    for (int i = 30; i >= 0; i--)
    {
        if ((sum >> i) & 1)
        {
            if (!p[i])
            {
                ok = 0;
                break;
            }
            sum ^= p[i];
            mask |= (1LL << i);
        }
    }
    vector<int> res(n);
    for (int i = 0; i <= 30; i++)
    {
        if ((mask >> i) & 1)
        {
            res[pos[i]] ^= 1;
            mask ^= msk[i];
        }
    }
    if (!ok)
        cout << "-1\n";
    else
    {
        for (int i = 0; i < n; i++)
            if (res[i])
                cout << b[i] << " \n"[i == n - 1];
            else
                cout << a[i] << " \n"[i == n - 1];
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}