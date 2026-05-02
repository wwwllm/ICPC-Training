#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 0; i < n; i++)
    {
        if (s1[i] == '0')
            s1[i] = 'O';
        if (s1[i] == 'I' || s1[i] == 'l')
            s1[i] = '1';
        if (s2[i] == '0')
            s2[i] = 'O';
        if (s2[i] == 'I' || s2[i] == 'l')
            s2[i] = '1';
    }
    if (s1 == s2)
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