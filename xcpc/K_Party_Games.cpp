#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/gym/105143
const int N = 1e6;
vector<int> sum(N + 1);
void init()
{
    for (int i = 1; i <= N; i++)
    {
        sum[i] = sum[i - 1] ^ i;
    }
}
void solve()
{
    int n;
    cin >> n;
    int s = sum[n];
    if (((s ^ 1) == 0) || ((s ^ n) == 0))
        cout
            << "Fluttershy\n";
    else
        cout << "Pinkie Pie\n";
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