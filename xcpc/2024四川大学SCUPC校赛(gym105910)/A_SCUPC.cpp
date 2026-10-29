#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/gym/105910
const int N = 1e5;
void solve()
{
    int n;
    cin >> n;
    string A, B, C;
    cin >> A >> B >> C;
    bitset<N> a(A), b(B), c(C);
    auto calc = [&](const string &a, const bitset<N> &b, const bitset<N> &c) -> int
    {
        string aa = a + a;
        int res = 0;
        int cnt = (b & c).count();
        auto y = b ^ c;
        bitset<N> x(a);
        for (int i = 0; i < n; i++)
        {
            x <<= 1;
            x |= (aa[i + n] - '0');
            res = max(res, cnt + (int)(y & x).count());
        }
        return res;
    };
    int ans = max({calc(A, b, c), calc(B, a, c), calc(C, a, b)});
    cout << ans << '\n';
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