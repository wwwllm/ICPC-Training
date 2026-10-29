#include <bits/stdc++.h>
#define int long long
using namespace std;

int top(int x)
{
    int ans = 0;
    while (x)
    {
        ans = x % 10;
        x /= 10;
    }
    return ans;
}
signed main()
{
    int l, r;
    cin >> l >> r;
    vector<int> cnt(11);
    auto f = [&](int x, int op)
    {
        int l = 1, r;
        while (l <= x)
        {
            int k = x / l;
            r = x / k;
            r = min(r, x);
            for (int i = 1; i <= r; i *= 10)
            {
                for (int p = 1; p <= 9; p++)
                {
                    int n = max(i * p, l);
                    int m = min(i * (p + 1) - 1, r);
                    if (m >= n)
                        cnt[p] += (m - n + 1) * op * k;
                }
            }
            l = r + 1;
        }
    };
    f(l - 1, -1);
    f(r, 1);
    for (int i = 1; i <= 9; i++)
        cout << cnt[i] << '\n';
    return 0;
}