#include <bits/stdc++.h>
#define int long long
using namespace std;

// x*t[i]+y*t[n-i+1]=b[i]
const int maxn = 2e3 + 50;
int t[maxn], b[maxn], a[maxn];
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> t[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    bool ans = false;
    for (int x = 1; x * t[1] <= b[1]; x++)
    {
        if (((b[1] - x * t[1]) % t[n]) != 0)
            continue;
        int y = (b[1] - x * t[1]) / t[n];
        bool flag = 1;
        for (int i = 2; i <= n; i++)
        {
            if (x * t[i] + y * t[n - i + 1] != b[i])
            {
                flag = false;
                break;
            }
        }
        if (flag)
            ans = 1;
    }
    if (ans)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
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
