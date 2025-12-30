#include <bits/stdc++.h>
// #define int long long
using namespace std;

typedef pair<int, int> PII;
const int maxn = 2e5 + 20, INF = 0x3f3f3f3f;
PII p[maxn];
int fy(int r, int o,int x)
{
    return (int)sqrt(r * r -(x-o) *(x-o));
}
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> p[i].first;
    for (int i = 1; i <= n; i++)
        cin >> p[i].second;
    int ans = 0;
    unordered_map<int, int> mp;
    for (int i = 1; i <=n;i++){
        for (int x = p[i].first - p[i].second; x <= p[i].first + p[i].second;x++){
            int y = fy(p[i].second, p[i].first, x);
            if(mp.find(x)==mp.end())
                mp[x] = 2 * y + 1;
            else
                mp[x] = max(2 * y + 1,mp [x]);
        }
    }
    for(auto [x,ele]:mp)
        ans += ele;
    cout << ans << endl;
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
