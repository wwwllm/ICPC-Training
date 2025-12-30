#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 105;
int a[maxn];
void solve()
{
    int n, x;
    cin >> n >> x;
    int sum = 0;
    for (int i = 1; i <= n; i++)
        cin >>a[i],sum += a[i];
    if (sum == n * x)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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