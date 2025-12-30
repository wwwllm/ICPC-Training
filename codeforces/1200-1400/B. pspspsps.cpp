#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/problem/2049/B
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt[2] = {0, 0};
    for (auto it : s)
        if (it == 'p')
            cnt[0]++;
        else if (it == 's')
            cnt[1]++;
    bool flag = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (s[i] == 's' & s[j] == 'p' && i != 0 && j != (n - 1))
            {
                flag = 0;
                break;
            }
        }
    cout << (flag ? "YES\n" : "NO\n");
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