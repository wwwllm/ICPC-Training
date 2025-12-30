#include <bits/stdc++.h>
#define int long long
using namespace std;

//x1%k==i&&x2%k==i--x2-x1==n*k
const int maxn = 1e5 + 50;
int a[maxn],cnt[maxn];
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    a[0] = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        a[i] = (a[i - 1]+a[i])%k;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += cnt[a[i]];
        cnt[a[i]]++;
        if(!a[i])
            ans++;
    }
    cout << ans << endl;
    return 0;
}