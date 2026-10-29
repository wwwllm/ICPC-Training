#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 2e5 + 50;
int l[maxn], r[maxn];
int f(int k)
{
    return k * (k + 1) * (k * 2 + 1) / 6;
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> l[i] >> r[i];
    int sum1 = 0, sum2 = 0, d = 0;
    for (int i = 2; i <= n; i++)
        sum1 += abs(l[i] - l[i - 1]), d += f(abs(r[i] - l[i] - r[i - 1] + l[i - 1]));
    for (int i = 1; i <= n; i++)
    {
        sum2 += f(r[i] - l[i] + 1);
    }
    sum2 *= 2;
    sum2 -= f(r[1] - l[1] + 1);
    sum2 -= f(r[n] - l[n] + 1);
    cout << sum2 - d << endl;
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}