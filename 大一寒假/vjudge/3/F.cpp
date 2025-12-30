#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 2e5 + 50;
int a[maxn], s[maxn];
void solve()
{
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i], sum += abs(a[i]);
    int top = 0, cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] < 0)
            s[++top] = a[i];
        else if(a[i]>0)
        {
            if (top != 0)
            {
                cnt++;
                top = 0;
            }
        }
    }
    if (top != 0)
    {
        cnt++;
    }
    cout << sum << ' ' << cnt << endl;
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
