#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n,k;
    cin >> n>>k;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end(), [&](int a, int b)
         { return a > b; });
    int ans = 0;
    for (int i =0, j; i < n; i++)
    {
        j = i;
        while (a[j]*(j-i+1)<k&&j<n)
            j++;
        if(j<n)
            ans++,i=j;
        else
            break;
    }
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}