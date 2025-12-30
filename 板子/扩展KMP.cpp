#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e7 + 50;
string a, b;
int z[N], e[N];
int n, m;
void zarr()
{
    z[0] = m;
    for (int i = 1, c = 1, r = 1, len; i < m; i++)
    {
        len = r > i ? min(r - i, z[i - c]) : 0;
        while (i + len < m && b[i + len] == b[len])
            len++;
        if (i + len > r)
            c = i, r = i + len;
        z[i] = len;
    }
}
void earr()
{
    for (int i = 0, c = 0, r = 0, len; i < n; i++)
    {
        len = r > i ? min(r - i, z[i - c]) : 0;
        while (len < m && i + len < n && a[i + len] == b[len])
            len++;
        if (i + len > r)
            c = i, r = i + len;
        e[i] = len;
    }
}
void check()
{
    ll ansz = 0, anse = 0;
    for (int i = 0; i < m; i++)
        ansz ^= (ll)(i + 1) * (z[i] + 1);
    for (int i = 0; i < n; i++)
        anse ^= (ll)(i + 1) * (e[i] + 1);
    cout << ansz << endl
         << anse << endl;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> a >> b;
    n = a.length(), m = b.length();
    zarr();
    earr();
    check();
    return 0;
}