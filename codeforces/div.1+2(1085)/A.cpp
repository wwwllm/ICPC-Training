#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    string mas = s;
    for (int i = 1; i < n - 1; i++)
    {
        if (mas[i - 1] == '1' && mas[i + 1] == '1')
            mas[i] = '1';
    }
    int mac = ranges::count(mas, '1');
    for (int i = 1; i < n - 1; i++)
    {
        if (mas[i - 1] == '1' && mas[i + 1] == '1')
            mas[i] = '0';
    }
    int mic = ranges::count(mas, '1');
    cout << mic << ' ' << mac << '\n';
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