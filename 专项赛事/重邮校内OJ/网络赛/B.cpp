#include <bits/stdc++.h>
#define int long long
using namespace std;

// N/i=k
// N/1--N/2+1:k=1:len=N/1-N/2=N/2
// N/2--N/3+1:k=2:len=N/2-N/3=N/(2*3)
// N/3--N/4+1:k=3
// N/j--N/(j+1)+1:k=j

// N/n--N/(n+1)+1:k=n

const int N = 1e9 + 7;
void solve()
{
    int p;
    cin >> p;
    int ans = 0;
    int l = 1;
    while (l <= p)
    {
        int d = N / l;
        int r = N / d;
        if (r > p)
            r = p;
        int cnt = r - l + 1;
        ans ^= cnt;
        l = r + 1;
    }
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}