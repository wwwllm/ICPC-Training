#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/gym/105143
void solve()
{
    int n, k;
    cin >> n >> k;
    auto query = [&](int i, int j, int x)
    {
        cout << "? " << i << ' ' << j << ' ' << x << endl;
        int res;
        cin >> res;
        return res;
    };
    auto answer = [&](int x)
    {
        cout << "! " << x << endl;
    };
    auto check = [&](int x)
    {
        int i = n, j = 1;
        int cnt = 0;
        while (i >= 1 && j <= n)
        {
            if (query(i, j, x))
            {
                cnt += i;
                j++;
            }
            else
            {
                i--;
            }
        }
        return cnt >= n * n - k + 1;
    };
    int l = 0, r = n * n + 1;
    while (l + 1 != r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }
    answer(r);
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}