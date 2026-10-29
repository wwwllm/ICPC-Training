#include <bits/stdc++.h>
#define int long long
using namespace std;
// using ll = long long;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int res = 0, x = 0;
    for (int i = 1; i <= n; i++)
    {
        res = res / 2 + a[i];
        if (res)
            cout << (res > 0 ? '+' : '-');
        else
        {
            if (x)
                cout << (x > 0 ? '+' : '-');
            else
                cout << 0;
        }
        if (res % 2)
            x = res % 2;
    }
    return 0;
}