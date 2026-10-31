#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18;
void solve()
{
    int n;
    cin >> n;
    vector<int> r(n), l(n);
    for (int i = 0; i < n;i++){
        cin >> l[i] >> r[i];
    }
    int mx = -inf, res = 0,cur=-inf;
    for (int i = 0; i < n;i++){
        mx = max(r[i], mx);
        if(cur<l[i]){
            cur = max(cur, mx);
            mx = -inf;
            res++;
        }
    }
    cout << res << '\n';
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