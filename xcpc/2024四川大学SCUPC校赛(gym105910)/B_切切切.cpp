#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/gym/105910
void solve()
{
    int n;
    cin >> n;
    vector<int> b;
    vector<int> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    b = p;
    int ans = 0;
    auto calc = [&](vector<int> &a)
    {
        int n = a.size();
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            res += abs(abs(a[i]) - abs(a[n - i - 1]));
        }
        return res / 2;
    };
    ans = calc(p);
    vector<int> a(n);
    for (int i = 0; i < n / 2; i++)
    {
        int mid = (p[i] + p[n - i - 1]) / 2;
        a[i] = a[n - i - 1] = mid;
        p[i] = p[i] - mid;
        p[n - i - 1] = p[n - i - 1] - mid;
    }
    int res = n + calc(p);
    if (res < ans)
    {
        cout << 2 << ' ' << res << '\n';
        for (int i = 0; i < n; i++)
            cout << a[i] << " \n"[i == n - 1];
        for (int i = 0; i < n; i++)
            cout << p[i] << " \n"[i == n - 1];
    }
    else
    {
        cout << 1 << ' ' << ans << '\n';
        for (int i = 0; i < n; i++)
            cout << b[i] << " \n"[i == n - 1];
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}