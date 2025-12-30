#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/problemset/problem/2033/C
// 解2：可以用dp
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int pos = (n + 1) / 2;
    int i, j;
    if (n & 1)
        i = pos - 1, j = pos + 1;
    else
        i = pos, j = pos + 1;
    int ans = 0;
    for (; i >= 1 && j <= n; i--, j++)
    {
        if (a[i] != a[i + 1] && a[j] != a[j - 1])
            continue;
        else
        {
            if ((a[i] != a[j - 1] && a[i] == a[i + 1]) || (a[j] != a[i + 1] && a[j] == a[j - 1]))
                swap(a[i], a[j]);
        }
    }

    for (int i = 1; i <= n;)
    {
        int j = i;
        while (j <= n && a[i] == a[j])
            j++;
        ans += max(0LL, j - i - 1);
        i = j;
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}