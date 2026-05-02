#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

const int inf = 1e9;
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = ' ' + s;
    auto f = [&]()
    {
        vector<int> a;
        for (int i = 1; i <= n; i++)
        {
            if ((i & 1) && s[i] == '0')
                a.pb(0);
            if (!(i & 1) && s[i] == '1')
                a.pb(1);
        }
        int cnt0 = 0, cnt1 = 0;
        int m = a.size();
        for (int i = 0; i < m; i++)
        {
            if (a[i] == 1)
            {
                cnt1++;
                if (cnt0)
                    cnt0--;
            }
            else
            {
                cnt0++;
                if (cnt1)
                    cnt1--;
            }
        }
        return cnt0 + cnt1;
    };
    int res = f();
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '1')
            s[i] = '0';
        else
            s[i] = '1';
    }
    cout << min(res, f()) << '\n';
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