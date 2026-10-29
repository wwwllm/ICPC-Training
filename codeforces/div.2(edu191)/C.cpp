#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s = ' ' + s;
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++)
    {
        b[i] = b[i - 1];
        if (s[i] == '(')
            b[i]++;
        else
            b[i]--;
    }
    int pos = ranges::min_element(b) - b.begin();
    vector<int> del;
    for (int i = 1; i <= pos; i++)
    {
        if (s[i] == '(')
        {
            if (del.size() < k)
                del.push_back(i);
        }
    }
    for (int i = n; i >= pos; i--)
    {
        if (s[i] == ')')
        {
            if (del.size() < k)
                del.push_back(i);
        }
    }
    vector<int> ans(n + 1);
    for (auto x : del)
        ans[x] = 1;
    for (int i = 1; i <= n; i++)
        cout << ans[i];
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}