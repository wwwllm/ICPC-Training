#include <bits/stdc++.h>
#define int long long
using namespace std;
using i128 = __int128;

// https://codeforces.com/gym/105909
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
std::istream &operator>>(std::istream &is, i128 &n)
{
    string s;
    if (is >> s)
    {
        n = 0;
        bool sign = s[0] == '-';
        for (int i = sign; i < s.size(); i++)
        {
            n = n * 10 + (s[i] - '0');
        }
        if (sign)
            n = -n;
    }
    return is;
}
const int N = 1e6;
void solve()
{
    int n, m, k, x;
    cin >> n >> m >> k >> x;
    vector<int> b(n), c(n);
    i128 sum = 0;
    for (int i = 0; i < n; i++)
        cin >> b[i] >> c[i], sum += (i128)b[i] * c[i];
    if (n * x < m)
    {
        cout << "NO\n";
        return;
    }
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        a.push_back(c[i] - k * b[i]);
    }
    ranges::sort(a, greater<int>());
    int p = 0;
    i128 ans = 0;
    while (p < n && m)
    {
        if (m >= x)
        {
            ans += (i128)k * x * x + (i128)a[p++] * x;
            m -= x;
        }
        else
        {
            int d = min(m, x);
            ans += (i128)k * d * d + (i128)a[p++] * d;
            m -= d;
        }
    }
    if (ans > sum)
    {
        cout << "YES\n";
    }
    else
        cout << "NO\n";
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