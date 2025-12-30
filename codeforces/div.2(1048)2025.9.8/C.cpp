#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int k;
    int x;
    cin >> k >> x;
    vector<int> op;
    vector<int> bit(61);
    for (int i = 0; i < 61; i++)
        bit[i] = ((x >> i) & 1);
    if (x == (1LL << k))
    {
        cout << 0 << '\n'
             << '\n';
        return;
    }
    int pre = -1;
    int tmp = (1LL << k);
    for (int i = 0; i <= 60; i++)
    {
        if (bit[i] == 1)
        {
            if (pre == -1)
            {
                pre = i;
                continue;
            }
            else
            {
                int cnt = i - pre - 1;
                for (int j = 0; j < cnt; j++)
                    op.push_back(1), tmp >>= 1;
                int y = (1LL << (k + 1)) - tmp;
                tmp += y >> 1;
                op.push_back(2);
                pre = i;
            }
        }
    }
    while (tmp != x)
    {
        tmp >>= 1;
        op.push_back(1);
    }
    cout << op.size() << '\n';
    for (auto p : op)
        cout << p << ' ';
    cout << '\n';
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