#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> cnt(4);
    for (int i = 0; i < n; i++)
    {
        cnt[i % 4]++;
    }
    cout << (cnt[0] == cnt[3] && cnt[1] == cnt[2] ? "Bob\n" : "Alice\n");
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