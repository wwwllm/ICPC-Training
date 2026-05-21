#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/gym/105910
const int N = 63;
vector C(N + 1, vector<int>(N + 1));
void init()
{
    for (int i = 0; i <= N; i++)
    {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++)
        {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }
    }
}
void solve()
{
    int m, k;
    cin >> m >> k;
    if (m == 0)
    {
        cout << 0 << '\n';
        return;
    }
    int c = k - 1;
    int ans = 0;
    for (int i = 63; i >= 0; i--)
    {
        if (c < 0)
            break;
        int cnt = C[i][c];
        if (m > cnt)
        {
            ans |= (1LL << i);
            m -= cnt;
            c--;
        }
    }
    cout << ans + 1 << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    init();
    while (t--)
        solve();
    return 0;
}