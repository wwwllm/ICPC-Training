#include <bits/stdc++.h>
#define int long long
using namespace std;

int Sqrt(int x)
{
    int res = sqrt(x);
    while (res * res > x)
    {
        res--;
    }
    return res;
}
void solve()
{
    int n;
    cin >> n;
    int k = Sqrt(n);
    map<int, int> ans;
    for (int i = 1; i <= k; i++)
    {
        for (int j = i + 1; j <= k; j++)
        {
            if (i * i + j * j <= n)
            {
                ans[i * i + j * j]++;
            }
        }
    }
    int cnt = 0;
    for (auto [x, c] : ans)
    {
        if (c == 1)
            cnt++;
    }
    cout << cnt << '\n';
    for (auto [x, c] : ans)
    {
        if (c == 1)
        {
            cout << x << ' ';
        }
    }
    cout << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}