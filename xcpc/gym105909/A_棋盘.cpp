#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/gym/105909
void solve()
{
    int n;
    cin >> n;
    vector<array<int, 2>> a(n + 1);
    int suma = 0, sumb = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i][0];
    for (int i = 1; i <= n; i++)
        cin >> a[i][1];
    if (n == 1)
    {
        if (a[1][0] > a[1][1])
            cout << "Mandy\n";
        else if (a[1][0] == a[1][1])
            cout << "draw\n";
        else
            cout << "brz\n";
        return;
    }
    for (int i = 1; i <= n / 2; i++)
    {
        suma += a[i][0];
        suma += a[i][1];
    }
    for (int i = (n + 1) / 2 + 1; i <= n; i++)
    {
        sumb += a[i][0];
        sumb += a[i][1];
    }

    if (n & 1)
        sumb += a[(n + 1) / 2][0], suma += a[(n + 1) / 2][1];
    if (suma > sumb)
        cout << "Mandy\n";
    else if (suma == sumb)
        cout << "draw\n";
    else
        cout << "brz\n";
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}