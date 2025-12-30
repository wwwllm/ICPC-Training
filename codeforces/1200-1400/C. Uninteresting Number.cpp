#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/problemset/problem/2050/C
//  3->6
//  2->2
void solve()
{
    string s;
    cin >> s;
    array<int, 2> cnt = {0, 0};
    int sum = 0;
    for (auto it : s)
    {
        int u = it - '0';
        if (u == 2 || u == 3)
            cnt[u - 2]++;
        sum += u;
    }
    if (sum % 9 == 0)
    {
        cout << "YES\n";
    }
    else
    {
        bool flag = 0;
        for (int i = 0; i <= min(9LL, cnt[0]); i++)
            for (int j = 0; j <= min(9LL, cnt[1]); j++)
            {
                if (((sum + 2 * i + 6 * j) % 9 == 0))
                    flag = 1;
            }
        cout << (flag ? "YES\n" : "NO\n");
    }
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