#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    int n, x, b, c;
    cin >> n >> x >> b >> c;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        a[i] += a[i - 1];
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = n; j >= i; j--)
        {
            int sum = a[j] - a[i - 1];
            if (sum > x * (b * j - c * i))
                ans = max(j - i + 1, ans);
        }
    }
    cout << ans << '\n';
    return 0;
}