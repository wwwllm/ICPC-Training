#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s, t;
    cin >> s >> t;
    if (s == t)
    {
        cout << "Yes\n";
        return;
    }
    if (n < 2 * k)
    {
        swap(s[0], s[n - 1]);
        if (s == t)
        {
            cout << "Yes\n";
            return;
        }
        else
        {
            cout << "No\n";
            return;
        }
    }
    if (n == 2 * k)
    {
        array<char, 4> ss{s[0], s[k - 1], s[k], s[n - 1]};
        array<char, 4> tt{t[0], t[k - 1], t[k], t[n - 1]};
        vector<array<int, 4>> p{
            {0, 1, 2, 3},
            {3, 1, 2, 0},
            {1, 0, 3, 2},
            {3, 2, 1, 0},
            {2, 3, 0, 1},
            {0, 2, 1, 3},
            {1, 3, 0, 2},
            {2, 0, 3, 1}};
        auto check = [&](array<int, 4> &pos) -> bool
        {
            array<char, 4> ns;
            for (int i = 0; i < 4; i++)
            {
                ns[pos[i]] = ss[i];
            }
            return tt == ns;
        };
        for (int i = 0; i < n; i++)
        {
            if (i == 0 || i == k - 1 || i == k || i == n - 1)
                continue;
            if (s[i] != t[i])
            {
                cout << "No\n";
                return;
            }
        }
        for (auto pos : p)
        {
            if (check(pos))
            {
                cout << "Yes\n";
                return;
            }
        }
        cout << "No\n";
        return;
    }
    array<int, 26> cnt{0};
    for (int i = 0; i < n; i++)
    {
        if (i == 0 || i == n - 1 || (i + 1 >= k && n - i >= k))
        {
            cnt[s[i] - 'a']++;
            cnt[t[i] - 'a']--;
        }
        else
        {
            if (s[i] != t[i])
            {
                cout << "No\n";
                return;
            }
        }
    }
    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] != 0)
        {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}