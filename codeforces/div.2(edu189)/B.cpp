#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<int>
        a(n);
    for (int i = 0; i < n; i++)
    {
        a[i] = s[i] == 'a' ? 0 : 1;
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        b[i] = a[i] ^ (i & 1);
    }
    array<int, 2> cnt{0};
    for (int i = 0, j = 0; i < n;)
    {
        j = i;
        while (j < n && b[i] == b[j])
            j++;
        cnt[b[i]]++;
        i = j;
    }
    if (cnt == array<int, 2>{0, 0} || ranges::count(cnt, 1) >= 1)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
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