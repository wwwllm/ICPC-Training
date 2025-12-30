#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    int c2 = 0, c5 = 0;
    int k = n;
    while (k % 2 == 0)
    {
        k /= 2;
        c2++;
    }
    while (k % 5 == 0)
    {
        k /= 5;
        c5++;
    }
    int ans = 1, num = max(c2, c5) - min(c2, c5);
    if (c2 > c5){
        while(ans*5<=m&&num){
            ans *= 5;
            num--;
        }
    } else{
        while (ans * 2 <= m&&num){
            ans *= 2;
            num--;
        }
    }
    while (ans*10 <= m)
    {
        ans *= 10;
    }
    cout << (m / ans) * ans*n << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
