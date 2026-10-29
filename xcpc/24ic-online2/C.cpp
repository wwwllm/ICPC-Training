#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e9;
void solve()
{
    int n;
    cin >> n;
    int sum = 0;
    auto get = [&](int &s, int &a, int &b)
    {
        cin >> s >> a >> b;
        s = (s + sum) % n;
    };
    vector<int> s, a, b;
    vector<int> z(n + 1);
    for (int i = 0; i < n; i++)
    {
        int x, y, u;
        get(x, y, u);
        s.push_back(x);
        a.push_back(y);
        b.push_back(u);
        for (int j = 0; j <= i; j++)
        {
            if (j + z[j] == i && s[z[j]] == s[i])
            {
                z[j]++;
                sum += a[i] * b[j];
            }
        }
        cout << sum << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}