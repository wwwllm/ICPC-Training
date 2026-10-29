#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    map<int, int, greater<int>> mp;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n;)
    {
        int j = i;
        while (j < n && a[i] == a[j])
            j++;
        mp[j - i]++;
        i = j;
    }
    int sum = 0, cnt = 0;
    int ans = 0;
    for (auto [l, c] : mp)
    {
        sum += l * c;
        cnt += c;
        int res = sum - (l - 1) * cnt;
        if (k - res >= 0 && (k - res) % cnt == 0)
            ans++;
    }
    cout << ans << '\n';
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