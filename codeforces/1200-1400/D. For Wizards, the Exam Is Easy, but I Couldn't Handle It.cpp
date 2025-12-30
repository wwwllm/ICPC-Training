#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/problem/2072/D
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int l = 0, r = 0, mx = -1e9;
    for (int i = 1; i <= n; i++)
    {
        int res = 0;
        for (int j = i; j <= n; j++)
        {
            if (a[i] > a[j])
                res++;
            else if (a[i] < a[j])
                res--;
            if (res > mx)
            {
                mx = res;
                l = i, r = j;
            }
        }
    }
    cout << l << ' ' << r << '\n';
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