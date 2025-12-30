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
    int l = 0, r = n + 1;
    auto cmp = [&](int l) -> bool
    {
        for (int i = 1, j = l; j <= n; j++, i++)
        {
            int sum = a[j] - a[i - 1], tmp = x * (b * j - c * i);
            if (sum > tmp)
                return 1;
        }
        return 0;
    };
    while (l + 1 != r)
    {
        int mid = l + r >> 1;
        if (cmp(mid))
            l = mid;
        else
            r = mid;
    }
    cout << l << '\n';
    return 0;
}