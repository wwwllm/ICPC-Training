#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/gym/105358
// 00001->1-1-1-1-1
// 000100->1-1-1-100
void solve()
{
    int n;
    cin >> n;
    if (n % 4 == 0)
    {
        cout << "NO\n";
        return;
    }
    else
        cout << "YES\n";
    vector<int> bit;
    for (int i = 31; i >= 0; i--)
    {
        bit.push_back((n >> i) & 1);
    }
    for (int i = 0; i < 31; i++)
    {
        if (bit[i] == 0)
        {
            bit[i] = 1;
            int j = i + 1;
            while (j < 31 && bit[j] == 0)
            {
                bit[j++] = -1;
            }
            if (bit[j - 1] == 0)
            {
                for (int k = i; k < j; k++)
                    bit[i] = 0;
            }
            else
                bit[j] = -1;
        }
    }
    for (int i = 31; i >= 0; i--)
        cout << bit[i] << " \n"[(i % 8) == 0];
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}