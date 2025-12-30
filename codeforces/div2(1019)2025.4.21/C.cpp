#include <bits/stdc++.h>
using namespace std;

// 前缀和维护前n个数的中位数是否大于k
// pre[i~j]=pre[j]-pre[i-1];
const int N = 2e5 + 10;
int a[N];
int pre[N];
void solve()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    pre[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + (a[i] > k ? 1 : -1);
    }
        bool flag = 0;
    int cnt = 0;
    for (int i = 2; i <= n; i++)
    {
        if (pre[i] < 0)
            flag |= 1;
        if (pre[i] == 0)
            cnt++;
    }
    flag |= (cnt > 1);
    cnt = 0;
    for (int i = n - 2; i >= 1; i--)
    {
        if (pre[n] - pre[i] < 0)
            flag |= 1;
        if (pre[n] - pre[i] == 0)
            cnt++;
    }
    flag |= (cnt > 1);
    int l = 1, r = n - 1;
    while (pre[l] > 0 && l < r)
        l++;
    while (l < r && pre[n] - pre[r] > 0)
        r--;
    flag |= (l < r);
    if(flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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