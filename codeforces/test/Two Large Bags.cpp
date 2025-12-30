#include <bits/stdc++.h>
#define int long long
using namespace std;

// dp[i]为以i结尾的最-字段和
// dp[i]=(dp[i-1]+a[i],0)
const int N = 2e5 + 10;
int a[N];
int dp1[N], dp2[N]; // dp1存最小，dp2求最大
void solve()
{
    int n, p=1;
    memset(dp1, 0, sizeof(dp1));
    memset(dp2, 0, sizeof(dp2));
    set<int> S;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] != 1 && a[i] != -1)
            p = i;
    }
    int res = 0, min1 = 0, max1 = 0;
    for (int i = p + 1; i <= n; i++)
    {
        res += a[i];
        min1 = min(res, min1);
        max1 = max(max1, res);
    }
    int min2 = 0, max2 = 0;
    res = 0;
    for (int i = p - 1; i >= 1; i--)
    {
        res += a[i];
        min2 = min(res, min2);
        max2 = max(max2, res);
    }
    for (int i = min1 + min2; i <= max1 + max2; i++)
        S.insert(a[p] + i);
    int minx = 0, maxx = 0;
    for (int i = 1; i <= p - 1; i++)
    {
        dp1[i] = min((int)0, dp1[i - 1] + a[i]);
        minx = min(dp1[i], minx);
        dp2[i] = max((int)0, dp2[i - 1] + a[i]);
        maxx = max(maxx, dp2[i]);
    }
    for (int i = p + 1; i <= n; i++)
    {
        dp1[i] = min((int)0, dp1[i - 1] + a[i]);
        minx = min(dp1[i], minx);
        dp2[i] = max((int)0, dp2[i - 1] + a[i]);
        maxx = max(maxx, dp2[i]);
    }
    for (int i = minx; i <= maxx; i++)
        S.insert(i);
    cout << S.size() << endl;
    for (auto ele : S)
        cout << ele << ' ';
    cout << endl;
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
