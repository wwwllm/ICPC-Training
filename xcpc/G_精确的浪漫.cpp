#include <bits/stdc++.h>
#define int long long
using namespace std;

// https://codeforces.com/gym/105909
void solve()
{
    int sx, sy, tx, ty, x, y;
    cin >> sx >> sy >> tx >> ty >> x >> y;
    int dx = 0, dy = 0;
    int tmp = y;
    vector<int> bit;
    while (tmp)
    {
        if (tmp & 1)
            dx++;
        dy++;
        bit.push_back(tmp % 2);
        tmp >>= 1;
    }
    dy--;
    int X = tx - dx, Y = ty - dy;
    string ans = "";
    dx = X - sx;
    for (int i = 0; i < 50; i++)
    {
        ans += 'S';
    }
    for (int i = 0; i < 50; i++)
        ans += 'W';
    if (dx != 0)
    {
        char c = dx < 0 ? 'A' : 'D';
        for (int i = 0; i < abs(dx); i++)
            ans += c;
    }
    for (int i = 0; i < 50; i++)
    {
        ans += 'S';
    }
    sy -= 50;
    dy = Y - sy;
    if (dy != 0)
    {
        char c = dy < 0 ? 'S' : 'W';
        for (int i = 0; i < abs(dy); i++)
            ans += c;
    }
    for (int i = bit.size() - 1; i >= 0; i--)
    {
        string s = "";
        if (bit[i] == 1)
            s += 'D';
        if (i != 0)
            s += 'W';
        ans += s;
    }
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