#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int ans = 0;
    while (n--)
    {
        int a;
        cin >> a;
        if (a % 2 == 0 || (int)sqrt(a) * (int)sqrt(a) == a)
            ans++;
    }
    cout << ans << endl;
    return 0;
}