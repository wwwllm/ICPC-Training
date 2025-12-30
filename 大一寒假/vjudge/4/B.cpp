#include <bits/stdc++.h>
#define int long long
using namespace std;

//1 2 3 4 5
//2 4
//1 2 3,3 4 5:3+2+1+3+2+1
//3 3 3 5 5 5
const int maxn = 1e5 + 50;
int l[maxn], r[maxn], a[maxn];
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        a[i] = n;
    for (int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        l[i] = min(x, y);
        r[i] = max(x, y);
    }
    for (int i = 1; i <= m;i++){
        a[l[i]] = min(a[l[i]], r[i] - 1);
    }
    for (int i = n-1; i >= 1;i--){
        a[i] = min(a[i], a[i + 1]);
    }
    int ans = 0;
    for (int i = 1; i <= n;i++){
        ans += a[i] - i + 1;
    }
    cout << ans << endl;
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
