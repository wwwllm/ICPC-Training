#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int a[N];
string s;
void solve()
{
    int n;
    cin >> n;
    int ans = 0, l = 0, r = 0;
    cin >> s;
    for (int i = 1; i <= n; i++)
        a[i] = s[i - 1] - '0';
    int op = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != op)
            ans += 2, op = a[i];
        else
            ans++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (l == 0 && a[i] == 1)
            l = i;
        if (l != 0 && r == 0)
        {
            if (i == n && a[i] == 0)
                r = i;
            if (i < n && a[i] == 0 && a[i + 1] == 1)
                r = i;
        }
    }
    if (l != 0 && r != 0 && r < n)
        ans -= 2;
    else if (l != 0 && r == n)
        ans--;
    cout << ans << endl;
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