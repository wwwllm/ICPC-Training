#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 10;
int n;
int x[N];
signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    sort(x + 1, x + 1 + n);
    int xx = x[n / 2 + 1],ans=0;
    for (int i = 1; i <= n;i++)
        ans += abs(xx - x[i]);
    cout << ans << endl;
    return 0;
}