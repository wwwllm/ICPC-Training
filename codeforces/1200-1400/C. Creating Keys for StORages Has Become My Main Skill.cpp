#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/problemset/problem/2072/C
int lowbit(int x)
{
    return x & -x;
}
void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n, 0);
    int res = 0;
    for (int i = 0; i < min(x + 1, n); i++)
    {
        int temp = i | x;
        res |= i;
        if (temp == x)
            a[i] = i;
        else
            break;
    }
    if (res != x)
    {
        a[n - 1] = x;
    }
    for (auto it : a)
        cout << it << ' ';
    cout << '\n';
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