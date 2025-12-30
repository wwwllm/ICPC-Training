#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e5 + 50;
int b[maxn];
map<int, int, greater<int>> mp;
int n, m;
int solve(int x)
{
    int ans = 0;
    for (auto [it, cnt] : mp)
    {
        if (x == 0)
            break;
        if (x / it != 0)
        {
            if (x / it > cnt)
            {
                x -= cnt * it;
                ans += cnt;
            }
            else
            {
                ans += x / it;
                x %= it;
            }
        }
    }
    if (x == 0)
        return ans;
    else
        return -1;
}
signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    for (int i = 1; i <= m; i++)
    {
        cout << solve(b[i]) << ' ';
    }
    cout << endl;
    return 0;
}