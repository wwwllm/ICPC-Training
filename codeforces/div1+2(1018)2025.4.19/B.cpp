#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 10;
int l[N], r[N],a[N];
void solve(){
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n;i++)
        cin >> l[i];
    for (int i = 1; i <= n;i++)
        cin >> r[i];
    int ans = 0;
    for (int i = 1; i <= n;i++){
        ans += max(l[i], r[i]);
        a[i] = min(l[i], r[i]);
    }
    sort(a + 1, a + 1 + n, [&](const int a, const int b)
         { return a > b; });
    for (int i = 1; i < k;i++)
        ans += a[i];
    cout << ans + 1 << endl;
}
signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}