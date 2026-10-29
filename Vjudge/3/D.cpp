#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e6;
int mp[maxn + 1] = {0};
void solve()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << "NO" << endl;
        return;
    }
    if (mp[n])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    for (int k = 2; k <= 1000; k++)
    {
        int sum = 1, ki = k;
        for (int i = 1; i <= 20; i++)
        {
            sum += ki;
            ki *= k;
            if (sum > maxn)
                break;
            if(i>=2)
                mp[sum] = 1;
        }
    }
    while (t--)
        solve();
    return 0;
}
