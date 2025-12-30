#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/problemset/problem/1980/D
int gcd(int x, int y)
{
    return y ? gcd(y, x % y) : x;
}
bool check(const vector<int> &a)
{
    int n = a.size();
    vector<int> b(1);
    for (int i = 1; i < n; i++)
    {
        int tmp = gcd(a[i], a[i - 1]);
        if (tmp >= b.back())
            b.push_back(tmp);
        else
            return 0;
    }
    return 1;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int pos = -1, pre = 0;
    for (int i = 0; i < n; i++)
    {
        int tmp = gcd(a[i], a[i + 1]);
        if (tmp >= pre)
        {
            pre = tmp;
        }
        else
        {
            pos = i;
            break;
        }
    }
    if (pos == -1)
    {
        cout << "YES\n";
        return;
    }
    vector<int> a1 = a, a2 = a, a3 = a;
    a1.erase(a1.begin() + pos - 1);
    a2.erase(a2.begin() + pos);
    a3.erase(a3.begin() + pos + 1);
    int ok = check(a1) || check(a2) || check(a3);
    if (ok)
        cout << "YES\n";
    else
        cout << "NO\n";
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