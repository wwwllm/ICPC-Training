#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1005;
int a[N];
int t[N];
void solve()
{
    int n;
    memset(t, 0, sizeof(t));
    cin >> n;
    bool flag = 1;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        t[a]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (t[i] == 1)
        {
            flag = 0;
            break;
        }
        if (t[i] > 2)
        {
            t[i + 1] += t[i] - 2;
        }
    }
    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
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
