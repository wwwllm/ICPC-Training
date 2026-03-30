#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<string> p2;
vector<int> a;
void dfs(const string &s)
{
    if (s.size() > 0)
        a.push_back(stoll(s));
    for (auto &str : p2)
    {
        if (s.size() + str.size() <= 10)
            dfs(s + str);
    }
}
void init()
{
    for (int i = 0; (1LL << i) <= 1e10; i++)
    {
        p2.push_back(to_string((1LL << i)));
    }
    dfs("");
    ranges::sort(a);
    a.erase(unique(a.begin(), a.end()), a.end());
}
void solve()
{
    int n;
    cin >> n;
    cout << a[n - 1] << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    init();
    while (t--)
        solve();
    return 0;
}