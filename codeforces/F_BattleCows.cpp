#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

// https://codeforces.com/contest/2185/problem/F
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a((1LL << n) + 1);
    for (int i = 1; i <= (1LL << n); i++)
    {
        cin >> a[i];
    }
    vector<int> sum((1LL << n) + 1);
    for (int i = 1; i <= (1LL << n); i++)
    {
        sum[i] = sum[i - 1] ^ a[i];
    }
    while (q--)
    {
        int b, c;
        cin >> b >> c;
        function<int(int, int)> clac = [&](int l, int r) -> int
        {
            if (l == r)
                return 0;
            int mid = (l + r) >> 1;
            int len = r - l + 1;
            int res = 0;
            int vall = sum[mid] ^ sum[l - 1], valr = sum[r] ^ sum[mid];
            if (b <= mid)
            {
                vall = vall ^ c ^ a[b];
                if (vall >= valr)
                    res = clac(l, mid);
                else
                    res = len / 2 + clac(l, mid);
            }
            else
            {
                valr = valr ^ c ^ a[b];
                if (vall >= valr)
                    res = len / 2 + clac(mid + 1, r);
                else
                    res = clac(mid + 1, r);
            }
            return res;
        };
        cout << clac(1, 1LL << n) << '\n';
    }
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