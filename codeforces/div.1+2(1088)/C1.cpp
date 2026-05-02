#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    bool ok = 1;
    for (int i = 1; i + k <= n; i++)
    {
        int j = i + k;
        if (a[i] == a[j])
        {
            if (b[i] != -1)
            {
                if (b[j] != -1 && b[j] != b[i])
                    ok = 0;
                b[j] = b[i];
            }
            else
            {
                if (b[j] != -1)
                    b[i] = b[j];
            }
        }
        else
        {
            if (b[i] == -1)
                b[i] = a[i];
            if (b[i] != a[i])
                ok = 0;
            if (b[j] == -1)
                b[j] = a[j];
            if (b[j] != a[j])
                ok = 0;
        }
    }
    for (int i = n; i - k >= 1; i--)
    {
        int j = i - k;
        if (a[i] == a[j])
        {
            if (b[j] != -1)
            {
                if (b[i] != -1 && b[i] != b[j])
                    ok = 0;
                b[i] = b[j];
            }
            else
            {
                if (b[i] != -1)
                    b[j] = b[i];
            }
        }
    }
    multiset<int> s;
    for (int i = 1; i <= k; i++)
    {
        s.insert(a[i]);
    }
    for (int i = 1; i <= k; i++)
    {
        if (b[i] == -1)
            continue;
        if (!s.contains(b[i]))
            ok = 0;
        else
            s.erase(s.find(b[i]));
    }
    cout << (ok ? "YES\n" : "NO\n");
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