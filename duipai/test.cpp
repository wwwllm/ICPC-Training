#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <functional>
#include <array>

using namespace std;
using i64 = long long;
using PII = pair<int, int>;

void solve()
{
    int n;
    i64 x, y;
    cin >> n >> x >> y;

    string s;
    cin >> s;
    if (x == 0 && y == 0)
    {
        for (char c : s)
        {
            if (c == '2')
                cout << 0;
            else
                cout << c;
        }
        cout << '\n';
        return;
    }
    i64 t = (x + y) / n;
    i64 m = (x + y) - t * n;

    vector<int> cnt_n(3);

    for (char c : s)
    {
        cnt_n[c - '0']++;
    }

    vector<int> cnt_m(3);
    string ss = s.substr(0, m);
    for (char c : ss)
    {
        cnt_m[c - '0']++;
    }

    if (t == 0 || m == 0)
    {
        int cnt;
        if (t == 0)
        {
            cnt = x - cnt_n[0];
        }
        else
        {
            cnt = x / t - cnt_n[0];
        }
        for (char c : s)
        {
            if (c == '2')
            {
                if (cnt != 0)
                {
                    cnt--;
                    cout << 0;
                }
                else
                {
                    cout << 1;
                }
            }
            else
            {
                cout << c;
            }
        }
        cout << '\n';
        return;
    }

    for (i64 p = cnt_m[2]; p >= 0; p--)
    {
        i64 q = cnt_m[2] - p;
        i64 sum0 = (x - cnt_n[0] * t - (p) * (t + 1) - cnt_m[0]);
        i64 sum1 = (y - cnt_n[1] * t - (q) * (t + 1) - cnt_m[1]);
        if (sum0 % t == 0 && sum1 % t == 0 && sum0 >= 0 && sum1 >= 0)
        {
            for (int i = 0; i < m; i++)
                if (s[i] == '2')
                {
                    if (p > 0)
                    {
                        cout << 0;
                        p--;
                    }
                    else
                    {
                        cout << 1;
                    }
                }
                else
                {
                    cout << s[i];
                }

            int cnt = sum0 / t;
            for (int i = m; i < n; i++)
            {
                if (s[i] == '2')
                {
                    if (cnt > 0)
                    {
                        cout << 0;
                        cnt--;
                    }
                    else
                    {
                        cout << 1;
                    }
                }
                else
                {
                    cout << s[i];
                }
            }
            cout << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}