#include <bits/stdc++.h>
#define int long long
using namespace std;

using i128 = __int128;
std::ostream &operator<<(std::ostream &os, i128 n)
{
    if (n == 0)
    {
        return os << 0;
    }
    bool sign = 0;
    if (n < 0)
    {
        sign = 1;
        n = -n;
    }
    std::string s;
    while (n > 0)
    {
        s += char('0' + n % 10);
        n /= 10;
    }
    if (sign)
        s = s + '-';
    std::reverse(s.begin(), s.end());
    return os << s;
}
void solve()
{
    int l, r;
    cin >> l >> r;
    i128 cur = 2;
    while (1)
    {
        i128 s = l / cur * cur;
        i128 t = s + cur - 1;
        if (r <= t)
            break;
        cur *= 2;
    }
    cout << (i128)l % cur << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}