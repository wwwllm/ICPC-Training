#include <bits/stdc++.h>
#define int long long
using namespace std;

// a2=a1+a3+(a5-a4)+(a7-a6)……
const int maxn = 4e5 + 50;
int b[maxn], a[maxn];
set<int> S;
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= 2 * n; i++)
    {
        cin >> b[i];
    }
    sort(b + 1, b + 1 + 2 * n);
    int a2 = b[2 * n] + b[2 * n - 1]; // a1+a3
    for (int i = 1; i <= n-1; i++)
    {
        a2 += b[2 * i] - b[2 * i - 1];
    }
    cout << b[2 * n] << ' ' << a2 << ' ' << b[2 * n - 1]<<' ';
    for (int i = 1; i <= n-1; i++)
        cout << b[2 * i-1] << ' ' << b[2 * i] << ' ';
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
