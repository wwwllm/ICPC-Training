#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve1(){
    int x;
    cin >> x;
    int l = 1, r;
    int ans = 0;
    while (l <= x)
    {
        int tmp = x / l;
        r = x / tmp;
        r = min(r, x);
        ans += tmp * (r - l + 1);
        l = r + 1;
    }
    cout << ans << '\n';
}
void solve(){
    int x;
    cin >> x;
    int ans = 0;
    for (int i = 1; i <= x / i;i++){
        int r = x / i;
        ans += (r - i + 1) * 2 - 1;
    }
    cout << ans << '\n';
}
signed main()
{
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}