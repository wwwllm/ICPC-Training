#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/problem/1989/C
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &X : a)
        cin >> X;
    for (auto &X : b)
        cin >> X;
    int suma = 0, sumb = 0;
    int cnt1 = 0, cnt0 = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0 && b[i] == 0)
            continue;
        else if (a[i] == 1 && b[i] == 1)
        {
            cnt1++;
        }
        else if (a[i] == -1 && b[i] == -1)
        {
            cnt0++;
        }
        else if (a[i] == 1)
            suma++;
        else if (b[i] == 1)
            sumb++;
    }
    while(cnt0)
    {
        if (suma >= sumb)
            suma--;
        else
            sumb--;
        cnt0--;
    }
    while (cnt1)
    {
        if (suma >= sumb)
            sumb++;
        else
            suma++;
        cnt1--;
    }
    cout << min(suma, sumb) << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}