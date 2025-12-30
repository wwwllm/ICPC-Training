#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e5 + 50;
int a[maxn];
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    int sum1 = 1, sum2 = 1;
    while (a[sum1] == a[sum1 + 1])
        sum1++;
    while (a[n - sum2 + 1] == a[n - sum2])
        sum2++;
    if(a[1]!=a[n])cout << sum1 * sum2 * 2 << endl;
    else
        cout << n * (n - 1) << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
